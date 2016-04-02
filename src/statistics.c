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
#include <math.h>
#include <stdlib.h>

// Moving average
double * omnia_moving_average(const double * data, const int n, const int distance)
{
    double * result = (double *)malloc(sizeof(double) * n);

    int m = n - distance;

    for (int i = 0; i < n; ++i)
    {
        double count = 0.0;

        for (int x = i - distance; x <= i + distance; ++x)
        {
            if ((x >= 0) && (x <= m))
            {
                result[i] += data[x];
                count += 1.0;
            }
        }

        result[i] /= count;
    }

    return result;
}

double * omnia_basic_stats(const double * a, size_t n)
{
    int i;
    double sum1 = 0.0, sum2 = 0.0;

    double * result = malloc(sizeof(double) * 3);

    for (i = 0; i < n; ++i)
        sum1 += a[i];

    result[0] = sum1 / (double)n;

    for (i = 0; i < n; ++i)
        sum2 = sum2 + pow(a[i] - result[0], 2);

    result[1] = sum2 / (double)n;
    result[2] = sqrt(result[1]);

    return result;
}