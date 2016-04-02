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

// Logarithm to a specified base
double omnia_log2base(const double x, const double base)
{
    double result = NAN;
    
    if (x >= 1.0)
        result = log(x) / log(base);
    
    return result;
}

// Smallest power of 2 that includes a given value
int omnia_sizepow2(const int n)
{
    int n2 = 0;
    
    if (n > 0)
    {
        n2 = 1;
        while (true)
        {
            if (n <= n2)
                break;
            else
                n2 <<= 1;
        }
    }
    
    return n2;
}
