#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H
#include "TNode.h"
#include "../Assignment-01/TSong.h"

template <typename T>
class TNode;

template <typename T>
class TLinkedList {
public:
    // Constructor and destructor
    explicit TLinkedList(bool aOwnsData);
    ~TLinkedList();

    void Append(T* aSong);
    void Delete(T* aSong);
    int GetSize();
    TNode<T>* GetHead();
    TNode<T>* GetTail();

    void PrintList();



private:
    TNode<T>* head; // Pointer to dummy head node
    TNode<T>* tail; // Pointer to dummy tail node
    bool ownsData; // Bool to see if the list owns the data
    int size; // Size of the list
};
// Global list for the song library
inline auto* songLibrary = new TLinkedList<TSong>(true);


#endif //TLINKEDLIST_H
