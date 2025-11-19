#ifndef TBST_HPP
#define TBST_HPP

#include "TBSTNode.hpp"

template <typename Key, typename Data>
class TBST {
private:
	TBSTNode<Key, Data>* root;

	// Recursive function that is called by the destructor
	void deleteAllNodes(TBSTNode<Key, Data>* node) {
		if (!node) {
			return;
		}
		deleteAllNodes(node->leftChild); // Delete left subtree
		deleteAllNodes(node->rightChild); // Delete right subtree
		delete node->data; // Delete nodes data
		delete node; // Delete current node
	}

public:
	// Constructor that initializes an empty tree
	TBST() : root(nullptr) {}

	// Destructor
	~TBST() {
		deleteAllNodes(root);
		root = nullptr; // Set as nullptr to avoid dangling pointer
	}

	void insert(Key aKey, Data aData) {
		root = TBSTNode<Key, Data>::insertRecursive(root, aKey, aData);
	}

	void remove(Key aKey) {
		root = TBSTNode<Key, Data>::deleteRecursive(root, aKey);
	}

	bool search(Key aKey) {
		return TBSTNode<Key, Data>::searchRecursive(root, aKey) != nullptr; // Returns true if a node is found and false if not
	}

	void printInorder() {
		TBSTNode<Key, Data>::inorder(root);
	}

	void printPreorder() {
		TBSTNode<Key, Data>::preorder(root);
	}

	void printPostorder() {
		TBSTNode<Key, Data>::postorder(root);
	}

	void printLevelOrder() {
		TBSTNode<Key, Data>::levelOrder(root);
	}
};

#endif