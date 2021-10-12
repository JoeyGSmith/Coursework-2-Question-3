#include <iostream>
#include <cassert>
#include <cmath>

#include "BestL2Fit.hpp"
#include "Gauss4point.hpp"


double function_1(double x);
double function_2(double x);
double function_3(double x);
double function_4(double x);


int main(int argc, char* argv[])
{
    int nxvalues = 101;

    //Function 1
    std::cout << "Approximating function 1: " << std::endl;
    Gauss4point* f1gauss
    = new Gauss4point(&function_1,0,1);

    BestL2Fit* f1approx
    = new BestL2Fit(&function_1,f1gauss,0,1,4,"f1approx");

    f1approx->Approximate(nxvalues);

    //function 2
    std::cout << "Approximating function 2: " << std::endl;
        Gauss4point* f2gauss
    = new Gauss4point(&function_2,0,1);

    BestL2Fit* f2approx
    = new BestL2Fit(&function_2,f2gauss,0,1,4,"f2approx");

    f2approx->Approximate(nxvalues);

    //function 3
    std::cout << "Approximating function 3: " << std::endl;
        Gauss4point* f3gauss
    = new Gauss4point(&function_3,0,1);

    BestL2Fit* f3approx
    = new BestL2Fit(&function_3,f3gauss,0,1,4,"f3approx");

    f3approx->Approximate(nxvalues);

    //function 4
    std::cout << "Approximating function 4: " << std::endl;
        Gauss4point* f4gauss
    = new Gauss4point(&function_4,0,1);

    BestL2Fit* f4approx
    = new BestL2Fit(&function_4,f4gauss,0,1,4,"f4approx");

    f4approx->Approximate(nxvalues);

        //Function 1 using quartic polynomials
    std::cout << "Approximating function 1: " << std::endl;
    Gauss4point* f1gauss2
    = new Gauss4point(&function_1,0,1);

    BestL2Fit* f1approx2
    = new BestL2Fit(&function_1,f1gauss2,0,1,5,"f1approx");

    f1approx2->Approximate(nxvalues);


    return 0;
}

double function_1(double x)
{
    return pow(x,3);
}

double function_2(double x)
{
    return sin(2*x);
}

double function_3(double x)
{
    return 1/(1+25*pow((2*x-1),2));
}

double function_4(double x)
{
    assert (x >= 0);
    return sqrt(x);
}
