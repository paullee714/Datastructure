#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;
//print Error Message
void error(char *message){
    fprintf(stderr,"%s\n",message);
}
//create nodes
ListNode *create_node(element data, ListNode *link){
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    if(new_node == NULL){
        error("Malloc Error!>>>>>>>>>>>>>\n");
    }
    new_node -> data = data;
    new_node -> link = link;
    return (new_node);
}
//print list
void display(ListNode *head){
    ListNode *p;
    if(head == NULL){
        return ;
    }
    p=head;
    do{
        printf("%d->",p->data);
        p=p->link;
    }while(p != head);
}
//insert first
void insert_first(ListNode **phead, ListNode *node){
    if(*phead == NULL){
        *phead = node;
        node->link = node;
    }else{
        node->link = (*phead)->link;
        (*phead)->link = node;
    }
}
//insert last
void insert_last(ListNode **phead, ListNode *node){
    if(*phead == NULL){
        *phead = node;
        node->link = node;
    }else{
        node->link = (*phead)->link;
        (*phead)->link = node;
        *phead = node;
    }
}

int main(void){

    ListNode *list1 = NULL;
    //list1 = 20 -> 10 -> 30
    insert_first(&list1,create_node(10,NULL));
    insert_first(&list1,create_node(20,NULL));
    insert_first(&list1,create_node(30,NULL));
    display(list1);

    return 0;
}

