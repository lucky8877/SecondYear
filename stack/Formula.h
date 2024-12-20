#pragma once
#include <string.h>
#include <set>
#include "Stack.h"
#include "Table.h"
#include "ExpressionChecker.h"


class Formula {
private:
    string _expr;
    string _postfix;
    Stack<char> _opStack;
    Table<char,int> _prior;
    Table<char, double> _unknow;
    set<char> _set;
    size_t _num_of_un;

public:
    Formula(string exp, size_t num_of_un);
    void FormulaConverter(size_t num_of_un);
    double FormulaCalculator();
};






