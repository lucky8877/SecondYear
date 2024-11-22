#include "ExpressionChecker.h"
#include "stack.h"

bool ExpressionChecker::CheckBrackets(std::string s){
    Stack<char> st;    
    for (int i =0; i < s.size();i++){
        if (s[i] == '(') {
            st.Push('(');
        } else if (s[i] == ')') {
            if (st.IsEmpty()) {
                return false;
            }
            st.Pop(); 
        }
    }
}