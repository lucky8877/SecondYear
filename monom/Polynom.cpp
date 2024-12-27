#include "Polynom.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

Polynom::Polynom() {
    _head = nullptr;
}

Polynom& Polynom::operator=(const Polynom& tmp) {
    Node* rp = tmp._head;
    Node* lp = _head;

    while(lp != nullptr){
        Node* next = lp->Next;
        delete lp;
        lp = next;
    }
    if(this == &tmp) return *this;
    if(tmp._head != nullptr){
        _head = new Node(rp->GetMonom());
        lp = _head;
        while(rp->Next != nullptr){
            lp->Next = new Node(rp->Next->GetMonom());
            lp = lp->Next;
            rp = rp->Next;
        }
    }
    return *this;
}

Polynom::Polynom(const Polynom& tmp) {
    if(tmp._head!=nullptr){
        _head=new Node(tmp._head->GetMonom());
        Node* tmp_next=tmp._head->Next;
        Node* current = _head;
        while(tmp_next!=0){
            current->Next=new Node(tmp_next->GetMonom());
            current=current->Next;
            tmp_next=tmp_next->Next;

        }
    }
}

Polynom::~Polynom() {
  Node* current = _head;
  while (current != nullptr) {
    Node* next = current->Next;
    delete current;
    current = next;
  }
  _head = nullptr;
}

void Polynom::AppendMonom(Monom monom) {
    if (_head == nullptr) {
        _head = new Node(monom);
        return;
    } 
        Node* tmp = _head;
        while (tmp->Next != nullptr) {
            if (tmp->GetMonom().CanOperate(monom)) {
                Monom result = tmp->GetMonom() + monom;
                tmp->SetMonom(result);
                return ;
            }
            tmp = tmp->Next;
        }
        if (tmp->GetMonom().CanOperate(monom)) {
                Monom result = tmp->GetMonom() + monom;
                tmp->SetMonom(result);
                return ;
            }
        else
            tmp->Next = new Node(monom);
}


void Polynom::Print() {
    Node* tmp = _head;
    int pr_flag=0;
    while (tmp != nullptr) {
        if (tmp == _head ){
            if(tmp->GetMonom().GetCoef()!=0){
                tmp->GetMonom().print();
                pr_flag++;
            }
        }
        else {
            if (tmp->GetMonom().GetCoef() > 0){
                if (pr_flag!=0)
                    std::cout << " +";
            }
            if (tmp->GetMonom().GetCoef() !=0){
                std::cout<<" ";
                tmp->GetMonom().print();
            }
        }
        tmp = tmp->Next;
    }
    std::cout<<std::endl;
}

Polynom Polynom::operator+(const Polynom& polynom) const {
    Polynom res(*this);
    Node* rightPolynom = polynom._head;

    while (rightPolynom != nullptr)
    {
        res.AppendMonom(rightPolynom->GetMonom());
        rightPolynom = rightPolynom->Next;
    }
    return res;
}

Polynom Polynom::operator-(const Polynom& polynom) const {
    Polynom res(*this);
    Node* rightPolynom = polynom._head;

    while (rightPolynom != nullptr) {
        Monom negatedMonom = rightPolynom->GetMonom();
        negatedMonom.SetCoef(negatedMonom.GetCoef()*-1); 
        res.AppendMonom(negatedMonom);
        rightPolynom = rightPolynom->Next;
    }
    return res;
}

Polynom Polynom::operator*(const Polynom& polynom) const {
    Node* rightPolynom = polynom._head;
    Polynom res=Polynom();
    while ((rightPolynom!=nullptr)){
        Node* left_polynom=_head;
        Monom right_mon=rightPolynom->GetMonom();
        while (left_polynom!=nullptr){
            Monom mon=(left_polynom->GetMonom())*right_mon;
            res.AppendMonom(mon);
            left_polynom=left_polynom->Next;
        }
        rightPolynom=rightPolynom->Next;
        
    }
    
    return res;
}

Polynom Polynom::operator*(const Monom& mon) const{
    Polynom res=Polynom();
    Node* tmp=_head;
    while(tmp!=nullptr){
        res.AppendMonom(tmp->GetMonom()*mon);
        tmp=tmp->Next;
    }
    return res;
}

bool Polynom::compareMonoms(const Monom& monom1, const Monom& monom2) {
    int aSum = 0;
    int bSum = 0;
    if(monom2.GetCoef() == 0 && monom1.GetCoef() != 0)
        return true;
    if(monom2.GetCoef() != 0 && monom1.GetCoef() == 0)
        return false;
    if(monom2.GetCoef() == 0 && monom1.GetCoef() == 0)
        return false;
    for (size_t i = 0; i < monom1.GetSize(); i++) {
        aSum += monom1.GetArray()[i];
        bSum += monom2.GetArray()[i];
    }
    if (aSum > bSum )
        return true;
    if(aSum == bSum){
        for (size_t i = 0; i < monom1.GetSize(); ++i) {
            if (monom1.GetArray()[i] >= monom2.GetArray()[i]) {
                return true;
            } 
            else {
                if (monom1.GetArray()[i] < monom2.GetArray()[i]) 
                    return false;
            }
        }
    }
        
    return false;

}

Monom Polynom::getLeadingMonom() const {
        if (_head == nullptr) {
            return Monom(0,0,nullptr);
        }
        Node* current = _head;
        Monom leadingMonom = _head->GetMonom();
        while (current != nullptr) {
            if (compareMonoms(current->GetMonom(), leadingMonom)) {
                leadingMonom = current->GetMonom();
            }
            current = current->Next;
        }
        return leadingMonom;
    }

Polynom Polynom::operator/(const Polynom& divisor) const {
    if(divisor._head == nullptr){
        throw "-";
    }
    Polynom dividend(*this);
    Polynom res;
    if(!compareMonoms(dividend.getLeadingMonom(),(divisor.getLeadingMonom())))
        throw "-";
    while(compareMonoms(dividend.getLeadingMonom(),(divisor.getLeadingMonom()))){
        Monom monom1 = dividend.getLeadingMonom();
        Monom monom2 = divisor.getLeadingMonom();
        Monom s = monom1/monom2;
        if(s.GetCoef() != 0){
            res.AppendMonom(s);
            Polynom newdividend = dividend - (divisor*s);
            dividend = newdividend;
        }
    }
    Polynom result = res;
    std::cout << "остаток:";
    dividend.Print();
    return result;

}