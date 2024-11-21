#include "BitField.h"

int main() {
    BitField s(10);
    s.SetBit(0);
    s.SetBit(3);
    s.SetBit(5);
    s.SetBit(9);
    BitField r = s<<2;
    BitField r1 = s>>2;
    return 0;
}