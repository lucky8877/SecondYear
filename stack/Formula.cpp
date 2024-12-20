#include "Formula.h"

Formula::Formula(string exp, size_t num_of_un) : _prior("sign", "prior", 6) , _unknow("u", "n", num_of_un){
    _expr = exp;
    _num_of_un = num_of_un;
    _prior.AppendRow('(', 0);
    _prior.AppendRow(')', 1);
    _prior.AppendRow('+', 2);
    _prior.AppendRow('-', 2);
    _prior.AppendRow('*', 3);
    _prior.AppendRow('/', 3);
}

void Formula::FormulaConverter(size_t num_of_un){


    for (int i = 0; i < _expr.size(); i++) {
        if (isalnum(_expr[i])) { 
            _postfix += _expr[i];

        } 
        
        else if (_expr[i] == '(') {
            if (_expr[i+1] == '-') { _expr.insert(i, "0"); }
            _opStack.Push(_expr[i]);

        } 
        
        else if (_expr[i] == ')') {
            while (!_opStack.isEmpty() && _opStack.Top() != '(') {
                _postfix += _opStack.Pop();
            }
        }

        else if (isalpha(_expr[i])){
            //проверка соседних символов
            _set.insert(_expr[i]);
            _postfix += _expr[i];
        }

        else {
            if (i == _expr.size() - 1 || !isalnum(_expr[i+1])) throw "wrong syntax";//сделать проверку в экспчекере

            while (!_opStack.isEmpty() && _prior.GetElemFromCol2(_opStack.Top()) >= _prior.GetElemFromCol2(_expr[i])) {
                _postfix += _opStack.Pop();
            }
            _opStack.Push(_expr[i]);
        }
    }

    while (!_opStack.isEmpty()) 
        _postfix += _opStack.Pop();
    

    if(_num_of_un != 0)
        for(char ch : _set){
            double tmp;
            cout << "Введите значение для переменной" << ch << ":";
            cin >> tmp;
            _unknow.AppendRow(ch, tmp);
            cout << endl;
        }

}

double Formula::FormulaCalculator(){
    double first, sec;
    Stack<double> stack;
    for (int i = 0; i < this->_expr.size(); i++) {
        if (isdigit(_postfix[i])) {
            stack.Push((_postfix[i]));
        }

        else {
            if (_postfix[i] == '+') {
                first = stack.Pop();
                sec = stack.Pop();
                stack.Push(first + sec);
            }

            else if (_postfix[i] == '*') {
                first = stack.Pop();
                sec = stack.Pop();
                stack.Push(first * sec);
            }
            
            else if (_postfix[i] == '-') {
                first = stack.Pop();
                sec = stack.Pop();
                stack.Push(sec - first);
            }

            else if (_postfix[i] == '/') {
                first = stack.Pop();
                sec = stack.Pop();
                stack.Push(sec / first);
            }
        }
    }
    return stack.Pop();
}