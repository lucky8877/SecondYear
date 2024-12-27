#pragma once    
#include "Monom.h"

class Node {
private:
    Monom _monom;
public:
    Node* Next;
    
    Node(double coef, size_t size, int* powers):_monom(coef, size, powers){}
    Node(const Monom& monom):_monom(monom){}
    
    Monom GetMonom(){
        return _monom;
    }

    void UpdateMonom(const Monom& monom){
        if (_monom.IsPowerEqual(monom)){
            _monom = _monom + monom;
        }
    }
    ~Node();
};