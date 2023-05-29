#ifndef __VZ_LINKEDLIST__
#define __VZ_LINKEDLIST__

#include <iostream>

template<typename T>
class nodeLL{ // 단일 링크드 리스트 노드
    private:
        T data;
        nodeLL<T>* nextPtr;
    public:
        nodeLL();
        ~nodeLL();

        T getData() const;
        void setData(T);

        nodeLL<T>* getNext() const;
        void setNext(nodeLL<T>*);
};

template<typename T>
nodeLL<T>::nodeLL(){ nextPtr = nullptr; }

template<typename T>
nodeLL<T>::~nodeLL(){}

template<typename T>
T nodeLL<T>::getData() const{ return data; }

template<typename T>
void nodeLL<T>::setData(T newData){ data = newData; }

template<typename T>
nodeLL<T>* nodeLL<T>::getNext() const{ return nextPtr; }

template<typename T>
void nodeLL<T>::setNext(nodeLL<T>* newNext){ nextPtr = newNext; }

template<typename T>
class LL{ // 단일 링크드리스트
    private:
        nodeLL<T>* headPtr;
    public:
        LL();
        ~LL();

        nodeLL<T>* getHead() const;
        void setHead(nodeLL<T>*);        

        virtual nodeLL<T>* getLastNode() const;
        bool IsEmpty() const;

        virtual void add(T);
        
        virtual bool remove(int);
        virtual bool remove(nodeLL<T>*);

        virtual nodeLL<T>* search(T, int&) const;
        
        virtual void printAll();
};

template<typename T>
LL<T>::LL(){ headPtr = nullptr; }

template<typename T>
LL<T>::~LL(){
    nodeLL<T>* delNode = headPtr;
    while(delNode != nullptr){
        headPtr = delNode;
        delNode = delNode->getNext();
        delete headPtr;
    }

    // O(N) ( O(4N+1) )
}

template<typename T>
nodeLL<T>* LL<T>::getHead() const{ return headPtr; }

template<typename T>
void LL<T>::setHead(nodeLL<T>* newHead){ headPtr = newHead; }

template<typename T>
nodeLL<T>* LL<T>::getLastNode() const{
    if (IsEmpty()) return nullptr;
    nodeLL<T>* lastNode = getHead();
    while(lastNode->getNext() != nullptr){ lastNode = lastNode->getNext(); }
    return lastNode;

    // O(N) ( O(4N+3) )
}

template<typename T>
bool LL<T>::IsEmpty() const{
    if (getHead() == nullptr){ return true; }
    return false;
}

template<typename T>
void LL<T>::add(T newData){
    nodeLL<T> *newNode, *lastNode = getLastNode();
    newNode = new nodeLL<T>;
    newNode->setData(newData);
    if (IsEmpty()) { setHead(newNode); return; }
    lastNode->setNext(newNode);

    // O(N) ( O(4N+8) )
}

template<typename T>
bool LL<T>::remove(int index){
    nodeLL<T> *delNode, *delPreNode = getHead();
    if (IsEmpty()){ return false; }
    
    if (index == 0){
        setHead(getHead()->getNext());
        delete delPreNode;
        return true;
    }
    
    for (int cmpIdx = 0; cmpIdx < (index-1); cmpIdx++){
        if (delPreNode == nullptr){return false;}
        delPreNode = delPreNode->getNext();
    }
    delNode = delPreNode->getNext();
    if (delNode == nullptr){return false;}
    delPreNode->setNext(delNode->getNext());
    delete delNode;
    return true;

    // O(N) ( O(4N+17) )
}

template<typename T>
bool LL<T>::remove(nodeLL<T>* selNode){
    if (IsEmpty()){ return false; }
    nodeLL<T>* selPreNode = getHead();
    if (selNode == getHead()){
        setHead(selNode->getNext());
        delete selNode;
        return true;
    }

    while (selPreNode->getNext() != selNode){
        selPreNode = selPreNode->getNext();
        if (selPreNode == nullptr){return false;}
    }
    selPreNode->setNext(selNode->getNext());
    delete selNode;
    return true;

    // O(N) ( O(5N+12) )
}


