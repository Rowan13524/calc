/**
 * @file    list.hpp
 * @brief   Definition of the list class.
 */

#ifndef LIST_HPP
#define LIST_HPP

#include <stdlib.h>

class list{
    public:
    /**
     * @struct  node
     * @brief   A singly linked list node to store the unitIDs of this unit.
     *          The actual units are stored in an external buffer.
     */
    struct node{
        /// @brief  The id of the unit.
        int64_t unitID;
        /// @brief  The power of this part of the unit.
        int32_t power;
        /// @brief  The next node in the linked list.
        node* next;
    };

    /**
     * @brief   Default constructor of the list class.
     */
    list();

    /**
     * @brief   Copy constructor of the list class.
     *
     * @param   other   The str to be copied.
     */
    list(const list& other);

    /**
     * @brief   Destructor of the list class.
     */
    ~list();

    /**
     * @brief   Appends a node to the end of the list.
     *
     * @param   n   The node to be added.
     */
    void append(const node* n);

    /**
     * @brief   A check for equallity of two lists.
     *
     * @param   other   The list to be compared with.
     *
     * @return  True if they are equal, false if they are not.
     */
    bool operator==(const list& other) const;

    /**
     * @brief   A check for inequallity of two lists.
     *
     * @param   other   The list to be compared with.
     *
     * @return  True if they are equal, false if they are not.
     */
    bool operator!=(const list& other) const;

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
    //private:
    /// @brief  The head of the list, representing the first element.
    node* head;
    /// @brief  The tail of the list, representing the last element.
    node* tail;
};

#endif

