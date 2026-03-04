#ifndef student.h
#define student.h

#include <bits/stdc++.h>


using namespace std;

struct Student {
    string id; // Unique national ID
    string name; // Full name 
    int year; // Academic year 
    vector<string> enrolledCourseIds;  // List of registered courses
};


void addStudent(vector<Student>& students); 

Student* findStudentById(vector<Student>& students, const string& id);

void printStudent(const Student& s);

#endif