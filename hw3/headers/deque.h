//
// Created by Jingfeng Sun on 2024/3/29.
//

#ifndef HW3_DEQUE_H
#define HW3_DEQUE_H
/**
 * This is my implementation of deque
 * It is implemented using Circular Linked List
 * @tparam T the Data stored in each Node
 */
#include <iostream>
#include <stdexcept>

template <class T>
class deque {
    /**
     * This is a double linked Node
     */
    class Node {
    public:
        Node* prev;
        T data;
        Node* next;
        Node() {
            prev = this;
            data = T();
            next = this;
        }
        Node(Node* pr, T x, Node* ne) {
            prev = pr;
            data = x;
            next = ne;
        }
    };
private:
    Node* sentinel;
    int size;

    void destructorHelper(Node* head) {
        if (size == 0) {
            delete head;
            return;
        }
        Node* ne = sentinel->next;
        size--;
        delete head;
        destructorHelper(ne);
    }

    T get(int index, Node* node) const {
        if (index == 0) {
            return node->data;
        }
        return get(index - 1, node->next);
    }

public:
    deque() {
        size = 0;
        sentinel = new Node();
    }

    deque(const deque<T>& dq) : deque() {
        for (int i = 0; i < dq.size; i++) {
            addLast(dq.get(i));
        }
    }

    deque<T>& operator=(const deque<T>& other) {
        if (this != &other) {
            destructorHelper(sentinel);
            sentinel = new Node();
            for (int i = 0; i < other.size; i++) {
                addLast(other.get(i));
            }
        }
        return *this;

    }

    ~deque() {
        destructorHelper(sentinel);
    }

    /**
     * Print the deque in order
     */
    void printList() const {
        Node* p = sentinel->next;
        while (p != sentinel) {
            std::cout << p->data << ' ';
            p = p->next;
        }
        std::cout << std::endl;
    }

    /**
     * Check if the deque is empty
     * @return true if empty false otherwise
     */
    bool isEmpty() const {
        return size == 0;
    }

    /**
     * Get the size of the deque
     * @return the size of the deque
     */
    int getSize() const {
        return size;
    }

    /**
     * Add an item in the end of the deque
     * @param x the item to add
     */
    void addLast(T x) {
        Node *lastNode = sentinel->prev;
        Node *newNode = new Node(lastNode, x, sentinel);
        sentinel->prev = newNode;
        lastNode->next = newNode;
        size++;
    }

    /**
     * Add an item at the front of the deque
     * @param x  the item to add to the front
     */
    void addFirst(T x) {
        Node* firstNode = sentinel->next;
        Node* newFirstNode = new Node(sentinel, x, firstNode);
        sentinel->next = newFirstNode;
        firstNode->prev = newFirstNode;
        size++;
    }

    /**
     * Get the first item of the deque,
     * if the deque is empty, raise runtime exception.
     * @return the first item in the deque
     */
    T getFirst() const {
        if (isEmpty()) {
            throw std::runtime_error("The deque is empty!");
        }
        return sentinel->next->data;
    }

    /**
     * Get the last item of the deque,
     * if the deque is empty, raise runtime exception.
     * @return the last item in the deque
     */
    T getLast() const {
        if (isEmpty()) {
            throw std::runtime_error("The deque is empty!");
        }
        return sentinel->prev->data;
    }

    /**
     * Get the index th data in the deque
     * if the index is bigger than the size of the deque,
     * raise runtime exception
     * @param index the index of the data you wanna get.
     * @return the data in the index of the deque
     */
    T get(int index) const {
        if (index >= size) {
            throw std::runtime_error("The deque doesn't have this index");
        }
        return get(index, sentinel->next);
    }

    /**
     * Remove the last item of the deque, and return its value
     * if the deque is empty, raise runtime error
     * @return the last item value in the deque
     */
    T removeLast() {
        if (isEmpty()) {
            throw std::runtime_error("The deque is empty, nothing to remove!");
        }
        Node* lastNode = sentinel->prev;
        T returnValue = lastNode->data;
        Node* newLastNode = sentinel->prev->prev;
        sentinel->prev = newLastNode;
        newLastNode->next = sentinel;
        delete lastNode;
        size--;
        return returnValue;
    }

    /**
     * Remove the last item in the deque, and
     * return its value.
     * If the deque is empty, raise runtime error.
     * @return the last item value in the deque
     */
    T removeFirst() {
        if (isEmpty()) {
            throw std::runtime_error("The deque is empty, nothing to remove!");
        }
        Node* firstNode = sentinel->next;
        Node* newFirstNode = sentinel->next->next;
        T returnValue = firstNode->data;
        sentinel->next = newFirstNode;
        newFirstNode->prev = sentinel;
        delete firstNode;
        size--;
        return returnValue;
    }
};

#endif //HW3_DEQUE_H
