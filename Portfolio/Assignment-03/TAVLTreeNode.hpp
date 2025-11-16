#ifndef TAVLTreeNode_HPP
#define TAVLTreeNode_HPP

#include "TBSTNode.hpp"

template <typename Key, typename Data>
class TAVLTreeNode{
private:
    int height;

    static int getHeight(TAVLTreeNode* node) {
        return node ? node->height : 0;
    }

    static int getBalanceFactor(TAVLTreeNode* node) {
        if (node == nullptr) return 0;
        return getHeight(node->leftChild) - getHeight(node->rightChild);
    }

    static TAVLTreeNode* rotateRight(TAVLTreeNode* y) {
        // 1. Identify the new root (y) and the subtree to move (T2)
        TAVLTreeNode* x = y->leftChild;
        TAVLTreeNode* T2 = x->rightChild;

        // 2. Perform the rotation
        x->rightChild = y;
        y->leftChild = T2;

        // 3. Update the heights
        y->height = 1 + std::max(getHeight(y->leftChild),getHeight(y->rightChild));
        x->height = 1 + std::max(getHeight(x->leftChild),getHeight(x->rightChild));

        //4. Return the root of the subtree
        return x;
    }

    static TAVLTreeNode* rotateLeft(TAVLTreeNode* x) {
        // 1. Identify the new root (y) and the subtree to move (T2)
        TAVLTreeNode* y = x->rightChild;
        TAVLTreeNode* T2 = y->leftChild;

        // 2. Perform the rotation
        y->leftChild = x;
        x->rightChild = T2;

        // 3. Update the heights
        x->height = 1 + std::max(getHeight(x->leftChild),getHeight(x->rightChild));
        y->height = 1 + std::max(getHeight(y->leftChild),getHeight(y->rightChild));

        // 4. Return the root of the subtree
        return y;
    }

public:
    Key key;
    Data data;
    TAVLTreeNode* leftChild;
    TAVLTreeNode* rightChild;

    TAVLTreeNode(Key aKey, Data aData) : key(aKey), data(aData), leftChild(nullptr), rightChild(nullptr), height(1) {}


    static TAVLTreeNode* insertRecursive(TAVLTreeNode* node, Key aKey, Data aData) {
        if (node == nullptr) return new TAVLTreeNode(aKey, aData);

        if (aKey < node->key) {
            node->leftChild = insertRecursive(node->leftChild, aKey, aData);
        }
        else if (aKey > node->key) {
            node->rightChild = insertRecursive(node->rightChild, aKey, aData);
        }
        // If aKey == node->key, we do nothing since keys are guaranteed to be unique

        node->height = 1 + std::max(getHeight(node->leftChild),getHeight(node->rightChild));

        int balance = getBalanceFactor(node);

        // 1) Left-Left case
        if (balance > 1 && aKey < node->leftChild->key)
            return rotateRight(node);

        // 2) Right-Right case
        if (balance < -1 && aKey > node->rightChild->key)
            return rotateLeft(node);

        // 3) Left-Right case
        if (balance > 1 && aKey > node->leftChild->key) {
            // First perform left rotation on nodes left child
            node->leftChild = rotateLeft(node->leftChild);
            // After rotation, we have a Left-Left case so we only need to do a simple right rotate
            return rotateRight(node);
        }

        // 4) Right-Left case
        if (balance < -1 && aKey < node->rightChild->key) {
            // First perform right rotation on nodes right child
            node->rightChild = rotateRight(node->rightChild);
            // After rotation, we have a Right-Right case so we only need to do a simple left rotate
            return rotateLeft(node);
        }
        return node;
    }

    static TAVLTreeNode* searchRecursive(TAVLTreeNode* node, Key aKey) {
        // Base case
        if (node == nullptr || node->key == aKey) return node;

        if (aKey < node->key) {
            return searchRecursive(node->leftChild, aKey);
        }
        return searchRecursive(node->rightChild, aKey);
    }
};

#endif