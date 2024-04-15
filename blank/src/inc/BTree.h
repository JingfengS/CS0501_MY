//
// Created by Jingfeng Sun on 2024/4/7.
//

#ifndef TREE_BTREE_H
#define TREE_BTREE_H
#include <iostream>
template <class T>
/**
 * This is my implementation of a Binary Tree
 * Yeah, this is just a silly binary tree...
 */
class BTree {
public:
    class Node {
    public:
        T key;
        Node* left;
        Node* right;
        Node() : key(T()), left(nullptr), right(nullptr) {}
        Node(T t, Node* l = nullptr, Node* r = nullptr) : key(t), left(l), right(r) {}
    };
    Node* root;
    /**
     * Defaut constructor
     */
    BTree() {
        root = nullptr;
    }

    BTree(T d) {
        root = new Node(d);
    }

    /**
     * Copy constructor
     * @param bt Btree instance to copy
     */
    BTree(const BTree<T>& bt) : BTree() {
        root = copy(bt.root);
    }

    /**
     * overloaded = operator
     * @param other
     * @return other
     */
    BTree<T>& operator=(const BTree<T>& other) {
        if (this != &other) {
            clear(root);
            root = copy(other.root);
        }
        return *this;
    }

    ~BTree() {
        clear(root);
    }

    /**
     * Delete all the node below node, includes node
     * @param node the node to delete
     */
    void deleteNode(Node* node) {
        if (node == root) {
            clear(root);
            root = nullptr;
            return;
        }
        clear(node);
    }

    /**
     * Print all the keys in nodes
     */
    void printTree() const {
        printTree(root);
        std::cout << std::endl;
    }

    /**
     * @return if the tree is empty
     */
    bool isEmpty() const {
        return root == nullptr;
    }

    /**
     * @return the num of branches that have 2 childs
     */
    int numOf2ChildsParents() const {
        return twoNodes(root);
    }

    /**
     * @return true if the tree is a complete tree
     * false otherwise.
     */
    bool isComplete() const {
        int size = countSize(root);
        return isComplete(root, 0, size);
    }
private:
    Node* copy(const Node* node) const {
        if (node == nullptr) {
            return nullptr;
        }
        Node* topNode = new Node(node->key);
        topNode->left = copy(node->left);
        topNode->right = copy(node->right);
        return topNode;
    }

    void clear(Node* node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void printTree(Node* n) const {
        if (n == nullptr) {
            return;
        }
        std::cout << n->key << " ";
        printTree(n->left);
        printTree(n->right);
    }

    Node* find(T x, Node* n) {
        if (n == nullptr) {
            return;
        }
        if (n->key == x) {
            return n;
        }
        Node* leftfind = find(x, n->left);
        if (leftfind == nullptr) {
            return find(x, n->right);
        }
        return leftfind;
    }

    int twoNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        if (node->right != nullptr && node->left != nullptr) {
            return 1 + twoNodes(node->left) + twoNodes(node->right);
        }
        return twoNodes(node->left) + twoNodes(node->right);
    }

    int countSize(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countSize(node->left) + countSize(node->right);
    }

    bool isComplete(Node* node, int index, int size) const {
        if (node == nullptr) {
            return true;
        }
        if (index >= size) {
            return false;
        }
        return isComplete(node->left, index * 2 + 1, size) && isComplete(node->right, index * 2 + 2, size);
    }
};

#endif //TREE_BTREE_H
