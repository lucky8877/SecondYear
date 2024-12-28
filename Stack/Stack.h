#pragma once
#include <iostream>

template <typename T>
class Stack{
private:
    T* _array;
    size_t _size;
    size_t _top; 
    bool _isEmpty = true; 
public:
    Stack(size_t size=10){
        _array = new T[size];
        _size = size;
        _top = 0;
    }
    bool IsEmpty() const{
        return _isEmpty;
    }
    bool IsFull() const{ 
        return _size-1 == _top&& ! _isEmpty;
    }
    void Push(T elem){ 
        if(IsFull())
            Expand(); 
        if(IsEmpty())
            _isEmpty = false;
        else _top++;

        _array[_top] = elem;
    }
    T Pop(){   
        if (_isEmpty)
            throw "Stack is empty";
        if (_top == 0){
            _isEmpty = true;
            return _array[_top];
        }    
        return _array[_top--];
    }
    T Check() const{
        return _array[_top];
    }

    void Expand(){
        T* arr = _array;
        delete [] _array;
        _array = new T[_size*2];
        
        for(size_t i = 0; i < _size; i++){
            _array[i] = arr[i];
        }
        _size = _size*2;
        delete [] arr;  
    }

    size_t GetLenght()const{
        return _size;
    }

    ~Stack(){
        delete [] _array;
    }


};