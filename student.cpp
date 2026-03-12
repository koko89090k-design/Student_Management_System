#include "student.h"
#include "course.h"
#include "color.h" 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addStudent(vector<Student>& students) {
    Student s;

    // دخل id الطالب
    cout << CYAN << "Enter Student ID: " << RESET;
    cin >> s.id;

    // نتأكد إن الـ ID مش موجود قبل كده

    if (findStudentById(students, s.id) != nullptr) {
        cout << RED << "Error: Student with ID " << s.id 
             << " already exists!" << RESET << '\n';
        return;
    }

    // دخل الاسم كامل 

    cout << CYAN << "Enter Name: " << RESET;
    cin.ignore();
    getline(cin, s.name);

    // دخل السنه وتأكد منها 

    cout << CYAN << "Enter Year: " << RESET;

    while (!(cin >> s.year) || s.year < 1 || s.year > 7) {
        
        cout << RED << "Invalid input! Enter a valid year (1-7): " 
             << RESET;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    students.push_back(s);
    cout << GREEN << "Student Added Successfully!" << RESET << '\n';
}

// دور علي الطالب بأستخدام ال ID

Student* findStudentById(vector<Student>& students, const string& id) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return nullptr;
}

// اطبع كل معلومات الطالب

void printStudent(const Student& s) {
    cout << BLUE << "===========================" << RESET << '\n';
    cout << CYAN << "ID:   " << RESET << s.id << '\n';
    cout << CYAN << "Name: " << RESET << s.name << '\n';
    cout << CYAN << "Year: " << RESET << s.year << '\n';

    cout << CYAN << "Enrolled Courses: " << RESET;
    if (s.enrolledCourseIds.empty()) {
        cout << RED << "None" << RESET;
    } else {
        for (int i = 0; i < s.enrolledCourseIds.size(); ++i) {
            cout << GREEN << s.enrolledCourseIds[i] << RESET;

            if (i < s.enrolledCourseIds.size() - 1) {
                cout << ", ";
            }
        }
    }

    cout << '\n';
    cout << BLUE << "===========================" << RESET << '\n';
}


void printStudentGPA(vector<Student>& students, vector<Course>& courses) {
    string studentId;
    cout << CYAN << "Enter Student ID: " << RESET;
    cin >> studentId;

    Student* s = findStudentById(students, studentId);

    if (s == nullptr) {
        cout << RED << "Student not found!" << RESET << '\n';
        return;
    }

    // لو الطالب مش مسجل في أي مادة
    if (s->enrolledCourseIds.empty()) {
        cout << RED << "Student " << s->name 
             << " is not enrolled in any course." << RESET << '\n';
        return;
    }

    double totalPoints = 0.0;
    int totalCredits = 0;
    bool hasGrades = false;

    // ندور على كل مادة الطالب مسجل فيها
    for (int i = 0; i < s->enrolledCourseIds.size(); ++i) {

        string courseId = s->enrolledCourseIds[i];

        Course* c = nullptr;

        for (int j = 0; j < courses.size(); ++j) {
            if (courses[j].id == courseId) {
                c = &courses[j];
                break;
            }
        }

        if (c == nullptr) continue;

        for (int k = 0; k < c->grades.size(); ++k) {

            if (c->grades[k].first == studentId) {

                double grade = c->grades[k].second;
                double gradePoint = 0.0;

                if (grade >= 90) 
                    gradePoint = 4.0;
                else if (grade >= 85)
                    gradePoint = 3.7;
                else if (grade >= 80)
                    gradePoint = 3.3;
                else if (grade >= 75)
                    gradePoint = 3.0;
                else if (grade >= 70)
                    gradePoint = 2.7;
                else if (grade >= 65)
                    gradePoint = 2.3;
                else if (grade >= 60)
                    gradePoint = 2.0;
                else if (grade >= 50)
                    gradePoint = 1.0;
                else           
                    gradePoint = 0.0;

                totalPoints += gradePoint * c->credit_hours;
                totalCredits += c->credit_hours;
                hasGrades = true;
                
                break;
            }
        }
    }

    if (!hasGrades) {
        cout << RED << "No grades recorded for " << s->name 
             << " yet." << RESET << '\n';
        return;
    }

    double gpa = totalPoints / totalCredits;

    cout << BLUE << "===========================" << RESET << '\n';
    cout << CYAN << "Student: " << RESET << s->name << '\n';
    cout << CYAN << "ID:      " << RESET << s->id << '\n';
    cout << GREEN << "GPA:     " << RESET << gpa << " / 4.0\n";
    cout << BLUE << "===========================" << RESET << '\n';
}