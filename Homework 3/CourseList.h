//
// Created by dilay on 7/14/21.
//

#ifndef HOMEWORK3_COURSELIST_H
#define HOMEWORK3_COURSELIST_H
#include <iostream>
using namespace std;

class CourseList {
public:
    CourseList();
    CourseList(const CourseList&);
    ~CourseList();
    bool insertEnd(int, string);
    bool removeCourse(int);
    void removeAll();
    int findIndexOfCourse(int);
    bool isEmpty() const;
    int getLength() const;
    bool isExist(int);
    void displayCourses() const;
    bool retrieve(int, string&) const;
private:
    struct CourseNode {
        int courseId;
        string courseName;
        CourseNode* next;
    };
    CourseNode* head;
    int size;
    CourseNode* findCourseNode(int) const;
};


#endif //HOMEWORK3_COURSELIST_H
