#include <stdio.h>
#include <stdlib.h>

#include "book.h"
// #include "customer.h"


int main(){
    struct book ksiega= {1, "Arthura Conana Doyle", "murder mystery", 1886, "Ward Lock & Co", 1, 1};
    Add_book(ksiega);
    return 0;
}