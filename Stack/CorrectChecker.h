#pragma once
#include "Stack.h"
#include "Table.h"

class CorrectChecker{
private:
    Stack<int> _brackets;
    Table<char, double> _varTable;
    Table<int, int> _brecketsTable;
    bool _state = false;
public:
    CorrectChecker();
    bool CheckBrackets(const std::string& s);
    bool CheckVariable();
    bool GetState();
    // void FillVariable(const std::string& s);
    // bool CheckFormula(const std::string& s); 
    // const Table<char, double>& GetVarTable() const;
};
