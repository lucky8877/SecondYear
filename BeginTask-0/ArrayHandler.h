#include <iostream>

using namespace std;

template <typename T>
class ArrayHandler
{

    private:
        size_t size = 0;
        size_t capacity = 101;
        T* arr = new T[capacity];
        T mx;
        T mn;
    public:

        // ArrayHandler() {
        //     size = 0;
        //     capacity = 101;
        //     arr = new T[capacity];
        // };

        void AppendElem(T elem) {
            if (size == capacity) {
                capacity = (capacity == 0) ? 1: capacity * 128;
                T* newarr = new T[capacity];
                for (size_t i = 0; i < size; i++) {
                    newarr[i] = arr[i];
                };
                delete []arr;
                arr = newarr;
            };
            if (size == 0) {
                mx = elem;
                mn = elem;
            }else {
                if (elem > mx) {
                    mx = elem;
                }
                if (elem < mn) {
                    mn = elem;
                }
            }
            arr[size] = elem;
            size++;                
        };
        
        T GetMax() {
        return mx;
        }

        T GetMin() {
        return mn;
        }

        bool IsContains(T elem) {
            for (size_t i = 0; i < size; i++) {
                if (arr[i] == elem)
                    return 1;
            };
            return 0;
        };
                
        T &operator[] (int i) {
            return arr[i];
        };

        ~ArrayHandler(){
            size = 0;
            capacity = 0;
            delete []arr;
        };
        
};