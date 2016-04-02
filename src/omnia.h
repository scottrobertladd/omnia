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

#if !defined(LIBOMNIA_MATHTOOLS_H)
#define LIBOMNIA_MATHTOOLS_H

#include <stddef.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Psuedo-random number generator -- xorshift+ 64 bits
//-----------------------------------------------------------------------------

//! Initialize a psuedo-random number generator (PRNG)
/*!
    Initializes a psuedo-random number generator using a specified seed.
    \param seed Initialization seed
*/
void omnia_xs128p_set_seed(const uint64_t seed[2]);

//!  Get the next integer
/*!
    Returns the next uint64_t in sequence.
    \return A pseudorandom uint64_t value
*/
uint64_t omnia_xs128p_next();

//! Get the next integer in the range [lo,hi]
/*!
    Returns the next int_value between lo and hi, inclusive.
    \param lo - Minimum value of result
    \param hi - Maximum value of result
    \return A pseudorandom uint64_t value
*/
uint64_t omnia_xs128p_range(const uint64_t lo, const uint64_t hi);

//! Get the next random value as a size_t index
/*!
    Returns the next value as a size_t "index" in the range [0,length).
    \param length - Maximum value of result
    \return A pseudorandom size_t value
*/
size_t omnia_xs128p_index(const size_t length);

//! Get the next number in the range [0,1)
/*!
    Returns the next real number in the range [0,1], i.e., a number
    greater than or equal to 0 and less than or equal to 1.
    Provides 64-bit precision.
    \return A pseudorandom double value
*/
double omnia_xs128p_real();

//-----------------------------------------------------------------------------
// Psuedo-random number generator -- Kiss 64 bits
//-----------------------------------------------------------------------------

//! Initialize a psuedo-random number generator (PRNG)
/*!
    Initializes a psuedo-random number generator using a specified seed.
    \param seed Initialization seed
*/
void omnia_kiss64_set_seed(const uint64_t seed);

//!  Get the next integer
/*!
    Returns the next uint64_t in sequence.
    \return A pseudorandom uint64_t value
*/
uint64_t omnia_kiss64_next();

//! Get the next integer in the range [lo,hi]
/*!
    Returns the next int_value between lo and hi, inclusive.
    \param lo - Minimum value of result
    \param hi - Maximum value of result
    \return A pseudorandom uint64_t value
*/
uint64_t omnia_kiss64_range(const uint64_t lo, const uint64_t hi);

//! Get the next random value as a size_t index
/*!
    Returns the next value as a size_t "index" in the range [0,length).
    \param length - Maximum value of result
    \return A pseudorandom size_t value
*/
size_t omnia_kiss64_index(const size_t length);

//! Get the next number in the range [0,1)
/*!
    Returns the next real number in the range [0,1], i.e., a number
    greater than or equal to 0 and less than or equal to 1.
    Provides 64-bit precision.
    \return A pseudorandom double value
*/
double omnia_kiss64_real();

//-----------------------------------------------------------------------------
// Psuedo-random number generator -- 32 bits
//-----------------------------------------------------------------------------

//! Initialize a psuedo-random number generator (PRNG)
/*!
    Initializes a psuedo-random number generator using a specified seed.
    \param seed Initialization seed
*/
void omnia_kiss32_set_seed(const uint32_t seed);

//!  Get the next integer
/*!
    Returns the next uint32_t in sequence.
    \return A pseudorandom uint32_t value
*/
uint32_t omnia_kiss32_next();

//! Get the next integer in the range [lo,hi]
/*!
    Returns the next int_value between lo and hi, inclusive.
    \param lo - Minimum value of result
    \param hi - Maximum value of result
    \return A pseudorandom uint32_t value
*/
uint32_t omnia_kiss32_range(const uint32_t lo, const uint32_t hi);

//! Get the next random value as a size_t index
/*!
    Returns the next value as a size_t "index" in the range [0,length).
    \param length - Maximum value of result
    \return A pseudorandom size_t value
*/
size_t omnia_kiss32_index(const size_t length);

