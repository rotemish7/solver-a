//
// Created by rotem levy on 29/04/2020.
//

#ifndef SOLVER_SOLVER_HPP
#define SOLVER_SOLVER_HPP


#include <iostream>
#include <complex>

using namespace std;

namespace solver
{
    class RealVariable
    {
        double a;
        double b;
        double c;


    public:

        RealVariable(double a,double b,double c)
        {
            (*this).a = a;
            (*this).b = b;
            (*this).c = c;
        }

        const double & getA() const
        {
            return a;
        }

        const double & getB() const
        {
            return b;
        }

        const double & getC() const
        {
            return c;
        }

        friend RealVariable operator+(const int, const RealVariable);
        friend RealVariable operator+(const RealVariable, const int);
        friend RealVariable operator+(const RealVariable, const double);
        friend RealVariable operator+(const double, const RealVariable);
        friend RealVariable operator+(const RealVariable, const RealVariable);

        friend RealVariable operator-(const int, const RealVariable);
        friend RealVariable operator-(const RealVariable, const int);
        friend RealVariable operator-(const RealVariable, const double);
        friend RealVariable operator-(const double, const RealVariable);
        friend RealVariable operator-(const RealVariable, const RealVariable);

        friend RealVariable operator*(const int, const RealVariable);
        friend RealVariable operator*(const double, const RealVariable);
        friend RealVariable operator*(const RealVariable, const int);
        friend RealVariable operator*(const RealVariable, const double);

        friend RealVariable operator/(const RealVariable, const double);
        friend RealVariable operator/(const RealVariable, const int);
        friend RealVariable operator/(const RealVariable, const RealVariable);

        friend RealVariable operator^(const RealVariable, const int);
        friend RealVariable operator^(const int, const RealVariable);

        friend RealVariable operator==(const RealVariable, const int);
        friend RealVariable operator==(const int, const RealVariable);
        friend RealVariable operator==(const RealVariable, const double);
        friend RealVariable operator==(const double, const RealVariable);
        friend RealVariable operator==(const RealVariable, const RealVariable);

    };

    class ComplexVariable
    {
        complex<double> a;
        complex<double> b;
        complex<double> c;

    public:

        ComplexVariable(): a(0), b(1,0), c(0) {}

        ComplexVariable(complex<double> a, complex<double> b, complex<double> c)
        {
            (*this).a = complex(a);
            (*this).b = complex(b);
            (*this).c = complex(c);
        }

        const complex<double> & getA() const
        {
            return a;
        }
        const complex<double> & getB() const
        {
            return b;
        }
        const complex<double> & getC() const
        {
            return c;
        }

        friend ComplexVariable operator*(const int, const ComplexVariable);
        friend ComplexVariable operator*(const complex<double>, const ComplexVariable);

        friend ComplexVariable operator-(const ComplexVariable, const int);
        friend ComplexVariable operator-(const int, const ComplexVariable);
        friend ComplexVariable operator-(const complex<double>, const ComplexVariable);
        friend ComplexVariable operator-(const ComplexVariable, const ComplexVariable);
        friend ComplexVariable operator-(const ComplexVariable, const complex<double>);
        friend complex<double> operator-(const int, const complex<double>);

        friend ComplexVariable operator+(const int, const ComplexVariable);
        friend ComplexVariable operator+(const ComplexVariable, const int);
        friend ComplexVariable operator+(const ComplexVariable, const ComplexVariable);
        friend ComplexVariable operator+(const ComplexVariable, const complex<double>);
        friend ComplexVariable operator+(const complex<double>, const ComplexVariable);
        friend complex<double> operator+(const int, const complex<double>);

        friend ComplexVariable operator^(const ComplexVariable, const int);

        friend ComplexVariable operator==(const ComplexVariable, const int);
        friend ComplexVariable operator==(const int, const ComplexVariable);
        friend ComplexVariable operator==(const ComplexVariable, const ComplexVariable);
        friend ComplexVariable operator==(const ComplexVariable, const complex<double>);
        friend ComplexVariable operator==(const complex<double>, const ComplexVariable);

        friend ComplexVariable operator/(const ComplexVariable, const int);
        friend ComplexVariable operator/(const ComplexVariable, const complex<double>);
    };

    double solve(const RealVariable&);
    complex<double> solve(const ComplexVariable&);

};

#endif //SOLVER_SOLVER_HPP