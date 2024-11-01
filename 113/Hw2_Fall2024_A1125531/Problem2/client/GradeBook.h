#include "string"

using namespace std;

class GradeBook {
    public: 
        explicit GradeBook(string);
        void setCourseName(string);
        string getCourseName() const;
        void setInsName(string);
        string getInsName() const;
        void displayMessage() const;
    private: 
        string courseName, insName;
};