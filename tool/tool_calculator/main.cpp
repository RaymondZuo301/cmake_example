#include <iostream>
#include <string>
#include <cstdlib>

#include <ray/math/calculator/calculator.h>

using namespace ray::math;

int main(int argc, char* argv[])
{
    if(argc != 3+1)
    {
        std::cout << "The number of parameters must be 3!" << std::endl;
        return -1;
    }

    double a = atof(argv[1]);
    std::string op(argv[2]);
    double b = atof(argv[3]);

    Calculator cal;

    if(op == "+")
        std::cout << cal(a, b, ADD) << std::endl;
    else if(op == "-")
        std::cout << cal(a, b, MINUS) << std::endl;
    else if(op == "*")
        std::cout << cal(a, b, MULTIPLY) << std::endl;
    else if(op == "/")
        std::cout << cal(a, b, DIVIDE) << std::endl;
    else
    {
        std::cout << "Operator error!" << std::endl;
        return -1;
    }
    return 0;
}
