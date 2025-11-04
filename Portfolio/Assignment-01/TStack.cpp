
#include "TStack.h"
#include "iostream"
#include "TQueue.h"

// Constructor
template<typename T>
TStack<T>::TStack(int aMaxSize) : size(aMaxSize) {
    arr = new T*[size];
}

// Destructor
template<typename T>
TStack<T>::~TStack() {
    delete[] arr;
}


// Adds a song to the stack
template<typename T>
void TStack<T>::Push(T *aSong) {
    if (top == size - 1) {
        std::cout << "Stack overflow" << std::endl;
        return;
    }
    arr[++top] = aSong;
}

// Removes the item from the top of the stack
template<typename T>
T *TStack<T>::Pop() {
    if (!IsEmpty()) {
        T* song = arr[top];
        top--;
        return song;
    }
    throw std::runtime_error("Stack already empty");
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
void TStack<T>::PlayPreviousSong() {
    // Pops the previous song
    TSong* song = HistoryStack->Pop();

    // Adds the previous song to the front of the list
    WishQueue->FrontOfQueue(song);

    // Now that the previous song is at the front of the list, play next song
    TQueue<TSong>::PlayNextSong();

}

template<typename T>
void TStack<T>::ViewHistory() {
    // While the history stack is not empty, print the songs
    while (!HistoryStack->IsEmpty()) {
        TSong* song = HistoryStack->Pop();
        std::cout << "  Artist: " << song->GetArtist() << "\n";
        std::cout << "  Title: " << song->GetTitle() << "\n";
        std::cout << "  Year: " << song->GetYear() << "\n";
        std::cout << "  Genre: " << song->GetGenre() << "\n";
        std::cout << "  Source: " << song->GetSource() << "\n\n";
    }
}

template class TStack<TSong>;






