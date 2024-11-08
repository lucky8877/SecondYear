#include <iostream>

template <typename T>

class Stack {
    private:
        T* _array;
        size_t _size;
        size_t _top;
        bool _isEmpty = true;

        void Expand() {
            T* arr;
            T* arr = new [_size * 2];
            for (size_t i = 0; i <=size; i++) {
                arr[i] = _array[i];
            }
        delete [] _array;
        __array = arr;
        }

    bool IsFull(){
        return (top == size - 1) && _isEmpty; 
    }

    void Reduce() {
        if (top > _size * 2 || _top < 100) {
            return
        }

        T* arr;
        T* arr = new [_size / 2];
        for (size_t i = 0; i <=top + 1; i++) {
            arr[i] = _array[i];
        }
        delete [] _array;
        __array = arr;
    }



    public:
        Stack(size_t size = 10) {
            _size = size;
            _top = 0;
            _array = new T[_size];
        }

        void Push(T elem) {
            if (_isEmpty) {
                _isEmpty = false;
            }else {
                top++;
            }
            
            if (IsFull()) Expand();

            _array[_top] = elem;
        }

        T Pop(T elem) {
            if (_isEmpty) 
                throw "stack is empty";

            if (!_top) 
                _isEmpty = true;
            else 
                top--;
            
            return _array[top + 1];
        }

        T Check(T *elem) const {
            if (_isEmpty) throw "stack is empty";
            return _array[_top];
        }

        T* GetArray() {
            return _array;
        }

        std::ostream& operator<<(std::ostream& out, const Stack& st) {
        
        }
};

