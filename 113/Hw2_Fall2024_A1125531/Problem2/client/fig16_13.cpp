#include "iostream"
#include "GradeBook.h"

using namespace std;

int main() {
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    gradeBook1.setInsName("Professor Jen-Feng");
    gradeBook1.displayMessage();

    return 0;
}