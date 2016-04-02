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
    int i;
    double a [] = { 1.0, 1.33333333333333333, 1.5 };

    for (i = 0; i < 3; ++i)
    {
        printf("atanh(tanh(%11.8f)) = %11.8f\n",  a[i], omnia_atanh(tanh(a[i])));
        printf("atanh(tanh(%11.8f)) = %11.8f\n", -a[i], omnia_atanh(tanh(-a[i])));
        printf("asinh(sinh(%11.8f)) = %11.8f\n",  a[i], omnia_asinh(sinh(a[i])));
        printf("asinh(sinh(%11.8f)) = %11.8f\n", -a[i], omnia_asinh(sinh(-a[i])));
        printf("acosh(cosh(%11.8f)) = %11.8f\n",  a[i], omnia_acosh(cosh(a[i])));
        printf("acosh(cosh(%11.8f)) = %11.8f\n", -a[i], omnia_acosh(cosh(-a[i])));
    }

    return 0;
}
