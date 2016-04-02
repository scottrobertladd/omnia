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
#include <string.h>
#include <time.h>
#include <stdint.h>

double * omnia_make_sinusoid(const omnia_wave_factor_t * factors, const size_t factor_n, const size_t array_n)
{
    double * result = NULL;

    if ((array_n > 0) && (factor_n > 0) && (factors != NULL))
    {
        result = (double *)malloc(sizeof(double) * array_n);

        if (result != NULL)
        {
            double * f = (double *)malloc(sizeof(double) * factor_n);
            double * a = (double *)malloc(sizeof(double) * factor_n);

            for (int n = 0; n < factor_n; ++n)
            {
                f[n] = OMNIA_PI / factors[n].wavelength;
                a[n] = 0.0;
            }

            for (size_t i = 0; i < array_n; ++i)
            {
                for (size_t n = 0; n < factor_n; ++n)
                {
                    result[i] += sin(a[n]) * factors[n].amplitude;
                    a[n] += f[n];
                }
            }
        }
    }

    return result;
}

void omnia_add_noise(double * a, const size_t n, double noise)
{
    if ((n > 0) && (a != NULL) && (noise > 0.0))
    {
        omnia_kiss64_set_seed((uint64_t)time(NULL));

        for (int i = 0; i < n; ++i)
        {
            double x = omnia_kiss64_real() * noise;

            if (1 == omnia_kiss64_next() % 2)
                a[i] += x;
            else
                a[i] -= x;
        }
    }
}
