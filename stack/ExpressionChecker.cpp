#include "ExpressionChecker.h"
#include "stack.h"
#include "table.h"
#include <optional>
bool ExpressionChecker::CheckBrackets(std::string s){
    Stack<char> st;
    Table <int,int> t("(", ")");    
    for (int i =0; i < s.size();i++){
        if (s[i] == '(') {
            st.Push('(');
        } else if (s[i] == ')') {
            if (st.IsEmpty()) {
                t.AppendRow(nullopt, i);
            }else {
                t.AppendRow(st.Pop(),i);
            }
            st.Pop(); 
        }
    }
}