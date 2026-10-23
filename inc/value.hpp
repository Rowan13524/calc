/**
 * @file    value.hpp
 * @brief   Definition of the value class,
 *          This class uses an internal linked list node structure.
 */

#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>
#include <stdlib.h>

#include "unit.hpp"

/**
 * @class   value
 * @brief   A pair of a double and a unit.
 */
class value{
public:
    /**
     * @brief   Default constructor of the value class.
     */
    value();

    /**
     * @brief   Constructor of the value class with a value and a unit.
     *
     * @param   value   The initial value of this value.
     * @param   unit    The initial unit of this value.
     */
    value(double value, unit unit);

    value(double value, str unit);

    /**
     * @brief   Destructor of the value class.
     */
    ~value();

    /**
     * @brief   Adds another value to this value.
     *
     * @param   other   The value to be added.
     */
    void add(const value& other);

    /**
     * @brief   Subtracts another value from this value.
     *
     * @param   other   The value to be subtracted.
     */
    void subtract(const value& other);

    /**
     * @brief   Multiplies this value with another value.
     *
     * @param   other   The value to be multiplied.
     */
    void multiply(const value& other);

    /**
     * @brief   Divides this value with another value.
     *
     * @param   other   The value to be divided with.
     */
    void divide(const value& other);

    /**
     * @brief   Overload of the << operator to be able to print a str with an ostream.
     *
     * @param   out     A reference to the output stream the string is sent to.
     * @param   print   The value to be sent to the output stream.
     *
     * @return  A reference to the original output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const value& print);
private:
    /// @brief  Numerical value of this value.
    double mValue;
    /// @brief  Unit of this value.
    unit mUnit;
};

#endif

