//
// Created by dilay on 7/14/21.
//

#ifndef HOMEWORK3_STUDENTLIST_H
#define HOMEWORK3_STUDENTLIST_H


#include "CourseList.h"
#include <iostream>
using namespace std;

class StudentList {
public:
    StudentList();
    StudentList(const StudentList&);
    ~StudentList();
    void addStudent(int, string, string);
    void addCourse(int, int, string);
    void deleteStudent(int);
    void withdrawCourse(int, int);
    void cancelCourse(int);
    void showStudent(int);
    void showCourse(int);
    void showAllStudents();
    void removeAll();

private:
    struct StudentNode {
        int studentId;
        string firstName;
        string lastName;
        CourseList courses;
        StudentNode* next;
        StudentNode* prev;
    };
    StudentNode* head;
    int size;
    int findIndexOfStudent(int);
    int getLength() const;
    bool isEmpty() const;
    bool isExist(int);
    StudentNode* findStudentNode(int) const;
};

#endif //HOMEWORK3_STUDENTLIST_H
