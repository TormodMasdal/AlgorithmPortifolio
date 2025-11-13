
#include "TStack.h"
#include "iostream"
#include "TQueue.h"

// Constructor
template<typename T>
TStack<T>::TStack(int aMaxSize) : size(aMaxSize) {
    arr = new T*[size];
    itemAmount = 0;
}

// Destructor
template<typename T>
TStack<T>::~TStack() {
    delete[] arr;
}


// Adds a song to the stack
template<typename T>
void TStack<T>::Push(T *aSong) {
    // If the top element has same index as size, we cannot push more to the stack
    if (top == size - 1) {
        std::cout << "Stack overflow" << std::endl;
        return;
    }
    // gives the top element one highest index, and gives it the value to aSong
    arr[++top] = aSong;
    itemAmount++;
}

// Removes the item from the top of the stack
template<typename T>
T *TStack<T>::Pop() {
    // If the stack is not empty return the top element
    if (!IsEmpty()) {
        T* song = arr[top];
        top--;
        itemAmount--;
        return song;
    }
    return nullptr;
}

// Peeks the song at the top of the stack
template<typename T>
T *TStack<T>::Peek() {
    return arr[top];
}

// Return the song at the top of the stack
template<typename T>
bool TStack<T>::IsEmpty() const {
    return top == -1;
}

// Returns the previous song
template<typename T>
T* TStack<T>::PlayPreviousSong() {
    // Peeks the previous song
    TSong* song = HistoryStack->Peek();

    // Adds the previous song to the front of the list
    WishQueue->FrontOfQueue(song);

    // Now that the previous song is at the front of the list, play next song
    return TQueue<TSong>::PlayNextSong();

}

template<typename T>
void TStack<T>::ViewHistory() {
    if (HistoryStack->itemAmount == 0) {
        std::cout << "No songs finished played yet" << std::endl;
        return;
    };
    for (int i = 0; i < HistoryStack->itemAmount; i++) {
        T* song = HistoryStack->arr[i];
        if (song != nullptr) {
            std::cout << "Artist: " << song->GetArtist() << "\n";
            std::cout << "Title: "  << song->GetTitle()  << "\n";
            std::cout << "Year: "   << song->GetYear()   << "\n";
            std::cout << "Genre: "  << song->GetGenre()  << "\n";
            std::cout << "Source: " << song->GetSource() << "\n\n";
        }
    }
}


template class TStack<TSong>;






