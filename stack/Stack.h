#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* _array;
    size_t _size;
    size_t _top;
    bool _isEmpty = true;

    void Expand() {
        _size *= 2;
        T* arr = new T[_size];
        for (size_t i = 0; i < _size / 2; i++) arr[i] = _array[i];
        delete[] _array;
        _array = arr;
    }

    void Reduce() {
        _size = _top + 1;
        T* arr = new T[_size];
        for (size_t i = 0; i < _size; i++) arr[i] = _array[i];
        delete[] _array;
        _array = arr;
    }

public:

    Stack (size_t size) {
        _size = size;
        _top = 0;
        _array = new T[size];
    }

    Stack (){
        _size = 10;
        _top = 0;
        _array = new T[_size];
    }

    ~Stack (){
        delete [] _array;
        _array = nullptr;
    }

    inline bool isEmpty() const{
        return _isEmpty;
    }

    inline bool isFull() const{
        return (_top == _size - 1 && !_isEmpty);
    }
    
    void Push(const T& elem){
        if (_isEmpty) _isEmpty = false;
        else _top++;
        if (isFull()) Expand();
        _array[_top] = elem;
    }

    const T Pop(){
        if (_isEmpty) throw "bebrachka";
        if (_top == 0) {
            _isEmpty = true;
            return _array[_top];
        }
        if (_top * 2 <= _size  && _size > 100) Reduce();
        return _array[_top--];
    }
    
    const T Top() const{
        if (_isEmpty) throw "bebrachka";
        return _array[_top];
    }

    void Revers(){
        T* arr;
        arr = new T[_size];
        for (int i = 0; i < _top; i++){
            arr[i] = _array[_top - i];
        }
        _array = arr;
    }

    size_t GetSize(){
        return _top;
    }   
};
