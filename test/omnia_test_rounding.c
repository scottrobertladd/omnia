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

#include "../src/omnia.h"

#include <stdio.h>

int main(int argc, char * argv[])
{
    const double pi = 3.14159265358979;
    const double e  = 27182.8182845905;
    const double c  = 299792.4562;

    printf("tonearest(pi)    = %15.8f (should be      3.00000000)\n", omnia_round_nearest(pi));
    printf("tonearest(-pi)   = %15.8f (should be     -3.00000000)\n", omnia_round_nearest(-pi));
    printf("tonearest(e)     = %15.8f (should be  27183.00000000)\n", omnia_round_nearest(e));
    printf("tonearest(-e)    = %15.8f (should be -27183.00000000)\n", omnia_round_nearest(-e));
    printf("tonearest(6.5)   = %15.8f (should be      6.00000000)\n", omnia_round_nearest(6.5));
    printf("tonearest(-6.5)  = %15.8f (should be     -6.00000000)\n", omnia_round_nearest(-6.5));
    printf("tonearest(17.5)  = %15.8f (should be     18.00000000)\n", omnia_round_nearest(17.5));
    printf("tonearest(-17.5) = %15.8f (should be    -18.00000000)\n\n", omnia_round_nearest(-17.5));

    printf("sigdig(pi,5)     = %15.8f (should be      3.14160000)\n", omnia_sigdig(pi,5));
    printf("sigdig(-pi,8)    = %15.8f (should be      3.14159270)\n", omnia_sigdig(-pi,8));
    printf("sigdig(e,5)      = %15.8f (should be  30000.00000000)\n", omnia_sigdig(e,1));
    printf("sigdig(-e,5)     = %15.8f (should be -27180.00000000)\n", omnia_sigdig(-e,4));
    printf("sigdig(c,1)      = %15.8f (should be 300000.00000000)\n", omnia_sigdig(c,1));
    printf("sigdig(c,2)      = %15.8f (should be 300000.00000000)\n", omnia_sigdig(c,2));
    printf("sigdig(c,3)      = %15.8f (should be 300000.00000000)\n", omnia_sigdig(c,3));
    printf("sigdig(c,4)      = %15.8f (should be 299800.00000000)\n", omnia_sigdig(c,4));
    printf("sigdig(c,5)      = %15.8f (should be 299790.00000000)\n", omnia_sigdig(c,5));
    printf("sigdig(c,6)      = %15.8f (should be 299792.00000000)\n", omnia_sigdig(c,6));
    printf("sigdig(c,7)      = %15.8f (should be 299792.50000000)\n", omnia_sigdig(c,7));
    printf("sigdig(c,8)      = %15.8f (should be 299792.46000000)\n", omnia_sigdig(c,8));
    printf("sigdig(c,9)      = %15.8f (should be 299792.45600000)\n", omnia_sigdig(c,9));
    printf("sigdig(c,10)     = %15.8f (should be 299792.45620000)\n", omnia_sigdig(c,10));
    printf("sigdig(6.5,2)    = %15.8f (should be      6.50000000)\n", omnia_sigdig(6.5,2));
    printf("sigdig(-6.5,2)   = %15.8f (should be     -6.50000000)\n", omnia_sigdig(-6.5,2));
    printf("sigdig(17.5,2)   = %15.8f (should be     18.00000000)\n", omnia_sigdig(17.5,2));
    printf("sigdig(-17.5,2)  = %15.8f (should be    -18.00000000)\n", omnia_sigdig(-17.5,2));

    return 0;
}
