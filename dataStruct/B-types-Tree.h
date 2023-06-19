#ifndef __VZ_BTREE__
#define __VZ_BTREE__

template<typename I,typename D>
class nodeB_Tree{
    private:
        nodeB_Tree<I,D>* leftPtr;
        I leftIndex;
        D leftData;
        nodeB_Tree<I,D>* centerPtr;
        I rightIndex;
        D rightData;
        nodeB_Tree<I,D>* rightPtr;
};

#endif