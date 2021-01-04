#include "data.h"

char plik[] = "books.txt";

struct book{
    int dir_num;
    char *author, *category;
    int date;
    char *publ;
    int isbn_code;
    int availablity;
};

void Add_book(struct book it){
    FILE d = open_file(plik, "a");
    printf("%d; %s; %s; %d; %s; %d; %d\n", it.dir_num, it.author, it.category, it.date, it.publ, it.isbn_code, it.availablity);

    // fwrite()
    fprintf(&d, "%d; %s; %s; %d; %s; %d; %d\n", it.dir_num, it.author, it.category, it.date, it.publ, it.isbn_code, it.availablity);

    close_file(d);    
}

void Edit_book(){

}

void Delete_book(){

}

void Print_Books(){

}

void Search_by_author(){

}

void Search_by_title(){

}

void Search_by_category(){

}