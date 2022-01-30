
all:	 
	gcc -ansi -pedantic -std=c89 -Wimplicit-function-declaration -Wreturn-type -Wall -Werror -g -o main main.c PuzzleMaker.c WordsReader.c OutputWriter.c 

test:	
	gcc  -ansi -pedantic -std=c89 -Wimplicit-function-declaration -Wreturn-type -Wall -Werror -g -o lab5test PuzzleMaker.c unittest.c test.c WordsReader.c 

clean:
	rm *.html main

zip:
	zip main.zip *.c *.h LAB5README makefile *.words 



