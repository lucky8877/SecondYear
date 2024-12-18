#include "BitField.h"


size_t BitField::GetMemIndex(size_t n) const{
    if (n >= _sizeBit) {
        throw "bit out of range";
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

// BitField::~BitField() {
//     delete [] _mem;
//     _mem = nullptr;
//     _memSize = 0;
//     _sizeBit = 0;
// }

BitField& BitField::operator=(const BitField& tmp) {

    if (_sizeBit != tmp._sizeBit) {
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        delete [] _mem;
        _mem = new uint16_t[_memSize];
    }


    for (size_t i = 0; i < _memSize; i++) {
        _mem[i] = tmp._mem[i];
    }

    return *this;
}
    
size_t BitField::GetLength() const {
    return _sizeBit;
}

void BitField::SetBit(size_t n) {
    // if (n <= _sizeBit) {
    _mem[GetMemIndex(n)] |= GetMask(n);
//     } else {
//         throw "SetBit error";
//     }    
// }
}

void BitField::ClrBit(size_t n) {
    // uint16_t mask = GetMask(n);
    // mask =~ mask;
    _mem[GetMemIndex(n)] &= ~GetMask(n);
    
}

uint8_t BitField::GetBit(size_t n) const {
    return ((_mem[GetMemIndex(n)] & GetMask(n)) != 0);
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
        // _mem[i] = ~_mem[i];
    }
    return tmp;
}

BitField BitField::operator<<(size_t n) {
    size_t size = _sizeBit + n;
    BitField tmp(size);
    for (size_t i = 0; i < _sizeBit; i++) {
        if (GetBit(i) == 1) {
            tmp.SetBit(i);
        }
    } 
    //     for (size_t i = 0; i < _sizeBit; i++) {
    //         std::cout<<+GetBit(i)<<"";

    // }
    // std::cout<<"\n";
    // for (size_t i = 0; i < tmp._sizeBit; i++) {
    //         std::cout<<+tmp.GetBit(i)<<"";

    // }
    // std::cout<<"\n";
    return tmp;
}

BitField BitField::operator>>(size_t n) {
    size_t size = _sizeBit - n;
    BitField tmp(size);
    for (size_t i = 0; i < tmp._sizeBit; i++) {
        if (GetBit(i) == 1) {
            tmp.SetBit(i);
        }
    }

    // for (size_t i = 0; i < _sizeBit; i++) {
    //     std::cout<<+GetBit(i)<<"";

    // }
    // std::cout<<"\n";
    // for (size_t i = 0; i < tmp._sizeBit; i++) {
    //         std::cout<<+tmp.GetBit(i)<<"";

    // }

    // std::cout<<"\n";
    return tmp;
}