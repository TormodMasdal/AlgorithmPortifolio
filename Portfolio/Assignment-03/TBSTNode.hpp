#ifndef TBSTNode_HPP
#define TBSTNode_HPP
#include <queue>

//#include "TQueue.h"

template <typename Key, typename Data>
class TBSTNode {
public:
	Key key;
	Data data;
	TBSTNode* leftChild;
	TBSTNode* rightChild;

	TBSTNode(Key aKey, Data aData) : key(aKey), data(aData), leftChild(nullptr), rightChild(nullptr) {}

	static TBSTNode* insertRecursive(TBSTNode* node, Key aKey, Data aData) {
		// Base case
		if (node == nullptr) return new TBSTNode(aKey, aData);

		// Recursive step, if key value is less than the nodes->key value go left
		if (aKey < node->key) {
			node->leftChild = insertRecursive(node->leftChild, aKey, aData);
		}
		// If key value is more than the nodes->key value go right
		else if (aKey > node->key) {
			node->rightChild = insertRecursive(node->rightChild, aKey, aData);
		}
		// If aKey == node->key, we do nothing since keys are guaranteed to be unique
		return node;
	}

	// Helper function to find in-order successor(smallest value in the right subtree)
	static TBSTNode* findMinValueNode(TBSTNode* node)
	{
		TBSTNode* current = node;
		while (current && current->leftChild != nullptr) {
			current = current->leftChild;
		}
		return current;
	}

	static TBSTNode* deleteRecursive(TBSTNode* node, Key aKey) {
		// Base case
		if (node == nullptr) return node;

		// Recursive step, if key value is less than the nodes->key value go left
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
				delete node; // Delete the node
				node = nullptr; // Set it as nullptr because it still has an address
			}
			// Case 2: One child
			else if (node->leftChild == nullptr) {
				TBSTNode* temp = node; // Store the node we want to delete
				node = node->rightChild; // Move the right child
				delete temp;
			}
			else if (node->rightChild == nullptr) {
				TBSTNode* temp = node;
				node = node->leftChild;
				delete temp;
			}
			// Case 3: 2 children, two methods in-order predecessor (largest value in its left subtree) and in-order successor(smallest value in the right subtree)
			else {
				TBSTNode* temp = findMinValueNode(node->rightChild);
				node->key = temp->key;
				node->data = temp->data;
				node->rightChild = deleteRecursive(node->rightChild, temp->key);
			}
		}
		return node;

	}

	static TBSTNode* searchRecursive(TBSTNode* node, Key aKey) {
		// Base case
		if (node == nullptr || node->key == aKey) return node;

		if (aKey < node->key) return searchRecursive(node->leftChild, aKey);
		return searchRecursive(node->rightChild, aKey);
	}

	// Visit the left subtree first, then process the current node, and finally traverse the right subtree
	static void inorder(TBSTNode* node) {
		if (!node) return;
		inorder(node->leftChild);
		std::cout << node->key << " ";
		inorder(node->rightChild);
	}

	// Visit the current node first, then you traverse its left subtree, and finally its right subtree
	static void preorder(TBSTNode* node) {
		if (!node) return;
		std::cout << node->key << " ";
		preorder(node->leftChild);
		preorder(node->rightChild);
	}

	// Visit the left and right subtrees first, and process the current node last
	static void postorder(TBSTNode* node) {
		if (!node) return;
		postorder(node->leftChild);
		postorder(node->rightChild);
		std::cout << node->key << " ";
	}

	// Performs a Breadth-First Search (BFS), visit level by level
	static void levelOrder(TBSTNode* root) {
		if (!root) return;

		std::queue<TBSTNode*> queue;
		queue.push(root);
		int level = 0;

		while (!queue.empty()) {
			int nodesAtThisLevel = queue.size();

			std::cout << "Level " << level << ": ";

			for (int i = 0; i < nodesAtThisLevel; i++) {
				TBSTNode* node = queue.front();
				queue.pop();

				std::cout << node->key << " ";

				if (node->leftChild)  queue.push(node->leftChild);
				if (node->rightChild) queue.push(node->rightChild);
			}

			std::cout << std::endl;
			level++;
		}
	}


};

#endif