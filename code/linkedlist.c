#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

//error print function
void error(char *message){
    fprintf(stderr,"%s\n",message);
}
//insert function
void insert_node(ListNode **phead,ListNode *p, ListNode *new_node){
    if(*phead == NULL){ //The List is Empty.
        new_node -> link = NULL;
        *phead = new_node;
    }else if(p == NULL){ // if 'p' is NULL, insert first node.
        new_node -> link = *phead;
        *phead = new_node;
    }else{ //insert after p
        new_node -> link = p->link;
        p->link = new_node;
    }
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed){
    if(p==NULL){
        *phead = (*phead)->link;
    }else{
        p->link = removed->link;
    }
    free(removed);
}
void display(ListNode *head){
    ListNode *p = head;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->link;
    }
    printf("\n");
}
void display_recur(ListNode *head){
    ListNode *p = head;
    if(p!=NULL){
        printf("%d->",p->data);
        display_recur(p->link);
    }
}
ListNode *search(ListNode *head, int x){
    ListNode *p;
    p=head;
    while(p!=NULL){
        if(p->data == x){ // search done!
            return p;
        }
        p = p->link;
    }
    return p;
}
//Link the List
ListNode *concat(ListNode *head1, ListNode *head2){
    ListNode *p;
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    else{
        p=head1;
        while(p->link !=NULL){
            p=p->link;
        }
        p->link = head2;
        return head1;
    }
}
//make reverse 
ListNode *reverse(ListNode *head){
    ListNode *p, *q, *r;
    p=head;
    q=NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}
ListNode *create_node(element data, ListNode *link){
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    if( new_node == NULL ){
        error("Malloc Error!>>>>>>>\n");
    }
    new_node->data = data;
    new_node->link = link;
    return (new_node);
}
int main(void){
    ListNode *list1 = NULL;
    ListNode *list2 = NULL;
    ListNode *p;

    //list1 = 30 -> 20 -> 10
    insert_node(&list1,NULL,create_node(10,NULL));
    insert_node(&list1,NULL,create_node(20,NULL));
    insert_node(&list1,NULL,create_node(30,NULL));
    display(list1);

    //list1 = 20 -> 10
    remove_node(&list1,NULL,list1);
    display(list1);

    //list2 = 80->70->60
    insert_node(&list2,NULL,create_node(60,NULL));
    insert_node(&list2,NULL,create_node(70,NULL));
    insert_node(&list2,NULL,create_node(80,NULL));
    display(list2);

    //list1 = list1 + list2
    list1 = concat(list1,list2);
    display(list1);

    //reverse list1
    list1 = reverse(list1);
    display(list1);

    //search 20 in list1
    p = search(list1,20);
    printf("Success!! : %d \n",p->data);
    return 0;
}