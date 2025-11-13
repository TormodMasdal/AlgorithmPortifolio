//
// Created by tormo on 11/4/2025.
//

#ifndef TSTACK_H
#define TSTACK_H
#include "../Assignment-01/TSong.h"


class TSong;

template<typename T>
class TStack {
public:
    // Constructor and destructor
    explicit TStack(int aMaxSize);
    ~TStack();

    void Push(T* aSong); // Add a song to the stack
    T* Pop(); // Remove the top of the stack
    T* Peek(); // Look at the top of the stack
    [[nodiscard]] bool IsEmpty() const; // Check if stack is empty

    static void ViewHistory(); // View all songs listened to
    static T* PlayPreviousSong(); // Play the most recent song

private:
    int size; // Size of the stack
    T** arr = nullptr; // Array. The data structure for the stack
    int top = -1; // Sets the top item to -1, so when we add an element to the array it will have the correct index: 0
    int itemAmount; // Amount of items in the stack
};

// Global history stack
inline auto HistoryStack = new TStack<TSong>(51);


#endif //TSTACK_H
