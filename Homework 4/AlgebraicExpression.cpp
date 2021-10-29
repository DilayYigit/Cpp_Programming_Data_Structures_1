/*
 * @author: Dilay Yigit
 * @date: 7/25/21
 */

#include "AlgebraicExpression.h"
#include "Stack.h"
#include <iostream>
using namespace std;

// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix (const string exp) {
    Stack temp;
    char c;
    string postFix = "";

    if (isValid(exp) && isBalanced(exp)) {
        for (int i = 0; i < exp.length(); i++) {
            c = exp[i];

            if (isOperand(c)) {
                postFix += c;
            }
            else if (isOperator(c)) {
                while (!temp.isEmpty() && precedence(c) <= precedence(temp.getTop())) {
                    postFix += temp.getTop();
                    temp.pop();
                }
                temp.push(c);
            }
            else if (c == '(') {
                temp.push(c);
            }
            else if (c == ')') {
                while (temp.getTop() != '(') {
                    postFix += temp.getTop();
                    temp.pop();
                }
                temp.pop();
            }
        }
        while (!temp.isEmpty()) {
            postFix += temp.getTop();
            temp.pop();
        }
    }
    return postFix;
}

// It evaluates a postfix expression.
double evaluatePostfix (const string exp) {
    Stack temp;
    char c;
    double result;
    if (isValid(exp)) {
        for (int i = 0; i < exp.length(); i++) {
            c = exp[i];
            if (c == '(' || c == ')') {
                cout << "ERROR: You cannot use parentheses."  << endl;
                result = NULL;
                break;
            }
            if (isOperand(c)) {
                temp.push(c - '0');
            }
            else {
                double rightOperand = temp.getTop();
                temp.pop();
                double leftOperand = temp.getTop();
                temp.pop();
                result = calculation(leftOperand, rightOperand, c);
                temp.push(result);
            }
        }
    }
    else
        result = NULL;
    return result;
}

// Helper function to evaluate postfix.
double calculation (double a, double b, char c) {
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
    else
        return 0;
}

// Helper function that checks whether chars are operands or operators.
bool isOperand (char c) {
    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
    || c == '6' || c == '7' || c == '8' || c == '9')
        return true;
    else
        return false;
}

// Helper function that checks whether chars are operands or operators.
bool isOperator (char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}

// Helper function to find the priority of the operation.
int precedence (char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Helper function that checks expression is valid or not.
bool isValid (string exp) {
    bool check = true;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == ')' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||
        exp[i] == '/' || exp[i] == '1' || exp[i] == '2' || exp[i] == '3' || exp[i] == '4' ||
        exp[i] =='5' || exp[i] == '6' || exp[i] == '7' || exp[i] == '8' || exp[i] == '9') {
            continue;
        }
        else {
            check = false;
            cout << "ERROR: Input contains invalid char." << endl;
            break;
        }
    }
    return check;
}

// Helper function that checks expression is balanced or not.
bool isBalanced (string exp) {
    Stack aStack;
    bool isBalanced = true;
    int i = 0;

    while (isBalanced && i < exp.length()) {
        char c = exp[i];
        i++;
        if (c == '(') {
            aStack.push('(');
        }
        else if (c == ')') {
            if (!aStack.isEmpty()) {
                aStack.pop();
            }
            else {
                isBalanced = false;
                cout << "ERROR: Input is not balanced." << endl;
            }
        }
    }
    return isBalanced;
}
