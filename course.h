

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>
#include "student.h"

struct Course {
    std::string id;
    std::string title;
    int credit_hours;
    std::vector<std::pair<std::string, double>> grades;
};

void addCourse(std::vector<Course>& courses);

Course* findCourseById(std::vector<Course>& courses, const std::string& id);

void recordGrade(std::vector<Course>& courses, std::vector<Student>& students);

void printCourseReport(std::vector<Course>& courses, std::vector<Student>& students);

#endif
