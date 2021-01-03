#include <stdio.h>
#include <stdlib.h>

FILE open_file(char* plik) {
	FILE *f = fopen(plik, "r");
    
	if (f == NULL) {
		perror("File open error");
		exit(0);
	}

	// fclose(f);
	return (*f);
}

void close_file(FILE f){
    fclose(&f);
}