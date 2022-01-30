/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
 */

#include "OutputWriter.h"

/* Program to read a .words file, create a list of words, create a word search puzzle, and finally output the puzzle and list to the output file.*/
int main(int argc, char *argv[])
{
  char **words = createArray(argc, argv);
  Puzzle *wordPuzzle = makePuzzle(words);
  createOutputFile(argc, argv, wordPuzzle, words);
  CleanUpPuzzle(wordPuzzle);
  CleanUpWordList(words);
  return EXIT_SUCCESS;
}

