#include<stdio.h>

typedef char Element;
typedef struct LCRSNode{
    struct LCRSNode* LeftChild;
    struct LCRSNode* RightSibling;
    Element data;
} LCRSNode;

LCRSNode* CreateNode(Element newData){
    LCRSNode* NewNode=(LCRSNode *)malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling=NULL;
    NewNode->data=newData;
    return NewNode;
}

void AppendNode(LCRSNode* Parent, LCRSNode* Child){
    if(Parent->LeftChild == NULL){
        Parent->LeftChild = Child;
    }
    else{
        LCRSNode* Curr = Parent->LeftChild;
        while(Curr->RightSibling != NULL){
            Curr = Curr->RightSibling;
        }
        Curr -> RightSibling = Child;
    }
}

void PrintTree(LCRSNode* Node, int depth){
    int i = 0;
    for(i = 0 ;i<depth;i++){
        printf(" ");
    }
    printf("%c\n",Node->data);
    if(Node->LeftChild != NULL){
        PrintTree(Node->LeftChild, depth+1);
    }
    if(Node->RightSibling !=NULL){
        PrintTree(Node->RightSibling,depth);
    }
}
void DestroyNode(LCRSNode* Node){
    free(Node);
}
void DestroyTree(LCRSNode* Root){
    if(Root->RightSibling!=NULL){
        DestroyTree(Root->RightSibling);
    }
    if(Root->LeftChild != NULL){
        DestroyTree(Root->LeftChild);
    }
    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    DestroyNode(Root);
}

