//스택 - 연결리스트로 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1


typedef struct Node //노드 정의
{
    int data;
    struct Node *next;
}Node;

typedef struct Stack //Stack 구조체 정의
{
    Node *top;    //맨 앞 노드(가장 최근에 생성한 노드)
}Stack;

void InitStack(Stack *stack);//스택 초기화
int IsEmpty(Stack *stack); //스택이 비었는지 확인
void Push(Stack *stack, char data); //스택에 보관
int Pop(Stack *stack); //스택에서 꺼냄
int check_matching(char *in);


int main(void)
{
    char input[100];
    printf("input exp: ");
    scanf("%s",input);
    printf("your exp is : %s\n",input);
    if(check_matching(input)==TRUE){
        printf("success!!\n");
    }else{
        printf("fail!\n");
    }
    return 0;
}
void InitStack(Stack *stack)
{
    stack->top = NULL; //스택 초기화에서는 top을 NULL로 설정
}

int IsEmpty(Stack *stack)
{   
    if(stack->top ==NULL){
        return 1;
    }else{
    return 0;    //top이 NULL이면 빈 상태    
    }
}
void Push(Stack *stack,char data)
{
    Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
    now->data = data;//데이터 설정
    now->next = stack->top;//now의 next링크를 현재 top으로 설정   
    stack->top = now;   //스택의 맨 앞은 now로 설정
}
int Pop(Stack *stack)
{
    Node *now;
    int re;
    if (IsEmpty(stack))
    {
        return 0;
    }
    now = stack->top;//now를 top으로 설정
    re = now->data;//꺼낼 값은 now의 data로 설정

    stack->top = now->next;//top을 now의 next로 설정
    free(now);//필요없으니 메모리 해제
    return re;
}
int check_matching(char *in){
    Stack s;
    char ch; // character from in
    char open_ch; // character from stack
    int i;
    int n = (int) strlen(in);
    InitStack(&s);
    
    for (i=0; i<n; i++) {
        ch = in[i];
        switch (ch) {
            case '(': case '{' : case '[':
                Push(&s, ch);
                break;
            case ')': case '}' : case ']':
                if (IsEmpty(&s)) // condition 1, 3
                    return FALSE;
                open_ch = Pop(&s); // condition 2, 3
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '{' && ch != '}') ||
                    (open_ch == '[' && ch != ']')) {
                    return FALSE;
                }
                break;
        }
    }
    if (!IsEmpty(&s)) // condition 1
        return FALSE;
    return TRUE;
}