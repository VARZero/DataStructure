#include "./BST.h"

#ifndef __VZ_TREES__
#define __VZ_TREES__

template<typename I,typename T>
class AVL_Tree : public BST{
    //bool add(I newIndex, T newData);
    //bool remove(nodeBST<I,T>* delNode);

    void rearrangement();
    void rotationLeft(nodeBST<I,T>* target);
    void rotationRight(nodeBST<I,T>* target);
};

template<typename I,typename T>
void AVL_Tree<I,T>::rearrangement(){
    // 루트에서 양쪽 끝단까지 깊이 확인
    
}

template<typename I,typename T>
void AVL_Tree<I,T>::rotationLeft(nodeBST<I,T>* target){
    // check
    nodeBST<I,T>* center = target->getRight();
    if (center == nullptr){ return; }

    target->setRight(center->getLeft());
    center->setLeft(target);
}

template<typename I,typename T>
void AVL_Tree<I,T>::rotationRight(nodeBST<I,T>* target){
    // check
    nodeBST<I,T>* center = target->getLeft();
    if (center == nullptr){ return; }

    target->setLeft(center->getRight());
    center->setRight(target);
}

#endif