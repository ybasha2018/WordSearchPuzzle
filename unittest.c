/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
*/


#include "unittest.h"

int testsPassed = 0;
int testsCount = 0;



int AssertCoordsDefaults(int len, Coordinates* c) {
  int i; 
  for (i = 0; i < len; i++) {
    int x = c[i].i;
    int y = c[i].j;
    if (x != -1 || y != -1) {
      free(c);
      return 0;
    }
  }
  free(c);
  return 1;
}

int AssertNull(char** words) {
  if (strlen(words[0]) == 0) {
    return 1;
  } else {
    return 0;
  }
}

int AssertArraysEqual(int len, char* expected[], char** actual) {
  int i = 0;
  while (i < len && expected[i] != NULL && actual[i] != NULL) {
    if (strcmp(expected[i], actual[i]) != 0) {
      return 0;
    }
    i++;
  }

  return 1;
}

/* Prints test results */
void PrintTestResults()
{
  printf("%d/%d tests passed\n", testsPassed, testsCount); 
}

