#include "./BST.h"

#ifndef __VZ_TREES__
#define __VZ_TREES__

template<typename I,typename T>
class AVL_Tree : public BST<I,T>{
    //bool add(I newIndex, T newData);
    //bool remove(nodeBST<I,T>* delNode);

    int getDepth(nodeBST<I,T>* targetNode);
    int checkBalance(int l, int r);
    void rearrangement();
    void rotationLeft(nodeBST<I,T>* target);
    void rotationRight(nodeBST<I,T>* target);
};

template<typename I,typename T>
int AVL_Tree<I,T>::getDepth(nodeBST<I,T>* targetNode){
    if (targetNode == nullptr) { return 0; }
    int dLeft = getDepth(targetNode->getLeft());
    int dRight = getDepth(targetNode->getRight());
    
    return (dLeft >= dRight) ? dLeft+1 : dRight+1 ;
}

template<typename I,typename T>
int AVL_Tree<I,T>::checkBalance(int l, int r){
    return r - l;
}

template<typename I,typename T>
void AVL_Tree<I,T>::rearrangement(){
    nodeBST<I,T>* root = this->getRoot();
    int rDL = getDepth(root->getLeft());
    int rDR = getDepth(root->getRight());

    int bal = checkBalance(rDL, rDR);

    if ( bal > 0 ){
        // LL, LR
        
    }

    else if ( bal > 0 ){
        // RR, RL
    }
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