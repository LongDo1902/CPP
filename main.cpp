#include <cmath>
#include <complex>
#include <initializer_list>
#include <iostream>
#include <stdio.h>

// ax^2 + bx + c = 0
using namespace std;

class QuadraticSolver {
  private:
    double a, b, c;

  public:
    // Constructor
    QuadraticSolver(double a, double b, double c) : a(a), b(b), c(c) {}

    double
    Get_Discriminant() const
    {
        double D = (b * b) - (4 * a * c);
        return D;
    };

    void
    Quadratic_Solver(double *x1, double *x2)
    {
        // Check NULL
        if (!x1 || !x2)
            return;

        // Check if a == 0 ? It is quadratic : Otherwise not
        if (a == 0.0)
            return;

        double D = QuadraticSolver::Get_Discriminant();

        // Check if D > 0 ? There are two real roots : There is one repeated root
        if (D > 0.0) {
            *x1 = (double)(b + sqrt(D)) / (2.0 * a);
            *x2 = (double)(b - sqrt(D)) / (2.0 * a);
        }

        else if (D == 0.0) {
            *x1 = (double)(-b / (2.0 * a));
            *x2 = *x1;
        }

        else { // Complex root
            double real_part    = -b / (2.0 * a);
            double complex_part = sqrt(-D) / (2.0 * a);

            complex<double> x1 = complex<double>(real_part, complex_part);
            complex<double> x2 = complex<double>(real_part, -complex_part);
        }
    }
};

int
main()
{
    QuadraticSolver solver(1.0, -5.0, 6.0);
    cout << (double)solver.Get_Discriminant();
}