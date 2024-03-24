//
// Created by Jingfeng Sun on 2024/3/22.
//

#ifndef STACK_STRINGSTACK_H
#define STACK_STRINGSTACK_H

#include <string>
#include <sstream>
#include <iostream>
#include "stack.h"

class stringStack : public Stack<std::string> {
public:
    stringStack() : Stack<std::string>(){

    }
    stringStack(const std::string& sentence) : Stack<std::string>(){
        std::istringstream iss(sentence);
        std::string token;

        while (iss >> token) {
            push(token);
        }
        reverse();
    }
private:
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
};



#endif //STACK_STRINGSTACK_H
