#ifndef __VZ_HEAP__
#define __VZ_HEAP__

template<typename T>
class heap{
    private:
        T* data;
        int into;
        int size;
    public:
        heap(int);
        ~heap();

        bool enqueue(T);
        T dequeue();

        int getInto();
};

template<typename T>
heap<T>::heap(int setSize){ size = setSize; into = 0; data = new T[size]; }

template<typename T>
heap<T>::~heap(){ delete data; }

template<typename T>
bool heap<T>::enqueue(T newData){
    if (into >= size){ return false; }
    data[into++] = newData; return true;
}

template<typename T>
T heap<T>::dequeue(){
    if (into == 0){return NULL;}
    T out = data[0];
    for(int i = 1; i <= size; i++){
        data[i-1] = data[i];
    }
    into--; return out;
}

template<typename T>
int heap<T>::getInto(){ return into; }

#endif