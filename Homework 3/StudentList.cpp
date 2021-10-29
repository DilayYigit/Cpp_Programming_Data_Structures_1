//
// Created by dilay on 7/14/21.
//

#include "StudentList.h"
StudentList::StudentList() : size(0), head(NULL) {

}

StudentList::StudentList(const StudentList& aList) : size(aList.size) {
    if (aList.isEmpty()) {
        head = NULL;
        size = 0;
    }
    else {
        head = new StudentNode;
        head->studentId = aList.head->studentId;
        head->firstName = aList.head->firstName;
        head->lastName = aList.head->lastName;
        head->courses = aList.head->courses;
        head->prev = NULL;

        StudentNode* last = head;
        for (StudentNode* cur = aList.head; cur != NULL; cur = cur->next) {
            last->next = new StudentNode;
            last = last->next;
            last->studentId = cur->studentId;
            last->firstName = cur->firstName;
            last->lastName = cur->lastName;
            last->courses = cur->courses;
            last->prev->next = cur;
            last->prev = cur;
        }
        last->next = NULL;
    }
}

StudentList::~StudentList() {
    removeAll();
}

bool StudentList::isEmpty() const {
    return (size == 0);
}

int StudentList::getLength() const {
    return size;
}

bool StudentList::isExist(int id) {
    bool isExist = false;
    for (StudentNode* cur = head; cur != NULL; cur = cur->next) {
        if (cur->studentId == id) {
            isExist = true;
            break;
        }
    }
    return isExist;
}

StudentList::StudentNode* StudentList::findStudentNode(int index) const {
    if (index < 1 || index > getLength()) {
        return NULL;
    }
    else {
        StudentNode* loc = head;
        for (int i = 1; i < index; i++) {
            loc = loc->next;
        }
        return loc;
    }
}

void StudentList::addStudent(int studentId, string firstName, string lastName) {
    if (isExist(studentId)) {
        cout << "Student " << studentId << " already exists." << endl;
    }
    else if (studentId < 0) {
        cout << "Student ID is invalid!" << endl;
    }
    else {
        StudentNode *newStu = new StudentNode;
        newStu->studentId = studentId;
        newStu->firstName = firstName;
        newStu->lastName = lastName;
        newStu->next = NULL;
        newStu->prev = NULL;

        if (isEmpty()) {
            head = newStu;
        } else {
            for (StudentNode *cur = head; cur != NULL; cur = cur->next) {
                if (cur == head && cur->studentId > studentId) {
                    newStu->next = cur;
                    cur->prev = newStu;
                    newStu->prev = NULL;
                    head = newStu;
                    break;
                }
                if (cur->studentId > studentId) {
                    newStu->next = cur;
                    newStu->prev = cur->prev;
                    cur->prev->next = newStu;
                    cur->prev = newStu;
                    break;
                }
                if (cur->next == NULL) {
                    newStu->prev = cur;
                    newStu->next = NULL;
                    cur->next = newStu;
                    break;
                }
            }
        }
        size++;
        cout << "Student " << studentId << " has been added." << endl;
    }
}


int StudentList::findIndexOfStudent(int studentId) {
    int index = 1;
    for (StudentNode *cur = head; cur != NULL; cur = cur->next) {
        if (cur->studentId != studentId) {
            index++;
        }
        else
            break;
    }
    return index;
}

void StudentList::addCourse(int stuId, int courId, string courName) {
    if (isExist(stuId)) {
        int index = findIndexOfStudent(stuId);
        if (!(findStudentNode(index)->courses).isExist(courId)) {
            (findStudentNode(index)->courses).insertEnd(courId, courName);
            cout << "Course " << courId << " has been added to student " << stuId << endl;
        }
        else
            cout << "Student " << stuId << " is already enrolled in course " << courId << endl;
    }
    else
        cout << "Student " << stuId << " does not exit." << endl;
}

