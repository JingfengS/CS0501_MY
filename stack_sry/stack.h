#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
class stringStack {
private:
    int size;
    int capicity;

    void updateCapicity() {
        if (size == capicity) {
            capicity *= 2;
            std::string *newArray = new std::string[capicity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        } else if (double(size) / capicity < 0.25 && capicity > 16) {
            capicity /= 2;
            std::string *newArray = new std::string[capicity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

    std::string *array;
    void setSize(int newSize) {
        size = newSize;
    }

    void setCapacity(int capi) {
        capicity = capi;
    }

    void reverse() {
        std::string* newArray = new std::string[getCapicity()];
        int sizeOld = getSize();
        int capiOld = getCapicity();
        for (int i = 0; i < sizeOld; i++) {
            newArray[i] = *pop();
        }
        delete [] array;
        array = newArray;
        setSize(sizeOld);
        setCapacity(capiOld);
    }

public:
    stringStack() {
        size = 0;
        capicity = 16;
        array = new std::string[capicity];
    }

    stringStack(const std::string& sentence) {
        size = 0;
        capicity = 16;
        array = new std::string[capicity];
        std::istringstream iss(sentence);
        std::string token;

        while (iss >> token) {
            push(token);
        }
        reverse();
    }


    ~stringStack() {
        delete[] array;
    }

    int getCapicity() const {
        return capicity;
    }

    int getSize() const {
        return size;
    }

    std::string* peak() const {
        if (size == 0) {
            return nullptr;
        }
        return &array[size - 1];
    }

    std::string* pop() {
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

    stringStack& operator=(const stringStack& other) {
        if (this != &other) {
            delete [] array;
            std::string* newArray = new std::string[other.getCapicity()];
            for (int i = 0; i < other.getSize(); i++) {
                newArray[i] = other.array[i];
            }
            size = other.getSize();
            capicity = other.getCapicity();
            array = newArray;
        }
        return *this;
    }

void push(std::string item) {
    array[size] = item;
    size += 1;
    updateCapicity();
}
};


class intStack {
private:
    int size;
    int capicity;

    void updateCapicity() {
        if (size == capicity) {
            capicity *= 2;
            int *newArray = new int[capicity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        } else if (double(size) / capicity < 0.25 && capicity > 16) {
            capicity /= 2;
            int *newArray = new int[capicity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

    int *array;
    void setSize(int newSize) {
        size = newSize;
    }

    void setCapacity(int capi) {
        capicity = capi;
    }


public:
    intStack() {
        size = 0;
        capicity = 16;
        array = new int[capicity];
    }



    ~intStack() {
        delete[] array;
    }

    int getCapicity() const {
        return capicity;
    }

    int getSize() const {
        return size;
    }

    int* peak() const {
        if (size == 0) {
            return nullptr;
        }
        return &array[size - 1];
    }

    int* pop() {
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

    intStack& operator=(const intStack& other) {
        if (this != &other) {
            delete [] array;
            int* newArray = new int[other.getCapicity()];
            for (int i = 0; i < other.getSize(); i++) {
                newArray[i] = other.array[i];
            }
            size = other.getSize();
            capicity = other.getCapicity();
            array = newArray;
        }
        return *this;
    }

    void push(int item) {
        array[size] = item;
        size += 1;
        updateCapicity();
    }
};
#endif