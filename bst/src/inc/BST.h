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
class BSTNon {
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
    BSTNon() {
        root = nullptr;
    }

    ~BSTNon() {
        clear(root);
    }

    /**
     * @return the size of the collection
     */
    int size() {
        return size(root);
    }

    /**
     * This method searches for a key in the collection
     * @param key
     * @return Value of the key
     */
    V search(K key) {
        TreeNode *searchResult = search(key, root);
        if (searchResult == nullptr) {
            throw std::runtime_error("The collection does not contain the key");
        }
        return searchResult->val;
    }

    /**
     * This method checks if the collection contains a key
     * @param key
     * @return true if key in the collection, false otherwise
     */
    bool containKey(K key) {
        TreeNode *searchResult = search(key, root);
        return searchResult != nullptr;
    }


    /**
     * This method inserts a key value pair into the collection
     * if key already exists, update the value
     * @param key
     * @param val
     */
    void insert(K key, V val) {
        root = insert(key, val, root);
    }

    /**
     * This method removes a key from the collection
     * @param key
     * @return val corresponds to key
     */
    V remove(K key) {
        V returnValue = search(key);
        root = remove(key, root);
        return returnValue;
    }

    /**
     * This method prints the collection in level order
     */
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

    /**
     * This method removes minimum elements from the collection
     * @return the value of the minimum element
     */
    V min() {
        TreeNode* minNode = min(root);
        return minNode->val;
    }

    /**
     * This method removes maximum elements from the collection
     * @return the value of the maximum element
     */
    V max() {
        return max(root)->val;
    }

    /**
     * This method removes the minimum element from the collection
     * @return the value of the minimum element
     */
    V delMin() {
        V returnValue = min(root)->val;
        root = delMin(root);
        return returnValue;
    }

    /**
     * This method removes the maximum element from the collection
     * @return the value of the maximum element
     */
    V delMax() {
        V returnValue = max(root)->val;
        root = delMax(root);
        return returnValue;
    }

    /**
     * This method checks if the collection is empty
     * @return true if the collection is empty, false otherwise
     */
    bool empty() {
        return root == nullptr;
    }

    /**
     * This method deletes all elements less than a key
     * @param key
     */
    void deleteLessThan(K key) {
        root = deleteLessThan(key, root);
    }

    /**
     * This method deletes all elements greater than a key
     * @param key
     */
    void deleteGreaterThan(K key) {
        root = deleteGreaterThan(key, root);
    }

    /**
     * This method deletes all elements within a range
     * @param left
     * @param right
     */
    void deleteRange(K left, K right) {
        root = deleteRange(left, right, root);
    }

    /**
     * This method finds the ith largest element in the collection
     * @param i
     * @return the value of the ith largest element
     */
    V findIthLargest(int i) {
        int count = 0;
        V val = V();
        reverseInOrder(root, i, count, val);
        return val;
    }

private:
    TreeNode* clear(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        clear(root->left);
        clear(root->right);
        delete root;
        return nullptr;
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

    TreeNode* min(TreeNode* root) {
        if (root == nullptr) {
            throw std::runtime_error("nullptr don't have min node!");
        }
        if (root->left == nullptr) {
            return root;
        }
        return min(root->left);
    }

    TreeNode* max(TreeNode* root) {
        if (root == nullptr) {
            throw std::runtime_error("nullptr don't have max node!");
        }
        if (root->right == nullptr) {
            return root;
        }
        return max(root->right);
    }

    TreeNode* delMin(TreeNode* root) {
        if (root == nullptr) {
            throw std::runtime_error("nullptr cannot delete!");
        }
        if (root->left == nullptr) {
            TreeNode* newRoot = root->right;
            delete root;
            return newRoot;
        }
        root->left = delMin(root->left);
        root->size = size(root->left) + size(root->right) + 1;
        return root;
    }

    TreeNode* delMax(TreeNode* root) {
        if (root == nullptr) {
            throw std::runtime_error("nullptr cannot delete!");
        }
        if (root->right == nullptr) {
            TreeNode* newRoot = root->left;
            delete root;
            return newRoot;
        }
        root->right = delMax(root->right);
        root->size = size(root->left) + size(root->right) + 1;
        return root;
    }

    TreeNode* remove(K key, TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            root->left = remove(key, root->left);
        } else if (key > root->key) {
            root->right = remove(key, root->right);
        } else {
           if (root->left == nullptr) {
               TreeNode* newRoot = root->right;
               delete root;
               return newRoot;
           } else if (root->right == nullptr) {
               TreeNode* newRoot = root->left;
                delete root;
                return newRoot;
           } else {
               TreeNode* tmp = root;
               TreeNode* tmpMin = min(root->right);
               root = new TreeNode(tmpMin->key, tmpMin->val);
               root->right = delMin(tmp->right);
               root->left = tmp->left;
           }
        }
        root->size = size(root->left) + size(root->right) + 1;
        return root;
    }

    TreeNode* deleteLessThan(K key, TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteLessThan(key, root->left);
            root->size = size(root->left) + size(root->right) + 1;
            return root;
        } else if (key > root->key) {
            TreeNode* newRoot = deleteLessThan(key, root->right);
            clear(root->left);
            delete root;
            return newRoot;
        } else if (key == root->key) {
            root->left = clear(root->left);
            root->size = size(root->left) + size(root->right) + 1;
            return root;
        }
    }

    TreeNode* deleteGreaterThan(K key, TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            TreeNode* newRoot = deleteGreaterThan(key, root->left);
            clear(root->right);
            delete root;
            return newRoot;
        } else if (key > root->key) {
            root->right = deleteGreaterThan(key, root->right);
            root->size = size(root->left) + size(root->right) + 1;
            return root;
        } else if (key == root->key) {
            root->right = clear(root->right);
            root->size = size(root->left) + size(root->right) + 1;
            return root;
        }
    }

    TreeNode* deleteRange(K left, K right, TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->key < left) {
            root->right = deleteRange(left, right, root->right);
            root->size = size(root->left) + size(root->right) + 1;
            return root;
        } else if (root->key > right) {
            root->left = deleteRange(left, right, root->left);
            root->size = size(root->left) + size(root->right) + 1;
            return root;
        } else {
            root->left = deleteRange(left, right, root->left);
            root->right = deleteRange(left, right, root->right);
            TreeNode* newRoot = merge(root->left, root->right);
            delete root;
            return newRoot;
        }
    }

    TreeNode* merge(TreeNode* left, TreeNode* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        TreeNode* maxLeft = max(left);
        maxLeft->right = right;
        TreeNode* node = maxLeft;
        node->size = size(node->left) + size(node->right) + 1;
        while (node != left) {
            node->size = size(node->left) + size(node->right) + 1;
            node = findParent(left, node);
        }
        return left;
    }

    TreeNode* findParent(TreeNode* root, TreeNode* target) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == target || root->right == target) {
            return root;
        }
        if (target->key < root->key) {
            return findParent(root->left, target);
        } else {
            return findParent(root->right, target);
        }
    }

    void reverseInOrder(TreeNode* root, int i, int &count, V &val) {
        if (root == nullptr || count >= i) {
            return;
        }
        reverseInOrder(root->right, i, count, val);
        count++;
        if (count == i) {
            val = root->val;
            return;
        }
        reverseInOrder(root->left, i, count, val);
    }
};

#endif //BST_BST_H
