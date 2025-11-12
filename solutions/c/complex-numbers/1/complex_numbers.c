#include "complex_numbers.h"
#include "math.h"

complex_t c_add(complex_t a, complex_t b)
{
   return (complex_t){.real= a.real + b.real, .imag=a.imag + b.imag}; // (a+c) + (b+d)i 
}

complex_t c_sub(complex_t a, complex_t b)
{
   return (complex_t){.real=a.real - b.real, .imag= a.imag - b.imag}; // (a-c) + (b-d)i
}

complex_t c_mul(complex_t a, complex_t b)
{
   return (complex_t){.real= ((a.real * b.real) - (a.imag * b.imag)), .imag=((a.real * b.imag) + (a.imag * b.real))}; // (ac - bd) + (ad + bc)i
}

complex_t c_div(complex_t a, complex_t b)
{
   return (complex_t){.real= ((a.real * b.real) + (a.imag * b.imag)) / (b.real*b.real + b.imag*b.imag), .imag=((a.imag * b.real) - (a.real * b.imag)) / (b.real*b.real + b.imag*b.imag)}; // (ac + bd)/(c^2 + d^2) + (bc - ad)/(c^2 + d^2)
}

double c_abs(complex_t x)
{
   return sqrt(pow(x.real, 2.0) + pow(x.imag, 2.0)); // sqrt(a^2 + b^2)
}

complex_t c_conjugate(complex_t x)
{
   return (complex_t){.real=x.real, .imag=-x.imag};
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   return (complex_t){.real= exp(x.real) * cos(x.imag), .imag= exp(x.real) * sin(x.imag)}; // e^a * cos(b) + e^a * sin(b)i
}