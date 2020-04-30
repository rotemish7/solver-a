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

    private:
        double num;


    public:

        RealVariable()
        {
            (*this).num = 1;
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

    private:
        complex<double> x;
    public:

        ComplexVariable()
        {
            (*this).x = 1;
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