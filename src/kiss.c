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

#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

/*
    An evolution of Marsaglia's KISS xor-based PRNGs.

    The xorshift+ algorithm by Vigna, which passes the BigShift test suite, 
    even when bit-reversed. This is a very fast generator, equidistributed
    in one dimension. Very small memory foot-print. See the 2014 paper:

        http://vigna.di.unimi.it/ftp/papers/xorshiftplus.pdf

    Faster than Kiss 64-bit (35%) and 32-bit (22%). All my new code is based
    on this generator, older KISS code remains as legacy support.
*/

/* The state must be seeded so that it is not everywhere zero. */
static uint64_t s[2];

// Initialize a psuedo-random number generator
void omnia_xs128p_set_seed(const uint64_t seed[2])
{
    s[0] = seed[0];
    s[1] = seed[1];
}

// get next 64-bit unsigned integer in sequence
uint64_t omnia_xs128p_next(void) 
{
    uint64_t x = s[0];
    const uint64_t y = s[1];

    s[0] = y;
    x ^= x << 23;
    s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);

    return s[1] + y;
}

// Get the next integer in the range [lo,hi]
uint64_t omnia_xs128p_range(uint64_t lo, uint64_t hi)
{
    if (hi == lo)
        return hi;

    if (hi < lo)
    {
        uint64_t tt = hi;
        hi = lo;
        lo = tt;
    }

    double range = hi - lo + 1.0;
    return lo + (uint64_t)(floor(range * omnia_xs128p_real()));
}

// Get the next random value as a size_t index
size_t omnia_xs128p_index(const size_t length)
{
    return (size_t)((double)length * omnia_xs128p_real());
}

// Get the next number in the range [0,1)
double omnia_xs128p_real()
{
    // privides a granularity of approx. 2.3E-10
    return (double)((double)omnia_xs128p_next() / 18446744073709551615.0);
}

/*
    The popular "Keep It Simple Stupid" psuedorandom number generator.
    
    This is the 64-bit version suggested by Marsaglia in the following thread:

    http://www.thecodingforums.com/threads/64-bit-kiss-rngs.673657/
*/

static uint64_t x = 1234567890987654321ULL;
static uint64_t c =  123456123456123456ULL;
static uint64_t y =  362436362436362436ULL;
static uint64_t z =    1066149217761810ULL;
static uint64_t t =   29979245822353888ULL;

// Initialize a psuedo-random number generator
void omnia_kiss64_set_seed(const uint64_t seed)
{
    t = seed;
}

// get next 64-bit unsigned integer in sequence
uint64_t omnia_kiss64_next()
{
    t = (t = (x << 58) + c, c = (x >> 6), x += t, c += (x < t), x)
      + (y ^= (y << 13), y ^= (y >> 17), y ^= (y << 43))
      + (z = 6906969069LL * z + 1234567);
      
    return t;
}

// Get the next integer in the range [lo,hi]
uint64_t omnia_kiss64_range(uint64_t lo, uint64_t hi)
{
    if (hi == lo)
        return hi;

    if (hi < lo)
    {
        uint64_t tt = hi;
        hi = lo;
        lo = tt;
    }

    double range = hi - lo + 1.0;
    return lo + (uint64_t)(floor(range * omnia_kiss64_real()));
}

// Get the next random value as a size_t index
size_t omnia_kiss64_index(const size_t length)
{
    return (size_t)((double)length * omnia_kiss64_real());
}

// Get the next number in the range [0,1)
double omnia_kiss64_real()
{
    // privides a granularity of approx. 2.3E-10
    return (double)((double)omnia_kiss64_next() / 18446744073709551615.0);
}

/*
    The popular "Keep It Simple Stupid" psuedorandom number generator.
    It has a period of around 2^125, which is shorter than most other
    algorithms, but certainly adequate for many applications.

    http://groups.google.com/group/comp.soft-sys.math.mathematica/msg/95a94c3b2aa5f077
*/

static const uint64_t A = 698769069ULL;
static const uint32_t K = 1812433253UL;
static uint32_t * m = NULL;

void omnia_kiss32_set_seed(const uint32_t seed)
{
    m = malloc(sizeof(uint32_t) * 4);

    if (m != NULL)
    {
        m[0] = K * (seed ^ (seed >> 30)) + 1;
        m[1] = K * (m[0] ^ (m[0] >> 30)) + 2;
        m[2] = K * (m[1] ^ (m[1] >> 30)) + 3;
        m[3] = K * (m[2] ^ (m[2] >> 30)) + 5;
    }
}

uint32_t omnia_kiss32_next()
{
    uint32_t result = 0;
    uint64_t temp;

    if (m != NULL)
    {
        m[1] = 69069 * m[1] + 12345;
        m[2] ^= ( m[2] << 13);
        m[2] ^= ( m[2] >> 17);
        m[2] ^= ( m[2] <<  5);

        temp = A * m[3] + m[0];
        m[0] = (temp >> 32);

        result = m[1] + m[2] + (m[3] = temp);
    }

    return result;
}

// Get the next integer in the range [lo,hi]
uint32_t omnia_kiss32_range(uint32_t lo, uint32_t hi)
{
    if (hi == lo)
        return hi;

    if (hi < lo)
    {
        uint32_t tt = hi;
        hi = lo;
        lo = tt;
    }

    double range = hi - lo + 1.0;
    return lo + (uint32_t)(floor(range * omnia_kiss32_real()));
}

// Get the next random value as a size_t index
size_t omnia_kiss32_index(const size_t length)
{
    return (size_t)((double)length * omnia_kiss32_real());
}

// Get the next number in the range [0,1)
double omnia_kiss32_real()
{
    // privides a granularity of approx. 2.3E-10
    return (double)((double)omnia_kiss32_next() / 4294967296.0);
}
