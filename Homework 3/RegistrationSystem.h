//
// Created by dilay on 7/14/21.
//

#ifndef HOMEWORK3_REGISTRATIONSYSTEM_H
#define HOMEWORK3_REGISTRATIONSYSTEM_H

#include "StudentList.h"
#include "CourseList.h"

class RegistrationSystem {
public:
    RegistrationSystem();
    ~RegistrationSystem();
    void addStudent(const int studentId, const string firstName, const string lastName);
    void deleteStudent(const int studentId);
    void addCourse(const int studentId, const int courseId,const string courseName);
    void withdrawCourse(const int studentId, const int courseId);
    void cancelCourse(const int courseId);
    void showStudent(const int studentId);
    void showCourse(const int courseId);
    void showAllStudents();

private:
    StudentList students;
};


#endif //HOMEWORK3_REGISTRATIONSYSTEM_H
