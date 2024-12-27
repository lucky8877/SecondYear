#include <iostream>
#include "Polynom.h"

int main(){

    Polynom p1;
    Monom m1 = Monom(1.0, 1, new int16_t[1]{2});
    Monom m2 = Monom(-2.0, 1, new int16_t[1]{1});
    Monom m3 = Monom(1.0, 1, new int16_t[1]{0});
    p1.AppendMonom(m1);
    p1.AppendMonom(m2);
    p1.AppendMonom(m3);
    std::cout<<"первый полином: ";
    p1.Print();

    Polynom p2;
    Monom m4 = Monom(1.0, 1, new int16_t[1]{1});
    Monom m5 = Monom(0, 1, new int16_t[1]{0});
    p2.AppendMonom(m4);
    p2.AppendMonom(m5);  
    std::cout<<"второй полином: ";
    p2.Print();
    
    Polynom p3;
    p3 = p1/ p2;
    std::cout<<"результат: ";
    p3.Print();
}
