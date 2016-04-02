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
#include <string.h>

int test_lcm(bool verbose)
{
    // test data
    static const size_t TEST_SIZE = 7;
    
    static const uint64_t test_set1[] = 
    {
        0, 1, 4, 25, 72,  36, 12
    };
        
    static const uint64_t test_set2[] =
    {
        0, 4, 6, 30, 90, 125, 15
    };
        
    static const uint64_t expected[] =
    {
        0, 4, 12, 150, 360, 4500, 60 
    };
       
    // counts errors
    size_t i, errcnt = 0;
    uint64_t result;
    
    for (i = 0; i < TEST_SIZE; ++i)
    {
        result = omnia_lcm(test_set1[i],test_set2[i]);

        if (verbose) 
            printf("lcm(%lu,%lu) = %lu (should be %lu)\n",
                    (unsigned long)test_set1[i],
                    (unsigned long)test_set2[i],
                    (unsigned long)result,
                    (unsigned long)expected[i]);
        
        if (result != expected[i])
            ++errcnt;
    }
    
    // return number of errors
    return errcnt;
}

int test_gcf(bool verbose)
{
    // test data
    static const size_t TEST_SIZE = 6;
    
    static const uint64_t test_set1[] = 
    {
        0, 1, 156, 24, 28, 644
    };
        
    static const uint64_t test_set2[] =
    {
        0, 4, 112, 36, 35, 805
    };
        
    static const uint64_t expected[] =
    {
        0, 1, 4, 12, 7, 161
    };
       
    // counts errors
    size_t i, errcnt = 0;
    uint64_t result;
    
    for (i = 0; i < TEST_SIZE; ++i)
    {
        result = omnia_gcf(test_set1[i],test_set2[i]);

        if (verbose) 
            printf("gcf(%lu,%lu) = %lu (should be %lu)\n",
                    (unsigned long)test_set1[i],
                    (unsigned long)test_set2[i],
                    (unsigned long)result,
                    (unsigned long)expected[i]);
        
        if (result != expected[i])
            ++errcnt;
    }
    
    // return number of errors
    return errcnt;
}

int main(int argc, char * argv[])
{
    bool verbose = false;
    size_t errcnt = 0;
    
    if (argc > 1)
    {
        if (0 == strcmp(argv[1],"-v"))
            verbose = true;
    }
    
    errcnt += test_lcm(verbose);
    errcnt += test_gcf(verbose);
    
    if (verbose)
        fprintf(stderr,"found %d error(s)\n",errcnt);
    
    return errcnt;
}
