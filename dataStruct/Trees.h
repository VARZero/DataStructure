#include "./BST.h"

#ifndef __VZ_TREES__
#define __VZ_TREES__

template<typename I,typename T>
class AVL_Tree : public BST{
    //bool add(I newIndex, T newData);
    //bool remove(nodeBST<I,T>* delNode);

    int getDepth(nodeBST<I,T>* targetNode, char* position);
    void rearrangement();
    void rotationLeft(nodeBST<I,T>* target);
    void rotationRight(nodeBST<I,T>* target);
};

template<typename I,typename T>
int AVL_Tree<I,T>::getDepth(nodeBST<I,T>* targetNode, char* position){
    if (targetNode == nullptr) { return 0; }
    int dLeft = getDepth(targetNode->getLeft(), nullptr);
    int dRight = getDepth(targetNode->getRight(), nullptr);
    
    if (dLeft > dRight) { position = -1; return dLeft; }
    else if (dLeft < dRight) { position = 1; return dRight; }
    else { position = 0; return 0; }
}

template<typename I,typename T>
void AVL_Tree<I,T>::rearrangement(){
    
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