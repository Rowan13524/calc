#include "unit.h"

#include <cstring>
#include <vector>

std::vector<str> unitStrings;

/*******************************
* node constructors/destructor *
*******************************/
unit::unit(){
    mMult.unitID = -1;
    mDiv.unitID = -1;
    mMult.next = NULL;
    mDiv.next = NULL;
}

unit::unit(const unit& other){
    const unit::node* po = &other.mMult;
    unit::node* pt = &mMult;
    while(po != NULL){
        pt->unitID = po->unitID;
        if(po->next != NULL){
            pt->next = (node*)malloc(sizeof(node));
        }
        else{
            break;
        }
        po = po->next;
        pt = pt->next;
    }
    pt->next = NULL;

    po = &other.mDiv;
    pt = &mDiv;
    while(po != NULL){
        pt->unitID = po->unitID;
        if(po->next != NULL){
            pt->next = (node*)malloc(sizeof(node));
        }
        else{
            break;
        }
        po = po->next;
        pt = pt->next;
    }
    pt->next = NULL;
}

unit::unit(str unit){
    mMult.unitID = -1;
    mDiv.unitID = -1;
    mMult.next = NULL;
    mDiv.next = NULL;
    if(unit[0] == '/'){
        unit.chopleft(1);
        for(size_t i = 0; i < unitStrings.size(); ++i){
            if(unit == unitStrings[i]){
                mDiv.unitID = i;
                return;
            }
        }
        mDiv.unitID = unitStrings.size();
        unitStrings.push_back(unit);
    }
    else{
        for(size_t i = 0; i < unitStrings.size(); ++i){
            if(unit == unitStrings[i]){
                mMult.unitID = i;
                return;
            }
        }
        mMult.unitID = unitStrings.size();
        unitStrings.push_back(unit);
    }
}

unit::~unit(){
    destroy(mMult.next);
    destroy(mDiv.next);
}

bool unit::operator==(const unit& other) const{
    return this->mMult == other.mMult && this->mDiv == other.mDiv;
}

bool unit::operator!=(const unit& other) const{
    return !(*this == other);
}


/*********************
* unit class methods *
*********************/
void unit::multiply(const unit& other){
    const unit::node* po = &other.mMult;
    unit::node* pt = &mMult;
    if(po->unitID != -1){
        while(pt->next != NULL){
            pt = pt->next;
        }
        if(pt->unitID != -1){
            pt->next = (node*)malloc(sizeof(node));
            pt = pt->next;
        }
        while(po != NULL){
            pt->unitID = po->unitID;
            if(po->next != NULL){
                pt->next = (node*)malloc(sizeof(node));
            }
            else{
                break;
            }
            po = po->next;
            pt = pt->next;
        }
        pt->next = NULL;
    }

    po = &other.mDiv;
    pt = &mDiv;
    if(po->unitID != -1){
        while(pt->next != NULL){
            pt = pt->next;
        }
        if(pt->unitID != -1){
            pt->next = (node*)malloc(sizeof(node));
            pt = pt->next;
        }
        while(po != NULL){
            pt->unitID = po->unitID;
            if(po->next != NULL){
                pt->next = (node*)malloc(sizeof(node));
            }
            else{
                break;
            }
            po = po->next;
            pt = pt->next;
        }
        pt->next = NULL;
    }
}

void unit::divide(const unit& other){
    const unit::node* po = &other.mMult;
    unit::node* pt = &mDiv;
    if(po->unitID != -1){
        while(pt->next != NULL){
            pt = pt->next;
        }
        if(pt->unitID != -1){
            pt->next = (node*)malloc(sizeof(node));
            pt = pt->next;
        }
        while(po != NULL){
            pt->unitID = po->unitID;
            if(po->next != NULL){
                pt->next = (node*)malloc(sizeof(node));
            }
            else{
                break;
            }
            po = po->next;
            pt = pt->next;
        }
        pt->next = NULL;
    }

    po = &other.mDiv;
    pt = &mMult;
    if(po->unitID != -1){
        while(pt->next != NULL){
            pt = pt->next;
        }
        if(pt->unitID != -1){
            pt->next = (node*)malloc(sizeof(node));
            pt = pt->next;
        }
        while(po != NULL){
            pt->unitID = po->unitID;
            if(po->next != NULL){
                pt->next = (node*)malloc(sizeof(node));
            }
            else{
                break;
            }
            po = po->next;
            pt = pt->next;
        }
        pt->next = NULL;
    }
}

str unit::asStr() const{
    str result;
    char buffer[10];
    result.append("[");

    if(mMult.unitID != -1){
        for(const node* ptr = &mMult; ptr != NULL; ptr = ptr->next){
            snprintf(buffer, 10, "%s", unitStrings[ptr->unitID].tocstring());
            result.append(buffer);
        }
    }
    else{
        result.append("1");
    }

    if(mDiv.unitID != -1){
        result.append("/");
        for(const node* ptr = &mDiv; ptr != NULL; ptr = ptr->next){
            snprintf(buffer, 10, "%s", unitStrings[ptr->unitID].tocstring());
            result.append(buffer);
        }
    }
    result.append("]");

    return result;
}


/***********************
* unit::node functions *
***********************/
bool operator==(const unit::node a, const unit::node b){
    return isEqual(&a, &b);
}

bool operator!=(const unit::node a, const unit::node b){
    return !(a == b);
}

bool isEqual(const unit::node* a, const unit::node* b){
    while(a != NULL && b != NULL){
        if(a->unitID != b->unitID){
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

void destroy(unit::node* n){
}

