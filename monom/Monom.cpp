#include "Monom.h"
#include <stdint.h>
#include <iostream>


Monom::Monom(double coef, size_t size, int16_t* array){
    _coef = coef;
    _varcount = size;
    _powers = array;
}

double Monom::GetCoef() const {
    return _coef;
}

void Monom::SetCoef(double coef){
        _coef = coef;
    }

size_t Monom::GetSize()const{
    return _varcount;
}

void Monom::Print() const{
    if (_coef == 0) {
        std::cout<< 0;
        return;
    }
    std::cout<<_coef;
    for (size_t i = 0; i < _varcount; i++){
        if (_powers[i] != 0)
        {
            std::cout<<"x"<<i+1; 
            if (_powers[i] != 1)
                std::cout<<"^"<<_powers[i];
        }
    }
}

Monom::Monom(const Monom& mon){
    _varcount = mon._varcount;
    _coef = mon._coef;
    _powers = new int16_t[_varcount];
    for (size_t i = 0; i < _varcount; i++){
        _powers[i] = mon._powers[i];
    }
}

Monom& Monom::operator=(const Monom& mon){
    if (this == &mon){
        return *this;
    }
    delete [] _powers;
    _powers = new int16_t[mon._varcount];
    _varcount = mon._varcount;
    _coef = mon._coef;
    for (size_t i = 0; i < _varcount; i++){
        _powers[i] = mon._powers[i];
    }
    return *this;
}

Monom Monom::operator+(const Monom& mon)const{
    Monom a(*this);
    if (a._varcount != mon._varcount){
        throw "error varcount";
    }
    for (size_t i = 0; i < _varcount; i ++){
        if (a._powers[i] != mon._powers[i]){
            throw "error powers";
        }
    }
    a._coef += mon._coef;
    return a;
};

bool Monom::CanOperate(const Monom& mon) const {
    if (this->_varcount != mon._varcount){
        return false;
    }
    for (size_t i = 0; i < _varcount; i ++){
        if (this->_powers[i] != mon._powers[i]){
            return false;
        }
    }
    return true;
}

Monom Monom::operator-(const Monom& mon)const{
    Monom a(*this);
    if (a._varcount != mon._varcount){
        throw "-";
    }
    for (size_t i = 0; i < _varcount; i ++){
        if (a._powers[i] != mon._powers[i]){
            throw "-";
        }
    }
    a._coef -= mon._coef;
    return a;
};

const int16_t* Monom::GetArray() const {
    return _powers;
}

Monom Monom::operator*(const Monom& mon) const{
    size_t mSize = std::max(this->_varcount, mon._varcount);
    int16_t* array = new int16_t[mSize];
    size_t minSize = std::min(this->_varcount, mon._varcount);
    for(size_t i = 0; i < mSize; i++){
        array[i]=0;
        if (i < _varcount) {
            array[i] += _powers[i]; 
        }
        if (i < mon._varcount) {
            array[i] += mon._powers[i]; 
        }
    }
    return Monom(_coef * mon._coef, mSize, array);
}

Monom Monom::operator/(const Monom& mon) const{
    if (mon._coef == 0) {
        throw "division on zero";
    }
    size_t mSize = std::max(this->_varcount, mon._varcount);
    int16_t* array = new int16_t[mSize]();
    size_t minSize = std::min(this->_varcount, mon._varcount);
    for(size_t i = 0; i < minSize; i++){
        array[i] = _powers[i] - mon._powers[i];
    }
    if(this->_varcount > mon._varcount){
        for(size_t i = minSize; i < this->_varcount; i++){
            array[i] -= _powers[i];
        } 
    }
    else{
        for(size_t i = minSize; i < mon._varcount; i++){
            array[i] -= mon._powers[i];
        } 
    }
    return Monom(_coef / mon._coef, mSize, array);
}

Monom::~Monom(){
    delete [] _powers;
}