/**
 * @file    unit.hpp
 * @brief   Definition of the unit class,
 *          This class uses an internal linked list node structure.
 */

#ifndef UNIT_H
#define UNIT_H

#include "str.hpp"

#include <stdlib.h>

/**
 * @class   unit
 * @brief   A reprentation of units, a part of the value class.
 *
 * The units are stored in two linked lists, representing the top and bottom half of a fractional unit (like m/s).
 */
class unit{
public:
    /**
     * @struct  node
     * @brief   A singly linked list node to store the unitIDs of this unit.
     *          The actual units are stored in an external buffer.
     */
    struct node{
        /// @brief  The id of the unit.
        int64_t unitID;
        /// @brief  The next node in the linked list.
        node* next;
    };

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

    /**
     * @brief   A check for equallity of two nodes and their following nodes are identical.
     *
     * @param   a   First operand.
     * @param   b   Second operand.
     *
     * @return  True if they are equal, false if they are not.
     */
    friend bool operator==(const node a, const node b);

    /**
     * @brief   A check for inequallity of two nodes and their following nodes are identical.
     *
     * @param   a   First operand.
     * @param   b   Second operand.
     *
     * @return  True if they are equal, false if they are not.
     */
    friend bool operator!=(const node a, const node b);

    /**
     * @brief   Helper function that compares the values of the nodes and their following nodes.
     *
     * This function interates over both nodes like a list, and compares the values of each node in that list.
     *
     * @param   a   First operand.
     * @param   b   Second operand.
     *
     * @return  True if they are equal, false if they are not.
     */
    friend bool isEqual(const node* a, const node* b);

    /**
     * @brief   Manual destructor of a node and its following nodes.
     *
     * Iterates over a node like a list, and frees every node on the way.
     *
     * @param   n   The node to be destroyed with its following nodes.
     */
    friend void destroy(node* n);
private:
    /// @brief  Top part of a fractional unit.
    node mMult;
    /// @brief  Bottom part of a fractional unit.
    node mDiv;
};

#endif
