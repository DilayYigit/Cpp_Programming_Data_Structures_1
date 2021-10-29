//
// Created by dilay on 7/14/21.
//

#include "CourseList.h"
CourseList::CourseList() : size(0), head(NULL) {

}

CourseList::CourseList(const CourseList& aList) : size(aList.size) {
    if (aList.isEmpty()) {
        head = NULL;
    }
    else {
        head = new CourseNode;
        head->courseId = aList.head->courseId;
        head->courseName = aList.head->courseName;

        CourseNode* last = head;
        for (CourseNode* cur = aList.head; cur != NULL; cur = cur->next) {
            last->next = new CourseNode;
            last = last->next;
            last->courseId = cur->courseId;
            last->courseName = cur->courseName;
        }
        last->next = NULL;
    }
}

CourseList::~CourseList() {
    removeAll();
}
bool CourseList::isEmpty() const {
    return (head == NULL);
}

int CourseList::getLength() const {
    return size;
}

bool CourseList::isExist(int id) {
    bool isExist = false;
    for (CourseNode* cur = head; cur != NULL; cur = cur->next) {
        if (cur->courseId == id) {
            isExist = true;
            break;
        }
    }
    return isExist;
}

CourseList::CourseNode* CourseList::findCourseNode(int index) const {
    if (index < 1 || index > getLength()) {
        return NULL;
    }
    else {
        CourseNode* loc = head;
        for (int i = 1; i < index; i++) {
            loc = loc->next;
        }
        return loc;
    }
}

bool CourseList::insertEnd(int id, string name) {
    CourseNode *newCourse = new CourseNode;
    newCourse->courseId = id;
    newCourse->courseName = name;
    newCourse->next = NULL;

    if (isEmpty()) {
        head = newCourse;
    }
    else {
        for (CourseNode* cur = head; cur != NULL; cur = cur->next) {
            if (cur->next == NULL) {
                newCourse->next = NULL;
                cur->next = newCourse;
                break;
            }
        }
    }
    size++;
    return true;
}

int CourseList::findIndexOfCourse(int id) {
    int count = 1;
    for (CourseNode* find = head; find != NULL; find = find->next) {
        if (find->courseId != id) {
            count++;
        }
        else
            break;
    }
    return count;
}

bool CourseList::removeCourse(int index) {
    if (index < 1 || index > getLength()) {
        return false;
    }
    CourseNode* deleted;
    if (index == 1) {
        deleted = head;
        head = head->next;
    }
    else {
        CourseNode* last = findCourseNode(index - 1);
        deleted = last->next;
        last->next = deleted->next;
    }
    size--;
    delete deleted;
    return true;
}

void CourseList::removeAll() {
    while (!isEmpty()) {
        removeCourse(1);
    }
}

void CourseList::displayCourses() const {
    CourseNode* cur = head;
    if ( head == NULL ) {
        return;
    }
    cout << "\t\t\tCourse Id\t Course Name" << endl;
    while ( cur != NULL )
    {
        cout << "\t\t\t" << cur->courseId << "\t\t\t" << cur->courseName << endl;
        cur = cur->next;
    }
}

bool CourseList::retrieve(int index, string& courseName) const {
    if (index < 1 || index > getLength()) {
        return false;
    }
    CourseNode* cur = findCourseNode(index);
    courseName = cur->courseName;
    return true;
}