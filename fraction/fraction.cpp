#include "fraction.hpp"

fraction
fraction::operator*(fraction fract)
{
    fraction result;

    result.num = num * fract.num;
    result.den = den * fract.den;

    return result;
}

fraction
fraction::operator+(fraction fract)
{
    fraction result;

    if (den == fract.den) {
        result.num = num + fract.num;
        result.den = den;
    }
    else {
        result.num = num * fract.den + fract.num * den;
        result.den = den * fract.den;
    }

    return result;
}

void
fraction::Simplify()
{
    // Find min number in a fraction
    int min = 0;
    if (num < den) {
        min = num;
    }
    else {
        min = den;
    }

    // Find largest common factors
    int gcb = 1;
    for (size_t i = min; i > 1; i--) {
        if ((num % i == 0) && (den % i == 0)) {
            gcb = i;
            break;
        }
    }

    // Start simplifying
    num = num / gcb;
    den = den / gcb;
}