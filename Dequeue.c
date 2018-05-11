#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int Item;
    struct Node *Prev;
    struct Node *Next;
}Node;

typedef struct{
    Node *header;
    Node *tailer;
}Deque;

void init_Deque(Deque *Target_Deque){
    Target_Deque->header = NULL;
    Target_Deque->tailer = NULL;
}

void Input_Head(Deque* Target_Deque,int Item){
    Node* New =(Node *)malloc(sizeof(Node));
    if(Target_Deque->header == NULL){
        Target_Deque->header = New;
        Target_Deque->tailer = New;
        New -> Item=Item;
        New->Next = NULL;
        New->Prev = NULL;
        return ;
    }
    Target_Deque->header->Prev = New;
    New->Next = Target_Deque->header;
    Target_Deque->header = New;
    New -> Item = Item;
    New -> Prev = NULL;
}

void Input_Tail(Deque* Target_Deque,int Item){
    Node *New = (Node *)malloc(sizeof(Node));
    if(Target_Deque->tailer == NULL){
        Target_Deque->header = New;
        Target_Deque->tailer = New;
        New->Item=Item;
        New->Next=NULL;
        New->Prev=NULL;
        return;
    }
    New->Item = Item;
    Target_Deque ->tailer->Next=New;
    New->Prev = Target_Deque->tailer;
    Target_Deque->tailer = New;
    New -> Next = NULL;
}

int Output_Head(Deque *Target_Dequeu){
    if(Target_Dequeu->header == NULL){
        printf("The Deque is Empty\n");
        return 0;
    }
    int return_value;
    Node *Cur = NULL;
    return_value = Target_Dequeu->header->Item;
    Target_Dequeu->header->Next->Prev = NULL;
    Cur = Target_Dequeu->header;
    Target_Dequeu->header = Target_Dequeu->header->Next;
    free(Cur);
    return return_value;
}

int Output_Tail(Deque *Target_Deque){

    if(Target_Deque->tailer == NULL){
        printf("The Deque is Empty\n");
        return 0;
    }
    int return_value=0;
    Node *Cur = NULL;
    return_value = Target_Deque->tailer->Item;
    Target_Deque->tailer->Prev->Next=NULL;
    Cur=Target_Deque->tailer;
    Target_Deque->tailer=Target_Deque->tailer->Prev;
    free(Cur);
    return return_value;
}

void printing(Deque *Target_Deque){

    Node *Cur = Target_Deque->header;
    while(Cur != NULL){
        printf("%d ",Cur->Item);
        Cur=Cur->Next;
    }
    printf("\n");
}

int main(void){
    Deque dq;
    init_Deque(&dq);
    
    Input_Head(&dq,1);
    Input_Head(&dq,3);
    printing(&dq);

}