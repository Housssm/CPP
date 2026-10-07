#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    Point const p_in(2.0f, 2.0f);
    Point const p_out(15.0f, 15.0f);
    Point const p_edge(5.0f, 0.0f);

    if (bsp(a, b, c, p_in))
        std::cout << "The point p_in is in" << std::endl;
    else
        std::cout << "The point p_in is out" << std::endl;

    if (bsp(a, b, c, p_out))
        std::cout << "The point p_out is in" << std::endl;
    else
        std::cout << "The point p_out is out" << std::endl;

    if (bsp(a, b, c, p_edge))
        std::cout << "The point p_edge is in" << std::endl;
    else
        std::cout << "The point p_edge is out" << std::endl;

    return 0;
}
