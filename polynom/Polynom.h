#pragma once
#include "Node.h"

class Polynom{
private:
    Node* _head = nullptr;

public:

    Polynom(){
    }

    void AppendMonom(double coef, size_t size, int* powers){
        Node* NewMonom = new Node(coef, size, powers);
        if (_head == nullptr){   
            _head = new Node(coef, size, powers);
            return;
        }
        Node* tmp =_head;
        while (tmp->Next != nullptr){
            tmp->UpdateMonom(NewMonom->GetMonom());
            tmp = tmp->Next;
        }
        tmp->Next =  NewMonom;
    }

    void AppendMonom(const Monom& monom){
        Node* NewMonom = new Node(monom);
        if (_head == nullptr) {  
            _head = new Node(monom);
            return; 
        }
        Node* tmp =_head;
        while (tmp->Next != nullptr){
            tmp->UpdateMonom(NewMonom->GetMonom());
            tmp = tmp->Next;
        }
        tmp->Next =  NewMonom;

    }

    Polynom(const Polynom& polynom){
        if (polynom._head != nullptr){
            Node* tmpPolynom = polynom._head;
            Node* tmp = _head;
            while (tmpPolynom->Next != nullptr){
                AppendMonom(tmpPolynom->GetMonom());
                tmpPolynom = tmpPolynom->Next;
            }
        }
    }

    Polynom operator/(const Polynom& polynom) const {
        Polynom res;
        Polynom temp1(*this);
        Polynom temp2;
        Monom m1 = temp1.MaxMonom();
        Monom m2 = polynom.MaxMonom();
        while(m1 >= m2){
            Monom m = m1 / m2;
            res.AppendMonom(m);
            Polynom* temp3 = new Polynom;
            temp3->AppendMonom(m);
            temp2 = *temp3 * polynom;
            temp1 = temp1 - temp2;
            delete temp3;
            m1 = temp1.MaxMonom();
        }
        return res;
    }

    Monom MaxMonom() const{
        Monom m = _head->GetMonom();
        Node* temp = _head->Next;
        while (temp != nullptr){
            if (temp->GetMonom() >= m){
                m = temp->GetMonom();
            }
            temp = temp->Next;
        }
        return m;
    }

    Polynom operator-(const Polynom& polynom) const {
        Polynom res(*this);
        Node* rightPolynom = polynom._head;

        while (rightPolynom != nullptr) {
            res.AppendMonom(rightPolynom->GetMonom() * (-1));
            rightPolynom = rightPolynom->Next;
        }
        return res;
    }

    
    Polynom operator+(const Polynom& polynom) const{
        Polynom result(*this);
        Node* tmpPolynom = polynom._head;
        while (tmpPolynom->Next != nullptr) result.AppendMonom(tmpPolynom->GetMonom());
        return result;
    }

    Polynom operator*(const Polynom& polynom) const{
        Polynom result(*this);
        Node* tmpPolynom = polynom._head;
        Node* thisPolynom = _head;
        while (thisPolynom->Next != nullptr)
            while (tmpPolynom->Next != nullptr)
                result.AppendMonom(Monom(thisPolynom->GetMonom() * tmpPolynom->GetMonom()));
            
        return result;
    }

};