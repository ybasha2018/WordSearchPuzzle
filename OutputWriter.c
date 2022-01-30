#include "OutputWriter.h"

/*
 * Creates the appropriate HTML output file.
 */
void createOutputFile(int argc, char* argv[], Puzzle *p, char** words){
  FILE *outputFile = OpenOutputFile(argc, argv);
  char title[50];
  printf("Please enter the title for your puzzle: ");
  scanf("%s", title);
  title[strcspn(title, "\n")] = 0;
  printFileHeader(outputFile, title);
  printPuzzle(outputFile, p);
  printWordTable(words, outputFile);
  printFileFooter(outputFile);
  CloseWordsFile(outputFile);
}

/*
 * Prints the necessary HTML footer to the output file.
*/
void printFileHeader(FILE *outputFile, char* title) {
  fprintf(outputFile, "%s\n", "<html>");
  fprintf(outputFile, "%s\n", "<head>");
  fprintf(outputFile, "%s%s%s\n", "<title>", title, "</title>");
  fprintf(outputFile, "%s\n", "</head>");
  fprintf(outputFile, "%s\n", "<body>");
  fprintf(outputFile, "%s%s%s\n", "<h1 style=\"text-align: center;\">", title, "</h1>");
  fprintf(outputFile, "%s\n", "<hr>");
  fprintf(outputFile, "%s\n", "<p style=\"text-align: center;\">");
}

/*
 * Returns a random alphabetical letter.
*/
char randomUpperChar(char c){
  int i = rand() % 26 + 65; /* int values between 65-90 */
  return (char)i;
}

/*
 * Prints a row in the puzzle to the output file.
 */
void printPuzzleHelper(FILE* outputFile, Puzzle* p) {
  int i, j; char c;
  for (i = 0; i < p->width; i++) {
    fprintf(outputFile, "<tr>\n");
    for (j = 0; j < p->length; j++) {
      if (p->puzzle[i][j] != 0) {
        c = toupper(p->puzzle[i][j]);
      } else {
        c = randomUpperChar(c);
      }
      fprintf(outputFile, "<td>%c</td\n>", c);
    }
    fprintf(outputFile, "</tr>\n");
  }
}


/*
 * Prints the puzzle to the output HTML file.
 */
void printPuzzle(FILE *outputFile, Puzzle *p) {
  int i;
  fprintf(outputFile, "%s\n", "<table align=center style=\"text-align:center\"; width=30%>");
  printPuzzleHelper(outputFile,  p);
  fprintf(outputFile, "%s\n", "</table>");
  for (i = 0; i < 3; i++) {
    fprintf(outputFile, "<br>\n");
  } 
}

/*
 * Prints the necessary HTML footer to the output file.
*/
void printFileFooter(FILE *outputFile) {
  fprintf(outputFile, "\n");
  fprintf(outputFile, "%s\n", "</p>");
  fprintf(outputFile, "%s\n", "</body>");
  fprintf(outputFile, "%s\n", "</body>");
  fprintf(outputFile, "%s\n", "</html>");
}

/*
 * Prints the words to the table
*/
void printWordsToTable(char** words, FILE* outputFile){
  int i = 0;
  while (strlen(words[i]) > 0) {
    fprintf(outputFile, "%s\n", "<tr>");
    fprintf(outputFile, "%s%s%s\n", "<td>", words[i], "</td>");
    fprintf(outputFile, "%s\n", "</tr>");
    i++;
  }
}

/*
 * Prints the list of words to the output file.
*/
void printWordTable(char** words, FILE* outputFile) {
  fprintf(outputFile, "%s\n", "<table align=center style=\"text-align:center\">");
  fprintf(outputFile, "<th><h3>Words List</h3></th>");
  printWordsToTable(words, outputFile);
  fprintf(outputFile, "%s\n", "</table>");
}

/*
 * Creates the output file, if necessary.
 */
FILE* OpenOutputFile(int argc, char *argv[]){
  /* Open f properly */
  FILE *f;
  if (argc > 2) {
    f = fopen(argv[2], "w");
  } else {
    f = fopen("output.html", "w");
  }
  return f;
}

