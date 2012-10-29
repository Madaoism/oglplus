/**
 *  @file oglplus/imports/blend_file/sdna.hpp
 *  @brief Helper class wrapping the SDNA structure of a .blend file
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef OGLPLUS_IMPORTS_BLEND_FILE_SDNA_1107121519_HPP
#define OGLPLUS_IMPORTS_BLEND_FILE_SDNA_1107121519_HPP

#include <vector>
#include <map>
#include <memory>

namespace oglplus {
namespace imports {

// Helper class storing the SDNA structure of a .blend file
// NOTE: implementation detail do not use directly
class BlendFileSDNA
 : public BlendFileReaderClient
{
private:
	// the size of pointers in bytes as used by the input file
	const std::size_t _ptr_size;

	// list of structure field names as loaded from the file's SDNA
	std::vector<std::string> _names;

	// list of type names as loaded from the the file's SDNA
	std::vector<std::string> _type_names;

	// list of type sizes as loaded from the the file's SDNA
	std::vector<uint16_t> _type_sizes;

	// 'map' of types to indices of structures stored in _structs
	// if the i-th type is atomic then the value stored here
	// is _structs.size(), if it is a structured type then the
	// value stored here is an index into the _structs list
	std::vector<uint32_t> _type_structs;

	// checks if a type with the specified index is a structure
	bool _type_is_struct(uint32_t type) const
	{
		return _type_structs[type] != _structs.size();
	}

	// stores the data describing a flattened structure.
	// flattening is a process of unfolding of the structure
	// so that it contains only atomic fields. if a structure's
	// field is another structure then this field is replaced
	// here by the list of the fields of that (also recursivelly
	// flattened) structure.
	struct _flat_struct_info
	{
		// flat field information
		// all vectors below have the same number of elements
		// and each stores a different property of the atomic
		// fields
		//
		// the full field names
		std::vector<std::string> _field_names;
		//
		// the indices of structures where the field is defined
		// if the field is defined in a nested structure
		// then the index of this structure is stored here
		// instead of the index of the original flattened structure
		std::vector<uint16_t> _field_structs;
		//
		// the indices inside of structures where field is defined
		std::vector<uint16_t> _field_indices;
		//
		// the offset of the fields in the flattened structure
		std::vector<uint32_t> _field_offsets;

		_flat_struct_info(std::size_t field_count)
		 : _field_names(field_count)
		 , _field_structs(field_count)
		 , _field_indices(field_count)
		 , _field_offsets(field_count)
		{ }

		// returns the number of fields in the flattened structure
		std::size_t _field_count(void) const
		{
			assert(
				_field_names.size() ==
				_field_structs.size()
			);
			assert(
				_field_names.size() ==
				_field_indices.size()
			);
			assert(
				_field_names.size() ==
				_field_offsets.size()
			);
			return _field_names.size();
		}
	};

	// stores the description of a single structured type
	struct _struct_info
	{
		// index to _type_names and _type_sized
		uint16_t _type_index;

		// field properties:
		// all vectors below have the same size -
		// the number of fields in a structure
		// and each stores a different property
		// of the individual fields
		//
		// indices to sdna::_type_indices
		std::vector<uint16_t> _field_type_indices;
		// indices to sdna::_name_indices
		std::vector<uint16_t> _field_name_indices;
		// stores the number of elements in the fields
		std::vector<uint16_t> _field_elem_counts;
		//
		// stores values indicating if the i-th
		//field is a pointer
		std::vector<bool> _field_ptr_flags;
		//
		// stores values indicating if the i-th
		// field is a pointer to a function
		std::vector<bool> _field_fn_ptr_flags;
		//
		// stores values indication if the i-th
		// field is an array with multiple values
		std::vector<bool> _field_array_flags;

		// pointer to a _flat_struct_info storing information
		// about the structure after flattening
		// this pointer is initialized on demand
		// by sdna's functions implemented below
		std::shared_ptr<_flat_struct_info> _flat_fields;

		// returns the number of fields in the structure
		std::size_t _field_count(void) const
		{
			assert(
				_field_type_indices.size() ==
				_field_name_indices.size()
			);
			assert(
				_field_type_indices.size() ==
				_field_elem_counts.size()
			);
			assert(
				_field_type_indices.size() ==
				_field_ptr_flags.size()
			);
			assert(
				_field_type_indices.size() ==
				_field_fn_ptr_flags.size()
			);
			assert(
				_field_type_indices.size() ==
				_field_array_flags.size()
			);
			return _field_type_indices.size();
		}
	};

	// helper function of testing whether a field specified
	// by a definition def is a pointer
	static bool _field_is_ptr(const std::string& def)
	{
		if(def.empty()) return false;
		return def[0] == '*';
	}

	// helper function of testing whether a field specified
	// by a definition def is a pointer to function
	static bool _field_is_fn_ptr(const std::string& def)
	{
		if(def.empty()) return false;
		return def.back() == ')';
	}

	// helper function of testing whether a field specified
	// by a definition def is an array
	static bool _field_is_array(const std::string& def)
	{
		if(def.empty()) return false;
		return def.back() == ']';
	}

	// helper function that parses a field definition string
	// and returns the number of elements.
	// returns 1 for non-arrays or the number of elements
	// in case of an (potentially multi-dimensional) array
	static std::size_t _field_elem_count(const std::string& def)
	{
		std::size_t n = 1;
		// find first '['
		auto p = def.find('['), e = std::string::npos;
		while(p != e)
		{
			// parse the number in '[' ']'
			std::size_t k = 0;
			do
			{
				++p;
				if(p == e)
				{
					throw std::runtime_error(
						"Invalid field name in blend file"
					);
				}
				char c = def[p];
				if(c == ']') break;
				if((c < '0') || (c > '9'))
				{
					throw std::runtime_error(
						"Invalid field name in blend file"
					);
				}
				k *= 10;
				k += c - '0';
			} while(true);

			// check the parsed number
			if(k == 0)
			{
				throw std::runtime_error(
					"Invalid array size in blend file"
				);
			}
			n *= k;
			// find the next bracket or EOS
			p = def.find('[', p);
		}
		return n;
	}

	// stores the information about the structures
	// in the SDNA block
	std::vector<_struct_info> _structs;

	// helper comparator
	struct _pstr_less
	{
		typedef const std::string* ptr;
		bool operator()(ptr a, ptr b) const
		{
			assert(a && b);
			return *a < *b;
		}
	};

	// maps type name to index in _type_names and _type_sizes
	// used for lookup of type properties by name
	std::map<const std::string*, std::size_t, _pstr_less> _type_map;

	// returns true if c is a valid character
	// for a structure field name identifier
	static bool _is_field_name_char(char c)
	{
		return	(c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') ||
			(c >= '0' && c <= '9') ||
			(c == '_');
	}

	// parses the field name from a field definition string
	// (basically removes the *,[,],(,), etc. characters)
	static std::string _field_name_from_def(std::string result)
	{
		std::size_t i = 0, n = result.size();
		while(i != n)
		{
			char c = result[i];
			if(!_is_field_name_char(c))
			{
				int k = 1;
				if(c == '[')
				{
					while((i+k != n) && (result[i+k] != ']'))
						++k;
				}
				else if(c == '(')
				{
					if(result[i+1] == '*') ++k;
					else while((i+k != n) && (result[i+k] != ')'))
						++k;
				}
				for(std::size_t j=i+k; j!=n; ++j)
					result[j-k] = result[j];
				n -= k;
			}
			else ++i;
		}
		result.resize(n);
		return result;
	}

	// returns the number of fields in a flattened structure
	// i.e. returns the number of the atomic fields
	// the structure is specified by its index in _structs
	std::size_t _struct_flat_field_count(uint32_t struct_index)
	{
		// if it is an atomic type return 1
		if(struct_index == _structs.size()) return 1;

		const _struct_info& si = _structs[struct_index];

		// if the struct has already been flattened
		// use the cached value
		if(si._flat_fields) return si._flat_fields->_field_count();

		// otherwise count them manually
		// and possibly recursivelly if necessary
		std::size_t result = 0;
		std::size_t f = 0;
		std::size_t fn = si._field_count();
		while(f != fn)
		{
			std::size_t elem_count = si._field_elem_counts[f];
			uint32_t fsi = _type_structs[si._field_type_indices[f]];
			if(si._field_fn_ptr_flags[f]) ++result;
			else if(si._field_ptr_flags[f]) ++result;
			else if(fsi == _structs.size()) ++result;
			else result += _struct_flat_field_count(fsi) * elem_count;
			++f;
		}
		return result;
	}

	const std::shared_ptr<_flat_struct_info>&
	_struct_flatten_fields(std::size_t struct_index)
	{
		// the current field index
		std::size_t field_index = 0;
		// the field offset in bytes
		std::size_t offset = 0;

		// get the structure info
		const _struct_info& si = _structs[struct_index];
		// and get a reference to the smart pointer
		// to the structure storing information
		// about this flattened structure
		std::shared_ptr<_flat_struct_info>& result = _structs[struct_index]._flat_fields;

		// if it already is initialized
		// we don't need to do anything else
		if(result) return result;

		// otherwise ..
		// get the number of atomic fields
		std::size_t fc = _struct_flat_field_count(struct_index);
		// make a new instance of the flat info
		result = std::make_shared<_flat_struct_info>(fc);

		// and go through the (potentially structured) fields
		std::size_t f = 0;
		std::size_t fn = si._field_count();
		while(f != fn)
		{
			// get the index of the type of f-th field
			uint16_t fti = si._field_type_indices[f];
			// try to map the type index to a structure
			// index (check if the field is atomic or not)
			uint32_t fsi = _type_structs[fti];

			// get the field definition string from the names
			// loaded during construction from the SDNA block
			const std::string& fd = _names[si._field_name_indices[f]];
			//
			// extract the name from definition
			std::string fn(_field_name_from_def(fd));

			// check if the field type is a pointer
			bool is_ptr =
				si._field_fn_ptr_flags[f] ||
				si._field_ptr_flags[f];
			// or if it is atomic (i.e. not a structured type)
			bool is_plain = fsi == _structs.size();

			// also get the number of elements in the field
			std::size_t elem_count = si._field_elem_counts[f];

			// if the field is a pointer
			// or if it is not structured
			if(is_ptr || is_plain)
			{
				// get it's size in bytes
				std::size_t size =
					is_ptr ?
					_ptr_size:
					std::size_t(_type_sizes[fti]);

				// initialize the properties for the currently
				// processed field in the resulting structure
				// describing the structure after flattenning
				//
				// the full field name
				result->_field_names[field_index] = fn;
				// the index of the structure in which the field
				// is actually defined
				result->_field_structs[field_index] = struct_index;
				// the index of the field in the structure
				result->_field_indices[field_index] = f;

				// align the field offset to the fields size
				if(offset % size)
					offset += size - offset % size;
				// store the offset
				result->_field_offsets[field_index] = offset;
				// update the offset
				offset += size * elem_count;

				// go to the next field
				++field_index;
			}
			else
			{
				// in case the field is structured...
				// we need to recursivelly flatten
				// the field's structure
				// so call this function again on the field's
				// structure
				const std::shared_ptr<_flat_struct_info>& nffi =
					_struct_flatten_fields(fsi);

				// after this the smart pointer must be
				// already initialized
				assert(nffi);

				// traverse the already flattened fields
				// in the nested structure
				std::size_t gn = nffi->_field_count();
				// and do that for each element in the currently
				// processed field
				for(std::size_t e=0; e!=elem_count; ++e)
				{
					for(std::size_t g=0; g!=gn ; ++g)
					{
						// get the nested field's full name
						const std::string& ffn = nffi->_field_names[g];
						// prepend the name of the currently
						// processed field
						std::string nfn = fn;
						nfn.append(".", 1);
						nfn.append(ffn);

						// get the index of the structure
						// where the nested field is defined
						std::size_t nfs = nffi->_field_structs[g];
						// and the index of this field in the
						// structure where it is defined
						std::size_t nfi = nffi->_field_indices[g];

						// initialize the properties of the currently
						// processed field in the flat info
						//
						// the full name
						result->_field_names[field_index] = nfn;
						// the parent structure
						result->_field_structs[field_index] = nfs;
						// the index in the parent structure
						result->_field_indices[field_index] = nfi;

						// the type of the field
						uint16_t nfti = _structs[nfs].
								_field_type_indices[nfi];
						// count of elements of the field
						uint16_t nfec = _structs[nfs].
								_field_elem_counts[nfi];
						// check if it is a pointer
						bool is_ptr = _structs[nfs].
								_field_ptr_flags[nfi];
						bool is_fn_ptr = _structs[nfs].
								_field_fn_ptr_flags[nfi];

						// calculate the size
						std::size_t size;
						if(is_ptr || is_fn_ptr)
							size = _ptr_size;
						else size = _type_sizes[nfti];

						// align the offset to size
						if(offset % size)
							offset += size - offset % size;
						// store the offset
						result->_field_offsets[field_index] = offset;
						// update the offset
						offset += size * nfec;
						// go to the next field
						++field_index;
					}
				}
			}
			++f;
		}

		// at this point the offset should be the same
		// as the size of the whole structure
		// TODO:assert(offset == _type_sizes[si._type_index]);

		return result;
	}

	// this class is used internally by a whole heap
	// of other classes
	friend class BlendFile;
	friend class BlendFileType;
	friend class BlendFileStruct;
	friend class BlendFileStructRange;
	friend class BlendFileStructField;
	friend class BlendFileStructFieldRange;
	friend class BlendFileFlattenedStruct;
	friend class BlendFileFlattenedStructField;
	friend class BlendFileFlattenedStructFieldRange;

public:
	// constructor uses a reader and info to parse the SDNA
	// block from the input stream
	BlendFileSDNA(BlendFileReader& bfr, const BlendFileInfo& bfi)
	 : _ptr_size(bfi.PointerSize())
	{
		// first align the input to 4 bytes
		_align(bfr, 4, "Failed to skip DNA block padding");
		// the SDNA code is expected
		_expect(bfr, "SDNA", 4, "Failed to read code in DNA block");

		// then the NAME code is expected
		_expect(bfr, "NAME", 4, "Failed to read code in DNA block");

		// read the number of field names (actually definitions)
		uint32_t i, j, n, k;
		n = _read_int<uint32_t>(
			bfr,
			bfi.ByteOrder(),
			"Failed to read name count from DNA block"
		);
		// prepare the vector to hold the names
		_names.reserve(n);
		// and load them from the input
		for(i=0; i!=n; ++i)
		{
			_names.push_back(_read_str(
				bfr,
				"Failed to read name from DNA block"
			));
		}

		// align the input to 4 bytes
		_align(bfr, 4, "Failed to skip DNA block padding");
		// the TYPE code is expected
		_expect(bfr, "TYPE", 4, "Failed to read code in DNA block");

		// now load the number of type names
		n = _read_int<uint32_t>(
			bfr,
			bfi.ByteOrder(),
			"Failed to read type name count from DNA block"
		);
		// prepare the vector
		_type_names.reserve(n);
		for(i=0; i!=n; ++i)
		{
			// load the names into the vector
			_type_names.push_back(_read_str(
				bfr,
				"Failed to read type name from DNA block"
			));
			// check for multiple definitions of a type
			// with the same name
			if(
				_type_map.find(&_type_names.back()) !=
				_type_map.end()
			)
			{
				std::string what("Multiple definitions of type '");
				what.append(_type_names.back());
				what.append("' in DNA block");
				throw std::runtime_error(what);
			}
			// otherwise update the type map
			_type_map[&_type_names.back()] = i;
		}
		assert(_type_names.size() == _type_map.size());

		// align the input to 4 bytes again
		_align(bfr, 4, "Failed to skip DNA block padding");
		// now the TLEN code is expected
		_expect(bfr, "TLEN", 4, "Failed to read code in DNA block");

		// prepare the vector
		_type_sizes.reserve(n);
		// and load the sizes of the types
		for(i=0; i!=n; ++i)
		{
			_type_sizes.push_back(_read_int<uint16_t>(
				bfr,
				bfi.ByteOrder(),
				"Failed to read type size from DNA block"
			));
		}

		// align the input again
		_align(bfr, 4, "Failed to skip DNA block padding");
		// and expect the STRC code in the input
		_expect(bfr, "STRC", 4, "Failed to read code in DNA block");

		// read the number of structures in the SDNA
		// NOTE the juggling of values between n and k
		k = _read_int<uint32_t>(
			bfr,
			bfi.ByteOrder(),
			"Failed to read number of structures from DNA block"
		);
		// n is now the number of types
		// k is the number of structures (= also an not-a-struct indicator)
		_type_structs.resize(n, k);
		// now n is the number of structures
		n = k;

		// prepare the vector
		_structs.resize(n);
		uint16_t ti;
		// and load the structures
		for(i=0; i!=n; ++i)
		{
			_struct_info& si = _structs[i];
			// read the type index
			ti = _read_int<uint16_t>(
				bfr,
				bfi.ByteOrder(),
				"Failed read structure type index from DNA block"
			);
			// store the type index
			si._type_index = ti;
			//
			// read the number of fields in the structure
			k = _read_int<uint16_t>(
				bfr,
				bfi.ByteOrder(),
				"Failed to read number of fields from DNA block"
			);

			// if the type -> structure map already holds
			// some value other than the not-a-struct indicator
			// then throw an exception
			if(_type_structs[ti] != n)
			{
				std::string what("Duplicate definitions of structure '");
				what.append(_type_names[ti]);
				what.append("' in DNA block");
				throw std::runtime_error(what);
			}
			// otherwise map the type to this structure
			_type_structs[ti] = i;

			// prepare the vectors storing the field
			// properties
			si._field_type_indices.resize(k);
			si._field_name_indices.resize(k);
			si._field_elem_counts.resize(k);
			si._field_ptr_flags.resize(k);
			si._field_fn_ptr_flags.resize(k);
			si._field_array_flags.resize(k);

			// and load the individual fields
			for(j=0; j!=k; ++j)
			{
				// first read the index of the type
				// of the field
				si._field_type_indices[j] = _read_int<uint16_t>(
					bfr,
					bfi.ByteOrder(),
					"Failed read field type index from DNA block"
				);
				// and then the index of the 'name' string
				// (the string in sdna::_names containing
				// the definition of the field)
				si._field_name_indices[j] = _read_int<uint16_t>(
					bfr,
					bfi.ByteOrder(),
					"Failed read field name index from DNA block"
				);
				// get the definition string
				const std::string& def = _names[si._field_name_indices[j]];
				// and check if the field is a pointer/array/...
				bool is_ptr = _field_is_ptr(def);
				bool is_fn_ptr = _field_is_fn_ptr(def);
				bool is_array = _field_is_array(def);

				// also get the element count in case of an array
				// and store this info for the j-th field
				// in the appropriate arrays
				si._field_elem_counts[j] = is_array?_field_elem_count(def):1;
				si._field_ptr_flags[j] = is_ptr;
				si._field_fn_ptr_flags[j] = is_fn_ptr;
				si._field_array_flags[j] = is_array;
			}
		}
	}
};


} // imports
} // oglplus

#endif // include guard