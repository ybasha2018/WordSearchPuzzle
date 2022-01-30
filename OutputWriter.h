/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT.
*/
#include "WordsReader.h"
#include "PuzzleMaker.h"
#include <ctype.h>
#include <time.h>

/*
 * Returns a random alphabetical letter.
 */
char randomUpperChar(char c);

/*
 * Prints a row in the puzzle to the output file.
 */
void printPuzzleHelper(FILE* outputFile, Puzzle* p);

/*
 * Prints the list of words to the output file.
 */
void printWordTable(char** words, FILE* outputFile);

/*
 * Prints the words to the table
 */
void printWordsToTable(char** words, FILE* outputFile);

/*
 * Creates the appropriate HTML output file.
 */
void createOutputFile(int argc, char* argv[], Puzzle *p, char** words);

/*
 * Creates the output file, if necessary.
 */
FILE* OpenOutputFile(int argc, char* argv[]);

/*
 * Prints the necessary HTML footer to the output file.
*/
void printFileHeader(FILE *fp, char* title);

/*
 * Prints the puzzle to the output HTML file.
 */
void printPuzzle(FILE *fp, Puzzle *p);

/*
 * Prints the necessary HTML footer to the output file.
*/
void printFileFooter(FILE *fp);

