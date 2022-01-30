/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
*/

#include "WordsReader.h"
#define MAX_WORDS 30
#define MAX_WORD_LENGTH 30

/*
 * Mallocs an arrray of words
*/
char** mallocArray() {
  int i;
  char** words = malloc(MAX_WORDS * sizeof(char*));
  for (i = 0; i < MAX_WORDS; i++) {
    words[i] = calloc(MAX_WORD_LENGTH,sizeof(char));
    
  }
  return words;
}

/*
 * Frees each word in the array of words. 
*/
void CleanUpWordList(char** words) {
  int i;
  for (i = 0; i < MAX_WORDS; i++) {
    free(words[i]);
  }
  free(words);
  words = NULL;
}

/*
 * Given a .words file, returns an array of words.
*/
char** createArray(int argc, char* argv[]) {
  FILE* wordsFile = OpenWordsFile(argc, argv);
  int i = 0;
  char** words; char s[MAX_WORD_LENGTH];
  words = mallocArray();
  while (fgets(s, MAX_WORD_LENGTH, wordsFile)) {
    s[strcspn(s, "\n")] = 0;
    strcpy(words[i++], s);
  }
  CloseWordsFile(wordsFile); 
  return words;
}

/*
 * Returns file ptr if given a .words file, otherwise NULL. 
*/
FILE* OpenWordsFile(int argc, char* argv[]) {
  /* Open f properly */
  if (argc > 1) {
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
      fprintf(stderr, "Unable to open .words file\n");
      abort();
    }
    return f;
  } else {
    fprintf(stderr, ".words file was not indicated.\n");
    abort();
  }
}

/* Closes files if open */
void CloseWordsFile(FILE *f) {
  /* Close f properly */
  if (f != NULL) {
    fclose(f);
    f = NULL;
  }
}

