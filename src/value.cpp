/**
 * @file    value.cpp
 * @brief   Implementation of the value class.
 */
#include "value.hpp"


/********************************
* value constructors/destructor *
********************************/
value::value(){
}

value::value(double value, unit unit) :
mValue(value), mUnit(unit)
{}

value::~value(){
}


/**********************
* value class methods *
**********************/
void value::add(const value& other){
    if(mUnit != other.mUnit){
        std::cout << "ERROR: units must be the same to allow addition" << std::endl;
        return;
    }
    mValue += other.mValue;
}

void value::subtract(const value& other){
    if(mUnit != other.mUnit){
        std::cout << "ERROR: units must be the same to allow addition" << std::endl;
        return;
    }
    mValue -= other.mValue;
}

void value::multiply(const value& other){
    mValue *= other.mValue;
    this->mUnit.multiply(other.mUnit);
}

void value::divide(const value& other){
    mValue /= other.mValue;
    this->mUnit.divide(other.mUnit);
}


/**********************
* ostream << overload *
**********************/
std::ostream& operator<<(std::ostream& out, const value& print){
    str unit = print.mUnit.asStr();
    out << print.mValue << unit;
    return out;
}
