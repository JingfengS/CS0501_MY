
#ifndef STACK_PASCAL_H
#define STACK_PASCAL_H
#include <string>
#include <iostream>

#include "stack.h"

bool check(std::string sentence) {
    stringStack tokens(sentence); // Assuming this constructor splits the sentence into tokens.
    stringStack keys;
    bool elseAccept = false;

    while (!tokens.isEmpty() || !keys.isEmpty()) {
        if (tokens.isEmpty()) {
            return keys.isEmpty();
        }

        std::string nextToken = *tokens.pop();

        if (nextToken == "begin" || nextToken == "if") {
            keys.push(nextToken);
            elseAccept = false;
        } else if (nextToken == "end") {
            if (keys.isEmpty() || *keys.pop() != "begin") {
                return false;
            }
            elseAccept = false;
        } else if (nextToken == "then") {
            if (keys.isEmpty() || *keys.pop() != "if") {
                return false;
            }
            elseAccept = true;
        } else if (nextToken == "else") {
            if (!elseAccept) {
                return false;
            }
            elseAccept = false;
        }
    }

    return true;
}


#endif //STACK_PASCAL_H
