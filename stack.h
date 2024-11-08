#include <iostream>

template <typename T>

class Stack {
    private:
        T* _array;
        size_t _size;
        size_t _top;
        bool _isEmpty = true;

        void Expand() {
            T *arr;
            arr = new T[_size * 2];
            for (size_t i = 0; i <=_size; i++) {
                arr[i] = _array[i];
            }
        delete [] _array;
        _array = arr;
        }

    bool IsFull(){
        return (_top == _size - 1) && _isEmpty; 
    }

    void Reduce() {
        if (_top > _size * 2 || _top < 100) {
            return;
        }

        T* arr;
        T* arr = new T[_size / 2];
        for (size_t i = 0; i <=_top + 1; i++) {
            arr[i] = _array[i];
        }
        delete [] _array;
        _array = arr;
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
                _top++;
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
                _top--;
            
            return _array[_top + 1];
        }

        T Check(T *elem) const {
            if (_isEmpty) throw "stack is empty";
            return _array[_top];
        }

        T* GetArray() {
            return _array;
        }

        size_t GetTop() {
            return _top;
        }

        std::ostream& Stack<T> operator<<(std::ostream& out, const Stack<T>& st) {
            return out;
        }
};

