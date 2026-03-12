#include "course.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addCourse(vector<Course>& courses) {
    Course c;

    // دخل الكود وشوف موجود قبل كده ولا لا
    cout << "Enter Course ID: ";
    cin >> c.id;

    if (findCourseById(courses, c.id) != nullptr) {
        cout << "Error: Course with ID " << c.id << " already exists!\n";
        return;
    }

    //دخل اسم الماده كله 
    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, c.title);

    // دخل عدد الساعات 
    cout << "Enter Credit Hours: ";
    
    while (!(cin >> c.credit_hours) || c.credit_hours < 1 || c.credit_hours > 6) {
        cout << "Invalid input! Enter valid credit hours (1-6): ";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    courses.push_back(c);
    cout << "Course Added Successfully!\n";
}

Course* findCourseById(vector<Course>& courses, const string& id) {
    for (int i = 0; i < courses.size(); ++i) {
        if (courses[i].id == id) {
            return &courses[i];
        }
    }
    return nullptr;
}

void recordGrade(vector<Course>& courses, vector<Student>& students) {
    string courseId, studentId;
    double grade;
    
    // دخل كود الماده

    cout << "Enter Course ID: ";
    cin >> courseId;

    Course* c = findCourseById(courses, courseId);
    if (c == nullptr) {
        cout << "Course not found!\n";
        return;
    }

    // دخل رقم الطالب 
    cout << "Enter Student ID: ";
    cin >> studentId;

    Student* s = findStudentById(students, studentId);
    if (s == nullptr) {
        cout << "Student not found!\n";
        return;
    }

    // نتأكد انه مش موجود قبل كده
    for (int i = 0; i < c->grades.size(); ++i) {
        if (c->grades[i].first == studentId) {
            cout << "Error: Grade already recorded for this student in this course!\n";
            return;
        }
    }

    
    cout << "Enter Grade (0-100): ";
    while (!(cin >> grade) || grade < 0 || grade > 100) {
        cout << "Invalid input! Enter a valid grade (0-100): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // ضيف الدرجه
    c->grades.push_back({studentId, grade});

    
    bool alreadyEnrolled = false;
    for (int i = 0; i < s->enrolledCourseIds.size(); ++i) {
        if (s->enrolledCourseIds[i] == courseId) {
            alreadyEnrolled = true;
            break;
        }
    }

    if (!alreadyEnrolled) {
        s->enrolledCourseIds.push_back(courseId);
    }

    cout << "Grade recorded successfully!\n";
}

void printCourseReport(vector<Course>& courses, vector<Student>& students) {
    string courseId;
    cout << "Enter Course ID: ";
    cin >> courseId;

    Course* c = findCourseById(courses, courseId);
    if (c == nullptr) {
        cout << "Course not found!\n";
        return;
    }

    cout << "==========================================\n";
    cout << "Course Report: " << c->title << " (" << c->id << ")\n";
    cout << "Credit Hours:  " << c->credit_hours << '\n';
    cout << "==========================================\n";

    
    if (c->grades.empty()) {
        cout << "No grades recorded yet.\n";
        cout << "==========================================\n";
        return;
    }

    
    double total = 0.0;
    double highest = c->grades[0].second;
    double lowest = c->grades[0].second;
    string topStudent = c->grades[0].first;
    string bottomStudent = c->grades[0].first;

    cout << "Student ID    | Name                | Grade\n";
    cout << "===============================================\n";

    for (int i = 0; i < c->grades.size(); ++i) {
        string sid = c->grades[i].first;
        double g = c->grades[i].second;
        total += g;


        string studentName = "Unknown";
        Student* s = findStudentById(students, sid);
        if (s != nullptr) {
            studentName = s->name;
        }

        cout << sid;

        // شويه مسافات 
        for (int j = sid.length(); j < 14; ++j) cout << ' ';
        cout << "| " << studentName;
        for (int j = studentName.length(); j < 20; ++j) cout << ' ';
        cout << "| " << g << '\n';

        // اعلي واقل واحد
        if (g > highest) {
            highest = g;
            topStudent = sid;
        }
        if (g < lowest) {
            lowest = g;
            bottomStudent = sid;
        }
    }

    double average = total / c->grades.size();

    cout << "------------------------------------------\n";
    cout << "Total Students: " << c->grades.size() << '\n';
    cout << "Average Grade:  " << average << '\n';
    cout << "Highest Grade:  " << highest << " (Student: " << topStudent << ")\n";
    cout << "Lowest Grade:   " << lowest << " (Student: " << bottomStudent << ")\n";
    cout << "==========================================\n";
}