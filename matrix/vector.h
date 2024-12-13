#include <iostream>
template <class T>
class Vector {
private:
    size_t _size;
    size_t _startIndex;
public:
    T* _array;

    Vector() {
        _size = 0;
        _startIndex = 0;
        _array = new T[_size];
    }
    Vector(size_t t, size_t startIndex = 0) {
        _size = t;
        _startIndex = startIndex;
        _array = new T[_size];
    }

    Vector(const Vector& tmp) {
        _size = tmp._size;
        _startIndex = tmp._startIndex;

        _array = new T[_size];

        for (int i = 0; i < _size; i++) {
            _array[i] = tmp._array[i];
        }
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

    size_t GetSize() const{
        return _size;
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

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec){
        for (size_t j = 0; j < vec.GetSize(); j++) {
            os << vec._array[j]<<" ";
        }
        os << std::endl;
        return os;
    }
};
