#include <bits/stdc++.h>
#include "student.h"

void addStudent(vector<Student>& students) {
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Year: ";
    cin >> s.year;

    students.push_back(s);

    cout << "Student Added Successfully!\n";
}

Student* findStudentById(vector<Student>& students, const string& id) {
    for (int i = 0 ; i < students.size() ; ++i) {
        if (students[i].id ==id) {
            return &students[i];
        }
    }
    return 0;
}

void printStudent(const Student& s) {
    cout << "ID: " << s.id << '\n'; 
    cout << "Name: " << s.name << '\n';
    cout << "Year: " << s.year << '\n';
}