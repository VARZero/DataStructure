#include <cstring>
#include "Linked_List.h"

// LL_Node
LL_Node::LL_Node(){
    data = NULL;
    pNext = NULL;
}

LL_Node::~LL_Node(){
    if (data != NULL){delete data;}
}

void LL_Node::setData(char* nData){
    int len = strlen(nData);
    data = new char[len + 1];
    strcpy(data, nData);
}

void LL_Node::setNext(LL_Node* nNext){
    pNext = nNext;
}

char* LL_Node::getData(){
    return data;
}

LL_Node* LL_Node::getNext(){
    return pNext;
}

// LL
LL::LL(){
    pHead = NULL;
}

LL::~LL(){
    if (pHead == NULL){return;}
    LL_Node *dNode;
    while(pHead != NULL){
        dNode = pHead;
        pHead = dNode->getNext();
        delete dNode;
    }
}

bool LL::add(LL_Node* newNode){
    LL_Node* lastNode = pHead;
    if (head_is_null()){pHead = newNode; return true;}
    while(lastNode->getNext() != NULL){lastNode = lastNode->getNext();}

    lastNode->setNext(newNode);
    return true;
}

bool LL::remove(int index){
    LL_Node* tgtPrevNode = pHead, *tgtNode;
    if (head_is_null()){return false;}
    for(int cmpIdx = 0; (cmpIdx < index-1) && (tgtPrevNode != NULL); cmpIdx++){
        tgtPrevNode = tgtPrevNode->getNext();
    }

    if (tgtPrevNode == NULL || tgtPrevNode->getNext() == NULL){return false;} // index에 노드가 없는 경우
    tgtNode = tgtPrevNode->getNext();
    tgtPrevNode->setNext(tgtPrevNode->getNext()->getNext());
    delete tgtNode;
    return true;
}

bool LL::remove(LL_Node* delNode){
    LL_Node* tgtPrevNode = pHead, *tgtNode;
    if (head_is_null()){return false;}
    while((tgtPrevNode->getNext() != delNode) || (tgtPrevNode != NULL)){
        tgtPrevNode = tgtPrevNode->getNext();
    }

    if (tgtPrevNode == NULL){return false;} // index에 노드가 없는 경우
    tgtNode = tgtPrevNode->getNext();
    if (tgtNode->getNext() == NULL){
        delete tgtNode; tgtPrevNode->setNext(NULL);
        return true;
    }
    tgtPrevNode->setNext(tgtPrevNode->getNext()->getNext());
    delete tgtNode;
    return true;
}

bool LL::search(char* sData, LL_Node* rNode, int* index){
    LL_Node* tgtNode;
    if (head_is_null()){return false;}
    while(tgtNode != NULL){
        if (strcmp(tgtNode->getData(), sData) == 0){break;}
        index++; tgtNode = tgtNode->getNext();
    }

    if (tgtNode == NULL){return false;}
    rNode = tgtNode;
    return true;
}

// LLd_Node
LLd_Node::LLd_Node(){pPrev = NULL;}

void LLd_Node::setPrev(LLd_Node* nPrev){pPrev = nPrev;}

LLd_Node* LLd_Node::getPrev(){return pPrev;}

// LLd
bool LLd::add(LLd_Node* newNode){
    LL_Node* lastNode = getHead();
    if (head_is_null()){setHead(newNode); return true;}
    while(lastNode->getNext() != NULL){lastNode = lastNode->getNext();}

    lastNode->setNext(newNode);
    return true;
}

bool LLd::remove(int index){
    LLd_Node* tgtNode;
    if (head_is_null()){return false;}
    for(int cmpIdx = 0; (cmpIdx < index) && (tgtNode != NULL); cmpIdx++){
        tgtNode = (LLd_Node*) tgtNode->getNext();
    }

    if (tgtNode == NULL){return false;}
    tgtNode->getNext()->setPrev(tgtNode->getPrev());
    tgtNode->getPrev()->setNext(tgtNode->getNext());
    delete tgtNode;
    return true;
}

bool LLd::remove(LLd_Node* delNode){
    LLd_Node* tgtNode;
    if (head_is_null()){return false;}
    while((tgtNode != delNode) && (tgtNode != NULL)){
        tgtNode = (LLd_Node*)tgtNode->getNext();
    }
    
    if (tgtNode == NULL){return false;}
    tgtNode->getNext()->setPrev(tgtNode->getPrev());
    tgtNode->getPrev()->setNext(tgtNode->getNext());
    delete tgtNode;
    return true;
}

