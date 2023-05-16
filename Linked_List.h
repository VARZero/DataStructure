#pragma once

class LL_Node{
    // 단일 링크드 리스트 노드
    private:
        char* data;
        LL_Node* pNext;
    public:
        LL_Node();
        ~LL_Node();
        
        void setData(char* nData);
        void setNext(LL_Node* nNext);

        char* getData();
        LL_Node* getNext();

        virtual void setPrev(LLd_Node* nPrev);
};

class LL{
    // 단일 링크드 리스트
    private:
        LL_Node* pHead;
    public:
        LL();
        ~LL();

        bool head_is_null(){return (pHead == NULL);}
        LL_Node* getHead(){return pHead;}
        void setHead(LL_Node* nHead){pHead = nHead;}

        virtual bool add(LL_Node* newNode);
        virtual bool remove(int index);
        virtual bool remove(LL_Node* delNode);
        
        virtual bool search(char* sData, LL_Node* rNode, int* index);
};

class LLd_Node : public LL_Node{
    // 연속 링크드 리스트 노드
    private:
        LLd_Node* pPrev;
    public:
        LLd_Node();

        void setPrev(LLd_Node* nPrev);
        LLd_Node* getPrev();
};

class LLd : public LL{
    // 연속 링크드 리스트
    public:
        bool add(LLd_Node* newNode);
        bool remove(int index);
        bool remove(LLd_Node* delNode);
};

class LLc : public LL{
    // 순환 링크드 리스트 (단방향)
    public:
        bool add(LL_Node* newNode);
        bool remove(int index);
        bool remove(LL_Node* delNode);
};