#ifndef VALUE_H
#define VALUE_H

#include <stdlib.h>

#include "unit.h"


class value{
public:
    value();
    value(double value, unit unit);
    ~value();

    void add(const value& other);
    void subtract(const value& other);
    void multiply(const value& other);
    void divide(const value& other);

    friend std::ostream& operator<<(std::ostream& out, const value& print);
private:
    double mValue;
    unit mUnit;
};

#endif
