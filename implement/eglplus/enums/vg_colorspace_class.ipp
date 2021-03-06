//  File implement/eglplus/enums/vg_colorspace_class.ipp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/eglplus/vg_colorspace.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
namespace enums {
template <typename Base, template<VGColorspace> class Transform>
class EnumToClass<Base, VGColorspace, Transform>
 : public Base
{
private:
	Base& _base() { return *this; }
public:

#if defined EGL_VG_COLORSPACE_sRGB
# if defined sRGB
#  pragma push_macro("sRGB")
#  undef sRGB
	Transform<VGColorspace::sRGB> sRGB;
#  pragma pop_macro("sRGB")
# else
	Transform<VGColorspace::sRGB> sRGB;
# endif
#endif
#if defined EGL_VG_COLORSPACE_LINEAR
# if defined Linear
#  pragma push_macro("Linear")
#  undef Linear
	Transform<VGColorspace::Linear> Linear;
#  pragma pop_macro("Linear")
# else
	Transform<VGColorspace::Linear> Linear;
# endif
#endif

	EnumToClass() { }
	EnumToClass(Base&& base)
	 : Base(std::move(base))
#if defined EGL_VG_COLORSPACE_sRGB
# if defined sRGB
#  pragma push_macro("sRGB")
#  undef sRGB
	 , sRGB(_base())
#  pragma pop_macro("sRGB")
# else
	 , sRGB(_base())
# endif
#endif
#if defined EGL_VG_COLORSPACE_LINEAR
# if defined Linear
#  pragma push_macro("Linear")
#  undef Linear
	 , Linear(_base())
#  pragma pop_macro("Linear")
# else
	 , Linear(_base())
# endif
#endif
	{ }
};

} // namespace enums

