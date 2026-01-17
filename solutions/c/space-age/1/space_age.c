#include "space_age.h"

 /*OP -> orbital period*/
 /*The orbital period of planets in earth years*/
#define MERCURY_OP 0.2408467 
#define VENUS_OP 0.61519726 
#define EARTH_OP 1.0
#define MARS_OP 1.8808158
#define JUPITER_OP 11.862615
#define SATURN_OP 29.447498
#define URANUS_OP 84.016846
#define NEPTUNE_OP 164.79132
#define EARTH_YEAR 365.25

float planet_years_to_seconds(float orbital_period){/*get the orbital period in seconds*/
    return EARTH_YEAR * orbital_period * 24 * 60 * 60;
}

float age(planet_t planet, int64_t seconds){/*get seconds in */
    switch (planet)
    {
    case MERCURY:
        return seconds / planet_years_to_seconds(MERCURY_OP);
        break;
    case VENUS:
        return seconds / planet_years_to_seconds(VENUS_OP);
        break; 
    case EARTH:
        return seconds / planet_years_to_seconds(EARTH_OP);
        break;
    case MARS:
        return seconds / planet_years_to_seconds(MARS_OP);
        break;
    case JUPITER:
        return seconds / planet_years_to_seconds(JUPITER_OP);
        break;
    case SATURN:
        return seconds / planet_years_to_seconds(SATURN_OP);
        break;
    case URANUS:
        return seconds / planet_years_to_seconds(URANUS_OP);
        break;
    case NEPTUNE:
        return seconds / planet_years_to_seconds(NEPTUNE_OP);
        break;
    default:
        return -1.0;
        break;
    }
}