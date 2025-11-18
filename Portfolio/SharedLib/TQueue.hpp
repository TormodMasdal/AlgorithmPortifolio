#ifndef TQUEUE_HPP
#define TQUEUE_HPP
#include "../Assignment-01/TSong.h"



template <typename T>
class TQueue {
public:
    explicit TQueue(const int aMaxSize, const bool aOwnsData): size(aMaxSize), ownsData(aOwnsData)  {
        arr = new T*[size];
    }

    ~TQueue(){
        if (ownsData) {
            for (int i = 0; i < size; i++) {
                delete arr[i];
            }
        }
        delete[] arr;
    }

    // Time complexity O(1), Space complexity O(1)
    void Enqueue(T* aData){
        if (count == size - 1) {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        back = (back+1) % size;
        arr[back] = aData;
        count++;
    }

    // Adds data to front of queue
    void FrontOfQueue(T* aData){
        if (count == size - 1) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        front = (front-1 + size) % size;
        arr[front] = aData;
        count++;
    }

    // Time complexity O(1). Space complexity O(1)
    T* Dequeue(){
        if (IsEmpty()) {
            std::cout << "Queue is already empty" << std::endl;
            return nullptr;
        }

        T* data = arr[front];
        front = (front+1) % size;
        count--;
        return data;
    }

    T* Peek(){
        if (IsEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return nullptr;
        }
        return arr[front];
    }

    [[nodiscard]] bool IsEmpty() const {
        return count == 0;
    }

private:
    int size;
    T** arr;
    int back = -1;
    int front = 0;
    int count = 0;
    bool ownsData;
};

// Global queues
inline auto MainQueue = new TQueue<TSong>(51, false);
inline auto WishQueue = new TQueue<TSong>(51, false);



#endif //TQUEUE_HPP