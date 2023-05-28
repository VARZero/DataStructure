#ifndef __VZ_STACK__
#define __VZ_STACK__

template<typename T>
class stack{
    private:
        T* data;
        int into;
        int size;
    public:
        stack(int);
        ~stack();

        bool Push(T);
        T Pop();

        int getInto();
};

template<typename T>
stack<T>::stack(int setSize){ size = setSize; into = 0; data = new T[size]; }

template<typename T>
stack<T>::~stack(){ delete data; }

template<typename T>
bool stack<T>::Push(T inData){
    if (into >= size){return false;}
    data[into++] = inData; return true;
}

template<typename T>
T stack<T>::Pop(){
    if (into == 0){return NULL;}
    return data[--into];
}

template<typename T>
int stack<T>::getInto(){return into;}

#endif