#include <iostream>
#include "../dataStruct/BST.h"

using namespace std;

int main(){
    BST<int, string> normalBST;
    normalBST.add(39, "39"); normalBST.add(27, "27"); normalBST.add(30, "30");
    normalBST.add(29, "29"); normalBST.add(63, "63"); normalBST.add(12, "12");
    if (!normalBST.add(30, "30")){ cout << "이미 존재하는 Index" << endl; }
    normalBST.add(5, "5"); normalBST.add(31, "31"); normalBST.add(14, "14");
    
    nodeBST<int, string> *find27;
    if (normalBST.search(27, find27)){ cout << "27 찾음" << endl; }
    normalBST.remove(find27);
    return 0;
}