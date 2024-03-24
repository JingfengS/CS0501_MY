#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
template<class T>
/**
 * This is my version of stack
 * It is implemented as a ArrayList Stack
*/
class Stack {
private:
    int size;
    int capicity;




    /*
     * update capicity in case of overflow or memory loss
     * if size == capicity, then the array is twice the capicity
     * if size / capicity < 0.25, then the array is half the size
     */
    void updateCapicity() {
        if (size == capicity) {
            capicity *= 2;
            T *newArray = new T[capicity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        } else if (double(size) / capicity < 0.25 && capicity > 16) {
            capicity /= 2;
            T *newArray = new T[capicity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }
protected:
    T *array;
    void setSize(int newSize) {
        size = newSize;
    }

    void setCapacity(int capi) {
        capicity = capi;
    }

public:
    /*
     * Default constructor
     * default capicity is 16
     */
    Stack() {
        size = 0;
        capicity = 16;
        array = new T[capicity];
    }

    /*
     * Customed capicity
     */
    Stack(int cap) {
        size = 0;
        capicity = cap;
        array = new T[capicity];
    }


    /*
     * Destructor
     */
    ~Stack() {
        delete[] array;
    }

    /*
     * Return the capicity of the stack
     */
    int getCapicity() const {
        return capicity;
    }

    /*
     * Return the size of the stack
     */
    int getSize() const {
        return size;
    }

    /*
     * Return the top item in the stack
     * if the stack has size == 0, return nullptr
     */
    T* peak() const {
        if (size == 0) {
            return nullptr;
        }
        return &array[size - 1];
    }

    /*
     * pop the last item in the stack and justify the array capicity
     * if the stack has size == 0, return nullptr
     */
    T* pop() {
        if (size == 0) {
            return nullptr;
        }
        size -= 1;
        updateCapicity();
        return &array[size];
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        for (int i = 0; i < size; i++) {
           std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete [] array;
            T* newArray = new T[other.getCapicity()];
            for (int i = 0; i < other.getSize(); i++) {
                newArray[i] = other.array[i];
            }
            size = other.getSize();
            capicity = other.getCapicity();
            array = newArray;
        }
        return *this;
    }

/*
 * push one item to the stack
 */
void push(T item) {
    array[size] = item;
    size += 1;
    updateCapicity();
}
};

#endif