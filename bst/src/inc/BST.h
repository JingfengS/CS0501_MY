//
// Created by Jingfeng Sun on 2024/5/12.
//

#ifndef BST_BST_H
#define BST_BST_H
#include <exception>
#include <queue>
#include <iostream>


template <class  K, class V>
/**
 * This is my own implementation of a Binary Search Tree
 * @tparam T Generic Type
 */
class BST {
    class TreeNode {
    public:
        K key;
        V val;
        TreeNode *left;
        TreeNode *right;
        int size;

        explicit TreeNode(K key, V val) : key(key), val(val), left(nullptr), right(nullptr), size(1) {}

        TreeNode(K key, V val, TreeNode *left, TreeNode *right, int size) : key(key), val(val), left(left),
                                                                            right(right),
                                                                            size(right->size + left->size + 1) {}
    };

    TreeNode *root;

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        clear(root);
    }

    int size() {
        return root->size;
    }

    V search(K key) {
        // TODO: write this method
        TreeNode *searchResult = search(key, root);
        if (searchResult == nullptr) {
            throw std::runtime_error("The collection does not contain the key");
        }
        return searchResult->val;
    }

    bool containKey(K key) {
        TreeNode *searchResult = search(key, root);
        return searchResult != nullptr;
    }


    void insert(K key, V val) {
        // TODO: write this method
        root = insert(key, val, root);
    }

    V remove(K key) {
        // TODO: fill this method
    }

    void printLevelOrder() {
        if (root == nullptr) {
            return;
        }
        std::queue<TreeNode*> fringe;
        fringe.push(root);
        while (!fringe.empty()) {
            TreeNode* curr = fringe.front();
            fringe.pop();
            std::cout << curr->key << ": " << curr->val << "    ";
            if (curr->left != nullptr) {
                fringe.push(curr->left);
            }
            if (curr->right != nullptr) {
                fringe.push(curr->right);
            }
        }
        std::cout << std::endl;
    }

private:
    void clear(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        clear(root->left);
        clear(root->right);
        delete root;
    }

    TreeNode *search(K key, TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->key == key) {
            return root;
        }
        if (key < root->key) {
            return search(key, root->left);
        } else {
            return search(key, root->right);
        }
    }

    TreeNode* insert(K key, V val, TreeNode *root) {
        if (root == nullptr) {
            return new TreeNode(key, val);
        }
        if (key < root->key) {
            root->left = insert(key, val, root->left);
        } else if (key > root->key) {
            root->right = insert(key, val, root->right);
        } else {
            root->val = val;
        }
        root->size = size(root->left) + size(root->right) + 1;
        return root;
    }

    int size(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return root->size;
    }

};

#endif //BST_BST_H
