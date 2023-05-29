#include <iostream>
#include "../dataStruct/LinkedList.h"

using namespace std;

/*
    링크드리스트 예시 동작
    int 링크드리스트 작성
    1. 10, 2, 15, 30를 링크드리스트에 삽입
    2. 세번째 요소를 제거 (index 2를 제거) 후 한번 전체 출력
    3. 14, 3, 9, 0를 링크드리스트에 삽입
    4. 14를 찾기기능으로 찾고 그 노드를 그대로 가져와서 삭제
    5. 전체 출력

    단일 / 연속 / 순환 모두 같은 동작 확인
*/

int main(){

    cout << "단일" << endl;

    LL<int> exm_LL1;
    exm_LL1.add(10); exm_LL1.add(2); exm_LL1.add(15); exm_LL1.add(30);
    exm_LL1.printAll();
    exm_LL1.remove(2);
    exm_LL1.printAll();
    exm_LL1.add(14); exm_LL1.add(3); exm_LL1.add(9); exm_LL1.add(0);
    exm_LL1.printAll();

    int idx1;
    nodeLL<int>* find1 = exm_LL1.search(14, idx1);
    cout << idx1 << " " << find1->getData() << endl;
    exm_LL1.remove(find1);
    exm_LL1.printAll();

    cout << "연속" << endl;

    LLd<int> exm_LLd;
    exm_LLd.add(10); exm_LLd.add(2); exm_LLd.add(15); exm_LLd.add(30);
    exm_LLd.printAll();
    exm_LLd.remove(2);
    exm_LLd.printAll();
    exm_LLd.add(14); exm_LLd.add(3); exm_LLd.add(9); exm_LLd.add(0);
    exm_LLd.printAll();

    int idx2;
    nodeLLd<int>* find2 = exm_LLd.search(14, idx2);
    cout << idx2 << " " << find2->getData() << endl;
    exm_LLd.remove(find2);
    exm_LLd.printAll();

    cout << "순환" << endl;
    LLc<int> exm_LLc;
    exm_LLc.add(10); exm_LLc.add(2); exm_LLc.add(15); exm_LLc.add(30);
    exm_LLc.printAll();
    exm_LLc.remove(2);
    exm_LLc.printAll();
    exm_LLc.add(14); exm_LLc.add(3); exm_LLc.add(9); exm_LLc.add(0);
    exm_LLc.printAll();

    int idx3;
    nodeLL<int>* find3 = exm_LLc.search(14, idx3);
    cout << idx3 << " " << find3->getData() << endl;
    exm_LLc.remove(find2);
    exm_LLc.printAll();

    return 0;
}