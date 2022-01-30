/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
 */

#include "PuzzleMaker.h"

/*
 * Asks user for the length and width of the puzzle.
*/
void AskForDimensions(Puzzle *p){
  int i, j;
  printf("Please enter the length and width of your desired puzzle: ");
  scanf("%d %d", &i, &j);

  p->length = i;
  p->width = j;
}

/*
 * Malloc's the rows and columns the the puzzle.
*/
Puzzle *mallocPuzzle(char** words){
  Puzzle *p = malloc(sizeof(Puzzle));
  int i, j;
  AskForDimensions(p); 
  p->puzzle = malloc((p->width)*sizeof(char*));
  for(i = 0; i < p->width; i++) {
   p->puzzle[i] = malloc((p->length)*sizeof(char));
   for (j = 0; j < p->length; j++) {
     p->puzzle[i][j] = 0;
   }
  }
  return p;
}

/*
 * Returns the greater of two ints.
*/
int max(int a, int b) {
  int max = a;
  if (a < b) {
    max = b;
  }
  return max;
}


/*
 * Defaults all coordinates to (-1,-1);
*/
void setValues(int len, Coordinates *possibleWordLocs) {
  int i;
  for (i = 0; i < len; i++) {
    possibleWordLocs[i].i = -1;
    possibleWordLocs[i].j = -1;
  }
}


/*
 * Determines if all needed vertical locations are null
 */
int verticalLettersAreNull(Puzzle *p, int i, int j, int len){
  int isNull = 1;
  int idx = i;
  int count = 0;
  while (idx < p->width && isNull && count < len) {
    char c = p->puzzle[idx][j];
    if (c != 0) {
      isNull = 0;
    }
    count++; idx++;
  }
  return isNull;
}

/*
 * Determines if all needed horizontal locations are null
*/
int horizontalLettersAreNull(Puzzle *p, int i, int j, int len){
  int isNull = 1;
  int idx = j;
  int count = 0;
  while (idx < p->length && isNull && count < len) {
    char c = p->puzzle[i][idx];
    if (c != 0) {
      isNull = 0;
    }
    count++; idx++;
  }
  return isNull;
}

/*
 * Determines if a word can be placed in the puzzle
 * at the given coordinates.
*/
int wordFits(int wordLen, Puzzle *p, int i, int j) {
  int w = -1;
  int width = p->width;
  int length = p->length;
    if (length - j >= wordLen && horizontalLettersAreNull(p, i, j, wordLen)) {
    w = 0;         /* can add horizontallly */
  } else if (width - i >= wordLen && verticalLettersAreNull(p, i, j, wordLen)) {
    w = 1;         /* can add vertically */
  } else {
    /* cant print word at these coords */
  }
  return w;
}

/*
 * Reverses a given word.
*/
char* reverseWord(char* word) {
  int a, b;
  if (word == NULL) {
    return 0;
  }
  a = strlen(word) - 1;
  b = 0;

  while (a > b) {
    char c = word[a];
    word[a] = word[b];
    word[b] = c;
    a--; b++;
  }
  return word;
}

/*
 * Adds the word horizontally at the given coordinates 
 */
void AddWordHorizontally(Puzzle *p, int i, int j, char* word) {
  int idx = j;
  int pos = 0;
  char w[30];
  strcpy(w, word);
  srand(time(0));
  if (rand() % 2) {
    reverseWord(w);
  }

  while (idx < p->length && pos < strlen(word)) {
    p->puzzle[i][idx] = w[pos];
    idx++; pos++;
  }

}

/*
 * Adds the word vertically at the given coordinates
 */
void AddWordVertically(Puzzle *p, int i, int j, char* word) {
  int idx = i;
  int pos = 0;
  char w[30];
  strcpy(w, word);
  srand(time(0));
  if (rand() % 2) {
    reverseWord(w);
  } 

  while (idx < p->width && pos < strlen(word)) {
    p->puzzle[idx][j] = w[pos];
    idx++; pos++;
  }

}

/*
 * Adds the word horizontally or vertically with given orientation and
 * coordinates.
*/
void AddWordToPuzzle(Puzzle* p, int i, int j, char* word, int orient){
  void (*func_ptr[2])(Puzzle*, int, int, char*) = {AddWordHorizontally, AddWordVertically};
  if (orient == 0) {
    (*func_ptr[0])(p, i, j, word); 
  } else if (orient == 1) {
    (*func_ptr[1])(p, i, j, word); 
  } 
}

/*
 * Frees malloc'd rows in the puzzle
*/
void CleanUpPuzzle(Puzzle *p) {
  int i;
  for(i = 0; i < p->width; i++) {
    free(p->puzzle[i]);
  }
  free(p);
}

/*
 * Gathers a set of possible locations for the given word in the puzzle.
 */
int getPossibleLocations(Puzzle* p, Coordinates* possibleWordLocs, char* word) {
  int i, j, len = strlen(word);
  int possibilites = 0;
  for (i = 0; i < p->width; i++) {
    for (j = 0; j < p->length; j++) {
       int canFitWord = wordFits(len, p, i, j);
       if (possibilites < 20 && canFitWord >= 0) {
         possibleWordLocs[possibilites].i = i; 
         possibleWordLocs[possibilites].j = j; 
         possibilites++;
       }
    }
  }
  return possibilites;
}

/*
 * Randomly adds a word into the puzzle.
*/
void AddWordRandomly(Coordinates* possibleWordLocs, int possibilites, Puzzle *p, char* word){
  int pos, randomI, randomJ, orient, len = strlen(word);
  srand(time(0));
  if (possibilites != 0) {
  do {
    pos = rand() % possibilites; /* int value between [0, NUM_OF_POSSIBILITES) */
    randomI = possibleWordLocs[pos].i;   
    randomJ = possibleWordLocs[pos].j;   
  } while (randomI < 0);
      orient = wordFits(len, p, randomI, randomJ);
      AddWordToPuzzle(p, randomI, randomJ, word, orient);
  } 
}

/*
 *  Creates word search puzzle given an array of words.
 */
Puzzle* makePuzzle(char** words) {
  Puzzle *p = mallocPuzzle(words);
  int x, i = 0;
  Coordinates* possibleWordLocs = malloc(21 * sizeof(Coordinates*));
  setValues(21, possibleWordLocs);
  while (words[i] != NULL && strlen(words[i]) > 0) {
    x = getPossibleLocations(p, possibleWordLocs, words[i]);
    AddWordRandomly(possibleWordLocs, x, p, words[i]);
    i++;   
    setValues(21, possibleWordLocs); 
  }
  return p;
}
