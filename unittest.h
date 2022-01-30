/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
*/

#include "WordsReader.h"
#include "PuzzleMaker.h"

extern int testsPassed;
extern int testsCount;
#define TEST(a) {\
  testsCount++;\
  if (a()) testsPassed++;\
}

int AssertCoordsDefaults(int len, Coordinates* c);

/* Checks if given list is NULL */
int AssertNull(char** words);

int AssertArraysEqual(int len, char* expected[], char** actual);

/* Prints test results */
void PrintTestResults();
