#include <iostream>
using namespace std;
#include "AlgebraicExpression.h"

int main() {

    cout << infix2postfix("(4+5)-2*4+7/5") << endl;   // (4+5)-2*4+7/5
    cout << evaluatePostfix ("352-8*+4/") << endl;
    return 0;
}
