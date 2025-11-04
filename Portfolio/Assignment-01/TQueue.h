//
// Created by tormo on 11/4/2025.
//

#ifndef TQUEUE_H
#define TQUEUE_H
#include "TSong.h"



template <typename T>
class TQueue {
public:
    explicit TQueue(int aMaxSize);
    ~TQueue();

    void Enqueue(T* aSong);
    void FrontOfQueue(T* aSong);
    T* Dequeue();
    T* Peek();
    [[nodiscard]] bool IsEmpty() const;

    static T* PlayNextSong();

private:
    int size;
    T** arr;
    int back = -1;
    int front = 0;
    int count = 0;
};

// Global queues
inline auto MainQueue = new TQueue<TSong>(51);
inline auto WishQueue = new TQueue<TSong>(51);



#endif //TQUEUE_H
