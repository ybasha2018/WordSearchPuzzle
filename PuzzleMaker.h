/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
 */

#ifndef PuzzleMaker_H
#define PuzzleMaker_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Puzzle Puzzle;
struct Puzzle {
  char **puzzle;
  int length;
  int width;
};

typedef struct Coordinates Coordinates;
struct Coordinates {
  int i;
  int j;
};

/*
 * Reverses a given word.
 */
char* reverseWord(char* word);

/*
 * Asks user for the length and width of the puzzle.
 */
void AskForDimensions(Puzzle *p);

/*
 * Malloc's the rows and columns the the puzzle.
 */
Puzzle *mallocPuzzle(char** words);

/*
 * Returns the greater of two ints.
 */
int max(int a, int b);

/*
 * Defaults all coordinates to (-1,-1);
 */
void setValues(int len, Coordinates *possibleWordLocs);

/*
 * Determines if a word can be placed in the puzzle
 * at the given coordinates.
 */
int wordFits(int wordLen, Puzzle *p, int i, int j);

/*
 * Determines if all needed vertical locations are null
 */
int verticalLettersAreNull(Puzzle *p, int i, int j, int len);

/*
 * Determines if all needed horizontal locations are null
 */
int horizontalLettersAreNull(Puzzle *p, int i, int j, int len);

/*
 * Adds the word horizontally at the given coordinates 
*/
void AddWordHorizontally(Puzzle *p, int i, int j, char* word);

/*
 * Adds the word vertically at the given coordinates
 */
void AddWordVertically(Puzzle *p, int i, int j, char* word);

/*
 * Randomly adds a word into the puzzle.
 */
void AddWordRandomly(Coordinates* possibleWordLocs, int possibilites, Puzzle *p, char* word);

/*
 * Adds the word horizontally or vertically with given orientation and
 * coordinates.
 */
void AddWordToPuzzle(Puzzle* p, int i, int j, char* word, int orient);

/*
 * Gathers a set of possible locations for the given word in the puzzle.
*/
int getPossibleLocations(Puzzle* p, Coordinates* possibleWordLocs, char* word);

/*
 * Creates word search puzzle given an array of words.
 */
Puzzle* makePuzzle(char** words);

/*
 * Frees malloc'd rows in the puzzle
 */
void CleanUpPuzzle(Puzzle *p);

#endif
