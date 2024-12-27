#pragma once
#include "Node.h"

class Polynom {
private:
    Node* _head;

public:
    Polynom();
    Polynom(const Polynom& tmp);
    ~Polynom();
    
    void AppendMonom(Monom monom);
    void Print();
    void sortPolynom();
    Polynom operator+(const Polynom& polynom) const;
    Polynom operator-(const Polynom& polynom) const;
    Polynom operator*(const Polynom& polynom) const;
    Polynom operator/(const Polynom& polynom) const;
    Polynom operator*(const Monom& mon) const;
    Polynom& operator=(const Polynom& polynom);

    Monom getLeadingMonom() const ;
    static bool compareMonoms(const Monom& a, const Monom& b);
};