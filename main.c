#include "book.h"


int main(){
    struct book ksiega= {1, "Arthura_Conana_Doyle", "murder_mystery", 1886, "Ward_Lock_&_Co", 1123, 5};
    struct book ksiega1= {2, "Arthura_Conana_Doyle", "murder_mystery", 1887, "Ward_Lock_&_Co", 14123, 3};
    struct book ksiega2= {3, "Arthura_Conana_Doyle", "murder_mystery", 1888, "Ward_Lock_&_Co", 1323, 1};
    struct book ksiega3= {4, "Arthura_Conana_Doyle", "murder_mystery", 1889, "Ward_Lock_&_Co", 115523, 5};
    struct book ksiega4= {5, "Wacław_Kubański", "murder_mystery", 1996, "Ward_Lock_&_Co", 11423, 2};
    Add_book(ksiega);
    Add_book(ksiega1);
    Add_book(ksiega2);
    Add_book(ksiega3);
    Add_book(ksiega4);
//    Delete_book(ksiega4);
//    Print_Books();
    Search_by_author("Wacław_Kubański");
    return 0;
}