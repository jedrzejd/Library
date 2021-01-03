#include <stdio.h>
#include <stdlib.h>

#include "book.h"
#include "data.h"
#include "customer.h"


int main(){
    FILE d = open_file("smiec.txt");
    char name[20];

    fscanf(&d, "%[^\n]", name);
    close_file(d);    
    printf("%s",name);
    return 0;
}