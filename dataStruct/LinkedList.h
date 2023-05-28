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
class LL{
    private:
        nodeLL<T>* headPtr;
        
        nodeLL<T>* getLastNode() const;
        bool IsEmpty() const;
    public:
        LL();
        ~LL();

        virtual void add(T);
        
        virtual bool remove(int);
        virtual bool remove(nodeLL<T>*);

        virtual nodeLL<T>* search(T, int&) const;
        
        virtual void printAll();
};

template<typename T>
nodeLL<T>* LL<T>::getLastNode() const{
    if (IsEmpty()) return nullptr;
    nodeLL<T>* lastNode = headPtr;
    while(lastNode->getNext() != nullptr){ lastNode = lastNode->getNext(); }
    return lastNode;

    // O(N) ( O(4N+3) )
}

template<typename T>
bool LL<T>::IsEmpty() const{
    if (headPtr == nullptr){ return true; }
    return false;
}

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
void LL<T>::add(T newData){
    nodeLL<T> *newNode, *lastNode = getLastNode();
    newNode = new nodeLL<T>;
    newNode->setData(newData);
    if (IsEmpty()) { headPtr = newNode; return; }
    lastNode->setNext(newNode);

    // O(N) ( O(4N+8) )
}

template<typename T>
bool LL<T>::remove(int index){
    nodeLL<T> *delNode, *delPreNode = headPtr;
    if (IsEmpty()){ return false; }
    
    if (index == 0){
        headPtr = headPtr->getNext();
        delete delPreNode;
        return true;
    }
    
    for (int cmpIdx = 0; cmpIdx < index; cmpIdx++){
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
    nodeLL<T>* selPreNode = headPtr;
    if (selNode == headPtr){
        headPtr = selNode->getNext();
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
    nodeLL<T>* findNode = headPtr;
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
    nodeLL<T>* printNode = headPtr;
    while(printNode != nullptr){
        std::cout << printNode->getData() << " ";
        printNode = printNode->getNext();
    }
    std::cout << std::endl;

    // O(N) ( O(3N+3) )
}

#endif