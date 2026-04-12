#include "fraction/fraction.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

ostream &
operator<<(ostream &os, fraction A)
{
    os << "phan so: " << A.num << "/" << A.den;
    return os;
}

int
main()
{
    fraction A = {1, 2};
    fraction B = {2, 3};

    fraction mult_fraction = A * B;
    fraction sum_fraction  = A + B;

    mult_fraction.Simplify();
    sum_fraction.Simplify();

    cout << mult_fraction << endl;
    cout << sum_fraction << endl;

    return 0;
}