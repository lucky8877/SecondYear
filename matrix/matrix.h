#pragma once
#include "Vector.h"

template <class T>
class Matrix: public Vector<Vector<T>>
{
private:
    int _deg = 1;
public:
    Matrix(size_t n): Vector<Vector<T>>(n, 0)
    {
        for(size_t i = 0; i<n; i++){
            _array[i] = Vector<T>(n-i,i);
        } 
    }
    
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt) {}

    Matrix(const Vector<Vector<T>>& vv):Vector<Vector<T>>(vv) {}

    
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


    void PowTo_1(){
        _deg = -1;
        T det;
        
        for(int i = 0; i < this->_size; i++)  det *= this->_array[i].GetElem(0);

        Vector<T> tmp_vec;

        for (int i = 0; i < (this->_size)/2; i++ ){
            tmp_vec = this->_array[i];
            this->_array[i] = this->_array[(this->_size) - i - 1];
            this->_array[(this->_size) - i - 1] = tmp_vec;
        }

        this->operator/(det);
    }


    Matrix operator*(const Matrix& mt) {
        if (this->_size != mt._size) {
            throw invalid_argument("Matrices have incompatible sizes for multiplication.");
        }

        Matrix result(this->_size);

        for (size_t i = 0; i < this->_size; i++) { 
            for (size_t j = i; j < this->_size; j++) { 
                T sum = 0;

                for (size_t k = i; k <= j; k++) {
                    if ((k - i) < this->_array[i].GetSize() && (j - k) < mt._array[k].GetSize()) {
                        sum += this->_array[i][k - i] * mt._array[k][j - k];
                    }
                }

                result._array[i][j - i] = sum; 
            }
        }

        return result;
    }
