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
            this->_array[i] = Vector<T>(n);
        }
    }

    size_t GetSize() const {
        return  Vector<Vector<T>>::GetSize();
    }

    Matrix& operator=(const Matrix& mt) {
        if (this != &mt) {
            for(size_t i = 0; i<GetSize(); i++){
            this->_array[i] = mt._array[i];
        }
        }
        return *this;
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
    
    Vector<T>& operator[](size_t i) {
        return this->_array[i];
    }

    Matrix operator*(const Matrix& mt) {
        Matrix res(mt.GetSize());
        for (size_t i = 0; i < mt.GetSize(); i++) {
            for (size_t j = 0; j < mt.GetSize(); j++) {
                res._array[i][j] = 0;
                for (size_t k = i; k < mt.GetSize(); k++) {
                    res._array[i][j] += this->_array[i][k] * mt._array[k][j];
                }
            }
        }
        return res;
    }

     Matrix Pow(size_t n) const {
        if (n == 0) {
            Matrix identity(this->GetSize());
            for (size_t i = 0; i < this->GetSize(); i++) {
                identity[i][i] = 1;
            }
            return identity;
        }

        Matrix result = *this; 
        Matrix base = *this;   

        for (size_t i = 1; i < n; i++) {
            result = result * base;
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mt){
        for (size_t i = 0; i < mt.GetSize(); i++){
            for (size_t j = 0; j < mt.GetSize(); j++) {
                os << mt._array[i][j]<<" ";
            }
            os << std::endl;
        }
        return os;
    }
};
