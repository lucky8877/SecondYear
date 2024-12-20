#pragma once
#include <iostream>
#include <iomanip>
#include <optional>
using namespace std;

template<typename T1, typename T2>
class Table{
private:
    string _titleCol1;
    string _titleCol2;
    size_t _table_size;
    optional<T1>* _col1;
    optional<T2>* _col2;
    size_t _count;
public:
    Table(string s1, string s2,size_t size){
        _titleCol1=s1;
        _titleCol2=s2;
        _table_size=size;
        _col1=new optional<T1>[_table_size];
        _col2=new optional<T2>[_table_size];
        _count =0;

    }
    void AppendRow(optional<T1> elem1, optional<T2> elem2){
        _col1[_count]=elem1;
        _col2[_count]=elem2;
        _count++;

    }

    T2 GetElemFromCol2(size_t row){
        return _col2[row].value();
    }

    T1 GetElemFromCol1(size_t row){
        return _col2[row].value();
    }

    void Print(){
        cout <<"|"<<setw(5)<< this->_titleCol1<<" | "<<setw(5)<<this->_titleCol2<<"|"<<endl;
        for (size_t i=0;i<15;i++){
            cout<<"-";
        }
        cout<<endl;
        
        for(size_t i=0; i<this->_count;i++){
            if(this->_col1[i]==nullopt){
                cout<<setw(5)<<"no";
            }
            else
            cout<<setw(5)<<this->_col1[i].value();
            cout<<"|";
            if(this->_col2[i]==nullopt){
                cout<<setw(5)<<"no";
            }
            else
            cout<<setw(5)<<this->_col2[i].value();
            cout<<endl;

        }
         for (size_t i=0;i<15;i++){
            cout<<"-";
        }
    }

};