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

    // Helper function to find in-order successor (smallest key in the right subtree)
    static TAVLTreeNode* findMinValueNode(TAVLTreeNode* node) {
        TAVLTreeNode* current = node;
        while (current && current->leftChild != nullptr) {
            current = current->leftChild;
        }
        return current;
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

    static TAVLTreeNode* rotateLeftRight(TAVLTreeNode* node) {
        // First perform left rotation on the nodes left child
        node->leftChild = rotateLeft(node->leftChild);
        // After rotation, we have a Left-Left case so we only need to do a simple right rotate
        return rotateRight(node);
    }

    static TAVLTreeNode* rotateRightLeft(TAVLTreeNode* node) {
        // First perform right rotation on the nodes right child
        node->rightChild = rotateRight(node->rightChild);
        // After rotation, we have a Right-Right case so we only need to do a simple left rotate
        return rotateLeft(node);
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
        if (balance > 1 && aKey < node->leftChild->key) return rotateRight(node);

        // 2) Right-Right case
        if (balance < -1 && aKey > node->rightChild->key) return rotateLeft(node);

        // 3) Left-Right case
        if (balance > 1 && aKey > node->leftChild->key) return rotateLeftRight(node);

        // 4) Right-Left case
        if (balance < -1 && aKey < node->rightChild->key) return rotateRightLeft(node);

        return node;
    }

    static TAVLTreeNode* deleteRecursive(TAVLTreeNode* node, Key aKey) {
        if (node == nullptr) return node;

        // If key value is less than the nodes->key value go left
        if (aKey < node->key) {
            node->leftChild = deleteRecursive(node->leftChild, aKey);
        }
        // If key value is more than the nodes->key value go right
        else if (aKey > node->key) {
            node->rightChild = deleteRecursive(node->rightChild, aKey);
        }
        // If none of the conditions above are true, then we found the node we want to delete
        else {
            // Case 1: No children
            if (node->leftChild == nullptr && node->rightChild == nullptr) {
                delete node->data;
                delete node; // Delete the node
                node = nullptr; // Set it as nullptr because it still has an address
            }
            // Case 2: One child
            else if (node->leftChild == nullptr) {
                TAVLTreeNode* temp = node; // Store the node we want to delete
                node = node->rightChild; // Move the right child
                delete temp->data;
                delete temp;
            }
            else if (node->rightChild == nullptr) {
                TAVLTreeNode* temp = node;
                node = node->leftChild;
                delete temp->data;
                delete temp;
            }
            // Case 3: Two children
            else {
                TAVLTreeNode* temp = findMinValueNode(node->rightChild);
                node->key = temp->key;
                *(node->data) = *(temp->data); // Copy the value
                node->rightChild = deleteRecursive(node->rightChild, temp->key);
            }
        }
        // After deletion we need to rebalance the tree

        if (node == nullptr) return node;

        // Update the height
        node->height = 1 + std::max(getHeight(node->leftChild),getHeight(node->rightChild));

        int balance = getBalanceFactor(node);

        // 1) Left-Left case
        if (balance > 1 && getBalanceFactor(node->leftChild) >= 0) {
            return rotateRight(node);
        }

        // 2) Right-Right case
        if (balance < -1 && getBalanceFactor(node->rightChild) <= 0) {
            return rotateLeft(node);
        }

        // 3) Left-Right case
        if (balance > 1 && getBalanceFactor(node->leftChild) < 0) {
            return rotateLeftRight(node);
        }

        // 4) Right-Left case
        if (balance < -1 && getBalanceFactor(node->rightChild) > 0) {
            return rotateRightLeft(node);
        }

        return node;
    }

    static TAVLTreeNode* searchRecursive(TAVLTreeNode* node, Key aKey) {
        // Base case
        if (node == nullptr || node->key == aKey) {
            return node;
        }

        if (aKey < node->key) {
            return searchRecursive(node->leftChild, aKey);
        }
        return searchRecursive(node->rightChild, aKey);
    }

    // Visit the left subtree first, then process the current node, and finally traverse the right subtree
    static void inorder(TAVLTreeNode* node) {
        if (!node) {
            return;
        }
        inorder(node->leftChild);
        std::cout << node->key << " ";
        inorder(node->rightChild);
    }

    // Visit the current node first, then you traverse its left subtree, and finally its right subtree
    static void preorder(TAVLTreeNode* node) {
        if (!node) {
            return;
        }
        std::cout << node->key << " ";
        preorder(node->leftChild);
        preorder(node->rightChild);
    }

    // Visit the left and right subtrees first, and process the current node last
    static void postorder(TAVLTreeNode* node) {
        if (!node) {
            return;
        }

        postorder(node->leftChild);
        postorder(node->rightChild);
        std::cout << node->key << " ";
    }

    // Performs a Breadth-First Search (BFS), visit level by level
    static void levelOrder(TAVLTreeNode* root) {
        if (!root) {
            return;
        }

        std::queue<TAVLTreeNode*> queue;
        queue.push(root);
        int level = 0;

        while (!queue.empty()) {
            int nodesAtThisLevel = queue.size();

            std::cout << "Level " << level << ": ";

            for (int i = 0; i < nodesAtThisLevel; i++) {
                TAVLTreeNode* node = queue.front();
                queue.pop();

                std::cout << node->key << " ";

                if (node->leftChild) {
                    queue.push(node->leftChild);
                }
                if (node->rightChild) {
                    queue.push(node->rightChild);
                }
            }
            std::cout << std::endl;
            level++;
        }
    }
};

#endif