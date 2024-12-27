#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class Monom {
private:
    double _coef;
    size_t _size;
    int* _powers;
public:
    Monom() : _coef(0), _size (0), _powers(new int [_size]){}
    
    Monom(double coef, size_t size, int* powers){
        _coef = coef;
        _size = size;
        _powers = powers;
    }

    Monom(const Monom& tmp){
        _coef = tmp._coef;
        _size = tmp._size;
        delete [] _powers;
        _powers = new int [_size];
        for (int i = 0; i < _size; i++){
            _powers[i] = tmp._powers[i];
        }
    }

    ~Monom() {
         delete [] _powers; 
         _powers = nullptr;
    }

    bool IsPowerEqual(const Monom& monom){
        if (_size != monom._size) return false;
        for (int i = 0; i < _size; i++){
            if (_powers[i] != monom._powers[i]) return false;
        }
        return true;
    }

    Monom& operator=(const Monom& tmp) {
        if(&tmp == this){
            return *this;
        }
        _coef = tmp._coef;
        _size = tmp._size;
        delete _powers;
        _powers = new int[_size];
        for (int i = 0; i < _size; i++){
            _powers[i] = tmp._powers[i];
        }
        return *this;
    }

    Monom operator+(const Monom& tmp) {
        if (_size != tmp._size) throw "Not equal size";

        for (int i = 1; i < _size; i++)
            if (_powers[i] != tmp._powers[i]) throw "Not equal powers";

        return Monom(_coef + tmp._coef, _size, _powers);
    }

    Monom operator-(const Monom& tmp) {
        if (_size != tmp._size) throw "Not equal size";
        
        for (int i = 1; i < _size; i++)
            if (_powers[i] != tmp._powers[i]) throw "Not equal powers";

        return Monom(_coef + tmp._coef, _size, _powers);
    }


    Monom operator*(const Monom& tmp) {
        size_t max_size = max(_size, tmp._size);
        size_t min_size = min(_size, tmp._size);
        int* new_powers = new int[max_size];
        int* tmp2 = (max_size == _size ? _powers:tmp._powers);

        for (int i = 1; i < max_size; i++){
            if (i < min_size)
                new_powers[i] = _powers[i] + tmp._powers[i];
            else 
                new_powers[i] =tmp2[i];
        }
        return Monom(_coef * tmp._coef, _size, new_powers);
    }
        
    Monom operator*(const int& elem) const{
       return Monom(_coef * elem, _size, _powers);
    }
    
    Monom operator/(const Monom& tmp) {
        size_t max_size = max(_size, tmp._size);
        size_t min_size = min(_size, tmp._size);
        int* new_powers = new int[max_size];
        int* tmp2 = (max_size == _size ? _powers:tmp._powers);

        for (int i = 1; i < max_size; i++){
            if (i < min_size)
                new_powers[i] = _powers[i] - tmp._powers[i];
            else 
                new_powers[i] = -tmp2[i];
        }
        return Monom(_coef / tmp._coef, _size, new_powers);
    }

    void Print(){

        if (_coef != 0){
            cout << _coef;

            for (int i = 0; i < _size; i++)
                cout << " x" << i << "^" << _powers[i];
                
        }
    }

    bool operator>=(const Monom& mon) const{
    for (int i = 0; i < _size; i++){
        if (_powers[i] < mon._powers[i]){
            return false;
        }
    }
    return true;
}

};