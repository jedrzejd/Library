#include "data.h"
#include <string.h>

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
    FILE d = open_file(plik, "ra");
    struct book temp;
    int licz = 1;
    int ch = 0;
    while(1){
        fscanf(&d, "%d %d %s %s %d %s %d %d\n", &ch, &temp.dir_num, temp.author, temp.category, &temp.date, temp.publ, &temp.isbn_code, &temp.availablity);
        // if(ch == -1){
        //     break;
        // }
        // printf("Line = %d\n", licz);
        // printf("%d %s %s %d %s %d  %d\n", temp.dir_num, temp.author, temp.category, temp.date, temp.publ, temp.isbn_code, temp.availablity);        
        // licz++;
        break;
    }

    // printf("%d; %s; %s; %d; %s; %d; %d\n", it.dir_num, it.author, it.category, it.date, it.publ, it.isbn_code, it.availablity);

    fprintf(&d, "%d %d %s %s %d %s %d %d\n",licz,  it.dir_num, it.author, it.category, it.date, it.publ, it.isbn_code, it.availablity);

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