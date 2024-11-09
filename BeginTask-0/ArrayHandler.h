template<typename T>
class ArrayHandler {
private:
  T* _array;
  size_t _len;
  size_t _capacity;
  T mn;
  T mx;

public:
  ArrayHandler(size_t capacity=10) {
    _len = 0;
    _capacity = capacity;
    _array = new T[_capacity];
  }

  void AppendElem(T elem) {
    if (_len == 0) { 
      mn = elem;
      mx = elem;
    }

    if (_len == _capacity) {
      _capacity = _capacity * 2;

      T* tmp = new T[_capacity];
      for (size_t i = 0; i < _len; i++) {
        tmp[i] = _array[i];
      }

      delete []_array;
      _array = tmp;
    }

    if (mx < elem) {
      mx = elem;
    }
    if (mn > elem) {
      mn = elem;
    }
    
    _array[_len] = elem;
    _len++;
  }

  T GetMax() {
    return mx;
  }

  T GetMin() {
    return mn;
  }

};

