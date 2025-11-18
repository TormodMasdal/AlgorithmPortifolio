#ifndef TSTACK_HPP
#define TSTACK_HPP
#include "../Assignment-01/TSong.h"


class TSong;

template<typename T>
class TStack {
public:
    // Constructor
    explicit TStack(const int aMaxSize, const bool aOwnsData) : size(aMaxSize), ownsData(aOwnsData){
        arr = new T*[size];
        itemAmount = 0;
    }

    // Destructor
    ~TStack(){
        if (ownsData) {
            for (int i = 0; i < size; i++) {
                delete arr[i];
            }
        }
        delete[] arr; // The stack owns the array, not the elements
    }

    void Push(T* aData){
        // If the top element has same index as size, we cannot push more to the stack
        if (top == size - 1) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        // gives the top element one highest index, and gives it the value to aSong
        arr[++top] = aData;
        itemAmount++;
    }

    T* Pop(){
        // If the stack is not empty return the top element
        if (!IsEmpty()) {
            T* song = arr[top];
            top--;
            itemAmount--;
            return song;
        }
        return nullptr;
    }

    T* Peek(){
        return arr[top];
    }

    [[nodiscard]] bool IsEmpty() const{
        return top == -1;
    }

    [[nodiscard]] int GetItemAmount() const {
        return itemAmount;
    }

    T* GetArray(int aIndex) {
        return arr[aIndex];
    }

    int GetSize() {
        return size;
    }

private:
    int size;
    T** arr = nullptr;
    int top = -1;
    int itemAmount;
    bool ownsData;
};

// Global history stack
inline auto HistoryStack = new TStack<TSong>(51, false);


#endif //TSTACK_HPP
