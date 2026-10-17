#ifndef STR_H
#define STR_H

#include <iostream>
#include <stdlib.h>

class str{
public:
    str();
    str(const str& other);
    str(const char* string);
    ~str();

    void append(const str& other);
    void chopleft(size_t amount);
    char* tocstring() const;

    char operator[](size_t i) const;
    char& operator[](size_t i);

    bool operator==(const str& other);
    bool operator!=(const str& other);

    friend std::ostream& operator<<(std::ostream& out, const str& print);
private:
    size_t mSize;
    char* mData;
};

#endif
