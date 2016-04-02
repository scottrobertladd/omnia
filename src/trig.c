/*
    Omnia is a heterogeous collection of tools written in Standard C.
    
    It is part of the author's Library of Interesting and Esoteric Oddities

    Copyright 2016 Scott Robert Ladd. All rights reserved.

    This is user-supported open source software. Its continued development
    is dependent on financial support from the community. You can provide 
    funding by visiting the author's website at:

        http://www.drakontos.com

    You license the library under the Simplified BSD License (FreeBSD 
    License), the text of which is available at the website above. 
*/

#include "omnia.h"

// hyperbolic arcsine
double omnia_asinh(const double x)
{
    return log(x + sqrt(x * x + 1.0));
}

//  hyperbolic arccosine 
double omnia_acosh(const double x)
{
    return log(x + sqrt(x * x - 1.0));
}

//  hyperbolic arctangent 
double omnia_atanh(const double x)
{
    return log((1.0 + x) / (1.0 - x)) / 2.0;
}
