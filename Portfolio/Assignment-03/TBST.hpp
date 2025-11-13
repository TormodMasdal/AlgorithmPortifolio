#ifndef TBST_HPP
#define TBST_HPP

#include "TBSTNode.hpp"


template <typename Key, typename Data>
class TBST {
private:
	TBSTNode<Key, Data> * root;

public:
	// Constructor that initializes an empty tree
	TBST() : root(nullptr) {}

	void insert(Key aKey, Data aData) {
		root = TBSTNode<Key, Data>::insertRecursive(root, aKey, aData);
	}

	void remove(Key aKey) {
		root = TBSTNode<Key, Data>::deleteRecursive(root, aKey);
	}

	bool search(Key aKey) {
		return TBSTNode<Key, Data>::searchRecursive(root, aKey) != nullptr; // Returns true if a node is found and false if not
	}
};

#endif