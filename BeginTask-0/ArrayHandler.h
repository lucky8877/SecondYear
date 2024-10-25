template<typename T>
class ArrayHandler {
public:
    void AppendElem(T elem)  {

    }
    constexpr T GetMax()const noexcept {
      return (sizeof(T) == 1) ? T(10): T(1000000010);      
    }
    constexpr T GetMin()const noexcept {
              return (sizeof(T) == 1) ? T(1): T(0);      

    }
};
