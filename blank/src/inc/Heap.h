//
// Created by Jingfeng Sun on 2024/4/7.
//

#ifndef TREE_HEAP_H
#define TREE_HEAP_H
#include <iostream>
#include <exception>
#include <queue>
#include <climits>
template <class T>
/**
 * This is my own implementation of Heap class,
 * note that the rootIndex will be 1
 * @tparam T the type of data to be stored
 */
class Heap {
private:
    class Node {
    public:
        int priority;
        T item;
        Node(int p, T t) : priority(p), item(t) {}
    };
    Node** contents;
    int size;
    int capicity;
    const static int rootIndex = 1;

    /**
     * Making sure the index of the node is validate
     * @param index
     */
    void validateSinkSwimArg(int index) {
        if (index < 1) {
            throw std::runtime_error("Cannot sink or swim nodes with idnex 0 or less");
        }
        if (index > size) {
            throw std::runtime_error("Cannot sink or swim nodes with index greater than current size");
        }
        if (contents[index] == nullptr) {
            throw std::runtime_error("Cannot sink or swim a null node");
        }
    }

    /**
     * Resize the contents array to be cap
     * @param cap the capicity to be resized
     */
    void resize(int cap) {
        Node** tmpContents = new Node*[cap];
        for (int i = 0; i < size + 1; i++) {
            tmpContents[i] = contents[i];
        }
        delete [] contents;
        contents = tmpContents;
        capicity = cap;
    }

    /**
     * The left child index of Node i
     * @param i the index of the node
     * @return the left child index of Node i
     */
    int leftIndex(int i) {
        return 2 * i;
    }

    /**
     * The right child index of Node i
     * @param i the index of the node
     * @return the right child index of Node i
     */
    int rightIndex(int i) {
        return 2 * i + 1;
    }

    /**
     * @param i the index of Node i
     * @return the parent Node index of Node i
     */
    int parentIndex(int i) {
       if (i <= rootIndex) {
           throw std::runtime_error("Root Node has no parent");
       }
       return i / 2;
    }

    /**
     * Check that if index is validate, raise error if not
     * @param index the index of the Node to be checked
     */
    bool inBounds(int index) {
        if (index < 1) {
            return false;
        }
        if (index > size) {
            return false;
        }
        if (contents[index] == nullptr) {
            return false;
        }
        return true;
    }

    /**
     * Get the Node corresponds to the index,
     * this method is used to build abstraction
     * raise error if the index is not exist
     * @param index the index of the Node to get
     * @return the Node pointer to the index of the Node
     */
    Node* getNode(int index) {
        if (inBounds(index)) {
            return contents[index];
        }
        if (index > size) {
            return nullptr;
        }
        throw std::runtime_error("The node you asked is not in bound");
    }

    /**
     * Add one Node at the end of the array to make sure that the tree is complete
     * Resize the array if needed
     * this method is used to build abstraction
     * @param item the data stored in the new Node
     * @param pri the priority of the new Node
     */
    void addNode(T item, int pri) {
        Node* newNode = new Node(pri, item);
        if (size + 1 >= capicity) {
            resize(capicity * 2);
        }
        size += 1;
        contents[size] = newNode;
    }

    /**
     * Delete the last Node of the array
     * this method is used to build abstraction
     */
    void deleteLastNode() {
        if (size == 0) {
            throw std::runtime_error("No item in this heap to delete");
        }
        if (double(size - 1) / capicity < 0.25 && capicity > 16) {
            resize(capicity / 2);
        }
        delete contents[size];
        size -= 1;
    }

    /**
     * Swap the contents of the Node in index1 and index2
     * @param index1 the first node to swap
     * @param index2 the second node to swap
     */
    void swap(int index1, int index2) {
        Node* node1 = getNode(index1);
        Node* node2 = getNode(index2);
        contents[index1] = node2;
        contents[index2] = node1;
    }

    /**
     * Return the index with smaller priority
     * @param index1 the first index
     * @param index2 the second index
     * @return the index from index1 and index2 which is smaller
     */
    int min(int index1, int index2) {
        Node* p1 = getNode(index1);
        Node* p2 = getNode(index2);
        if (p1 == nullptr) {
            return index2;
        } else if (p2 == nullptr) {
            return index1;
        } else if (p1->priority < p2->priority) {
            return index1;
        } else {
            return index2;
        }
    }

    /**
     * Bubbles up the node currently at the given index
     * @param index
     */
    void swim(int index) {
        validateSinkSwimArg(index);
        if (index == rootIndex) {
            return;
        }
        if (getNode(index)->priority >= getNode(parentIndex(index))->priority) {
            return;
        }
        swap(index, parentIndex(index));
        swim(parentIndex(index));
    }

