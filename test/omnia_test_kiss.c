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
#include <time.h>
#include <locale.h>

static const size_t TEST_SIZE = 1010000000;
static const size_t NUM_BUCKETS = 101;

double test_xs128p()
{
    double total;
    size_t i;
    double n, l, s;
    double counts[NUM_BUCKETS];

    struct timespec start, stop;

    printf("\n>>>> xorshift+ <<<<\n");

    s = 1.1;
    l = -0.1;

    uint64_t seed[2];
    seed[0] = (uint64_t)time(NULL) << 32 | (uint64_t)time(NULL);
    seed[1] = (uint64_t)time(NULL) << 32 | (uint64_t)time(NULL);

    omnia_xs128p_set_seed(seed);

    for (i = 0; i < TEST_SIZE; ++i)
    {
        n = omnia_xs128p_real();

        if (n < s) s = n;
        if (n > l) l = n;
    }

    printf("    largest = %15.14f\n   smallest = %15.14f\n", l, s);
    
    //  check ranges
    for (i = 0; i < NUM_BUCKETS; ++i)
        counts[i] = 0.0;

    for (i = 0; i < TEST_SIZE; ++i)
        ++counts[omnia_xs128p_index(NUM_BUCKETS)];

    printf("\n");

    total = 0;

    for (i = 0; i < NUM_BUCKETS; ++i)
    {
        printf("counts %3d  = %'10.0f\n", i + 1, counts[i]);
        total += counts[i];
    }

    printf("      total = %'10.0f\n", total);

    double * stats = omnia_basic_stats(counts, NUM_BUCKETS);

    printf("    average = %10.0f\n", stats[0]);
    printf("   std. dev = %10.0f (%8.4f%%)\n", stats[2], stats[2] / stats[1] * 100.0);

    // get starting time
    clock_gettime(CLOCK_REALTIME,&start);

    // test generation speed
    for (i = 0; i < TEST_SIZE; ++i)
        omnia_xs128p_next();

    // calculate run time
    clock_gettime(CLOCK_REALTIME,&stop);

    // done
    return ((stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)TEST_SIZE);
}

double test_kiss32()
{
    double total;
    size_t i;
    double n, l, s;
    double counts[NUM_BUCKETS];

    struct timespec start, stop;

    printf("\n>>>> 32 bit KISS <<<<\n");

    s = 1.1;
    l = -0.1;

    omnia_kiss32_set_seed((uint32_t)time(NULL));

    for (i = 0; i < TEST_SIZE; ++i)
    {
        n = omnia_kiss32_real();

        if (n < s) s = n;
        if (n > l) l = n;
    }

    printf("    largest = %15.14f\n   smallest = %15.14f\n", l, s);
    
    //  check ranges
    for (i = 0; i < NUM_BUCKETS; ++i)
        counts[i] = 0.0;

    for (i = 0; i < TEST_SIZE; ++i)
        ++counts[omnia_kiss32_index(NUM_BUCKETS)];

    printf("\n");

    total = 0;

    for (i = 0; i < NUM_BUCKETS; ++i)
    {
        printf("counts %3d  = %'10.0f\n", i + 1, counts[i]);
        total += counts[i];
    }

    printf("      total = %'10.0f\n", total);

    double * stats = omnia_basic_stats(counts, NUM_BUCKETS);

    printf("    average = %10.0f\n", stats[0]);
    printf("   std. dev = %10.0f (%8.4f%%)\n", stats[2], stats[2] / stats[1] * 100.0);

    // get starting time
    clock_gettime(CLOCK_REALTIME,&start);

    // test generation speed
    for (i = 0; i < TEST_SIZE; ++i)
        omnia_kiss32_next();

    // calculate run time
    clock_gettime(CLOCK_REALTIME,&stop);

    // done
    return ((stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)TEST_SIZE);
}

double test_kiss64()
{
    double total;
    size_t i;
    double n, l, s;
    double counts[NUM_BUCKETS];

    struct timespec start, stop;

    printf("\n>>>> 64-bit KISS <<<<\n");

    s = 1.1;
    l = -0.1;

    omnia_kiss64_set_seed((uint64_t)time(NULL));

    for (i = 0; i < TEST_SIZE; ++i)
    {
        n = omnia_kiss64_real();

        if (n < s) s = n;
        if (n > l) l = n;
    }

    printf("    largest = %15.14f\n   smallest = %15.14f\n", l, s);
    
    //  check ranges
    for (i = 0; i < NUM_BUCKETS; ++i)
        counts[i] = 0;

    for (i = 0; i < TEST_SIZE; ++i)
        ++counts[omnia_kiss64_index(NUM_BUCKETS)];

    printf("\n");

    total = 0;

    for (i = 0; i < NUM_BUCKETS; ++i)
    {
        printf("counts %3d  = %10.0f\n", i + 1, counts[i]);
        total += counts[i];
    }

    printf("      total = %10.0f\n", total);

    double * stats = omnia_basic_stats(counts, NUM_BUCKETS);

    printf("    average = %10.0f\n", stats[0]);
    printf("   std. dev = %10.0f (%8.4f%%)\n", stats[2], stats[2] / stats[1] * 100.0);

    // get starting time
    clock_gettime(CLOCK_REALTIME,&start);

    // test generation speed
    for (i = 0; i < TEST_SIZE; ++i)
        omnia_kiss64_next();

    // calculate run time
    clock_gettime(CLOCK_REALTIME,&stop);

    // done
    return ((stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)TEST_SIZE);
}

int main()
{
    double kiss32_time = test_kiss32();
    double kiss64_time = test_kiss64();
    double xs128p_time = test_xs128p();

    setlocale(LC_NUMERIC, "");

    printf("\nALGORITHM TIMING (random numbers / second)\n\n");
    printf("            KISS32 = %'d/sec\n",    (long)(TEST_SIZE / kiss32_time));
    printf("            KISS64 = %'d/sec\n\n",  (long)(TEST_SIZE / kiss64_time));
    printf("            XS128P = %'d/sec\n\n",  (long)(TEST_SIZE / xs128p_time));

    return 0;
}

