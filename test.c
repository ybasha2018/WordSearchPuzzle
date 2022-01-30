/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
*/

#include "unittest.h"

int reverseNullWord(){
  char* word = NULL;
  reverseWord(word); /*ensure method doesnt break */
  return 1;
}

int reverseAnyWord1(){
  char w[30];
  char* r;
  strcpy(w, "hello");
  r = reverseWord(w); 
  return strcmp(w, r) == 0;
}

int reverseAnyWord2(){
  char w[30];
  char* r;
  strcpy(w, "goodbye");
  r = reverseWord(w);
  return strcmp(w, r) == 0;
}

int reversePalindrome(){
  char w[30];
  char* r;
  strcpy(w, "racecar");
  r = reverseWord(w);
  return strcmp(w, r) == 0;
}

int setValues1(){
  Coordinates* c = malloc(sizeof(Coordinates));
  setValues(1, c);
  return AssertCoordsDefaults(1, c);
}

int setValues2(){
  Coordinates* c = malloc(2 * sizeof(Coordinates));
  setValues(2, c);
  return AssertCoordsDefaults(2, c);
}

int setValues5(){
  Coordinates* c = malloc(5 * sizeof(Coordinates));
  setValues(5, c);
  return AssertCoordsDefaults(5, c);
}

int setValues8(){
  Coordinates* c = malloc(8 * sizeof(Coordinates));
  setValues(8, c);
  return AssertCoordsDefaults(8, c);
}

int TestOneWord(){
  int argc = 2;
  char* argv[2] = {"lab5", "test1.words"};
  char* expected[1] = {"hello"};
  char** actual = createArray(argc, argv);
  return AssertArraysEqual(1, expected, actual);
}


int CleanWordList1(){
  int argc = 2;
  char* argv[2] = {"lab5", "test1.words"};
  char** actual = createArray(argc, argv);
  CleanUpWordList(actual);
  return AssertNull(actual);
}

int TestThreeWords(){
  int argc = 2;
  char* argv[2] = {"lab5", "test2.words"};
  char* expected[3] = {"hello", "maybe", "goodbye"};
  char** actual = createArray(argc, argv);
  return AssertArraysEqual(3, expected, actual);
}

int CleanWordList3(){
  int argc = 2;
  char* argv[2] = {"lab5", "test2.words"};
  char** actual = createArray(argc, argv);
  CleanUpWordList(actual);
  return AssertNull(actual);
}

int TestSixWords(){
  int argc = 2;
  char* argv[2] = {"lab5", "test3.words"};
  char* expected[6] = {"hello", "maybe", "goodbye", "until", "above", "below"};
  char** actual = createArray(argc, argv);
  return AssertArraysEqual(6, expected, actual);
}

int CleanWordList6(){
  int argc = 2;
  char* argv[2] = {"lab5", "test3.words"};
  char** actual = createArray(argc, argv);
  CleanUpWordList(actual);
  return AssertNull(actual);
}

int Test8Words(){
  int argc = 2;
  char* argv[2] = {"lab5", "test4.words"};
  char* expected[8] = {"hello", "maybe", "goodbye", "until", "above", "below", "between", "beyond"};
  char** actual = createArray(argc, argv);
  return AssertArraysEqual(8, expected, actual);
}

int CleanWordList8(){
  int argc = 2;
  char* argv[2] = {"lab5", "test4.words"};
  char** actual = createArray(argc, argv);
  CleanUpWordList(actual);
  return AssertNull(actual);
}

int Test10Words(){
  int argc = 2;
  char* argv[2] = {"lab5", "test5.words"};
  char* expected[10] = {"hello", "maybe", "goodbye", "until", "above", "below", "between", "beyond", "incredible", "sweet"};
  char** actual = createArray(argc, argv);
  return AssertArraysEqual(10, expected, actual);
}

int CleanWordList10(){
  int argc = 2;
  char* argv[2] = {"lab5", "test5.words"};
  char** actual = createArray(argc, argv);
  CleanUpWordList(actual);
  return AssertNull(actual);
}


int OpenNullFile(){
/* compiling and running program by typing only "lab5 input.words" */
  int argc = 2;
  FILE* fp;
  char *argv[2] = {"lab5", "testnull.words"};
  fp = OpenWordsFile(argc, argv);
  fclose(fp);
  return 1;
}

int OpenGivenFile(){
/* compiling and running program by typing only "lab5 input.words given.html" */
  int argc = 3;
  FILE* fp;
  char *argv[3] = {"lab5", "testnull.words", "given.html"};
  fp = OpenWordsFile(argc, argv);
  fclose(fp);
  return 1;
}

/*Cant fclose on an empty */
int CloseNullFilePtr(){
  FILE* fp = NULL;
  CloseWordsFile(fp);
  return 1;
}

int main()
{
  /* assert (expected, actual) */
  TEST(reverseNullWord);
  TEST(reverseAnyWord1);
  TEST(reverseAnyWord2);
  TEST(reversePalindrome);
  TEST(TestOneWord);
  TEST(CleanWordList1);
  TEST(TestThreeWords);
  TEST(CleanWordList3);
  TEST(TestSixWords);
  TEST(CleanWordList6);
  TEST(Test8Words);
  TEST(CleanWordList8);
  TEST(Test10Words);
  TEST(CleanWordList10);
  TEST(OpenNullFile);
  TEST(OpenGivenFile);
  TEST(CloseNullFilePtr);
  TEST(setValues1);
  TEST(setValues2);
  TEST(setValues5);
  PrintTestResults();
  return 0;
}