template<typename T>
nodeLL<T>* LL<T>::search(T findData, int& index) const{
    if (IsEmpty()){ index = -1; return nullptr; }
    int idxOut = 0;
    nodeLL<T>* findNode = getHead();
    while (findNode->getData() != findData){
        findNode = findNode->getNext(); idxOut++;
        if (findNode == nullptr){ index = -1; return nullptr; }
    }
    index = idxOut;
    return findNode;

    // O(N) ( O(6N+5) )
}

template<typename T>
void LL<T>::printAll(){
    nodeLL<T>* printNode = getHead();
    while(printNode != nullptr){
        std::cout << printNode->getData() << " ";
        printNode = printNode->getNext();
    }
    std::cout << std::endl;

    // O(N) ( O(3N+3) )
}

template<typename T>
class nodeLLd:public nodeLL<T>{ // 연속 링크드 리스트 노드
    private:
        nodeLLd<T>* prevPtr;
    public:
        nodeLLd():nodeLL<T>(){ prevPtr = nullptr; }

        nodeLLd<T>* getPrev() const;
        void setPrev(nodeLLd<T>*);
};

template<typename T>
nodeLLd<T>* nodeLLd<T>::getPrev() const{ return prevPtr; }

template<typename T>
void nodeLLd<T>::setPrev(nodeLLd<T>* newPrev){ prevPtr = newPrev; }

template<typename T>
class LLd:public LL<T>{ // 연속 링크드 리스트 
    // 연속 링크드 리스트는 포인터로 자식요소에 접근하게 할거임..
    public:
        nodeLLd<T>* getLastNode() const;

        void add(T);
        
        bool remove(int);
        bool remove(nodeLLd<T>*);

        nodeLLd<T>* search(T, int&) const;
};

template<typename T>
nodeLLd<T>* LLd<T>::getLastNode() const{
    if (this->IsEmpty()) return nullptr;
    nodeLLd<T>* lastNode = (nodeLLd<T>*) this->getHead();
    while(lastNode->getNext() != nullptr){
        lastNode = (nodeLLd<T>*) lastNode->getNext();
    }
    return lastNode;
}

template<typename T>
void LLd<T>::add(T newData){
    nodeLLd<T> *newNode, *lastNode = getLastNode();
    newNode = new nodeLLd<T>;
    newNode->setData(newData);
    if (this->IsEmpty()){ this->setHead(newNode); return; }
    newNode->setPrev(lastNode);
    lastNode->setNext(newNode);
}

template<typename T>
bool LLd<T>::remove(int index){
    if (this->IsEmpty()){return false;}
    nodeLLd<T> *delNode = (nodeLLd<T>*) this->getHead();
    if (index == 0){
        if (delNode->getNext() == nullptr){this->setHead(nullptr); delete delNode; return true;}
        ((nodeLLd<T>*) (delNode->getNext()))->setPrev(nullptr);
        delete delNode;
        return true;
    }

    for (int cmpIdx = 0; cmpIdx < index; cmpIdx++){
        delNode = (nodeLLd<T>*) delNode->getNext();
        if (delNode == nullptr){return false;}
    }
    if (delNode->getNext() != nullptr){
        ((nodeLLd<T>*) (delNode->getNext()))->setPrev(delNode->getPrev());
    }
    delNode->getPrev()->setNext(delNode->getNext());
    delete delNode;
    return true;
}

template<typename T>
bool LLd<T>::remove(nodeLLd<T>* selNode){
    if (this->IsEmpty()){return false;}
    if (this->getHead() == selNode){
        if (this->getHead()->getNext() == nullptr){this->setHead(nullptr); delete this->getHead(); return true;}
            ((nodeLLd<T>*) (this->getHead()->getNext()))->setPrev(nullptr);
        delete this->getHead();
        return true;
    }
    nodeLLd<T>* delNode = (nodeLLd<T>*) this->getHead();
    while (delNode != selNode){
        delNode = (nodeLLd<T>*) delNode->getNext();
        if (delNode == nullptr){return false;}
    }
    
    if (delNode->getNext() != nullptr){
        ((nodeLLd<T>*) (delNode->getNext()))->setPrev(delNode->getPrev());
    }
    delNode->getPrev()->setNext(delNode->getNext());
    delete delNode;
    return true;
}