void StudentList::deleteStudent(int studentId) {
    if(isExist(studentId)) {
        int index = findIndexOfStudent(studentId);

        StudentNode *deleted = findStudentNode(index);
        (deleted->courses).removeAll();

        if (index == 1) {
            deleted = head;
            head = head->next;
        }
        else if (index == getLength()) {
            deleted->prev->next = NULL;
            deleted->prev = NULL;
        }
        else {
            deleted->prev->next = deleted->next;
            deleted->next->prev = deleted->prev;
        }
        delete deleted;
        size--;
        cout << "Student " << studentId << " has been deleted." << endl;
    }
    else
        cout << "Student " << studentId << " does not exist." << endl;
}

void StudentList::removeAll() {
    while(!isEmpty()) {

        StudentNode *deleted = findStudentNode(1);
        (deleted->courses).removeAll();

        deleted = head;
        head = head->next;

        delete deleted;
        size--;
    }
}

void StudentList::withdrawCourse(int studentId, int courseId) {
    if (isExist(studentId)) {
        int indexOfStudent = findIndexOfStudent(studentId);
        if ((findStudentNode(indexOfStudent)->courses).isExist(courseId)) {

            int indexOfCourse = (findStudentNode(indexOfStudent)->courses).findIndexOfCourse(courseId);
            (findStudentNode(indexOfStudent)->courses).removeCourse(indexOfCourse);
            cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
        }
        else
            cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
    }
    else
        cout << "Student " << studentId << " does not exist." << endl;
}

void StudentList::cancelCourse(int courseId) {
    if (isEmpty()) {
        cout << "There are no students and courses in the system." << endl;
    }
    else {
        bool success = false;
        for (StudentNode* cur = head; cur != NULL; cur = cur->next) {
            if ((cur->courses).isExist(courseId)) {
                int indexOfCourse = (cur->courses).findIndexOfCourse(courseId);
                (cur->courses).removeCourse(indexOfCourse);
                success = true;
            }
        }
        if (success) {
            cout << "Course " << courseId << " has been cancelled." << endl;
        }
        else
            cout << "Course " << courseId << " does not exist." << endl;
    }
}

void StudentList::showStudent(int studentId) {
    if (isExist(studentId)) {
        int index = findIndexOfStudent(studentId);
        cout << "Student Id\t First Name\t Last Name" << endl;
        cout << studentId << "\t\t" << (findStudentNode(index)->firstName) << "\t\t" << (findStudentNode(index)->lastName) << endl;
        (findStudentNode(index)->courses).displayCourses();
    }
    else
        cout << "Student " << studentId << " does not exist." << endl;

}

void StudentList::showCourse(int courseId) {
    bool success = false;
    int index;
    string courseName;
    for (StudentNode* cur = head; cur != NULL; cur = cur->next) {
        if ((cur->courses).isExist(courseId)) {
            success = true;
            index = (cur->courses).findIndexOfCourse(courseId);
            (cur->courses).retrieve(index, courseName);
            break;
        }
    }
    if (!success) {
        cout << "Course " << courseId << " does not exist." << endl;
    }
    else {
        cout << "Course Id\t Course Name" << endl;
        cout << courseId << "\t\t\t" << courseName << endl;
        cout << "\t\t\tStudent Id\t First Name\t Last Name" << endl;
        for (StudentNode* cur = head; cur != NULL; cur = cur->next) {
            if ((cur->courses).isExist(courseId)) {
                cout << "\t\t\t" << (cur->studentId) << "\t\t" << (cur->firstName) << "\t\t" << (cur->lastName) << endl;
            }
        }
    }
}

void StudentList::showAllStudents() {
    if (!isEmpty()) {
        cout << "Student Id\t First Name\t Last Name" << endl;
        for (int i = 1; i <= getLength(); i++) {
            cout << findStudentNode(i)->studentId << "\t\t" << (findStudentNode(i)->firstName) << "\t\t" << (findStudentNode(i)->lastName) << endl;
            (findStudentNode(i)->courses).displayCourses();
            cout << endl;
        }
    }
    else {
        cout << "There are no students and courses in the system." << endl;
    }
}
