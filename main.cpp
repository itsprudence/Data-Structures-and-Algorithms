#include <iostream>
#include <string>
using namespace std;

class Grade {
    int mark;
    char grade;
    bool calculated;

public:
    Grade() : mark(0), grade(' '), calculated(false) {}

    bool setMark(int m) {
        if (calculated) {
            cout << "Grade already calculated. Cannot change mark.\n";
            return false;
        }
        if (m < 0 || m > 100) {
            cout << "Invalid mark. Must be between 0 and 100.\n";
            return false;
        }
        mark = m;
        grade = calculateGrade(mark);
        calculated = true;
        return true;
    }

    int getMark() { return mark; }
    char getGrade() { return grade; }
    bool isCalculated() { return calculated; }

private:
    char calculateGrade(int m) {
        if (m > 69) return 'A';
        if (m > 59) return 'B';
        if (m > 49) return 'C';
        if (m > 39) return 'D';
        return 'E';
    }
};

class Student {
    string regNo;
    string name;
    int age;
    string courseCode;
    string courseName;
    Grade grade;

public:
    void setDetails(string rn, string n, int a, string cc, string cn) {
        regNo = rn;
        name = n;
        age = a;
        courseCode = cc;
        courseName = cn;
    }

    bool setMark(int m) { return grade.setMark(m); }

    string getRegNo() { return regNo; }
    string getName() { return name; }
    int getAge() { return age; }
    string getCourseCode() { return courseCode; }
    string getCourseName() { return courseName; }
    Grade getGrade() { return grade; }

    void editDetails(string n, int a, string cc, string cn) {
        name = n;
        age = a;
        courseCode = cc;
        courseName = cn;
    }
};

class StudentManage {
    Student students[40];  // Fixed-size array for max 40 students
    int studentCount = 0;

public:
    void addStudent() {
        if (studentCount >= 40) {
            cout << "Cannot add more students. Maximum 40 reached.\n";
            return;
        }

        string regNo, name, courseCode, courseName;
        int age;

        cout << "Enter registration number: ";
        getline(cin, regNo);

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter course code: ";
        getline(cin, courseCode);

        cout << "Enter course name: ";
        getline(cin, courseName);

        students[studentCount].setDetails(regNo, name, age, courseCode, courseName);
        studentCount++;
        cout << "Student added successfully.\n";
    }

    void editStudent() {
        if (studentCount == 0) {
            cout << "No students to edit.\n";
            return;
        }

        string regNo;
        cout << "Enter registration number of student to edit: ";
        getline(cin, regNo);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRegNo() == regNo) {
                string name, courseCode, courseName;
                int age;

                cout << "Editing student " << students[i].getName() << endl;

                cout << "Enter new name: ";
                getline(cin, name);

                cout << "Enter new age: ";
                cin >> age;
                cin.ignore();

                cout << "Enter new course code: ";
                getline(cin, courseCode);

                cout << "Enter new course name: ";
                getline(cin, courseName);

                students[i].editDetails(name, age, courseCode, courseName);
                cout << "Details updated.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void addMarks() {
        if (studentCount == 0) {
            cout << "No students to add marks for.\n";
            return;
        }

        string regNo;
        cout << "Enter registration number of student to enter marks for: ";
        getline(cin, regNo);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRegNo() == regNo) {
                if (students[i].getGrade().isCalculated()) {
                    cout << "Grade already set. Cannot change.\n";
                    return;
                }

                int mark;
                cout << "Enter mark (0-100): ";
                cin >> mark;
                cin.ignore();

                if (students[i].setMark(mark)) {
                    cout << "Mark and grade set successfully.\n";
                }
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void displayStudents() {
        if (studentCount == 0) {
            cout << "No students to display.\n";
            return;
        }

        cout << "\n--- Student List ---\n";
        for (int i = 0; i < studentCount; i++) {
            cout << "Reg No: " << students[i].getRegNo() << endl;
            cout << "Name: " << students[i].getName() << endl;
            cout << "Age: " << students[i].getAge() << endl;
            cout << "Course Code: " << students[i].getCourseCode() << endl;
            cout << "Course Name: " << students[i].getCourseName() << endl;

            if (students[i].getGrade().isCalculated()) {
                cout << "Mark: " << students[i].getGrade().getMark() << endl;
                cout << "Grade: " << students[i].getGrade().getGrade() << endl;
            } else {
                cout << "Grade: Not yet set.\n";
            }

            cout << "-----------------------\n";
        }
    }
};

int main() {
    StudentManage manage;
    int choice;

    do {
        cout << "1. Add Student" << endl;
        cout << "2. Edit Student" << endl;
        cout << "3. Add Marks and Calculate Grade" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: manage.addStudent(); break;
            case 2: manage.editStudent(); break;
            case 3: manage.addMarks(); break;
            case 4: manage.displayStudents(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
