//
// Created by dilay on 7/14/21.
//

#include "RegistrationSystem.h"
#include "StudentList.h"
#include "CourseList.h"

RegistrationSystem::RegistrationSystem() {
    students = StudentList();
}
RegistrationSystem::~RegistrationSystem() {
    students.removeAll();
}
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
    students.addStudent(studentId, firstName, lastName);
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {
    students.addCourse(studentId, courseId, courseName);
}

void RegistrationSystem::deleteStudent(const int studentId) {
    students.deleteStudent(studentId);
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
    students.withdrawCourse(studentId, courseId);
}

void RegistrationSystem::cancelCourse(const int courseId) {
    students.cancelCourse(courseId);
}

void RegistrationSystem::showStudent(const int studentId) {
    students.showStudent(studentId);
}

void RegistrationSystem::showCourse(const int courseId) {
    students.showCourse(courseId);
}

void RegistrationSystem::showAllStudents() {
    students.showAllStudents();
}