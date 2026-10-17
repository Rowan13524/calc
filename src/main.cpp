#include <iostream>

#include "str.h"
#include "value.h"

int main(int argc, char** argv){
    str string("hello ");
    str string2("world");

    string.append(string2);
    string.append(" =D");

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

    std::cout << string << std::endl;
    std::cout << v1 << std::endl;
    std::cout << a << std::endl;
    return 0;
}
