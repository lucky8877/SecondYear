#include "stack.h"
#include "table.h"
int main() {
    Stack<int> s;
    s.Push(4);
    s.Push(5);
    s.Push(6);
    s.Push(7);
    int *r = s.GetArray();
    Table<int,int> t("213","123");

}