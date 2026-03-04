#include <bits/stdc++.h>
#include "course.h"

void addcource (vector <Course> &cources){
    Course c;

    cout << "Enter Course ID: ";
    cin >> c.id;

    cout << "Enter title: ";
    cin >> c.title;

    cout << "Enter credit_hours: ";
    cin >> c.credit_hours;

    cources.push_back(c);

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
    
}




