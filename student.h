#ifndef student_h
#define student_h

#include <bits/stdc++.h>


using namespace std;

struct Student {
    string id; 
    string name;  
    int year; 
    vector<string> enrolledCourseIds;  
};


void addStudent(vector<Student>& students); 

Student* findStudentById(vector<Student>& students, const string& id);

void printStudent(const Student& s);

#endif