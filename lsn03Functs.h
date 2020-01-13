//
// Created by troywein on 1/9/19.
//

#ifndef L2_LSN02FUNCTS_H
#define L2_LSN02FUNCTS_H

typedef struct student_rec {
    char first[20];
    char last[30];
    long age;
    long squadron;
    long numGrades;
    long* grades;
    struct student_rec* next;
} StudentType;

// allocates memory for and initializes data for each
// student, returns a pointer to an array of student
// records
StudentType* initStudents(long numStudents);

// print student data
void printStudents(StudentType* stdPtr);

// deallocates all student data
void deallocStudents(StudentType* stdPtr);

#endif //L2_LSN02FUNCTS_H