//! Get the next number in the range [0,1)
/*!
    Returns the next real number in the range [0,1], i.e., a number
    greater than or equal to 0 and less than or equal to 1.
    Provides 32-bit precision.
    \return A pseudorandom double value
*/
double omnia_kiss32_real();

//-----------------------------------------------------------------------------
// Rounding
//-----------------------------------------------------------------------------

//! Round to nearest value
/*!
    Rounds a value to nearest integer, rounding to even for exact fractions of 0.5.
*/
double omnia_round_nearest(const double x);

// Set number of significant digits in a floating-point value
/*!
    Returns the given value rounded for the number of specified decimal
    digits of precision.
    \param x - Original value to be rounded
    \param n - Number of significant digits
    \return The value <i>x</i> rounded to <i>n</i> digits of precision
*/
double omnia_sigdig(const double x, const uint16_t n);

//-----------------------------------------------------------------------------
// Lowest Common Multple (LCM) and Lowest Common Denominator (GCD)
//-----------------------------------------------------------------------------

// Lowest common multiple
/*!
    Calculates the lowest common multiple for two values.
    \param x first value
    \param y second value
    \return The lowest common multiple for <i>x</i> and <i>y</i>
*/
uint64_t omnia_lcm(const uint64_t x, const uint64_t y);

// Greatest common factor (denominator)
/*!
    Calculates the greatest common factor for two values.
    \param x first value
    \param y second value
    \return The greatest common factor for <i>x</i> and <i>y</i>
*/
uint64_t omnia_gcf(uint64_t x, uint64_t y);

//-----------------------------------------------------------------------------
// Logarithms
//-----------------------------------------------------------------------------

// Logarithm to a specified base
/*!
    Calculates the base-n logarithm for a given value. If a range
    error occurs, the return value equals NaN.
    \param x value for which logarithm is required
    \param base lagarithm base
    \return logarithm of <i>x</i> to base <i>base</i>; NAN on range error
*/
double omnia_log2base(const double x, const double base);

// Smallest power of 2 that includes a given value
/*!
    Returns the smallest power of 2 that includes n in its range
    \param n number that must be less than the result
    \return the lowest power of 2 that is greater than <i>n</i>, or
*/
int omnia_sizepow2(const int n);

//-----------------------------------------------------------------------------
// Statistical functions
//-----------------------------------------------------------------------------

// Moving average
/*!
    Computes the moving average for an array. The returned buffer
    must be freed by the calling code.
    \param data array of double values to be averaged
    \param n number of elements in data
    \param distance number elements to average before and after an element in <i>data</i>
    \return an allocated <i>n</i>-length array containing the moving average of corresponding elements in <i>data</i>
*/
double * omnia_moving_average(const double * data, const int n, const int distance);

//! index of average in array returned from omnia_basic_stats
#define OMNI_STAT_AVG 0;

//! index of variance in array returned from omnia_basic_stats
#define OMNI_STAT_VAR 1;

//! index of standard deviation in array returned from omnia_basic_stats
#define OMNI_STAT_DEV 2;

// Moving average
/*!
    Computes basic statistics for an array. The returned buffer
    must be freed by the calling code.
    \param a array of double values to be analyzed
    \param n number of elements in data
    \return an allocated 3-element array containing the average, variance, and standard deviation of the elements in <i>a</i>
*/
double * omnia_basic_stats(const double * a, size_t n);

//-----------------------------------------------------------------------------
// Sine Wave Generation
//-----------------------------------------------------------------------------

/*!
     Defines the characteristics of a sine wave.
*/
typedef struct
{
    double wavelength;  //! wavelength
    double amplitude;   //! arbitrary wave amplitude (units implied by user)
}
omnia_wave_factor_t;

// Sine wave based artificial signal generator.
/*!
    Generates an array of doubles by combining sine waves. The primary
    purpose is to produce an artificial signal with known properties,
    for testing signal analysis applications. The caller is responsible
    for freeing the memory used by the array returned by this function.
    \param factors defines properties of the sine waves to be combined
    \param factor_n number of elements in factors
    \param array_n number of elements in the output array
    \return an allocated array containg values generated from the given factors
*/
double * omnia_make_sinusoid(const omnia_wave_factor_t * factors, const size_t factor_n, const size_t array_n);

