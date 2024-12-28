#pragma once
#include <iostream>
#include <iomanip>
#include <optional>
using namespace std;

template <typename T1, typename T2>

class Table{
private:
    size_t _tableSize;
    std::optional<T1>* _col1;
    std::optional<T2>* _col2;
    size_t _count;
    std::string _titleCol1;
    std::string _titleCol2;
public:
    Table(std::string titleCol1 = "h", std::string titleCol2 = "g", size_t size = 20){
        _titleCol1 = titleCol1;
        _titleCol2 = titleCol2;
        _tableSize = size;
        _col1 = new std::optional<T1>[_tableSize];
        _col2 = new std::optional<T2>[_tableSize];
        _count = 0;
    }
    std::optional<T2> operator[](T1 tmp){
        for(size_t i = 0; i < _tableSize; i++){
            if(tmp == _col1[i])
                return _col2[i];
        }
        return 0;
    }
    void AppendRow(std::optional<T1> t1, std::optional<T2> t2){
        _col1[_count] = t1;
        _col2[_count] = t2;
        _count++;
    }
    
    void Print(){
        std::cout << std::endl;
        for(size_t i = 0; i < 14; i++){
            std::cout << "~";
        }   
        std::cout << std::endl;
        std::cout << "| " << std::setw( 4 ) << this->_titleCol1 << "| " << setw( 5 ) << _titleCol2 << "| " << std::endl;
        for(size_t i = 0; i < 14; i++){
            std::cout << "~";
        }    
        std::cout << std::endl;
        for(size_t i = 0; i < _count; i++){
            if(_col1[i] == std::nullopt){
                std::cout << "| " << setw( 4 )  << "No" << "| " << setw( 5 ) <<  _col2[i].value() << "| " << endl;
            }
            else if (_col2[i] == std::nullopt)
                std::cout << "| " << setw( 4 )  << _col1[i].value() << "| " << setw( 5 ) << "No" << "| " << endl;
            else
                std::cout << "| " << setw( 4 )  << _col1[i].value() << "| " << setw( 5 ) <<  _col2[i].value() << "| " << endl;
           
        }
        for(size_t i = 0; i < 14; i++){
            std::cout << "~";
        }    
        std::cout << std::endl;
    }

    std::optional<T2> operator[](std::optional<T1> u){
        for(size_t i = 0; i < _tableSize; i++){
            if(u == _col1[i]) 
                return _col2[i];
        }
        return 0;
    }

    size_t GetCount()const{
        return _count;
    }

    std::optional<T1>* GetCol1(){
        return _col1;
    }

    std::optional<T2>* GetCol2(){
        return _col2;
    }

};
