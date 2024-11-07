#include "BitField.h"


size_t BitField::GetMemIndex(size_t n) const{
    if (n >= _sizeBit) {
        throw "Bit out of range";
    }
    return n / (8 * sizeof(uint16_t));

}

uint16_t BitField::GetMask(size_t n) const {
    return 1 << (n % (8 * sizeof(uint16_t)));
}

BitField::BitField(size_t len) {
    _sizeBit = len;
    _memSize = (len / (8 * sizeof(uint16_t))) + (len % (8 * sizeof(uint16_t)) != 0);
    _mem = new uint16_t[_memSize];  
    for (size_t i = 0; i < _memSize; i++) {
        _mem[i] = 0;
    }
}

BitField::BitField(const BitField& tmp) {
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = new uint16_t[_memSize];
    for (size_t i = 0; i < _memSize; i++) {
        _mem[i] = tmp._mem[i];
    }
}

BitField& BitField::operator=(const BitField& tmp) {
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    delete [] _mem;
    _mem = new uint16_t[_memSize];

    for (size_t i = 0; i < _memSize; i++) {
        _mem[i] = tmp._mem[i];
    }
    return *this;
}
    
size_t BitField::GetLength() const {
    return _sizeBit;
}

void BitField::SetBit(size_t n) {
    _mem[GetMemIndex(n)] |= GetMask(n);
}

void BitField::ClrBit(size_t n) {
    uint16_t mask = GetMask(n);
    mask =~ mask;
    _mem[GetMemIndex(n)] &= mask;
}

uint8_t BitField::GetBit(size_t n) const {
    return (_mem[GetMemIndex(n)] & GetMask(n)) != 0;
}
BitField BitField::operator|(const BitField& tmp) {
    BitField Bf(*this);
    for (size_t i = 0; i < _memSize; i++) {
        Bf._mem[i] = _mem[i] | tmp._mem[i];
    }
    return Bf;
}

BitField BitField::operator&(const BitField& tmp) {
    BitField Bf(*this);
    for (size_t i = 0; i < _memSize; i++) {
        Bf._mem[i] = _mem[i] & tmp._mem[i];
    }
    return Bf;
}

BitField BitField::operator^(const BitField& tmp) {
    BitField Bf(*this);
    for (size_t i = 0; i < _memSize; i++) {
        Bf._mem[i] = _mem[i] ^ tmp._mem[i];
    }
    return Bf;
}

bool BitField::operator==(const BitField& tmp) const{
    // uint8_t mx = _memSize > tmp._memSize ? _memSize: tmp._memSize;
    for (size_t i = 0; i < _memSize; i++) {
        if (_mem[i] != tmp._mem[i]) 
            return false;
    }
    return true;
}

BitField BitField::operator~(){
     BitField tmp(*this);
    for (size_t i=0; i<_sizeBit; i++){
        if (GetBit(i))
            tmp.ClrBit(i);
        else
            tmp.SetBit(i);  
    }
    return tmp;
}