template<typename T>
nodeLLd<T>* LLd<T>::search(T findData, int& index) const{
    if (this->IsEmpty()){ index = -1; return nullptr; }
    int idxOut = 0;
    nodeLLd<T>* findNode = (nodeLLd<T>*) this->getHead();
    while (findNode->getData() != findData){
        findNode = (nodeLLd<T>*) findNode->getNext(); idxOut++;
        if (findNode == nullptr){ index = -1; return nullptr; }
    }
    index = idxOut;
    return findNode;
}

template<typename T>
class LLc:public LL<T>{
    public:
        nodeLL<T>* getLastNode() const;

        void add(T);

        bool remove(int);
        bool remove(nodeLL<T>*);

        nodeLL<T>* search(T, int&) const;

        void printAll();
};

template<typename T>
nodeLL<T>* LLc<T>::getLastNode() const{
    std::cout << " -gln- ";
    if (this->IsEmpty()){ return nullptr; }
    nodeLL<T>* LastNode = this->getHead();
    while(LastNode->getNext() != this->getHead()){
        LastNode = LastNode->getNext();
        if (LastNode == nullptr){ return nullptr; }
    }
    return LastNode;
}

template<typename T>
void LLc<T>::add(T newData){ std::cout << " -add- ";
    nodeLL<T> *newNode, *lastNode = getLastNode();
    newNode = new nodeLL<T>;
    newNode->setData(newData);
    if (this->IsEmpty()){
        this->setHead(newNode); newNode->setNext(newNode); return;
    }
    lastNode->setNext(newNode);
}

template<typename T>
bool LLc<T>::remove(int index){
    nodeLL<T> *delNode, *delPreNode = this->getHead();
    if (this->IsEmpty()){ return false; }
    
    if (index == 0){
        this->setHead(this->getHead()->getNext());
        delete delPreNode;
        return true;
    }
    delPreNode = delPreNode->getNext();
    for (int cmpIdx = 1; cmpIdx < (index-1); cmpIdx++){
        if (delPreNode == this->getHead()){return false;}
        delPreNode = delPreNode->getNext();
    }
    delNode = delPreNode->getNext();
    if (delNode == this->getHead()){return false;}
    delPreNode->setNext(delNode->getNext());
    delete delNode;
    return true;
}

template<typename T>
bool LLc<T>::remove(nodeLL<T>* selNode){
    if (this->IsEmpty()){ return false; }
    nodeLL<T>* selPreNode = this->getHead();
    if (selNode == this->getHead()){
        this->setHead(selNode->getNext());
        delete selNode;
        return true;
    }
    selPreNode = selPreNode->getNext();
    while (selPreNode->getNext() != selNode){
        selPreNode = selPreNode->getNext();
        if (selPreNode == nullptr){return false;}
    }
    selPreNode->setNext(selNode->getNext());
    delete selNode;
    return true;
}

template<typename T>
nodeLL<T>* LLc<T>::search(T findData, int& index) const{
    if (this->IsEmpty()){ index = -1; return nullptr; }
    int idxOut = 0;
    nodeLL<T>* findNode = this->getHead();
    while (findNode->getData() != findData){
        findNode = findNode->getNext(); idxOut++;
        if (findNode == this->getHead()){ index = -1; return nullptr; }
    }
    index = idxOut;
    return findNode;
}

template<typename T>
void LLc<T>::printAll(){
    nodeLL<T>* printNode = this->getHead();
    do{
        std::cout << printNode->getData() << " ";
        printNode = printNode->getNext();
    }while(printNode != this->getHead());
    std::cout << std::endl;
}

#endif