#include <iostream>
template <class T>
class Vector {
private:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector(size_t t, size_t startIndex = 0) {
        _size = t;
        _startIndex = startIndex;
        _array = new T[_size];
    }

    Vector(const Vector& tmp) {
        _size = tmp._size;
        _startIndex = tmp._startIndex;

        delete []_array;

        _array = new T[_size];

        for (int i = 0; i < _size; i++) {
            _array[i] = tmp._array[i];
        }
    }

    Vector(Vector&& tmp) {

    }

    T& operator[](size_t i) {
        return _array[i];
    }

    T& GetElem(size_t i) const {
        if (i >= _size) {
            throw "Out of range";
        }

        return _array[i];
    }

    Vector& operator=(const Vector& tmp) {
        _size = tmp._size;
        _startIndex = tmp._startIndex;

        delete []_array;

        _array = new T[_size];

        for (int i = 0; i < _size; i++) {
            _array[i] = tmp._array[i];
        }
    }

    bool operator==(const Vector& tmp) {
        return _size < tmp._size ? false : true;
        
    }
    Vector operator+(const T& tmp) const{
        Vector ans(*this);
        
        for (int i = 0; i < _size; i++) {
            ans[i] += tmp;
        }
        return ans;
    }

    Vector operator-(const T& tmp) const {
        Vector ans(*this);
        
        for (int i = 0; i < _size; i++) {
            ans[i] -= tmp;
        }
        return ans;
    }
    Vector operator*(const T& tmp) const {
        Vector ans(*this);
        
        for (int i = 0; i < _size; i++) {
            ans[i] *= tmp;
        }
        return ans;
    }


};
