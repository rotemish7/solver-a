//
// Created by rotem levy on 29/04/2020.
//


#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;

namespace solver
{
    //// solver ////

    /**
     *
     * @param num
     * @return
     */
    double solve(const RealVariable& num)
    {
        return 7;
    }

    /**
     *
     * @param num
     * @return
     */
    complex<double> solve(const ComplexVariable& num)
    {
        return 4;
    }

    //// RealVariable ////

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator*(const int num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator*(const double num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator*(const RealVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator*(const RealVariable num1, const double num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator-(const int num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator-(const RealVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator-(const RealVariable num1, const double num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator-(const double num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator-(const RealVariable num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator+(const int num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator+(const RealVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator+(const RealVariable num1, const double num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator+(const double num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator+(const RealVariable num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator^(const RealVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator^(const int num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator==(const RealVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator==(const int num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator==(const RealVariable num1, const double num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator==(const double num1, const RealVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator==(const RealVariable num1, const RealVariable num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator/(const RealVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator/(const RealVariable num1, const double num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    RealVariable operator/(const RealVariable num1, const RealVariable num2)
    {
        return num1;
    }

    //// ComplexVariable ////

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator*(const int num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator*(const complex<double> num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator-(const ComplexVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator-(const ComplexVariable num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator-(const ComplexVariable num1, const complex<double> num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    complex<double> operator-(const int num1, const complex<double> num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator-(const complex<double> num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator-(const int num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator+(const int num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator+(const ComplexVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator+(const ComplexVariable num1, const ComplexVariable num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator+(const ComplexVariable num1, const complex<double> num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator+(const complex<double> num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    complex<double> operator+(const int num1, const complex<double> num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator^(const ComplexVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator==(const int num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator==(const ComplexVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator==(const ComplexVariable num1, const ComplexVariable num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator==(const complex<double> num1, const ComplexVariable num2)
    {
        return num2;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator==(const ComplexVariable num1, const complex<double> num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator/(const ComplexVariable num1, const int num2)
    {
        return num1;
    }

    /**
     *
     * @param num1
     * @param num2
     * @return
     */
    ComplexVariable operator/(const ComplexVariable num1, const complex<double> num2)
    {
        return num1;
    }

};
