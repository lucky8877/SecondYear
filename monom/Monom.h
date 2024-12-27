#include <iostream>
#include <stdint.h>

class Monom{
private:
    double _coef;
    size_t _varcount;
    int16_t* _powers;
public:
    Monom(double coef, size_t size, int16_t* array);
    Monom(const Monom& monom);
    ~Monom();
    
    size_t GetSize()const;
    double GetCoef()const;
    void SetCoef(double coef);
    void print() const;    
    bool CanOperate(const Monom& monom) const;

    Monom& operator=(const Monom& monom);
    Monom operator+(const Monom& monom)const;
    Monom operator-(const Monom& monom)const;
    Monom operator*(const Monom& monom) const;
    Monom operator/(const Monom& monom) const;

    const int16_t* GetArray() const;
};