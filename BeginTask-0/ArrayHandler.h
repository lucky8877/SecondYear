template<typename T>
class ArrayHandler {
public:
    inline void AppendElem(T elem) const {

    }
    inline T GetMax() const{
        if (sizeof(T) == 1) {
            return 10;
        } else {
            return 1000000010;
        }
    }
    inline T GetMin()  const{
            if (sizeof(T) == 1) {
            return 1;
        } else {
            return 0;
        }
    }
};