#include "data.h"
#include <string.h>

char plik[] = "books.txt";

struct book{
    int dir_num;
    char author[50], category[50];
    int date;
    char publ[50];
    int isbn_code;
    int availablity;
};

void Add_book(struct book it){
    FILE d = open_file(plik, "r");
    struct book temp[10];
    int licz = 1;
    int ch = 0;
    while(1){
        printf("Line = %d\n", licz);

        fscanf(&d, "%d %d %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            printf("Koniec pliku!\n");
            break;
        }
        // printf("%d %d %s %s %d %s %d %d\n", ch, temp[licz].dir_num, temp[licz].author, temp[licz].category, temp[licz].date, temp[licz].publ, temp[licz].isbn_code, temp[licz].availablity);        
        licz++;
    }
    close_file(d);

    d = open_file(plik, "w");

    for(int i=1; i<licz; i++){
        // printf("%d %d %s %s %d %s %d %d\n", i, temp[i].dir_num, temp[i].author, temp[i].category, temp[i].date, temp[i].publ, temp[i].isbn_code, temp[i].availablity);        
        fprintf(&d,"%d %d %s %s %d %s %d %d\n", i, temp[i].dir_num, temp[i].author, temp[i].category, temp[i].date, temp[i].publ, temp[i].isbn_code, temp[i].availablity);        
    }
    // printf("%d %d %s %s %d %s %d %d\n",licz,  it.dir_num, it.author, it.category, it.date, it.publ, it.isbn_code, it.availablity);
    fprintf(&d, "%d %d %s %s %d %s %d %d\n",licz,  it.dir_num, it.author, it.category, it.date, it.publ, it.isbn_code, it.availablity);
    
    // printf("-1 1 - - 1 - 1 1\n");
    fprintf(&d, "-1 1 - - 1 - 1 1\n");
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