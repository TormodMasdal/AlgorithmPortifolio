//
// Created by tormo on 11/4/2025.
//

#ifndef TSTACK_H
#define TSTACK_H
#include "TSong.h"


class TSong;

template<typename T>
class TStack {
public:
    explicit TStack(int aMaxSize);
    ~TStack();

    void Push(T* aSong);
    T* Pop();
    T* Peek();
    [[nodiscard]] bool IsEmpty() const;

    static void ViewHistory();
    static void PlayPreviousSong();

private:
    int size;
    T** arr = nullptr;
    int top = -1;
};

inline auto HistoryStack = new TStack<TSong>(50);


#endif //TSTACK_H
