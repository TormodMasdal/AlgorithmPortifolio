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

    void remove(Key aKey) {
        root = TAVLTreeNode<Key, Data>::deleteRecursive(root, aKey);
    }

    bool search(Key aKey) {
        return TAVLTreeNode<Key, Data>::searchRecursive(root, aKey) != nullptr;
    }

    void printInorder() { TAVLTreeNode<Key, Data>::inorder(root); }
    void printPreorder() { TAVLTreeNode<Key, Data>::preorder(root); }
    void printPostorder() { TAVLTreeNode<Key, Data>::postorder(root); }
    void printLevelOrder(){ TAVLTreeNode<Key, Data>::levelOrder(root); }
};

#endif