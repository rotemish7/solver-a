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
     * @param real
     * @return
     */
    double solve(const RealVariable& real)
    {
        double a = real.getA();
        double b = real.getB();
        double c = real.getC();

        if(a == 0 && b == 0 && c == 0)
        {
            return 0;
        }

        if(a == 0 && b == 0 && c!=0)
        {
            throw runtime_error("There is no solution");
        }

        if(a == 0 && b!=0)
        {
            return (c/-b);
        }

        if(a == 0 && b == 0)
        {
            return c;
        }

        double fx = (b*b) - 4*a*c;
        if (fx >= 0)
        {
            return ((-b + sqrt(fx))/(2*a));
        }
        throw runtime_error("There is no real solution");
    }

    /**
     *
     * @param comp
     * @return
     */
    complex<double> solve(const ComplexVariable& comp)
    {
        complex<double> a = comp.getA();
        complex<double> b = comp.getB();
        complex<double> c = comp.getC();

        if(a == complex(0.0,0.0) && b == complex(0.0,0.0) && c == complex(0.0,0.0))
        {
            return 0;
        }

        if(a == complex(0.0,0.0))
        {
            if (( b == complex(0.0,0.0)) && (c != complex(0.0,0.0)))
            {
                throw runtime_error("There is no solution");
            }
            else
            {
                return -c/b;
            }
        }
        complex<double> fx = (b*b) - (complex(4.0,0.0)*a*c);
        return ((-b + sqrt(fx)) / (complex(2.0,0.0)*a));
    }

    /**
     *
     * @param comp
     * @return
     */
    string ComplexToString(const complex<double> comp)
    {
        return to_string(comp.real()) + "+" + to_string(comp.imag()) + "i";
    }

    //// RealVariable ////


    /**
     *
     * @param num
     * @param real
     * @return
     */
    RealVariable operator*(const double num, const RealVariable real)
    {
        return RealVariable(real.a*num, real.b*num, real.c*num);
    }

    /**
     *
     * @param real1
     * @param real2
     * @return
     */
    RealVariable operator*(const RealVariable real1, const RealVariable real2)
    {
        if((real1.a > 0 && real2.a > 0) || (real1.a > 0 && real2.b > 0) || (real2.a > 0 && real1.b > 0))
        {
            throw runtime_error("Power is higher than 2");
        }
        return RealVariable((real1.a*real2.c) + (real2.a*real1.c) + (real1.b*real2.b), (real1.b*real2.c) + (real2.b*real1.c), real1.c*real2.c);
    }

    /**
     *
     * @param real
     * @param num
     * @return
     */
    RealVariable operator*(const RealVariable& real, const double num)
    {
        return real*num;
    }

    /**
     *
     * @param real
     * @param num
     * @return
     */
    RealVariable operator-(const RealVariable& real, const double num)
    {
        return RealVariable(real.a, real.b, real.c-num);
    }

    /**
     *
     * @param num
     * @param real
     * @return
     */
    RealVariable operator-(const double num, const RealVariable& real)
    {
        return RealVariable(-real.a, -real.b, -real.c+num);
    }

    /**
     *
     * @param real1
     * @param real2
     * @return
     */
    RealVariable operator-(const RealVariable& real1, const RealVariable& real2)
    {
        return RealVariable(real1.a-real2.a, real1.b-real2.b, real1.c-real2.c);
    }

    /**
     *
     * @param real
     * @param num
     * @return
     */
    RealVariable operator+(const RealVariable& real, const double num)
    {
        return RealVariable(real.a, real.b, real.c+num);
    }

    /**
     *
     * @param num
     * @param real
     * @return
     */
    RealVariable operator+(const double num, const RealVariable& real)
    {
        return RealVariable(real.a, real.b, real.c+num);
    }

    /**
     *
     * @param real1
     * @param real2
     * @return
     */
    RealVariable operator+(const RealVariable& real1, const RealVariable& real2)
    {
        return RealVariable(real1.a+real2.a, real1.b+real2.b, real1.c+real2.c);
    }

    /**
     *
     * @param real
     * @param num
     * @return
     */
    RealVariable operator^(const RealVariable& real, const double num)
    {
        if(num == 1)
        {
            return real;
        }

        if(num == 0)
        {
            return RealVariable(0,0,1);
        }

        if(num>2 || num<0)
        {
            throw runtime_error("Cannot solve power higher than 2");
        }

        if(num == 2 && real.a > 0)
        {
            throw runtime_error("Cannot solve power higher than 2");
        }
        return RealVariable(real.b,0,real.c*real.c);
    }

    /**
     *
     * @param real
     * @param num
     * @return
     */
    RealVariable operator==(const RealVariable& real, const double num)
    {
        return real-num;
    }

    /**
     *
     * @param num
     * @param real
     * @return
     */
    RealVariable operator==(const double num, const RealVariable& real)
    {
        return num-real;
    }

    /**
     *
     * @param real1
     * @param real2
     * @return
     */
    RealVariable operator==(const RealVariable& real1, const RealVariable& real2)
    {
        return real1-real2;
    }

    /**
     *
     * @param real
     * @param num
     * @return
     */
    RealVariable operator/(const RealVariable& real, const double num)
    {
        if(num == 0)
        {
            throw runtime_error("Cannot divide by 0");
        }
        return RealVariable(real.a/num, real.b/num, real.c/num);
    }

    /**
     *
     * @param real1
     * @param real2
     * @return
     */
    RealVariable operator/(const RealVariable& real1, const RealVariable& real2)
    {
        if(real2.a == 0 && real2.b == 0 && real2.c == 0)
        {
            throw runtime_error("Cannot divide by 0");
        }
        if((real1.a == 0 && real2.a != 0) || (real1.a == 0 && real1.b == 0 && real2.b != 0))
        {
            throw runtime_error("Power is less than 0");
        }
        RealVariable real3 = real1-real2;
        if(real3.a == 0 && real3.b == 0 && real3.c == 0)
        {
            return RealVariable(0, 0, 1);
        }
        if(real1.a != 0 && real1.b == 0 && real1.c == 0 && real2.a != 0 && real2.b == 0 && real2.c == 0)
        {
            return RealVariable(0,0,real1.a/real2.a);
        }
        if(real1.a != 0 && real1.b == 0 && real1.c == 0 && real2.a == 0 && real2.b != 0 && real2.c == 0)
        {
            return RealVariable(0,real1.a/real2.b, 0);
        }
        if(real1.a == 0 && real1.b != 0 && real1.c == 0 && real2.a == 0 && real2.b != 0 && real2.c == 0)
        {
            return RealVariable(0,0,real1.b/real2.b);
        }
        if(real1.a != 0 && real1.b != 0 && real1.c == 0 && real2.a == 0 && real2.b != 0 && real2.c == 0)
        {
            return RealVariable(0, real1.a/real2.c, real1.b/real2.c);
        }
        if(real2.a == 0 && real2.b == 0)
        {
            return real1/real2.c;
        }
        throw runtime_error("Divide error");
    }

    //// ComplexVariable ////

    /**
     *
     * @param num
     * @param comp
     * @return
     */
    ComplexVariable operator*(const complex<double> num, const ComplexVariable& comp)
    {
        return ComplexVariable(comp.a*num, comp.b*num, comp.c*num);
    }

    /**
    *
    * @param comp
    * @param num
    * @return
    */
    ComplexVariable operator*(const ComplexVariable& comp,const complex<double> num)
    {
        return ComplexVariable(comp.a*num, comp.b*num, comp.c*num);
    }

    /**
     *
     * @param comp1
     * @param comp2
     * @return
     */
    ComplexVariable operator* (const ComplexVariable& comp1, const ComplexVariable& comp2)
    {
        if((comp1.a!=complex(0.0,0.0)&&comp2.a!=complex(0.0,0.0))||(comp1.a!=complex(0.0,0.0)&&comp2.b!=complex(0.0,0.0))||(comp2.a!=complex(0.0,0.0)&&comp1.b!=complex(0.0,0.0)))
        {
            throw runtime_error("Power is higher than 2");
        }
        return ComplexVariable((comp1.a*comp2.c) + (comp2.a*comp1.c) + (comp1.b*comp2.b),(comp1.b*comp2.c) + (comp2.b*comp1.c),comp1.c*comp2.c);
    }

    /**
     *
     * @param comp1
     * @param comp2
     * @return
     */
    ComplexVariable operator-(const ComplexVariable& comp1, const ComplexVariable& comp2)
    {
        return ComplexVariable(comp1.a-comp2.a, comp1.b-comp2.b, comp1.c-comp2.c);
    }

    /**
     *
     * @param comp
     * @param num
     * @return
     */
    ComplexVariable operator-(const ComplexVariable& comp, const complex<double> num)
    {
        return ComplexVariable(comp.a, comp.b, comp.c-num);
    }

    /**
     *
     * @param num
     * @param comp
     * @return
     */
    ComplexVariable operator-(const complex<double> num, const ComplexVariable& comp)
    {
        return ComplexVariable(-comp.a, -comp.b, comp.c+num);
    }

    /**
     *
     * @param comp1
     * @param comp2
     * @return
     */
    ComplexVariable operator+(const ComplexVariable& comp1, const ComplexVariable& comp2)
    {
        return ComplexVariable(comp1.a+comp2.a, comp1.b+comp2.b, comp1.c+comp2.c);
    }

    /**
     *
     * @param comp
     * @param num
     * @return
     */
    ComplexVariable operator+(const ComplexVariable& comp, const complex<double> num)
    {
        return ComplexVariable(comp.a, comp.b, comp.c+num);
    }

    /**
     *
     * @param num
     * @param comp
     * @return
     */
    ComplexVariable operator+(const complex<double> num, const ComplexVariable& comp)
    {
        return num+comp;
    }

    /**
     *
     * @param comp
     * @param num
     * @return
     */
    ComplexVariable operator^(const ComplexVariable& comp, const complex<double> num)
    {
        if(num.imag() != 0)
        {
            throw runtime_error("Invalid");
        }
        if(num.real() == 0)
        {
            return ComplexVariable(0, 0, 1);
        }
        if(num.real() == 1)
        {
            return num1;
        }
        if(comp.a != complex(0.0,0.0))
        {
            throw runtime_error("The power is higher than 2");
        }
        if(num.real() < 0)
        {
            throw runtime_error("The power is higher than 2");
        }
        if(num.real() > 2)
        {
            if(comp.b != complex(0.0,0.0))
            {
                throw runtime_error("The power is higher than 2");
            }
            else
            {
                complex<double> power = pow(comp.c, num);
                return ComplexVariable(0, 0, power);
            }
        }
        return comp*comp;
    }

    /**
     *
     * @param comp1
     * @param comp2
     * @return
     */
    ComplexVariable operator==(const ComplexVariable& comp1, const ComplexVariable& comp2)
    {
        return comp1-comp2;
    }

    /**
     *
     * @param num
     * @param comp
     * @return
     */
    ComplexVariable operator==(const complex<double> num, const ComplexVariable& comp)
    {
        return comp-num;
    }

    /**
     *
     * @param comp
     * @param num
     * @return
     */
    ComplexVariable operator==(const ComplexVariable& comp, const complex<double> num)
    {
        return comp-num;
    }

    /**
     *
     * @param comp
     * @param num
     * @return
     */
    ComplexVariable operator/(const ComplexVariable& comp, const complex<double> num)
    {
        if(num.real() == 0 && num.imag() == 0)
        {
            throw invalid_argument("Cannot divide by 0");
        }

        return ComplexVariable(comp.a/num,comp.b/num,comp.c/num);
    }

    /**
     *
     * @param comp1
     * @param comp2
     * @return
     */
    ComplexVariable operator/(const ComplexVariable& comp1, const ComplexVariable& comp2)
    {
        if(comp2.a == complex(0.0,0.0) && comp2.b == complex(0.0,0.0) && comp2.c == complex(0.0,0.0))
        {
            throw runtime_error("Cannot divide by 0");
        }

        ComplexVariable x;
        ComplexVariable temp1 = operator-(comp1,x^2);
        ComplexVariable temp2 = operator-(comp2,x);
        ComplexVariable comp3 = comp1 - comp2;
        ComplexVariable comp4 = comp2 - comp1;

        if(comp3.a == complex(0.0,0.0) && comp3.b == complex(0.0,0.0) && comp3.c == complex(0.0,0.0))
        {
            return ComplexVariable(0,0,complex(1.0,0.0));
        }

        if(comp4.a == complex(0.0,0.0) && comp4.b == complex(0.0,0.0) && comp4.c == complex(0.0,0.0))
        {
            return ComplexVariable(0,0,complex(1.0,0.0));
        }

        if(temp1.a == complex(0.0,0.0) && temp1.b == complex(0.0,0.0) && temp1.c == complex(0.0,0.0) && temp2.a == complex(0.0,0.0) && temp2.b == complex(0.0,0.0) && temp2.c == complex(0.0,0.0))
        {
            return ComplexVariable(0,complex(1.0,0.0),0);
        }
        if(comp2.a == complex(0.0,0.0) && comp2.b == complex(0.0,0.0))
        {
            return comp1/comp2.c;
        }
        throw runtime_error("Error dividing");
    }
};
