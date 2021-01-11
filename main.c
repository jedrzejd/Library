#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "list.h"

int main(){
    struct book ksiega= {1, "CCArthura_Conana_Doyle", "Sherlock_Holmes","murder_mystery",1886, "Ward_Lock_&_Co", 1123, 5};
    struct book ksiega1= {2, "BArthura_Conana_Doyle", "Sherlock_Holmes_2","murder_mystery", 1887, "Ward_Lock_&_Co", 14123, 3};
    struct book ksiega2= {3, "Arthura_Conana_Doyle", "Dzien_jak_codzień","murder_mystery", 1888, "Ward_Lock_&_Co", 1323, 1};
    struct book ksiega3= {4, "DArthura_Conana_Doyle", "Holmes_na_dzikim_zachodzie","murder_mystery", 1889, "Ward_Lock_&_Co", 115523, 5};
    struct book ksiega4= {5, "Wacław_Kubański", "Chłopaki_nie_płaczą","murder_mystery", 1996, "Ward_Lock_&_Co", 11423, 2};
    struct book ksiegaedit = {1, "Stefan_Batory", "Sherlock_Holmes","murder_mystery",1886, "Ward_Lock_&_Co", 1123, 5};
    Add_book(ksiega);
    Add_book(ksiega1);
    Add_book(ksiega2);
    Add_book(ksiega3);
    Add_book(ksiega4);
    Delete_book(ksiega4);
    Edit_book(ksiegaedit);
    Print_Books();
    Search_by_author("Wacław_Kubański");
    Search_by_title("Sherlock_Holmes");
    Search_by_category("murder_mystery");

//    list_elm *first = malloc(sizeof(list_elm));
//    first->val = 123;
//    first->next = NULL;
//    first->prev = NULL;
//    Add(12, first);
//    Add(1, first);
//    Add(99, first);
//    Remove_first(&first);
//    Remove_last(first);
//    Add(1000, first);
//    Print_list(first);
//    printf("%d\n", get_last(first));
    return 0;
}