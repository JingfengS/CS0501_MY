//
// Created by Jingfeng Sun on 2024/3/22.
//

#ifndef STACK_PASCALCHECKER_H
#define STACK_PASCALCHECKER_H
#include <string>
#include <iostream>

#include "stringStack.h"

bool checkHelper(stringStack& tokens, stringStack& keywords, bool elseFlag) {
    if (tokens.isEmpty() && keywords.isEmpty()) {
        return true;
    }
    if (tokens.isEmpty() && !keywords.isEmpty()) {
        return false;
    }
    std::string nextToken = *tokens.pop();
    if (nextToken == "begin") {
        keywords.push(nextToken);
        return checkHelper(tokens, keywords, false);
    }
    if (nextToken == "end") {
        if (keywords.isEmpty() || *keywords.pop() != "begin") {
            return false;
        }
        return checkHelper(tokens, keywords, false);
    }
    if (nextToken == "if") {
        keywords.push(nextToken);
        return checkHelper(tokens, keywords, false);
    }
    if (nextToken == "then") {
        if (keywords.isEmpty() || *keywords.pop() != "if") {
            return false;
        }
        return checkHelper(tokens, keywords, true);
    }
    if (nextToken == "else") {
        if (!elseFlag) {
            return false;
        }
        return checkHelper(tokens, keywords, false);
    }
    return checkHelper(tokens, keywords, elseFlag);
}

bool check(std::string sentence) {
    stringStack tokens(sentence);
    stringStack keywords;
    return checkHelper(tokens, keywords, false);
}


#endif //STACK_PASCALCHECKER_H
