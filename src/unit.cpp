/**
 * @file    unit.cpp
 * @brief   Implementation of the unit class.
 */

#include "unit.hpp"

#include <cstring>
#include <vector>

/// @brief  Global buffer that holds the strings associated with the units.
std::vector<str> unitStrings;


/*******************************
* unit constructors/destructor *
*******************************/
unit::unit(){
}

unit::unit(const unit& other){
    mMult = other.mMult;
    mDiv = other.mDiv;
}

unit::unit(str unit){
    if('/' == unit[0]){
        unit.chopleft(1);
        for(size_t i = 0; i < unitStrings.size(); ++i){
            if(unit == unitStrings[i]){
                list::node result;
                result.unitID = i; result.power = 1;
                mDiv.append(&result);
                return;
            }
        }
        list::node result;
        result.unitID = unitStrings.size(); result.power = 1;
        mDiv.append(&result);
        unitStrings.push_back(unit);
    }
    else{
        for(size_t i = 0; i < unitStrings.size(); ++i){
            if(unit == unitStrings[i]){
                list::node result;
                result.unitID = i; result.power = 1;
                mMult.append(&result);
                return;
            }
        }
        list::node result;
        result.unitID = unitStrings.size(); result.power = 1;
        mMult.append(&result);
        unitStrings.push_back(unit);
    }
}

unit::~unit(){
}

/*********************
* unit class methods *
*********************/
bool unit::operator==(const unit& other) const{
    return mMult == other.mMult && mDiv == other.mDiv;
}

bool unit::operator!=(const unit& other) const{
    return !(*this == other);
}

void unit::multiply(const unit& other){
    bool addedPower = false;
    for(list::node* n = other.mMult.head; nullptr != n; n = n->next){
        for(list::node* m = mMult.head; nullptr != m; m = m->next){
            if(n->unitID == m->unitID){
                m->power += n->power;
                addedPower = true;
                break;
            }
        }
        if(!addedPower){
            addedPower = false;
            mMult.append(n);
        }
    }
    for(list::node* n = other.mDiv.head; nullptr != n; n = n->next){
        for(list::node* m = mDiv.head; nullptr != m; m = m->next){
            if(n->unitID == m->unitID){
                m->power += n->power;
                addedPower = true;
                break;
            }
        }
        if(!addedPower){
            addedPower = false;
            mDiv.append(n);
        }
    }
}

void unit::divide(const unit& other){
    bool addedPower = false;
    for(list::node* n = other.mMult.head; nullptr != n; n = n->next){
        for(list::node* m = mDiv.head; nullptr != m; m = m->next){
            if(n->unitID == m->unitID){
                m->power += n->power;
                addedPower = true;
                break;
            }
        }
        if(!addedPower){
            addedPower = false;
            mDiv.append(n);
        }
    }
    for(list::node* n = other.mDiv.head; nullptr != n; n = n->next){
        for(list::node* m = mMult.head; nullptr != m; m = m->next){
            if(n->unitID == m->unitID){
                m->power += n->power;
                addedPower = true;
                break;
            }
        }
        if(!addedPower){
            addedPower = false;
            mMult.append(n);
        }
    }
}

str unit::asStr() const{
    str result;
    char buffer[10];
    result.append("[");

    if(nullptr != mMult.head){
        for(const list::node* ptr = mMult.head; nullptr != ptr; ptr = ptr->next){
            char* tmp = unitStrings[ptr->unitID].tocstring();
            snprintf(buffer, 10, "%s^%d", tmp, ptr->power);
            delete[] tmp;
            result.append(buffer);
        }
    }
    else{
        result.append("1");
    }

    if(nullptr != mDiv.head){
        result.append("/");
        for(const list::node* ptr = mDiv.head; nullptr != ptr; ptr = ptr->next){
            char* tmp = unitStrings[ptr->unitID].tocstring();
            snprintf(buffer, 10, "%s^%d", tmp, ptr->power);
            delete[] tmp;
            result.append(buffer);
        }
    }
    result.append("]");

    return result;
}
