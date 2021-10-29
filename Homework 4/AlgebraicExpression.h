/*
 * @author: Dilay Yigit
 * @date: 7/25/21
 */

#ifndef HOMEWORK4_ALGEBRAICEXPRESSION_H
#define HOMEWORK4_ALGEBRAICEXPRESSION_H
#include "Stack.h"
#include <iostream>
using namespace std;

string infix2postfix (const string);
double evaluatePostfix (const string);
bool isValid (string);
bool isBalanced (string);
bool isOperand (char);
bool isOperator (char);
int precedence (char);
double calculation (double, double, char);

class AlgebraicExpression {

};


#endif //HOMEWORK4_ALGEBRAICEXPRESSION_H
