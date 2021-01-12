
FILE open_file(char* plik, char* type) {
	FILE *f = fopen(plik, type);
    
	if (f == NULL) {
		perror("File open error");
		exit(0);
	}
	return (*f);
}

void close_file(FILE f){
    fclose(&f);
}