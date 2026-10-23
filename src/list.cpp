/**
 * @file    list.cpp
 * @brief   Implementation of the unit class.
 */

#include "list.hpp"


/*******************************
* list constructors/destructor *
*******************************/
list::list() :
head(nullptr), tail(nullptr)
{}

list::list(const list& other) :
head(nullptr), tail(nullptr)
{
    for(node* n = other.head; nullptr != n; n = n->next){
        append(n);
    }
}

list::~list(){
    while(nullptr != head){
        tail = head->next;
        delete head;
        head = tail;
    }
}


/*********************
* list class methods *
*********************/
void list::append(const node* other){
    if(nullptr != tail){
        tail->next = new node;
        tail = tail->next;
        tail->unitID = other->unitID;
        tail->power = other->power;
        tail->next = nullptr;
        return;
    }
    head = new node;
    tail = head;
    tail->unitID = other->unitID;
    tail->power = other->power;
    tail->next = nullptr;
}

bool list::operator==(const list& other) const{
    return isEqual(head, other.head);
}

bool list::operator!=(const list& other) const{
    return !isEqual(head, other.head);
}


/***********************
* list::node functions *
***********************/
bool isEqual(const list::node* a, const list::node* b){
    while(nullptr != a && nullptr != b){
        if(a->unitID != b->unitID && a->power != b->power){
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

