#include "iostream"
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string name) : courseName(name) {};

void GradeBook::setCourseName(string name) {
    courseName = name;
}

string GradeBook::getCourseName() const {
    return courseName;
}

void GradeBook::displayMessage() const {
    cout << "Welcome to the GradeBook user" << getCourseName() << "!\n";
}