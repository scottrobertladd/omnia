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

// lowest common denominator
uint64_t omnia_lcm(const uint64_t x, const uint64_t y)
{
    uint64_t result = 0;

    if (x == y)
        result = x;
    else
        if (x < y)
            result = (y / omnia_gcf(x,y)) * x;
        else
            result = (x / omnia_gcf(y,x)) * y;

    return result;
}

// greatest common multiple
uint64_t omnia_gcf(uint64_t x, uint64_t y)
{
    uint64_t temp;

    while (y != 0)
    {
        temp = x % y;
        x = y;
        y = temp;
    }

    return x;
}
