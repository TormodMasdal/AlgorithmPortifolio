#ifndef TAVLTree_HPP
#define TAVLTree_HPP

#include "TAVLTreeNode.hpp"

template <typename Key, typename Data>
class TAVLTree {
private:
    TAVLTreeNode<Key, Data>* root;

    // Recursive function that is called by the destructor
    void deleteAllNodes(TAVLTreeNode<Key, Data>* node) {
        if (!node) {
            return;
        }
        deleteAllNodes(node->leftChild); // Delete left subtree
        deleteAllNodes(node->rightChild); // Delete right subtree
        delete node; // Delete current node
    }

public:
    // Constructor that initializes an empty tree
    TAVLTree() : root(nullptr) {}

    // Destructor
    ~TAVLTree() {
        deleteAllNodes(root);
        root = nullptr; // Set as nullptr to avoid dangling pointer
    }

    void insert(Key aKey, Data aData) {
        root = TAVLTreeNode<Key, Data>::insertRecursive(root, aKey, aData);
    }

    void remove(Key aKey) {
        root = TAVLTreeNode<Key, Data>::deleteRecursive(root, aKey);
    }

    bool search(Key aKey) {
        return TAVLTreeNode<Key, Data>::searchRecursive(root, aKey) != nullptr;
    }

    void printInorder() {
        TAVLTreeNode<Key, Data>::inorder(root);
    }

    void printPreorder() {
        TAVLTreeNode<Key, Data>::preorder(root);
    }

    void printPostorder() {
        TAVLTreeNode<Key, Data>::postorder(root);
    }

    void printLevelOrder() {
        TAVLTreeNode<Key, Data>::levelOrder(root);
    }
};

#endif