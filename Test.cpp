//
// Created by rotem levy on 30/04/2020.
//

#include "solver.hpp"
#include "doctest.h"

using namespace solver;
using namespace std;


TEST_CASE("Find method")
{
    RealVariable x;
    ComplexVariable y;

    for (int i = 0; i < 110; i++)
    {
        CHECK(solve(2*i * x - 4 == 10));
    }
}