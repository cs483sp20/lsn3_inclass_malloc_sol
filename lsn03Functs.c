//
// Created by troywein on 1/9/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lsn03Functs.h"

StudentType* initStudents(long numStudents) {
    char buf[50];
    StudentType* newNode = NULL;
    StudentType* curNode = NULL;
    StudentType* head = NULL;

    // All user to enter data
    for (int i = 0; i < numStudents; i++) {
        // Allocate a new student struct
        newNode = malloc(sizeof(StudentType));

        printf("Enter first name (%d): ",i);
        fgets(newNode->first, 19, stdin);
        newNode->first[strlen(newNode->first)-1] = '\0';

        printf("Enter last name (%d): ",i);
        fgets(newNode->last, 29, stdin);
        newNode->last[strlen(newNode->last)-1] = '\0';

        printf("Enter age (%d): ",i);
        fgets(buf, 10, stdin);
        newNode->age = strtol(buf, NULL, 10);

        // Allocate storage for grades
        printf("How many grades (%d): ",i);
        fgets(buf, 10, stdin);
        newNode->numGrades = strtol(buf, NULL, 10);
        newNode->grades = malloc(newNode->numGrades * sizeof(long));

        // generate random #'s and assign as a grade
        for (int j = 0; j < newNode->numGrades; j++) {

            newNode->grades[j] = random() % 101;
        }

        if (head == NULL) {
            head = newNode;
            curNode = head;
        } else {
            curNode->next = newNode;
            curNode = newNode;
        }
    }

    return head;
}

void printStudents(StudentType* stdPtr) {
    StudentType* curPtr = stdPtr;
    int i = 0;
    while (curPtr != NULL) {
        printf("Student %d ->\n",i++);
        printf("\tName: %s %s\n", curPtr->first, curPtr->last);
        printf("\tAge: %ld\n", curPtr->age);
        printf("\tGrades: ");
        for (int j = 0; j < curPtr->numGrades; j++) {
            printf("%ld ",curPtr->grades[j]);
        }
        printf("\n\n");
        curPtr = curPtr->next;
    }
}

void deallocStudents(StudentType* stdPtr) {
    StudentType* curPtr = stdPtr;
    StudentType* prevPtr = NULL;
    // Must deallocate grades array in each struct prior
    // to deallocating the array of structs
    while (curPtr != NULL) {
        free(curPtr->grades);
        prevPtr = curPtr;
        curPtr = curPtr->next;
        free(prevPtr);
    }

}