    /**
     * Bubbles down the node currently at the given index.
     */
    void sink(int index) {
        validateSinkSwimArg(index);
        if (getNode(leftIndex(index)) == nullptr && getNode(rightIndex(index)) == nullptr) {
            return;
        }
        int minLeftRightIndex = min(leftIndex(index), rightIndex(index));
        if (getNode(index)->priority <= getNode(minLeftRightIndex)->priority) {
            return;
        }
        swap(index, minLeftRightIndex);
        sink(minLeftRightIndex);
    }

    int changePriorityUtil(T item, int priority) {
        for (int i = 1; i < size + 1; i++) {
            if (getNode(i)->item == item) {
                getNode(i)->priority = priority;
                return i;
            }
        }
        throw std::runtime_error("No such node that has the very item");
    }

public:
    Heap() {
        capicity = 16;
        contents = new Node*[capicity];
        contents[0] = nullptr;
        size = 0;
    }

    Heap(const Heap<T>& h) {
        capicity = h.capicity;
        size = h.size;
        contents = new Node*[capicity];
        for (int i = 0; i < size + 1; i++) {
            contents[i] = h.contents[i];
        }
    }

    ~Heap() {
        size = 0;
        delete [] contents;
    }

    Heap<T>& operator=(const Heap<T>& other) {
        if (this != &other) {
            size = other.size;
            capicity = other.capicity;
            delete [] contents;
            contents = new Node[capicity];
            for (int i = 0; i < size + 1; i++) {
                contents[i] = other.contents[i];
            }
        }
        return *this;
    }

    /**
     * Inserts an item with the given priority value. This is enqueue, or offer.
     * To implement this method, add it to the end of the ArrayList, then swim it.
     */
    void insert(T item, int priority) {
        addNode(item, priority);
        swim(size);
    }

    /**
     * Returns the Node with the smallest priority value, but does not remove it
     * from the heap. To implement this, return the item in the 1st position of the ArrayList.
     */
    T peek() {
        if (size == 0) {
            throw std::runtime_error("No item in this heap");
        }
        return getNode(rootIndex)->item;
    }

    /**
    * Returns the Node with the smallest priority value, and removes it from
    * the heap. This is dequeue, or poll. To implement this, swap the last
    * item from the heap into the root position, then sink the root. This is
    * equivalent to firing the president of the company, taking the last
    * person on the list on payroll, making them president, and then demoting
    * them repeatedly. Make sure to avoid loitering by nulling out the dead
    * item.
    */
    T removeMin() {
        T minItem = peek();
        if (size == 1) {
            delete contents[size];
            size -= 1;
            return minItem;
        }
        swap(rootIndex, size);
        deleteLastNode();
        sink(rootIndex);
        return minItem;
    }
   /**
   * Change the node in this heap with the given item to have the given
   * priority. You can assume the heap will not have two nodes with the same
   * item.
   */
    void changePriority(T item, int priority) {
        int index = changePriorityUtil(item, priority);
        sink(index);
        swim(index);
    }

    /**
     * Return the number of Items in the PQ
     * @return size
     */
    int getSize() {
        return size;
    }

    int findMin(int x) {
        using std::queue;
        queue<int> qu;
        int root = rootIndex;
        qu.push(root);
        int minIndex = -1;
        int minPriority = INT_MAX;
        while (!qu.empty()) {
            int index = qu.front();
            qu.pop();
            if (getNode(index)->priority < x) {
                if (inBounds(leftIndex(index))) {
                    qu.push(leftIndex(index));
                }
                if (inBounds(rightIndex(index))) {
                    qu.push(rightIndex(index));
                }
            } else {
                if (getNode(index)->priority < minPriority) {
                    minPriority = getNode(index)->priority;
                    minIndex = index;
                }
            }
        }
        return minIndex;
    }

    T getValue(int index) {
        if (index == -1) {
            throw std::runtime_error("No such item in contents!");
        }
        validateSinkSwimArg(index);
        return getNode(index)->item;
    }

    void decreaseKey(int index, int value) {
        validateSinkSwimArg(index);
        getNode(index)->priority -= value;
        swim(index);
        sink(index);
    }

    void printContent() {
        for (int i = 1; i < size + 1; i++) {
            std::cout << getNode(i)->priority << " ";
        }
        std::cout << std::endl;
    }
};


#endif //TREE_HEAP_H
