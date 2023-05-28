#include <iostream>
#include "../dataStruct/LinkedList.h"

using namespace std;

/*
    단일 링크드리스트 예시 동작
    int 링크드리스트 작성
    1. 10, 2, 15, 30를 링크드리스트에 삽입
    2. 세번째 요소를 제거 (index 2를 제거) 후 한번 전체 출력
    3. 14, 3, 9, 0를 링크드리스트에 삽입
    4. 14를 찾기기능으로 찾고 그 노드를 그대로 가져와서 삭제
    5. 전체 출력
*/

int main(){
    LL<int> exm_LL1;
    exm_LL1.add(10); exm_LL1.add(2); exm_LL1.add(15); exm_LL1.add(30);
    exm_LL1.remove(2);
    exm_LL1.printAll();
    exm_LL1.add(14); exm_LL1.add(3); exm_LL1.add(9); exm_LL1.add(0);
    exm_LL1.printAll();

    int idx;
    nodeLL<int>* find = exm_LL1.search(14, idx);
    cout << idx << " " << find->getData() << endl;
    exm_LL1.remove(find);
    exm_LL1.printAll();

    return 0;
}