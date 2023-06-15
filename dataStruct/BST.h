#ifndef __VZ_BST__
#define __VZ_BST__

template<typename I,typename T>
class nodeBST{
    private:
        I index;
        T data;
        nodeBST<I,T>* leftPtr;
        nodeBST<I,T>* rightPtr;
    public:
        nodeBST();
        ~nodeBST();
        
        void setIndex(I newIdx);
        void setData(T newData);
        void setLeft(nodeBST<I,T>* newLeft);
        void setRight(nodeBST<I,T>* newRight);

        I getIndex();
        T getData();
        nodeBST<I,T>* getLeft();
        nodeBST<I,T>* getRight();
};

template<typename I,typename T>
nodeBST<I,T>::nodeBST(){ leftPtr = nullptr; rightPtr = nullptr; }

template<typename I,typename T>
nodeBST<I,T>::~nodeBST(){}

template<typename I,typename T>
void nodeBST<I,T>::setIndex(I newIdx){ index = newIdx; }

template<typename I,typename T>
void nodeBST<I,T>::setData(T newData){ data = newData; }

template<typename I,typename T>
void nodeBST<I,T>::setLeft(nodeBST<I,T>* newLeft){ leftPtr = newLeft; }

template<typename I,typename T>
void nodeBST<I,T>::setRight(nodeBST<I,T>* newRight){ rightPtr = newRight; }

template<typename I,typename T>
I nodeBST<I,T>::getIndex(){ return index; }

template<typename I,typename T>
T nodeBST<I,T>::getData(){ return data; }

template<typename I,typename T>
nodeBST<I,T>* nodeBST<I,T>::getLeft(){ return leftPtr; }

template<typename I,typename T>
nodeBST<I,T>* nodeBST<I,T>::getRight(){ return rightPtr; }

template<typename I,typename T>
class BST{
    private:
        nodeBST<I,T>* root;
    public:
        BST();
        ~BST();

        bool IsEmpty() const;
        nodeBST<I,T>* getParent(I findIdx) const;
        char checkLR(I checkIdx, I sourceIdx) const;

        void setRoot(nodeBST<I,T>* newRoot);
        nodeBST<I,T>* getRoot() const;

        virtual bool add(I newIndex, T newData);
        virtual bool remove(nodeBST<I,T>* delNode);
        virtual bool search(I findIdx, nodeBST<I,T>* findNode);
};

template<typename I,typename T>
BST<I,T>::BST(){ root = nullptr; }

template<typename I,typename T>
BST<I,T>::~BST(){}

template<typename I,typename T>
bool BST<I,T>::IsEmpty() const{
    if (root == nullptr){ return true; }
    return false;
}

template<typename I,typename T>
nodeBST<I,T>* BST<I,T>::getParent(I findIdx) const {
    if (IsEmpty()){ return nullptr; }
    nodeBST<I,T> *parent = nullptr, *checkNode = getRoot();
    while(checkNode != nullptr){
        if (checkNode->getIndex() == findIdx){ return parent; }
        else if (checkNode->getIndex() < findIdx){
            checkNode = checkNode->getLeft();
        }
        else if (checkNode->getIndex() > findIdx){
            checkNode = checkNode->getRight();
        }

        if (checkNode == nullptr){ return parent; }
        parent = checkNode;
    }
    return nullptr;
}

template<typename I,typename T>
char BST<I,T>::checkLR(I checkIdx, I sourceIdx) const {
    if (checkIdx < sourceIdx){return -1;}
    else if (checkIdx > sourceIdx){return 1;}
    return 0;
}

template<typename I,typename T>
void BST<I,T>::setRoot(nodeBST<I,T>* newRoot){ root = newRoot; }

template<typename I,typename T>
nodeBST<I,T>* BST<I,T>::getRoot() const { return root; }

template<typename I,typename T>
bool BST<I,T>::add(I newIndex, T newData){
    nodeBST<I,T>* newNode = new nodeBST<I,T>;
    newNode->setIndex(newIndex);
    newNode->setData(newData);
    if (IsEmpty()){ setRoot(newNode); return true; }
    nodeBST<I,T> *nNParent = getParent(newNode->getIndex()), *preNode;
    
    if (nNParent == nullptr){ nNParent = getRoot(); }
    
    switch(checkLR(nNParent->getIndex(), newIndex)){
        case -1:
            preNode = nNParent->getLeft();
            nNParent->setLeft(newNode);
        break;
        case 0: return false; break;
        case 1:
            preNode = nNParent->getRight();
            nNParent->setRight(newNode);
        break;
    }

    if (preNode != nullptr){
        switch(checkLR(newIndex, preNode->getIndex())){
            case -1: newNode->setLeft(preNode); break;
            case 1: newNode->setRight(preNode); break;
        }
    }

    return true;
}

template<typename I,typename T>
bool BST<I,T>::remove(nodeBST<I,T>* delNode){
    if (!search(delNode->getIndex(), nullptr)){ return false; }
    nodeBST<I,T> *parNode, *delLNode, *chnNode, *mostLeft;
    
    delLNode = delNode->getLeft(); chnNode = delNode->getRight();
    mostLeft = chnNode;
    if (getRoot() == delNode){
        setRoot(chnNode);
    }
    else{
        parNode = getParent(delNode->getIndex());
        switch(checkLR(parNode->getIndex(), delNode->getIndex())){
            case -1: parNode->setLeft(chnNode); break;
            case 1: parNode->setRight(chnNode); break;
        }
    }
    while(mostLeft->getLeft() != nullptr){ mostLeft = mostLeft->getLeft(); }
    mostLeft->setLeft(delLNode);
    delete delNode;
    return true;
}

template<typename I,typename T>
bool BST<I,T>::search(I findIdx, nodeBST<I,T>* findNode){
    nodeBST<I,T>* checkNode = getRoot();
    while(checkNode != nullptr){
        switch(checkLR(findIdx, checkNode->getIndex())){
            case -1: checkNode = checkNode->getLeft(); break;
            case 0:
                if (findNode != nullptr){ findNode = checkNode; }
                return true;
            break;
            case 1: checkNode = checkNode->getRight(); break;
        }
    }
    return false;
}

#endif