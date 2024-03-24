//
// Created by Jingfeng Sun on 2024/3/23.
//

#ifndef STACK_ACKERMAN_H
#define STACK_ACKERMAN_H
// Here is the defination of Ackerman function
// A(m, n) = n + 1 if m = 0
// A(m, n) = A(m - 1, 1) if m > 0 and n = 0
// A(m, n) = A(m - 1, A(m, n - 1)) if m > 0 and n > 0

/*
 * Implement ackerman recursively
 */
int ackerman_recursive(int m, int n);

/*
 * Implement ackerman nonrecursively
 */
int ackerman_nonrecursive(int m, int n);

#endif //STACK_ACKERMAN_H
