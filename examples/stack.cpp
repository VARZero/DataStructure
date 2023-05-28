#include <iostream>
#include "../dataStruct/stack.h"

using namespace std;

/*
    스택 연습
    0. 크기 5개짜리 int 넣을수 있는 스택을 만든뒤에
    1. 10, 2, 15를 넣고 두번 꺼내서 15, 2가 출력되는지 확인
    2. 30, 14, 3, 9, 0을 넣고 0이 들어가지 않는지 확인
    3. 들어간것이 역순으로 출력되는지 확인
*/

int main(){
    stack<int> ex_stk1(5); // #0

    ex_stk1.Push(10); ex_stk1.Push(2); ex_stk1.Push(15);
    cout << "Pop " << ex_stk1.Pop() 
        << " " << ex_stk1.Pop() << endl;
    ex_stk1.Push(30); ex_stk1.Push(14);
    ex_stk1.Push(3); ex_stk1.Push(9);
    if (!ex_stk1.Push(0)){
        cout << "stack is Full" << endl;
    }
    cout << "Pop " << ex_stk1.Pop() 
        << " " << ex_stk1.Pop() 
        << " " << ex_stk1.Pop() 
        << " " << ex_stk1.Pop()
        << " " << ex_stk1.Pop() << endl;

    return 0;
}