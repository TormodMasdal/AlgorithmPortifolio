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
        TAVLTreeNode* x  = y->leftChild;
        TAVLTreeNode* T2 = x->rightChild;

        x->rightChild = y;
        y->leftChild  = T2;

        y->height = 1 + std::max(getHeight(y->leftChild),getHeight(y->rightChild));
        x->height = 1 + std::max(getHeight(x->leftChild),getHeight(x->rightChild));

        return x;
    }

    static TAVLTreeNode* rotateLeft(TAVLTreeNode* x) {
        TAVLTreeNode* y  = x->rightChild;
        TAVLTreeNode* T2 = y->leftChild;

        y->leftChild  = x;
        x->rightChild = T2;

        x->height = 1 + std::max(getHeight(x->leftChild),getHeight(x->rightChild));
        y->height = 1 + std::max(getHeight(y->leftChild),getHeight(y->rightChild));
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
            node->leftChild  = insertRecursive(node->leftChild, aKey, aData);
        }
        else if (aKey > node->key) {
            node->rightChild = insertRecursive(node->rightChild, aKey, aData);
        }

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
            node->leftChild = rotateLeft(node->leftChild);
            return rotateRight(node);
        }

        // 4) Right-Left case
        if (balance < -1 && aKey < node->rightChild->key) {
            node->rightChild = rotateRight(node->rightChild);
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