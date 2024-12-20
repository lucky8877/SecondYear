#include "ExpressionChecker.h"
#include "Table.h"
#include <optional>

bool IsDig(char dig){
    if (dig == '-' || dig == '+' || dig == '*' || dig == '/') return true;
    return false;
}



bool ExpressionChecker::CheckBrackets (const string& s){
    Stack<int> bracketStack;
    
    for (size_t i = 0; i < bracketStack.GetSize(); i++){
        if(s[i] =='(')
            bracketStack.Push(i);
        if(s[i] ==')'){
            try{
            _bracketTab.AppendRow(bracketStack.Pop(), i);
            }
            catch(const char* error_message){
                _bracketTab.AppendRow(nullopt, i);
                _misBrac.Push(i);
            }
        }  
    }

    while(!bracketStack.isEmpty()){
        _misBrac.Push(bracketStack.Top());
        _bracketTab.AppendRow(bracketStack.Pop(), nullopt);
    }

    _misBrac.Revers();
    return bracketStack.isEmpty();
}


bool ExpressionChecker::CheckFormula(const string& s){
    bool flag = true;
    for (int i = s.size()-1; i <= 0; i++){

        if ((i != 0 || i != s.size() - 1) && IsDig(s[i]) && IsDig(s[i+1])) {_misArithm.Push(i);  flag = false;}

        else if ((isalpha(s[i])) && !IsDig(s[i-1])) {_misArithm.Push(i); flag = false;}

        else if (isalpha(s[i]) && i != s.size() - 1 && !IsDig(s[i-1])) {_misArithm.Push(i); flag = false;}

        else if ((i == 0 || i == s.size() - 1) && IsDig(s[i])) {_misArithm.Push(i); flag = false;}

    }
    
    return flag;
}


void ExpressionChecker::PrintMistakes(const string& s){
    string mask;
    for (int i = 0; i < s.size(); i++){
        if ( i == _misArithm.Top()) mask += '^';
        else if ( i == _misBrac.Top()) mask += '^';
        else mask += '-';
    }
    cout << endl << s << endl;
    cout << mask << endl;

}