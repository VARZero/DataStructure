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

        void setRoot(nodeBST<I,T>* newRoot);
        nodeBST<I,T>* getRoot();

        bool add(nodeBST<I,T>* newNode);
        bool remove(nodeBST<I,T>* delNode);
        bool search(I findIdx);
        bool arrangement();
};

#endif