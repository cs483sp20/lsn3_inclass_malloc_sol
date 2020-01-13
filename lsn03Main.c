//
// Created by troywein on 1/9/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lsn03Functs.h"


int main() {

    long numStudents = 0;
    char buf[50];

    // prompt the user for a number of students whose data will be entered
    printf("Enter the number of students: ");
    fgets(buf,49,stdin);
    numStudents = strtol(buf, NULL, 10);

    // get student data
    StudentType* studentPtr = initStudents(numStudents);

    // output student & grades
    printStudents(studentPtr);

    // deallocate students
    deallocStudents(studentPtr);

    return 0;
}
