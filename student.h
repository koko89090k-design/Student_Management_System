#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

struct Course; // Forward declaration

struct Student {
    std::string id;
    std::string name;
    int year;
    std::vector<std::string> enrolledCourseIds;
};

void addStudent(std::vector<Student>& students);

Student* findStudentById(std::vector<Student>& students, const std::string& id);

void printStudent(const Student& s);

void printStudentGPA(std::vector<Student>& students, std::vector<Course>& courses);

#endif