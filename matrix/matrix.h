#pragma once
#include "vector.h"
// операция возведения в степень для матрицы
using namespace std;
template <class T>
class Matrix: public Vector<Vector<T>>{
public:
    Matrix(size_t n): Vector<Vector<T>>(n, 0)
    {
        for(size_t i = 0; i<n; i++){
            this->_array[i] = Vector<T>(n-i,i);
        }
    }

    size_t GetSize() const {
        return  Vector<Vector<T>>::GetSize();
    }
    Matrix& operator=(const Matrix& mt){
        return Vector<Vector<T>>::operator=(mt);
    }

    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }

    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }

    Matrix operator/(const T& elem){
        return Vector<Vector<T>>::operator/(elem);
    }

    Matrix operator*(const Matrix& mt) {
        Matrix res(this->_size);
        for (size_t i = 0; i < this->_size; i++) {
            for (size_t j = i; j < this->_size; j++) {
                res._array[i][j] = 0;
                for (size_t k = 0; k < this->_size; k++) {
                    res._array[i][j] += this->_array[i][j] + mt._array[i][j];
                }
            }
        }
        return res;
    }

    friend ostream& operator<<(ostream& os, const Matrix& mt){
        for (int i = 0; i < this->._size; i++){
            os << 1<<endl;
        // os << "|";
        //     for (size_t j = 0; j < i; j++) 
        //         os << "0, ";
        // os << mt._array[i] << "|" << endl;
        }
        return os;
    }
};
