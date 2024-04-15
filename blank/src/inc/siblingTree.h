//
// Created by Jingfeng Sun on 2024/4/7.
//

#ifndef TREE_SIBLINGTREE_H
#define TREE_SIBLINGTREE_H
#include <iostream>
#include <queue>
template <class T>
/**
 * This is my implementation of child-sibling tree
 * @tparam T data type
 */
class SiblingTree {
public:
    class Node {
    public:
        T data;
        Node* child;
        Node* sibling;
        Node() : data(T()), child(nullptr), sibling(nullptr) {}
        Node(T d, Node* c = nullptr, Node* s = nullptr) : data(d), child(c), sibling(s) {}
    };
    Node* root;
    /**
     * Default constructor
     */
    SiblingTree() {
        root = nullptr;
    }

    /**
     * Constructor with initial data
     */
     SiblingTree(T data) {
         root = new Node(data);
     }

     /**
      * Copy constructor of sibling tree
      * @param st
      */
     SiblingTree(const SiblingTree<T>& st) {
         root = copy(st.root);
     }

     /**
      * Operator= overloaded
      * @param other
      * @return *this
      */
     SiblingTree<T>& operator=(const SiblingTree<T>& other) {
         if (this != &other) {
            clear(root);
            root = copy(other.root);
         }
         return *this;
     }

     ~SiblingTree() {
         clear(root);
     }

     /**
      * Print out the sibling-child tree in pre order
      */
     void preOrder() const {
         preOrder(root);
         std::cout << std::endl;
     }

     /**
      * Print out the sibling tree in post order
      */
     void postOrder() const {
        postOrder(root);
        std::cout << std::endl;
     }

     /**
      * Print out the sibling tree in level order
      */
     void levelOrder() const {
        if (root == nullptr) {
            return;
        }
        std::queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node* n = queue.front();
            queue.pop();
            for (Node* tmp = n; tmp != nullptr; tmp = tmp->sibling) {
                std::cout << tmp->data << ' ';
                if (tmp->child != nullptr) {
                    queue.push(tmp->child);
                }
            }
        }
     };

private:
    Node* copy(Node* node) {
         if (node == nullptr) {
             return nullptr;
         }
         Node* tmp = new Node(node->data);
         tmp->child = copy(node->child);
         tmp->sibling = copy(node->sibling);
         return tmp;
     }

     void clear(Node* node) {
         if (node == nullptr) {
             return;
         }
         clear(node->child);
         clear(node->sibling);
         delete node;
     }

     void preOrder(Node* node) const {
         if (node == nullptr) {
             return;
         }
         std::cout << node->data << ' ';
         preOrder(node->child);
         preOrder(node->sibling);
     }

     void postOrder(Node* node) const {
         if (node == nullptr) {
             return;
         }
         postOrder(node->child);
         postOrder(node->sibling);
         std::cout << node->data << ' ';
     }
};

#endif //TREE_SIBLINGTREE_H
