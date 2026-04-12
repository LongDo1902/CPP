#include <stdio.h>

class fraction {
  public:
    int num; // Numerator
    int den; // Denominator

    fraction operator*(fraction fract);

    fraction operator+(fraction fract);

    void Simplify();
};