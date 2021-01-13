#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "customer.h"


int main(){
    int n,m;
    char author[50], title[50], category[50];
    list_elm *first = malloc(sizeof(list_elm));

    printf("Witamy w Biblotece PB\n");
    printf("**Aby zacząć podaj swoje dane osobowe**\n");
    printf("Pamiętając aby spacje zastępować  _ \nDane wprowadzone zatwierdzaj Enterem\n");

    struct custumer czlowiek;
    struct book ksiazka;

    printf("Podaj swoje imię\n");
    scanf("%s",czlowiek.name);

    printf("Podaj swoje nazwisko\n");
    scanf("%s",czlowiek.second_name);

    printf("Podaj swój adress\n");
    scanf("%s",czlowiek.address);

    printf("Podaj swój numer telefonu\n");
    scanf("%d",&czlowiek.phone_number);

    while(1){
        printf("Wybierz co chesz robić:\n- Wybierz 1 aby wypożyczyć książkę\n- Wybierz 2 aby zwrócić książkę\n- Wybierz 3 aby dodać książke zbioru biblotecznego bibloteki\n- Wybierz 4 aby zakończyć program\n");
        printf("Twój wybór\n");
        scanf("%d",&n);

        if(n==1){
            printf("Wybierz co chesz robić:\n");
            printf("- Wybierz 0 aby wypożyczyć książkę\n");
            printf("- Wybierz 1 aby wyświetlić listę książek\n- Wybierz 2 aby wyszukać listę książek po autorze\n");
            printf("- Wybierz 3 aby wyszukać listę książek po tytule\n- Wybierz 4 aby wyszukać listę książek po kategori\n");
            printf("- Wybierz 5 aby wyjść do menu\n");
            printf("Twój wybór\n");
            scanf("%d",&m);
            if(m==0){
                printf("Podaj autora\n");
                scanf("%s", author);
                printf("Podaj tytuł\n");
                scanf("%s", title);
                BorrowBook(czlowiek, author, title, first);
            }
            else if(m==1){
                Print_Books();
            }
            else if(m==2){
                printf("Podaj autora\n");
                scanf("%s", author);
                Search_by_author(author);
            }
            else if(m==3){
                printf("Podaj tytuł\n");
                scanf("%s", title);
                Search_by_title(title);
            }
            else if(m==4){
                printf("Podaj kategorie\n");
                scanf("%s", category);
                Search_by_category(category);
            }
            else if(m==5){

            }
            else{
                printf("Wprowadz poprawny wybór w zakresie 0-5\n");
            }

        }
        else if(n==2){
            printf("Wybierz co chesz robić:\n");
            printf("- Wybierz 0 aby zrócić książkę\n");
            printf("- Wybierz 1 aby wyświetlić listę książek\n- Wybierz 2 aby wyszukać listę książek po autorze\n");
            printf("- Wybierz 3 aby wyszukać listę książek po tytule\n- Wybierz 4 aby wyszukać listę książek po kategori\n");
            printf("- Wybierz 5 aby wyjść do menu\n");
            printf("Twój wybór\n");
            scanf("%d",&m);
            if(m==0){
                printf("Podaj autora\n");
                scanf("%s", author);
                printf("Podaj tytuł\n");
                scanf("%s", title);
                ReturnBook(czlowiek, author, title, first);
            }
            else if(m==1){
                Print_Books();
            }
            else if(m==2){
                printf("Podaj autora\n");
                scanf("%s", author);
                Search_by_author(author);
            }
            else if(m==3){
                printf("Podaj tytuł\n");
                scanf("%s", title);
                Search_by_title(title);
            }
            else if(m==4){
                printf("Podaj kategorie\n");
                scanf("%s", category);
                Search_by_category(category);
            }
            else if(m==5){

            }
            else{
                printf("Wprowadz poprawny wybór w zakresie 0-5\n");
            }
        }
        else if(n==3){

            printf("Podaj co chsz zrobić\n- Wybierz jeden aby dodać książke\n- Wybierz 2 aby edytować książkę\n- Wybierz 3 aby usunąć ksiażkę\n- Wybierz 4 aby wrócić do menu\n");
            printf("Twój wybór\n");
            scanf("%d",&m);

            if(m==1){
                printf("Podaj nr katalogowy\n");
                scanf("%d",&ksiazka.dir_num);
                printf("Podaj autora\n");
                scanf("%d",&ksiazka.author);
                printf("Podaj tytuł\n");
                scanf("%d",&ksiazka.title);
                printf("Podaj kategorie\n");
                scanf("%d",&ksiazka.category);
                printf("Podaj date wydania\n");
                scanf("%d",&ksiazka.date);
                printf("Podaj wydawnictwo\n");
                scanf("%d",&ksiazka.publ);
                printf("Podaj nr ISBN\n");
                scanf("%d",&ksiazka.isbn_code);
                printf("Podaj ilość sztuk\n");
                scanf("%d",&ksiazka.availablity);
                Add_book(ksiazka);
            }
            else if(m==2){
                printf("Podaj nr katalogowy\n");
                scanf("%d",&ksiazka.dir_num);
                printf("Podaj autora\n");
                scanf("%d",&ksiazka.author);
                printf("Podaj tytuł\n");
                scanf("%d",&ksiazka.title);
                printf("Podaj kategorie\n");
                scanf("%d",&ksiazka.category);
                printf("Podaj date wydania\n");
                scanf("%d",&ksiazka.date);
                printf("Podaj wydawnictwo\n");
                scanf("%d",&ksiazka.publ);
                printf("Podaj nr ISBN\n");
                scanf("%d",&ksiazka.isbn_code);
                printf("Podaj ilość sztuk\n");
                scanf("%d",&ksiazka.availablity);
                Edit_book(ksiazka);
            }
            else if(m==3){
                printf("Podaj nr katalogowy\n");
                scanf("%d",&ksiazka.dir_num);
                printf("Podaj autora\n");
                scanf("%d",&ksiazka.author);
                printf("Podaj tytuł\n");
                scanf("%d",&ksiazka.title);
                printf("Podaj kategorie\n");
                scanf("%d",&ksiazka.category);
                printf("Podaj date wydania\n");
                scanf("%d",&ksiazka.date);
                printf("Podaj wydawnictwo\n");
                scanf("%d",&ksiazka.publ);
                printf("Podaj nr ISBN\n");
                scanf("%d",&ksiazka.isbn_code);
                printf("Podaj ilość sztuk\n");
                scanf("%d",&ksiazka.availablity);
                Delete_book(ksiazka);
            }
            else if(m==4){

            }
            else{
                printf("Wprowadz poprawny wybór w zakresie 1-4\n");
            }

        }

        else if(n==4){
            printf("Dziekujęmy\nZapraszamy ponownie\n");
            return 0;
        }
        else{
            printf("Wprowadz poprawny wybór w zakresie 1-4\n");
        }
    }

//    struct book ksiega= {1, "CCArthura_Conana_Doyle", "Sherlock_Holmes","murder_mystery",1886, "Ward_Lock_&_Co", 1123, 5};
//    struct book ksiega1= {2, "BArthura_Conana_Doyle", "Sherlock_Holmes_2","murder_mystery", 1887, "Ward_Lock_&_Co", 14123, 3};
//    struct book ksiega2= {3, "Arthura_Conana_Doyle", "Dzien_jak_codzień","murder_mystery", 1888, "Ward_Lock_&_Co", 1323, 1};
//    struct book ksiega3= {4, "DArthura_Conana_Doyle", "Holmes_na_dzikim_zachodzie","murder_mystery", 1889, "Ward_Lock_&_Co", 115523, 5};
//    struct book ksiega4= {5, "Wacław_Kubański", "Chłopaki_nie_płaczą","murder_mystery", 1996, "Ward_Lock_&_Co", 11423, 2};
//    struct book ksiegaedit = {1, "Stefan_Batory", "Sherlock_Holmes","murder_mystery",1886, "Ward_Lock_&_Co", 1123, 5};
//    struct custumer czlowiek1= {"Jan", "Kowalski", "Warszawa",123123123};
//    struct custumer czlowiek2= {"Jan", "Kow1alski", "Warzawa",123123223};
//    Add_book(ksiega);
//    Add_book(ksiega1);
//    Add_book(ksiega2);
//    Add_book(ksiega3);
//    Add_book(ksiega4);
//    Delete_book(ksiega4);
//    Edit_book(ksiegaedit);
//    Print_Books();
//
//    list_elm *first = malloc(sizeof(list_elm));
//    first->val = ksiega;
//    first->val2 = czlowiek1;
//    first->next = NULL;
//    first->prev = NULL;
//    BorrowBook(czlowiek1,"Arthura_Conana_Doyle", "Dzien_jak_codzień", first);
//    BorrowBook(czlowiek1,"Arthura_Conana_Doyle", "Dzien_jak_codzień", first);
//    BorrowBook(czlowiek1,"Arthura_Conana_Doyle", "Dzien_jak_codzień", first);
//    ReturnBook(czlowiek2,"Arthura_Conana_Doyle", "Dzien_jak_codzień", first);
//    ReturnBook(czlowiek1,"Arthura_Conana_Doyle", "Dzien_jak_codzień", first);
//    Search_by_author("Wacław_Kubański");
//    Search_by_title("Sherlock_Holmes");
//    Search_by_category("murder_mystery");

    return 0;
}