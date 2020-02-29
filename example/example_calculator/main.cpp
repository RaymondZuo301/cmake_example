#include <iostream>

#include <ray/math/calculator/calculator.h>

using namespace ray::math;

int main(int argc, char* argv[])
{
    Calculator cal;

    std::cout << "1.1+2.2=" << cal(1.1, 2.2, ADD) << std::endl;
    return 0;
}
