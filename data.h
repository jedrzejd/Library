#include <stdio.h>
#include <stdlib.h>

FILE open_file(char* plik, char* type) {
	FILE *f = fopen(plik, type);
    
	if (f == NULL) {
		perror("File open error");
		exit(0);
	}
//	printf("File open ok\n");
	return (*f);
}

void close_file(FILE f){
    fclose(&f);
}