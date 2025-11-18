#ifndef TNODE_HPP
#define TNODE_HPP
#include "TLinkedList.hpp"


template <typename T>
class TNode {
public:
    explicit TNode(T* aData) : data(aData), next(nullptr), prev(nullptr) {}


    ~TNode(){
        // Sets all to nullptr to avoid dangling pointers
        data = nullptr; // Don't delete data, may exist outside the list
        next = nullptr;
        prev = nullptr;
    }

    // Getters
    T* GetData(){return data;}
    TNode* GetNextPtr(){return next;}
    TNode* GetPrevPtr(){return prev;}

    // Setters
    void SetNext(TNode* aNextNode){next = aNextNode;}
    void SetPrev(TNode* aPrevNode){prev = aPrevNode;}


private:
    T* data;
    TNode* next;
    TNode* prev;
};



#endif //TNODE_HPP