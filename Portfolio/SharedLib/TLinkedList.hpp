#ifndef TLINKEDLIST_HPP
#define TLINKEDLIST_HPP
#include "TNode.hpp"
#include "../Assignment-01/TSong.h"

template <typename T>
class TNode;

template <typename T>
class TLinkedList {
public:
    // Constructor and destructor
    explicit TLinkedList(const bool aOwnsData) : size(0) {
        // Creates dummy nodes
        head = new TNode<T>(nullptr);
        tail = new TNode<T>(nullptr);
        ownsData = aOwnsData;

        head->SetNext(tail);
        tail->SetPrev(head);
    }
    ~TLinkedList() {
        TNode<T>* temp = head; // Temporary node to iterate through list
        while (temp != nullptr) { // Iterate through the entire list
            TNode<T>* next = temp->GetNextPtr(); // Saves the next ptr
            if (ownsData && temp->GetData() != nullptr) {
                delete temp->GetData(); // Delete the data
            }
            delete temp; // Delete the node
            temp = next;
        }
    }

    void Append(T* aSong) {
        // Creates a new node
        auto* newNode = new TNode<T>(aSong);
        newNode->SetNext(tail); // Next points to the tail
        newNode->SetPrev(tail->GetPrevPtr()); // The new nodes prev will be the tail prevs

        tail->GetPrevPtr()->SetNext(newNode); // The node which pointed to tail will now point to the new node
        tail->SetPrev(newNode); // Tail prev will now point to the new node

        size++;
    }
    void Delete(T* aSong) {
        // Creates an iterating node
        auto* temp = head->GetNextPtr();
        while (temp != tail) { // Loops until the list is iterated through
            if (temp->GetData() == aSong) { // If the node data corresponds with the song, delete the node
                temp->GetNextPtr()->SetPrev(temp->GetPrevPtr());
                temp->GetPrevPtr()->SetNext(temp->GetNextPtr());
                delete temp;
                return;
            }
            temp = temp->GetNextPtr();
        }
    }
    int GetSize() const {return size;}
    TNode<T>* GetHead(){return head;}
    TNode<T>* GetTail(){return tail;}

    void PrintList() {
        auto* temp = head->GetNextPtr();
        while (temp != tail) {
            std::cout << "  Artist: " << temp->GetData()->GetArtist() << "\n";
            std::cout << "  Title: " << temp->GetData()->GetTitle() << "\n";
            std::cout << "  Year: " << temp->GetData()->GetYear() << "\n";
            std::cout << "  Genre: " << temp->GetData()->GetGenre() << "\n";
            std::cout << "  Source: " << temp->GetData()->GetSource() << "\n\n";
            temp = temp->GetNextPtr();
        }
    }

private:
    TNode<T>* head; // Pointer to dummy head node
    TNode<T>* tail; // Pointer to dummy tail node
    bool ownsData; // Bool to see if the list owns the data
    int size; // Size of the list
};

// Global list for the song library
inline auto* songLibrary = new TLinkedList<TSong>(true);


#endif //TLINKEDLIST_HPP