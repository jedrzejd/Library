
typedef struct item{
    int val;
    struct item *next, *prev;
}list_elm;


void Add(int val, list_elm *item){
    while (item->next != NULL) {
        item = item->next;
    }
    list_elm *pom = malloc(sizeof(list_elm));
    pom->val = val;
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

int *get_last(list_elm *first){
    while (first->next != NULL) {
        first = first->next;
    }
    return first->val;
}

void Print_list(list_elm *first){
    while(first!=NULL){
        printf("%d\n", first->val);
        first = first->next;
    }
}