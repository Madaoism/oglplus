/*
 *  Copyright 2014-2019 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

//[oglplus_texture_swizzle_tuple

#if GL_VERSION_3_3 || GL_ARB_texture_swizzle
class TextureSwizzleTuple {
public:
    TextureSwizzleTuple(); /*<
    No swizzling.
    >*/

    TextureSwizzleTuple(
      __TextureSwizzle mode_r,
      __TextureSwizzle mode_g,
      __TextureSwizzle mode_b,
      __TextureSwizzle
        mode_a); /*<
              Specifies modes for all texture components/coordinates.
              >*/

    TextureSwizzleTuple& SwizzleR(__TextureSwizzle mode); /*<
    Sets the swizzle value for the red component.
    >*/
    TextureSwizzleTuple& Red(__TextureSwizzle mode);
    __TextureSwizzle SwizzleR() const; /*<
    Returns the swizzle value for the red component.
    >*/
    __TextureSwizzle Red() const;

    TextureSwizzleTuple& SwizzleG(__TextureSwizzle mode); /*<
    Sets the swizzle value for the green component.
    >*/
    TextureSwizzleTuple& Green(__TextureSwizzle mode);
    __TextureSwizzle SwizzleG() const; /*<
    Returns the swizzle value for the green component.
    >*/
    __TextureSwizzle Green() const;

    TextureSwizzleTuple& SwizzleB(__TextureSwizzle mode); /*<
    Sets the swizzle value for the blue component.
    >*/
    TextureSwizzleTuple& Blue(__TextureSwizzle mode);
    __TextureSwizzle SwizzleB() const; /*<
    Returns the swizzle value for the blue component.
    >*/
    __TextureSwizzle Blue() const;

    TextureSwizzleTuple& SwizzleA(__TextureSwizzle mode); /*<
    Sets the swizzle value for the alpha component.
    >*/
    TextureSwizzleTuple& Alpha(__TextureSwizzle mode);
    __TextureSwizzle SwizzleA() const; /*<
    Returns the swizzle value for the alpha component.
    >*/
    __TextureSwizzle Alpha() const;

    TextureSwizzleTuple& Swizzle(
      __TextureSwizzleCoord coordinate,
      __TextureSwizzle
        mode);                                                        /*<
                                                                   Sets the swizzle [^mode] for the specified [^coordinate].
                                                                   >*/
    __TextureSwizzle Swizzle(__TextureSwizzleCoord coordinate) const; /*<
    Returns the swizzle mode for the specified [^coordinate].
    >*/
};
#endif

//]
