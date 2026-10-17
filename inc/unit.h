#ifndef UNIT_H
#define UNIT_H

#include "str.h"

class unit{
public:
    struct node{
        int64_t unitID;
        node* next;
    };

    unit();
    unit(const unit& other);
    unit(str unit);
    ~unit();

    bool operator==(const unit& other) const;
    bool operator!=(const unit& other) const;

    void multiply(const unit& other);
    void divide(const unit& other);

    str asStr() const;

    friend bool operator==(const node a, const node b);
    friend bool operator!=(const node a, const node b);

    friend bool isEqual(const node* a, const node* b);
    friend void destroy(node* n);
private:
    node mMult;
    node mDiv;
};

#endif
