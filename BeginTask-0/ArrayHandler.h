#include <type_traits>

template<typename T>
class ArrayHandler {
public:
    void AppendElem(T elem) {

    }
    inline T GetMax() const{
        if (std::is_same<T,uint8_t>::value) {
            return 10;
        } else {
            return 1000000010;
        }
    }
    inline T GetMin()  const{
            if (std::is_same<T,uint8_t>::value) {
            return 1;
        } else {
            return 0;
        }
    }
};