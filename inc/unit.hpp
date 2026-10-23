/**
 * @file    unit.hpp
 * @brief   Definition of the unit class,
 *          This class uses an internal linked list node structure.
 */

#ifndef UNIT_HPP
#define UNIT_HPP

#include <stdlib.h>

#include "str.hpp"
#include "list.hpp"

/**
 * @class   unit
 * @brief   A reprentation of units, a part of the value class.
 *
 * The units are stored in two linked lists, representing the top and bottom half of a fractional unit (like m/s).
 */
class unit{
public:
    /**
     * @brief   Default constructor of the unit class.
     */
    unit();

    /**
     * @brief   Copy constructor of the unit class.
     *
     * @param   other   The other unit to be copied.
     */
    unit(const unit& other);

    /**
     * @brief   Contructor of a unit with a str respresentation.
     *
     * This constructor creates a new entry in the external buffer of unit strings,
     * and sent the unitID of this unit to the index of that string.
     *
     * @param   unit    A str that represents this unit.
     */
    unit(str unit);

    /**
     * @brief   Destructor of the unit class.
     */
    ~unit();

    /**
     * @brief   A check for equallity with another unit.
     *
     * @param   other   The unit to be compared to.
     *
     * @return  True if they are equal, false if they are not.
     */
    bool operator==(const unit& other) const;

    /**
     * @brief   A check for inequallity with another unit.
     *
     * @param   other   The unit to be compared to.
     *
     * @return  True if they are equal, false if they are not.
     */
    bool operator!=(const unit& other) const;

    /**
     * @brief   Multiplies this unit with another unit.
     *
     * @param   other   The unit to be multiplied with.
     */
    void multiply(const unit& other);

    /**
     * @brief   Divides this unit with another unit.
     *
     * @param   other   The unit to be divided with.
     */
    void divide(const unit& other);

    /**
     * @brief   String representation of this unit.
     *
     * @return  The string representation of this unit in a str.
     */
    str asStr() const;
private:
    /// @brief  Top part of a fractional unit.
    list mMult;
    /// @brief  Bottom part of a fractional unit.
    list mDiv;
};

#endif

