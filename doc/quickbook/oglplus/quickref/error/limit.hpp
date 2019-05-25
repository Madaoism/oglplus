/*
 *  Copyright 2014-2019 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

//[oglplus_error_LimitError

class LimitError : public __Error {
public:
    LimitError(const char* message);

    GLfloat Value() const; /*<
    Returns the value, which triggered the error.
    >*/
    GLfloat Limit() const; /*<
    Returns the limit value, which has been exceeded.
    >*/
};

//]
