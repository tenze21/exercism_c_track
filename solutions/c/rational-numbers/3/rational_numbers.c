#include "rational_numbers.h"
#include "stdlib.h"
#include "math.h"

static int gcd(unsigned int n1, unsigned int n2){/*euclid's algorithm: get the greatest common divisor.*/
    while(n2!=0){
        int t=n2;
        n2= n1%n2;
        n1=t;
    }
    return n1;
}

rational_t reduce(rational_t r){/*reduce the provided rational number to it's lowest term.*/
    if(r.denominator < 0){
        r.numerator*=-1;
        r.denominator*=-1;
    }
    int sign=(r.numerator<0)? -1 : 1;
    int divisor= gcd(sign * r.numerator, r.denominator);
    return (rational_t){.numerator=r.numerator/divisor, .denominator=r.denominator/divisor};
}

rational_t absolute(rational_t r){
    r=reduce(r);
    if(r.numerator<0)
        r.numerator*=-1;
    return r;
}

rational_t add(rational_t r1, rational_t r2){/*add rational numbers*/
    rational_t sum={.numerator=r1.numerator*r2.denominator + r2.numerator*r1.denominator, .denominator=r1.denominator*r2.denominator};
    return reduce(sum);
}

rational_t subtract(rational_t r1, rational_t r2){/*subtract rational numbers*/
    rational_t diff={.numerator=r1.numerator*r2.denominator - r2.numerator*r1.denominator, .denominator=r1.denominator*r2.denominator};
    return reduce(diff);
}

rational_t multiply(rational_t r1, rational_t r2){/*multiply rational numbers*/
    rational_t prod={.numerator=r1.numerator*r2.numerator, .denominator=r1.denominator*r2.denominator};
    return reduce(prod);
}

rational_t divide(rational_t r1, rational_t r2){/*divide rational numbers*/
    rational_t quotient={.numerator=r1.numerator*r2.denominator, .denominator=r1.denominator*r2.numerator};
    return reduce(quotient);
}

rational_t exp_rational(rational_t r, int16_t exp){/*raise rational numbers to integer power*/
    int numerator=exp<0?(int)pow(r.denominator, abs(exp)) : (int)pow(r.numerator, exp);
    int denominator=exp<0?(int)pow(r.numerator, abs(exp)) : (int)pow(r.denominator, exp);
    return reduce((rational_t){.numerator=numerator, .denominator=denominator});
}

float exp_real(uint16_t base, rational_t r){/*raise real number to rational number*/
    return powf(base, ((float)r.numerator/r.denominator));
}
