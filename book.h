#include "data.h"
#include <string.h>

char plik[40] = "books.txt";

struct book{
    int dir_num;
    char author[50], title[50], category[50];
    int date;
    char publ[50];
    int isbn_code;
    int availablity;
};

int comp(struct book a, struct book b){
    if((a.dir_num == b.dir_num )&&( a.date == b.date )&&( a.isbn_code == b.isbn_code )) {
        return 1;
    }
    return 0;
}

int comp_strings(char *a, char *b){
    int n = strlen(a);
    int m = strlen(b);
    if(n != m){
        return 0;
    }
    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

int compare(const void* a, const void *b){
    return strcmp(((struct book*) a) -> author, ((struct book *) b) -> author);
}

void sort_arr(){
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int licz = 0, ch = 0;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }

        licz++;
    }
    qsort (temp, licz, sizeof(struct book), compare);
    close_file(d);

    d = open_file(plik, "w");
    for(int i = 0; i<licz; i++){
        fprintf(&d, "%d %d %s %s %s %d %s %d %d\n", i, temp[i].dir_num, temp[i].author, temp[i].title, temp[i].category, temp[i].date, temp[i].publ, temp[i].isbn_code, temp[i].availablity);
    }
    fprintf(&d, "-1 1 - - - 1 - 1 1\n");
    close_file(d);
}

void Add_book(struct book it){
    sort_arr();

    FILE d = open_file(plik, "r");
    struct book temp[100];
    int licz = 0, ch = 0;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        licz++;
    }
    close_file(d);

    d = open_file(plik, "w");
    int ok = 0;
    for(int i=0; i<licz; i++){
        if(comp(temp[i], it)==1){
            ok = 1;
        }
        else {
            fprintf(&d, "%d %d %s %s %s %d %s %d %d\n", i, temp[i].dir_num, temp[i].author, temp[i].title, temp[i].category, temp[i].date,
                    temp[i].publ, temp[i].isbn_code, temp[i].availablity);
        }
    }
    fprintf(&d, "%d %d %s %s %s %d %s %d %d\n", licz,  it.dir_num, it.author, it.title, it.category, it.date, it.publ, it.isbn_code, it.availablity);
    
    fprintf(&d, "-1 1 - - - 1 - 1 1\n");
    if( ok == 0 ){
        printf("Plik dodany prawidłowo\n");
    }
    else{
        printf("Plik już istnieje\n");
    }
    close_file(d);    
}

void Edit_book(struct book it){
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int licz = 0, ch = 0, ok=0;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        else if(it.dir_num == temp[licz].dir_num && it.isbn_code == temp[licz].isbn_code){
            temp[licz]=it;
            ok=1;
        }
        licz++;
    }
    d = open_file(plik, "w");
    for(int i=0; i<licz; i++){
        fprintf(&d, "%d %d %s %s %s %d %s %d %d\n", i, temp[i].dir_num, temp[i].author, temp[i].title, temp[i].category, temp[i].date,
                    temp[i].publ, temp[i].isbn_code, temp[i].availablity);
    }

    fprintf(&d, "-1 1 - - - 1 - 1 1\n");
    if( ok == 1 ){
        printf("Książka zedytowana poprawnie\n");
    }
    else{
        printf("Książka nie istnieje\n");
    }
    close_file(d);

    sort_arr();
}

void Delete_book(struct book it){
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int licz = 0, ch = 0;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        licz++;
    }
    close_file(d);

    d = open_file(plik, "w");
    int ok=0;
    int cnt = 1;
    for(int i=0; i<licz; i++) {
        if (comp(temp[i], it) == 0) {
            fprintf(&d, "%d %d %s %s %s %d %s %d %d\n", cnt++, temp[i].dir_num, temp[i].author, temp[i].title, temp[i].category, temp[i].date,
                    temp[i].publ, temp[i].isbn_code, temp[i].availablity);
        }
        else {
            ok = 1;
        }
    }
    fprintf(&d, "-1 1 - - - 1 - 1 1\n");
    printf("Książka usunięta poprawnie\n");
    close_file(d);    
}

void Print_Books(){
    sort_arr();

    FILE d = open_file(plik, "r");
    struct book temp[100];
    int licz = 0, ch = 0;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }

        printf("%d %d %s %s %s %d %s %d %d\n", licz, temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, temp[licz].date, temp[licz].publ, temp[licz].isbn_code, temp[licz].availablity);
        licz++;
    }
    close_file(d);
}

void Search_by_author(char *author){
    sort_arr();

    printf("%s\n", author);
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int ch = 0, licz = 0;
    int cnt = 1;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        if(comp_strings(temp[licz].author, author)){
            printf("%d %d %s %s %s %d %s %d %d\n",cnt++, temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, temp[licz].date, temp[licz].publ, temp[licz].isbn_code, temp[licz].availablity);
        }
        licz++;
    }
    if(cnt == 1){
        printf("W bazie nie ma książek autorstwa %s\n",author);
    }
    close_file(d);
}

void Search_by_title(char *title){
    sort_arr();
    printf("%s\n", title);
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int ch = 0, licz = 0;
    int cnt = 1;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        if(comp_strings(temp[licz].title, title)){
            printf("%d %d %s %s %s %d %s %d %d\n",cnt++, temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, temp[licz].date, temp[licz].publ, temp[licz].isbn_code, temp[licz].availablity);
        }
        licz++;
    }
    if(cnt == 1){
        printf("W bazie nie ma książek o tytule %s\n",title);
    }
}

void Search_by_category(char *category){
    sort_arr();
    printf("%s\n", category);
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int ch = 0, licz = 0;
    int cnt = 1;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        if(comp_strings(temp[licz].category, category)){
            printf("%d %d %s %s %s %d %s %d %d\n",cnt++, temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, temp[licz].date, temp[licz].publ, temp[licz].isbn_code, temp[licz].availablity);
        }
        licz++;
    }
    if(cnt == 1){
        printf("W bazie nie ma książek z kategori %s\n",category);
    }
}