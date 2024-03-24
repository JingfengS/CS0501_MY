//
// Created by Jingfeng Sun on 2024/3/23.
//
// Here is the defination of Ackerman function
// A(m, n) = n + 1 if m = 0
// A(m, n) = A(m - 1, 1) if m > 0 and n = 0
// A(m, n) = A(m - 1, A(m, n - 1)) if m > 0 and n > 0
#include <utility>
#include "stack.h"

/*
 * Implement ackerman recursively
 */
int ackerman_recursive(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackerman_recursive(m - 1, 1);
    }
    return ackerman_recursive(m - 1, ackerman_recursive(m, n - 1));
}

/*
 * Implement ackerman nonrecursively
 */
int ackerman_nonrecursive(int m, int n) {
    Stack<int> s;
    s.push(m);
    while (!s.isEmpty()) {
        m=*s.pop();
        if (m==0 || n==0)
            n+=m+1;
        else {
            s.push(--m);
            s.push(++m);
            n--;
        }
    }
    return n;
}

