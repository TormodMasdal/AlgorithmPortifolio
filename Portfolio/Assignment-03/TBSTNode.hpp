#ifndef TBSTNode_HPP
#define TBSTNode_HPP

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
		if (node == nullptr) {
			return new TBSTNode(aKey, aData) ;
		}

		// Recursive step, if key value is less than the nodes->key value go left
		if (aKey < node->key) {
			node->leftChild = insertRecursive(node->leftChild, aKey, aData);
		}
		// If key value is less than the nodes->key value go right
		else if (aKey > node->key) {
			node->rightChild = insertRecursive(node->rightChild, aKey, aData);
		}
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
		if (node == nullptr) {
			return node;
		}

		if (aKey < node->key) {
			node->leftChild = deleteRecursive(node->leftChild, aKey);
		}
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
		if (node == nullptr || node->key == aKey) {
			return node;
		}

		if (aKey < node->key) {
			return searchRecursive(node->leftChild, aKey);
		}
		return searchRecursive(node->rightChild, aKey);
	}
};

#endif