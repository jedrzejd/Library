
struct custumer{
    char name[50], second_name[50], address[50];
    int phone_number;
};

typedef struct item{
    struct book val;
    struct custumer val2;
    struct item *next, *prev;
}list_elm;


void Add(struct book val, struct custumer val2, list_elm *item){
    while (item->next != NULL) {
        item = item->next;
    }
    list_elm *pom = malloc(sizeof(list_elm));
    pom->val = val;
    pom->val2 = val2;
    pom->next = NULL;
    pom->prev = item;

    item->next = pom;
}

void Remove_first(list_elm **item){
    list_elm *pom = *item;
    if(pom == NULL)return;
    *item = (*item)->next;
    (*item)->prev = NULL;
    free(pom);
}

void Remove_last(list_elm *item){
    while (item->next != NULL) {
        item = item->next;
    }
    list_elm *pom = item;
    if(pom == NULL)return;
    (item->prev)->next=NULL;
    free(pom);
}

list_elm get_last(list_elm *first){
    while (first->next != NULL) {
        first = first->next;
    }
    return *first;
}

void Print_list(list_elm *first){
    while(first!=NULL){
//        printf("%s %s %s %s\n", first->val.name, first->val.name,first->val.name,first->val.name);
        first = first->next;
    }
}

int comp_cust(struct custumer a, struct custumer b){
    if(comp_strings(a.name, b.name )==1&&comp_strings( a.second_name, b.second_name )==1&&comp_strings( a.address, b.address )==1&&( a.phone_number == b.phone_number )) {
        return 1;
    }
    return 0;
}

int exist_list(list_elm *first, struct book it1, struct custumer it2, list_elm last){
    while(first!=NULL){
//            printf("%s %s %s %s\n", first->val, first->val,first->val,first->val.name);
        if (comp_strings(first->val.author, it1.author) && comp_strings(first->val.title, it1.title) && comp_cust(first->val2, it2)==1){
            first->val=last.val;
            first->val2=last.val2;
            return 1;
        }
        first = first->next;
    }
    return 0;
}


void BorrowBook( struct custumer client, char *author, char *title, list_elm *first){
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int ch = 0, licz = 0;
    int cnt = 0;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        if(comp_strings(temp[licz].author, author)==1 && comp_strings(temp[licz].title, title)==1 && temp[licz].availablity>0){
//            printf("%s %s %d\n",author, title, temp[licz].availablity);
            cnt=1;
            temp[licz].availablity = temp[licz].availablity - 1;
        }
        licz++;
    }
    close_file(d);

    d = open_file(plik, "w");
    for(int i=0; i<licz; i++){
        fprintf(&d, "%d %d %s %s %s %d %s %d %d\n", i, temp[i].dir_num, temp[i].author, temp[i].title, temp[i].category, temp[i].date,
                temp[i].publ, temp[i].isbn_code, temp[i].availablity);
    }

    fprintf(&d, "-1 1 - - - 1 - 1 1\n");
    close_file(d);


    if(cnt == 1){
        printf("Wypożyczono książke %s\n",title);
        struct book curr;
        strcpy(curr.author,author);
        strcpy(curr.title,title);
        Add(curr, client, first);
    }
    else{
        printf("Książke %s nie jest dostępna\n",title);
    }


}


void ReturnBook(struct custumer client, char *author, char *title, list_elm *first){
    FILE d = open_file(plik, "r");
    struct book temp[100];
    int ch = 0, licz = 0;
    int cnt = 0;
    while(1){
        fscanf(&d, "%d %d %s %s %s %d %s %d %d", &ch, &temp[licz].dir_num, temp[licz].author, temp[licz].title, temp[licz].category, &temp[licz].date, temp[licz].publ, &temp[licz].isbn_code, &temp[licz].availablity);
        if(ch == -1){
            break;
        }
        if(comp_strings(temp[licz].author, author)==1 && comp_strings(temp[licz].title, title)==1){
            cnt=licz+1;

        }
        licz++;
    }
    close_file(d);

    d = open_file(plik, "w");
    for(int i=0; i<licz; i++){
        fprintf(&d, "%d %d %s %s %s %d %s %d %d\n", i, temp[i].dir_num, temp[i].author, temp[i].title, temp[i].category, temp[i].date,
                temp[i].publ, temp[i].isbn_code, temp[i].availablity);
    }

    fprintf(&d, "-1 1 - - - 1 - 1 1\n");
    close_file(d);

    struct book curr;
    strcpy(curr.author,author);
    strcpy(curr.title,title);
    int czy = exist_list(first, curr, client, get_last(first));
    if(cnt > 0 && czy==1){
        printf("Zwrócono książke %s\n",title);
        temp[cnt-1].availablity++;
        Remove_last(first);
    }
    else{
        printf("Książke %s nie da się zwrócić \n",title);
    }
}

