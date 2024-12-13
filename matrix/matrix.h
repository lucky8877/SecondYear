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
    
    Vector<T>& operator[](size_t i) {
        return this->_array[i];
    }

   
    Matrix operator*(const Matrix& mt) {
        Matrix res(mt.GetSize());
        for (size_t i = 0; i < mt.GetSize(); i++) {
            for (size_t j = 0; j < mt.GetSize(); j++) {
                res._array[i][j] = 0;
                for (size_t k = 0; k < mt.GetSize(); k++) {
                    res._array[i][j] += this->_array[i][k] * mt._array[k][j];
                }
            }
        }
        return res;
    }

    
    void Pow(size_t degree) {
        Matrix res = *this;
        cout<<res*res*res;
        Matrix fin(res.GetSize());
        for (int i = 0; i < degree; i++) {
            res = &(res * res);
            cout<<res;
        }
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
