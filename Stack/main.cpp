#include "Stack.h"
#include "Formula.h"
#include "CorrectChecker.h"
#include "Table.h"
#include <optional>

std::optional<std::string> create(bool b){
    if(b)
        return "ghh";
    return std::nullopt;
}

int main(){
    std::string s = "10+a^12";
    CorrectChecker checker;
    std::cout << checker.CheckFormula(s) << std::endl;
    CorrectChecker y;
    y.FillVariable(s);
    Table VarTable = y.GetVarTable();
    Formula g(s);
    double res = g.Calculate(VarTable);
    std::cout << res << std::endl;
}
