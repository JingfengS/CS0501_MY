//
// Created by Jingfeng Sun on 2024/5/12.
//

#ifndef BST_BSTNONRECURSIVE_H
#define BST_BSTNONRECURSIVE_H

#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

class BSTNonRecursive {
public:
    TreeNode* root;
    BSTNonRecursive() : root(nullptr) {}

    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (value < current->value) {
                current = current->left;
                if (current == nullptr) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == nullptr) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }

    bool search(int value) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->value == value) return true;
            else if (value < current->value) current = current->left;
            else current = current->right;
        }
        return false;
    }

    bool remove(int value) {
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        bool isLeftChild = true;

        while (current != nullptr && current->value != value) {
            parent = current;
            if (value < current->value) {
                isLeftChild = true;
                current = current->left;
            } else {
                isLeftChild = false;
                current = current->right;
            }
        }

        if (current == nullptr) return false;

        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) root = nullptr;
            else if (isLeftChild) parent->left = nullptr;
            else parent->right = nullptr;
        }
        else if (current->right == nullptr) {
            if (current == root) root = current->left;
            else if (isLeftChild) parent->left = current->left;
            else parent->right = current->left;
        }
        else if (current->left == nullptr) {
            if (current == root) root = current->right;
            else if (isLeftChild) parent->left = current->right;
            else parent->right = current->right;
        }
        else {
            TreeNode* successor = getSuccessor(current);
            if (current == root) root = successor;
            else if (isLeftChild) parent->left = successor;
            else parent->right = successor;
            successor->left = current->left;
        }
        delete current;
        return true;
    }

private:
    TreeNode* getSuccessor(TreeNode* delNode) {
        TreeNode* successorParent = delNode;
        TreeNode* successor = delNode;
        TreeNode* current = delNode->right;

        while (current != nullptr) {
            successorParent = successor;
            successor = current;
            current = current->left;
        }

        if (successor != delNode->right) {
            successorParent->left = successor->right;
            successor->right = delNode->right;
        }
        return successor;
    }
};

#endif //BST_BSTNONRECURSIVE_H
