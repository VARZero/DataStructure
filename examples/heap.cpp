#include <iostream>
#include "../dataStruct/heap.h"

using namespace std;

/*
    힙 연습
    0. 크기 5개짜리 int 넣을수 있는 힙을 만든뒤에
    1. 10, 2, 15를 넣고 두번 꺼내서 10, 2가 출력되는지 확인
    2. 30, 14, 3, 9, 0을 넣고 0이 들어가지 않는지 확인
    3. 들어간순으로 출력되는지 확인
*/

int main(){
    heap<int> ex_heap1(5); // #0

    ex_heap1.enqueue(10); ex_heap1.enqueue(2); ex_heap1.enqueue(15);
    cout << "dequeue " << ex_heap1.dequeue() 
        << " " << ex_heap1.dequeue() << endl;
    ex_heap1.enqueue(30); ex_heap1.enqueue(14);
    ex_heap1.enqueue(3); ex_heap1.enqueue(9);
    if (!ex_heap1.enqueue(0)){
        cout << "heap is Full" << endl;
    }
    cout << "dequeue " << ex_heap1.dequeue() 
        << " " << ex_heap1.dequeue() 
        << " " << ex_heap1.dequeue() 
        << " " << ex_heap1.dequeue()
        << " " << ex_heap1.dequeue() << endl;

    return 0;
}