// Apply noise to a signal
/*!
    Adds a percentage of noise to a signal. If "noise" is set to 0.1 (for example)
    each value will be adjust to between 90% and 110% of its original value. This
    function changes the existing values in the array.
    \param a array containing signal data
    \param n number of samples in signal
    \param noise percentage of noise
*/
void omnia_add_noise(double * a, const size_t n, double noise);

//-----------------------------------------------------------------------------
// Trigonometry
//-----------------------------------------------------------------------------
//! Hyperbolic arcsine
/*!
    Calculates sinh<sup>-1</sup>.
    \param x a value
    \return inverse hyperbolic sine of <i>x</i>
*/
double omnia_asinh(const double x);

//! Hyperbolic arccosine
/*!
    Calculates cosh<sup>-1</sup>.
    \param x a value
    \return inverse hyperbolic cosine of <i>x</i>
*/
double omnia_acosh(const double x);

//! Hyperbolic arctangent
/*!
    Calculates tanh<sup>-1</sup>.
    \param x a value
    \return inverse hyperbolic tangent of <i>x</i>
*/
double omnia_atanh(const double x);

//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------

// mathematical constants
//! e (natural logarithm base
#define OMNIA_E               2.71828182845904523536028747135

//! log_2 (e)
#define OMNIA_LOG2_E          1.44269504088896340735992468100

//! log_10 (e)
#define OMNIA_LOG10_E         0.43429448190325182765112891892

//! sqrt(2)
#define OMNIA_SQRT_2          1.41421356237309504880168872421

//! sqrt(1/2)
#define OMNIA_SQRT_HALF       0.70710678118654752440084436210

//! sqrt(3)
#define OMNIA_SQRT_3          1.73205080756887729352744634151

//! pi  (180 deg)
#define OMNIA_PI              3.14159265358979323846264338328

//! pi/2 (90 deg)
#define OMNIA_PI_DIV_2        1.57079632679489661923132169164

//! pi/3 (60 deg)
#define OMNIA_PI_DIV_3        1.04719755119659774615421446109

//! pi/4 (45 deg)
#define OMNIA_PI_DIV_4        0.78539816339744830961566084582

//! pi/6 (30 deg)
#define OMNIA_PI_DIV_6        0.52359877559829887307710723055

//! pi/9 (20 deg)
#define OMNIA_PI_DIV_9        0.34906585039886591538473815370

//! pi / 12 (15 deg)
#define OMNIA_PI_DIV_12       0.26179938779914943653855361527

//! pi / 18 (10 deg)
#define OMNIA_PI_DIV_18       0.17453292519943295769236907685

//! pi / 36 (5 deg)
#define OMNIA_PI_DIV_36       0.08726646259971647884618453842

//! degrees per radian
#define OMNIA_DEG_PER_RAD     57.2957795130823208767981548141

//! radians per degree
#define OMNIA_RAD_PER_DEG     0.01745329251994329576923690768

//! sqrt(pi)
#define OMNIA_SQRT_PI         1.77245385090551602729816748334

//! 2/sqrt(pi)
#define OMNIA_TWO_DIV_SQRT_PI 1.12837916709551257389615890312

//! 1/pi
#define OMNIA_ONE_DIV_PI      0.31830988618379067153776752675

//! 2/pi
#define OMNIA_TWO_DIV_PI      0.63661977236758134307553505349

//! ln(10)
#define OMNIA_LN_10           2.30258509299404568401799145468

//! ln(2)
#define OMNIA_LN_2            0.69314718055994530941723212146

//! log(2)
#define OMNIA_LOG_2           0.30102999566398119521373889472

//! ln(pi)
#define OMNIA_LN_PI           1.14472988584940017414342735135

//! Euler constant
#define OMNIA_EULER           0.57721566490153286060651209008

#if defined(__cplusplus)
}
#endif

#endif
