/*
 * @author: Dilay Yigit
 * @date: 7/25/21
 */

#ifndef HOMEWORK4_STACK_H
#define HOMEWORK4_STACK_H


class Stack {
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(char);
    bool pop();
    bool pop(char&);
    bool getTop(char&) const;
    char getTop();
private:
    struct StackNode {
        char item;
        StackNode* next;
    };
    StackNode* top;
};


#endif //HOMEWORK4_STACK_H
