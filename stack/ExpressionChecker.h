#pragma once
#include "Stack.h"
#include "Table.h"

class ExpressionChecker{
private:
    Table<string, double> _valTab;
    Table<int, int> _bracketTab;
    Stack<int> _misArithm;
    Stack<int> _misBrac;

public:
    bool CheckBrackets(const string& s);
    bool CheckFormula(const string& s);
    void PrintMistakes(const string& s);
};