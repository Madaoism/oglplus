//  File doc/quickbook/oglplus/quickref/enums/conditional_render_mode_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/conditional_render_mode.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_conditional_render_mode_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template <__ConditionalRenderMode> class Transform>
class __EnumToClass<Base, __ConditionalRenderMode, Transform> /*<
Specialization of __EnumToClass for the __ConditionalRenderMode enumeration.
>*/
  : public Base {
public:
    EnumToClass();
    EnumToClass(Base&& base);

    Transform<ConditionalRenderMode::QueryWait> QueryWait;
    Transform<ConditionalRenderMode::QueryNoWait> QueryNoWait;
    Transform<ConditionalRenderMode::QueryByRegionWait> QueryByRegionWait;
    Transform<ConditionalRenderMode::QueryByRegionNoWait> QueryByRegionNoWait;
    Transform<ConditionalRenderMode::QueryWaitInverted> QueryWaitInverted;
    Transform<ConditionalRenderMode::QueryNoWaitInverted> QueryNoWaitInverted;
    Transform<ConditionalRenderMode::QueryByRegionWaitInverted>
      QueryByRegionWaitInverted;
    Transform<ConditionalRenderMode::QueryByRegionNoWaitInverted>
      QueryByRegionNoWaitInverted;
};

} // namespace enums
#endif
//]
