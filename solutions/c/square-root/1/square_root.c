#include "square_root.h"

uint16_t square_root(uint16_t nbr){/*Computing square root using heron's method*/

    if(nbr == 1) return 1;
    
    double guess= nbr / 2;
    while(1){/*only assuming for positive whole numbers*/
        double new_guess= 0.5*(guess + nbr/guess);

        if(guess - new_guess < 1) break;

        guess=new_guess;
    }
    return (uint16_t)guess;
}