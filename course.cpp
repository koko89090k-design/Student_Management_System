#include <bits/stdc++.h>
#include "course.h"
#include "student.h"
#include "student.cpp"

void addcource (vector <Course> &courses){
    Course c;

    cout << "Enter Course ID: ";
    cin >> c.id;

    cout << "Enter title: ";
    cin >> c.title;

    cout << "Enter credit_hours: ";
    cin >> c.credit_hours;

    courses.push_back(c);

     cout << "Course Added Successfully!\n";

}

Course * findCoursebyid(vector<Course> &Courses , const string &id){
    for(int i = 0 ; i<Courses.size() ; ++i){
        if(Courses[i].id == id ){
            return &Courses[i];
        }
    }
    return 0;
}

void recordGrade(vector<Course>& Courses, vector<Student>& students){
    string courseId , studentId;
    double grade;

    cout << "Enter Course Id: ";
    cin >> courseId;
    
    cout << "Enter Student Id: ";
    cin >> studentId;

    cout << "Enter Grade: ";
    cin >> grade;

    Course* c = findCoursebyid(Courses, courseId);
    if(c == 0){
        cout << "course not found!\n";
        return;
    }
    
    Student *s = findStudentById(students, studentId);
    if(s == 0){
        cout << "Student not found!";
        return;
    }

   
    c->grades.push_back({studentId , grade});

    cout << "Grade recorded successfully!\n";

}




