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

//  Rounds a value to nearest integer, rounding to even for exact fractions of 0.5.
double omnia_round_nearest(const double x)
{
    double result, fraction, dummy;

    fraction = fabs(modf(x,&result));

    if (fraction == 0.0)
        return result;

    if (fraction == 0.5)
    {
        if (modf(result / 2.0, &dummy) != 0.0)
        {
            if (x < 0.0)
                result -= 1.0;
            else
                result += 1.0;
        }
    }
    else
    {
        if (fraction > 0.5)
        {
            if (x < 0.0)
                result -= 1.0;
            else
                result += 1.0;
        }
    }

    return result;
}

//  Returns the given value rounded for the number of specified decimal digits of precision.
double omnia_sigdig(const double x, const uint16_t n)
{
    double scale_factor, result;

    // is asking for no digits, or more digits than in double, simply return x
    if ((n == 0) || (n > DBL_DIG))
        result = x;
    else
    {
        // find a factor of ten such that all significant digits will
        //    be in the integer part of the double
        scale_factor = pow(10.0,(double)((int)n - 1 - (int)floor(log10(fabs(x)))));

        // scale up, round, and scale down
        result = omnia_round_nearest(x * scale_factor) / scale_factor;
    }

    return result;
}
