/**
 * @file    str.cpp
 * @brief   Implementation of the str class.
 */
#include "str.hpp"

#include <string.h>


/******************************
* str constructors/destructor *
******************************/
str::str(){
    mSize = 0;
    mData = NULL;
}

str::str(const str& other){
    mSize = other.mSize;
    mData = (char*)malloc(mSize);
    memcpy(mData, other.mData, mSize);
}

str::str(const char* string){
    mSize = strlen(string);
    mData = (char*)malloc(mSize);
    memcpy(mData, string, mSize);
}

str::~str(){
    free(mData);
}


/********************
* str class methods *
********************/
void str::append(const str& other){
    char* newData = (char*)malloc(mSize+other.mSize);
    memcpy(newData, mData, mSize);
    memcpy(newData + mSize, other.mData, other.mSize);
    free(mData);
    mData = newData;
    mSize += other.mSize;
}

void str::chopleft(size_t amount){
    if(amount >= mSize){
        mSize = 0;
        free(mData);
        mData = NULL;
        return;
    }
    char* newData = (char*)malloc(mSize-amount);
    memcpy(newData, mData+amount, mSize-amount);
    free(mData);
    mData = newData;
    mSize -= amount;
}

char* str::tocstring() const{
    char* newString = (char*)malloc(mSize + 1);
    memcpy(newString, mData, mSize);
    newString[mSize] = '\0';
    return newString;
}

char str::operator[](size_t i) const{
    return mData[i];
}

char& str::operator[](size_t i){
    return mData[i];
}

bool str::operator==(const str& other) const{
    if(mSize != other.mSize){
        return false;
    }
    for(size_t i = 0; i < mSize; ++i){
        if(mData[i] != other.mData[i]){
            return false;
        }
    }
    return true;
}

bool str::operator!=(const str& other) const{
    return !(*this == other);
}


/**********************
* ostream << overload *
**********************/
std::ostream& operator<<(std::ostream& out, const str& print){
    char* tmp = print.tocstring();
    out << tmp;
    free(tmp);
    return out;
}
