#include <iostream>
#include <string>
#include <iomanip>
template<typename T2, typename T1>
class Table {
private:
    size_t _size;
    size_t count;
    T1* _col1;
    T2* _col2;
    std::string _title1;
    std::string _title2;
public:
    Table(std::string title1, std::string title2,size_t size = 10){
        _size = size;
        count = 0;
        _title1 = title1;
        _title2 = title2;
        _col1 = new T1[size];
        _col2 = new T2[size];
    }
    ~Table(){
        delete[] _col1;
        delete[] _col2;
        _col1 = nullptr;
        _col2 = nullptr; 
    }
    /// @brief функция для добавления элементов в строку
    /// @param elem1 элемент 1-го столбца
    /// @param elem2 элемент 2-го столбца
    void AppendRow(T1 elem1, T2 elem2) {
        _col1[count] = elem1;
        _col2[count] = elem2;
        if (count + 1 > _size) throw;
        count++;
    }

    void Print(){
        size_t flag = 5;
        std::cout<<"+";
        for (int i = 0; i < flag * 2 + 1; i++) {
            if (i == flag) {
                std::cout<<"+";
            }
            std::cout<<"-";
        }
        std::cout<<"+"<<std::endl;
        std::cout<<"|" <<std::setw(flag) << _title1 << "|" <<std::setw(flag) <<_title2 <<"|"<<std::endl; 

    }
};