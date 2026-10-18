/**
 * @file    str.hpp
 * @brief   Definition of the str class.
 */

#ifndef STR_H
#define STR_H

#include <iostream>

/**
 * @class   str
 * @brief   Sized string stucture to manage string of dynamic lengths.
 */
class str{
public:
    /**
     * @brief   Default constructor of the str class.
     */
    str();

    /**
     * @brief   Copy constructor of the str class.
     *
     * @param   other   The str to be copied.
     */
    str(const str& other);

    /**
     * @brief   Copy constructor of the str class.
     *
     * @param   string  A cstring that gets copied to the str.
     */
    str(const char* string);

    /**
     * @brief   Destructor of the str class.
     */
    ~str();

    /**
     * @brief   Appends the inputted string to this one.
     *
     * @param   other   The string to be appended.
     */
    void append(const str& other);

    /**
     * @brief   Chops the inputted amount of characters from the left side of the str.
     *
     * @param   amount  The amount of characters to be chopped.
     */
    void chopleft(size_t amount);

    /**
     * @brief   A way to convert a size str to a null-terminated cstring.
     *
     * @return  A null-terminated cstring allocated on the heap.
     *
     * @note    The returned string needs to be freed mannually after calling this function.
     */
    char* tocstring() const;

    /**
     * @brief   An index into the bytes of the str.
     *
     * @param   i   The index of the lookup.
     *
     * @return  The character at index i.
     */
    char operator[](size_t i) const;

    /**
     * @brief   An index into the bytes of the str.
     *
     * @param   i   The index of the lookup.
     *
     * @return  A reverence to the character at index i.
     */
    char& operator[](size_t i);

    /**
     * @brief   A check for equallity with another str.
     *
     * @param   other   The str to be compared to.
     *
     * @return  True if they are equal, false if they are not.
     */
    bool operator==(const str& other) const;

    /**
     * @brief   A check for inequallity with another str.
     *
     * @param   other   The str to be compared to.
     *
     * @return  True if they are not equal, false if they are.
     */
    bool operator!=(const str& other) const;

    /**
     * @brief   Overload of the << operator to be able to print a str with an ostream.
     *
     * @param   out     A reference to the output stream the string is sent to.
     * @param   print   The string to be sent to the output stream.
     *
     * @return  A reference to the original output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const str& print);
private:
    size_t mSize;
    char* mData;
};

#endif
