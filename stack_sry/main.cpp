#include <iostream>
#include "acker.h"
#include "stack.h"
#include "pascal.h"
int main() {
    using namespace std;
    cout << check("begin a b c if a b c then a b c else a b c end") << endl;
    cout << check("begin then") << endl;
    cout << check("begin if end") << endl;
    cout << ackerman_recursive(2, 2) << endl;
    cout << ackerman_nonrecursive(2, 2) << endl;

    return 0;
}