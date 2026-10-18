/**
 * @file    main.cpp
 * @brief   Main starting point of the program.
 */
#include <iostream>

#include "str.hpp"
#include "value.hpp"

/**
 * @brief   Main starting point of this program.
 */
int main(int argc, char** argv){
    (void)argc;
    (void)argv;
    value v1(56.3, str("m"));
    value v2(30, str("s"));

    v1.divide(v2);
    v1.divide(v2);

    value a(1, str("m"));
    value b(2, str("m"));
    value c(3, str("m"));

    a.multiply(b);
    a.multiply(c);
    a.divide(v2);

    std::cout << v1 << std::endl;
    std::cout << a << std::endl;

    str string("hello ");
    str string2("world");

    string.append(string2);
    string.append(" =D");

    std::cout << string << std::endl;

    return 0;
}
