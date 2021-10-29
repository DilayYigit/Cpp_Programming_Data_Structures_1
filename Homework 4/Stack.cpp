/*
 * @author: Dilay Yigit
 * @date: 7/25/21
 */

#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() : top(NULL) {

}

Stack::Stack(const Stack &aStack) {
    if (aStack.top == NULL) {
        top = NULL;
    }
    else {
        top = new StackNode;
        top->item = aStack.top->item;

        StackNode* cur = top;
        for (StackNode* orig = aStack.top->next; orig != NULL; orig = orig->next) {
            cur->next = new StackNode;
            cur = cur->next;
            cur->item = orig->item;
        }
        cur->next = NULL;
    }
}

Stack::~Stack() {
    while (!isEmpty())
        pop();
}
bool Stack::isEmpty() const {
    return top == NULL;
}

bool Stack::push(char newItem) {
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = top;
    top = newPtr;

    return true;
}

bool Stack::pop(char& aTop) {
    if (isEmpty()) {
        return false;
    }
    else {
        aTop = top->item;
        StackNode* temp = top;
        top = top->next;

        delete temp;
        return true;
    }
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }
    else {
        StackNode* temp = top;
        top = top->next;

        delete temp;
    }
}

bool Stack::getTop(char& aTop) const {
    if (isEmpty()) {
        return false;
    }
    else {
        aTop = top->item;
        return true;
    }
}

char Stack::getTop() {
    if (!isEmpty())
        return top->item;
}




