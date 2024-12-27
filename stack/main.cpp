#include <iostream>
#include <string>
#include "Stack.h"
#include "Table.h"
#include "Formula.h"


int main(){
    Table<int,int> table("(",")", 10);
    table.AddRow(std :: nullopt, 10);
    table.AddRow(5,7);
    table.AddRow(71,99);

    Table<char,char> t2("A","B",10);
    t2.AddRow('3','3');
    t2.AddRow('2','1');
    t2.AddRow('3','6');
    t2.AddRow('3','4');

    Formula f("2 + af * 801");
    f.BuildPostFix();
    std::string n = f.GetExpression(); 
    std::string n1 = f.GetPostFix();
    double sum = f.Calculate();
    
    std::cout << n << std::endl;
    std::cout << n1 << std::endl;
    std::cout << sum << std::endl;

    
    return 0;
}