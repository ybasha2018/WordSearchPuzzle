/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Frees each word in the array of words.
*/
void CleanUpWordList(char** words);

/*
 * Mallocs an arrray of words
 */
char** mallocArray();

/*
 * Given a .words file, returns an array of words.
*/
char** createArray(int argc, char* argv[]);

/*
 * Returns file ptr if given a .words file, otherwise NULL. 
*/
FILE* OpenWordsFile(int argc, char* argv[]);

/* Closes files if open */
void CloseWordsFile(FILE *f);

