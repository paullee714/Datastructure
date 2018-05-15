#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* Left;
    struct Node* Right;
    char Data;
}Node;

Node* CreateNode(char newdata){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Left=NULL;
    NewNode->Right=NULL;
    NewNode->Data = newdata;
    return NewNode;
}

void PreorderPrintTree(Node* Node){
    if(Node==NULL){
        return ;
    }
    printf("%c ",Node->Data);

    PreorderPrintTree(Node->Left);
    PreorderPrintTree(Node->Right);
}
void InorderPrintTree(Node* Node){
    if(Node == NULL){
        return;
    }
    InorderPrintTree(Node->Left);
    printf("%c ",Node->Data);
    InorderPrintTree(Node->Right);
}
void PostorderPrintTree(Node* node){
    if(node == NULL){
        return ;
    }
    PostorderPrintTree(node->Left);
    PostorderPrintTree(node->Right);
    printf("%c ",node->Data);

}

int main( void )
{
    /*  Create Node */
    Node* A = CreateNode('A');
    Node* B = CreateNode('B');
    Node* C = CreateNode('C');
    Node* D = CreateNode('D');
    Node* E = CreateNode('E');

    /*  Append Node */
    A->Left  = B;
    B->Left  = C;
    B->Right = D;
    A->Right = E;

    /*  Print Node */
    printf("Preorder Sequence \n");
    PreorderPrintTree( A );
    printf("\n\n");

    printf("Inorder Sequence \n");
    InorderPrintTree( A );
    printf("\n\n");

    printf("Postorder Sequence \n");
    PostorderPrintTree( A );
    printf("\n");

    return 0;
}