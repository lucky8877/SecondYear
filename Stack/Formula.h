#pragma once
#include "Stack.h"
#include "Table.h"
#include <string>
#include <iostream>
#include "CorrectChecker.h"
#include <cmath>


class Formula{
private:
    std::string _expression; 
    Stack<char> _calcStack;  
    std::string _postfix; 
    Table<char, int> _prior;
public:
    //Formula(std::string exp);
    Formula(const std::string& exp){
        _expression = exp;
        _prior = Table<char, int>("oper", "prioritet");
        _prior.AppendRow('(', 0);
        _prior.AppendRow(')', 1);
        _prior.AppendRow('+', 2);
        _prior.AppendRow('-', 2);
        _prior.AppendRow('*', 3);
        _prior.AppendRow('/', 3);
        _prior.AppendRow('^', 4);
    }
    void EnterVariableValues(const std::string& s);
    
    void BuildPostfix(){
        std::string operazia{"()+-*/^"};
        std::string num = "";
        for(int i = 0; i < _expression.size(); i++){
            if(operazia.find(_expression[i]) != std::string::npos){
                if(num != ""){
                    _postfix.append(num);
                    _postfix.push_back(' ');
                    num = "";
                }
                if(_prior[_expression[i]].value() == 0 || _prior[_expression[i]].value() > _prior[_calcStack.Check()].value() || _calcStack.IsEmpty()){
                    if(_expression[i] != ')'){
                        _calcStack.Push(_expression[i]);
                    }
                    else{
                        while(_calcStack.Check() != '('){
                            _postfix.push_back(_calcStack.Check());
                            _calcStack.Pop();
                        }

                    }
                }
                else{
                    while( _prior[_expression[i]].value() <= _prior[_calcStack.Check()].value() &&  !_calcStack.IsEmpty()){
                        if(_calcStack.Check() == '(')
                            _calcStack.Pop();
                        else{
                            _postfix.push_back(_calcStack.Pop());
                        }
                        
                    }
                    if(_expression[i]!=')')
                        _calcStack.Push(_expression[i]);
                }
            }
            else{
                num.push_back(_expression[i]);
                //_postfix.push_back(_expression[i]);
            }
        }
        
        
        if(num!=""){
            _postfix.append(num);
            _postfix.push_back(' ');
            num = "";
                }
    while(!_calcStack.IsEmpty()){
        if(_calcStack.Check() != '(' && _calcStack.Check() != ')'){
            _postfix.push_back(_calcStack.Pop());
        }
        else{
            _calcStack.Pop();
        }
    }
    std::cout << _postfix << std::endl;
    }
    double Calculate(Table<char, double> varTable){ 
        BuildPostfix();

        Stack<double> stack;
        double oper1 = 0;
        double oper2 = 0;
        std::string operazia{"()+-*/^"};
        std::string num;
        for(size_t i = 0; i < _postfix.length(); i++){
            if(isdigit(_postfix[i])){
                num.push_back(_postfix[i]);
            }
            else if(_postfix[i] == ' ' && isdigit(_postfix[i-1])){
                stack.Push(std::stod(num));
                num = "";
            }
            else if(isalpha(_postfix[i])){
                stack.Push(varTable[_postfix[i]].value());
            }
            else if(operazia.find(_postfix[i]) != std::string::npos){
                oper2 = stack.Pop();
                oper1 = stack.Pop();
                double res;
                switch (_postfix[i])
                {
                case '-':
                    res = oper1 - oper2;
                    break;
                case '+':
                    res = oper1 + oper2;
                    break;
                case '*':
                    res = oper1 * oper2;
                    break;
                case '/':
                    res = oper1 / oper2;
                    break;
                case '^':
                    res = std::pow(oper1,oper2);
                    break;
                default:
                    break;
                }
                stack.Push(res);
            }
        }
        double resOp = stack.Pop();
        return resOp;
    }
};
