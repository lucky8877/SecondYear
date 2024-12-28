#include "CorrectChecker.h"
#include "Table.h"
#include <ctype.h>
#include <vector>
#include <algorithm>

CorrectChecker::CorrectChecker(): _brecketsTable("(", ")", 20), _brackets(), _varTable("var", "value"){
}

bool CorrectChecker::CheckBrackets(const std::string& s){
    int scob;
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == '('){
            _brackets.Push(i);
            scob = i;
        }
        if(s[i] == ')'){
            try{
                _brecketsTable.AppendRow(_brackets.Pop(), i);
                int scob2 = i;
            }
            catch(const char* error_message){
                _brecketsTable.AppendRow(std::nullopt, i);
                _brecketsTable.Print();
                std::cout << "Error is brackets: \n" << s <<std::endl;
                int cnt = 0;
                while(cnt < i){
                    std::cout << " ";
                    cnt++;
                }
                std::cout << "^" << std::endl;

                return false;
            }
        }
    }

        while (!_brackets.IsEmpty()){
            _brecketsTable.AppendRow(_brackets.Pop(), std::nullopt);

            _brecketsTable.Print();
            std::cout << "Error is brackets: \n" << s <<std::endl;
            int cnt = 0;
            while(cnt < scob){
                std::cout << " ";
                cnt++;
            }
            std::cout << "^" << std::endl;

                
            return false;
        }

    _brecketsTable.Print();
    return _brackets.IsEmpty();
}

bool CorrectChecker::CheckVariable(){
    for(size_t i = 0; i < _varTable.GetCount(); i++ ){
        if(_varTable.GetCol1()[i] == std::nullopt)
            return false;
        if(_varTable.GetCol2()[i] == std::nullopt)
            return false;
    }
    return true;
}

void CorrectChecker::FillVariable(const std::string& s){
    double var;
    vector<char> val;
    std::string Zn;
    for(int i = 0; i < s.size(); i++){
        char x = s[i];
        if (std::isalpha((unsigned char)x)){
            val.push_back(s[i]);
        }
    }
    std::sort(begin(val), end(val));
    val.erase(std::unique(begin(val), end(val)), end(val));
    for(int i = 0; i < val.size(); i++){
        std::cout << "enter value " << val[i] << std::endl;
        std::cin >> Zn;
        if(Zn == "no"){
            _varTable.AppendRow(val[i], std::nullopt);
        }
        else{
            var = std::stod(Zn);
            _varTable.AppendRow(val[i], var);
        }
            
    }
    _varTable.Print();

}

const Table<char, double>& CorrectChecker::GetVarTable() const{
    return _varTable;
}


bool CorrectChecker::GetState(){
    return _state;
}

bool CorrectChecker::CheckFormula(const std::string& s){
    std::string operazia{"*/-+^"};
    if(!CheckVariable()){
        _state = false;
        return false;
    }
    if(!CheckBrackets(s)){
        _state = false;
        return false;
    }
    else{
    for(int i = 1; i < s.size(); i++){
        if(operazia.find(s[i]) != std::string::npos && operazia.find(s[i-1]) != std::string::npos){
            _state = false;
            return false;
        }
    }
    for(size_t i = 1; i < s.size(); i++){
        char x = s[i];
        char y = s[i-1];
        if (std::isalpha((unsigned char)x) && std::isalpha((unsigned char)y)){
            _state = false;
            return false;
        }
    }
    for(size_t i = 0; i < s.size()-2; i++){
        if(s[i] == '(' && (s[i+2] == ')' || s[i+1] == ')')){
            _state = false;
            return false;
        }
    }
    }
    return true;
}