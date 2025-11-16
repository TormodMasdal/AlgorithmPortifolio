#ifndef TAVLTree_HPP
#define TAVLTree_HPP

#include "TAVLTreeNode.hpp"


template <typename Key, typename Data>
class TAVLTree {
private:
    TAVLTreeNode<Key, Data>* root;

public:
    // Constructor that initializes an empty tree
    TAVLTree() : root(nullptr) {}

    void insert(Key aKey, Data aData) {
        root = TAVLTreeNode<Key, Data>::insertRecursive(root, aKey, aData);
    }

    bool search(Key aKey) {
        return TAVLTreeNode<Key, Data>::searchRecursive(root, aKey) != nullptr;
    }
};

#endif