#include "book.h"


int main(){
    struct book ksiega= {1, "Arthura_Conana_Doyle", "murder_mystery", 1886, "Ward_Lock_&_Co", 1123, 5};
    struct book ksiega1= {1, "Wacław_Kubański", "murder_mystery", 1996, "Ward_Lock_&_Co", 11423, 2};
    Add_book(ksiega);
    Add_book(ksiega1);
    Delete_book(ksiega);
    Print_Books();
    return 0;
}