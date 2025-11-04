//
// Created by tormo on 11/3/2025.
//

#ifndef TNODE_H
#define TNODE_H
#include "TLinkedList.h"


template <typename T>
class TNode {
public:
    explicit TNode(T* aData); // Constructor
    ~TNode(); // Destructor

    // Getters
    T* GetData();
    TNode* GetNextPtr();
    TNode* GetPrevPtr();

    // Setters
    void SetNext(TNode* aNextNode);
    void SetPrev(TNode* aPrevNode);


private:
    T* data; // Data of type T
    TNode* next; // Pointer to next node
    TNode* prev; // Pointer to previous node
};



#endif //TNODE_H
