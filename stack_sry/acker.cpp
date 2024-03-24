#include "stack.h"

int ackerman_recursive(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackerman_recursive(m - 1, 1);
    }
    return ackerman_recursive(m - 1, ackerman_recursive(m, n - 1));
}

int ackerman_nonrecursive(int m, int n) {
    intStack s;
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

