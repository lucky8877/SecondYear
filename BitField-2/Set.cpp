#include "Set.h"


Set::Set(size_t mp) : _bitField(mp), _maxPower(mp) {

}
Set::Set(const Set &s) : _bitField(s._bitField), _maxPower(s._maxPower){

} 
Set::Set(const BitField &bf) : _bitField(bf), _maxPower(bf.GetLength()){

}

size_t Set::GetMaxPower() const{
    return _maxPower;
}

void Set::InsElem(const uint64_t Elem){
    _bitField.SetBit(Elem);
}
void Set::DelElem(const uint64_t Elem){
    _bitField.ClrBit(Elem);
}
bool Set::IsMember(const uint64_t Elem) const{
    return _bitField.GetBit(Elem);
}


bool Set::operator== (const Set &s) const{
    return s._bitField == _bitField;
}
bool Set::operator!= (const Set &s) const{
    return (s._bitField == _bitField) != 1;
}

Set& Set::operator=(const Set &s){
    _maxPower = s.GetMaxPower();
    _bitField = s._bitField;
    return *this;
}
Set Set::operator+ (const uint64_t Elem){
    Set res(*this);
    res.InsElem(Elem);
    return res;
}
                                  
Set Set::operator- (const uint64_t Elem){
    Set res(*this);
    res.DelElem(Elem);
    return res;
}
                                   
Set Set::operator+ (const Set &s){
    return _bitField | s._bitField;
}
Set Set::operator* (const Set &s){
    return _bitField & s._bitField;
}
Set Set::operator~ (){
    return Set(~_bitField);
}
std::vector<uint64_t> Set::GetPrimary(){
    // return std::vector<uint64_t>();
    std::vector<uint64_t>finalVec;
    std::vector<bool>boolVec;

    for (size_t i = 0; i < _maxPower+1; i++) {
        boolVec.push_back(true);
    }

    boolVec[0] = false;
    boolVec[1] = false;

    for (size_t i = 2; i < _maxPower+1; i++) {
        if (boolVec[i] == true) {
        int j = i;
        while (j + i <= _maxPower) {
            j += i;
            boolVec[j] = false;
            }
        }
    }

    finalVec.push_back(1);
    for (int i = 0; i < _maxPower+1; i++) {
        if (boolVec[i] != false) {
            std::cout<<i<<"\n";
            finalVec.push_back(i);
        }
    }

    return finalVec;
}