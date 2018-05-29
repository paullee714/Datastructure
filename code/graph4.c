#include <stdio.h> 
#include <stdlib.h>          // malloc 
#include <string.h>          // puts, gets 
#define MAX 8                  // 정점의 갯수 
#define TRUE 1    
#define FALSE 0 
////////////  노드 구 조 체 //////////////////////// 
typedef struct Node *P_Node;                   // 노드포인터 
typedef struct Node {         
    P_Node link;                                     // 노드의 포인터 링크 
    int vtx;                                               // 정점 번호 
}Node; 

////////////  전 역 변 수 ////////////////////////// 
P_Node graph[MAX];                    // 인접리스트 구성 초기 포인터배열 
short int mark[MAX];                   // 검색시 이용될 마킹배열 
int Que[MAX];                              // bfs에 이용될 환형큐 
int matrix[MAX][MAX]={          // 인접행렬 
                    {0,1,1,0,0,0,0,0}, 
                    {1,0,0,1,1,0,0,0}, 
                    {1,0,0,0,0,1,1,0}, 
                    {0,1,0,0,0,0,0,1}, 
                    {0,1,0,0,0,0,0,1}, 
                    {0,0,1,0,0,0,0,1}, 
                    {0,0,1,0,0,0,0,1}, 
                    {0,0,0,1,1,1,1,0} 
};
//////////// 함 수       /////////////////////////////// 

void init();                    // 인접행렬을 이용해서 인접리스트 초기화 
void Clear_mark();          // 마킹 FALSE로 클리어 

//-------------------------------------- 탐색 
void dfs(int v);                   // 깊이탐색  
void bfs(int v);                   // 너비탐색 
//-------------------------------------- QUEUE 
void enq(int *rear,int vtx); 
int deq(int *front); 

int main() { 
    int v;                     // 탐색 정점 
    Clear_mark();          // 마킹클리어 
    init();         // 인접행렬을 기반으로 인접 리스트 구성  
    puts("깊이 우선탐색 초기 정점"); 
    scanf("%d",&v); 
    dfs(v); 
    puts(""); 
    Clear_mark();         // 마킹 클리어 
    puts("너비 우선탐색 초기 정점"); 
    scanf("%d",&v); 
    bfs(v); 
    puts(""); 
    return 0; 
    } 

// 인접행렬을 인접리스트로 초기화 
void init(){ 
    int x,y; 
    P_Node move;         // 이동포인터 
    P_Node st;          // 비교 포인터 
    P_Node tmp;          // 동적할당 
    for(x=0; x<MAX; x++){ 
        st = graph[x];         // 움직이면서 비교할 변수 
        printf("V%d  ---> ", x); 
        for(y=0; y<MAX; y++) { 
            if(matrix[x][y] != FALSE)  // matrix[x][y] == TRUE 
            { 
                tmp = (P_Node)malloc(sizeof(Node)); 
                tmp->vtx = y;     // vtx값에 점 번호  
                if(graph[x] == st)   // 초기에 아무연결도 없을때 
                {     // move가 tmp주소값 갖게하고 graph역시 tmp의 주소값 가진다. 
                    move = tmp;     
                    graph[x] = tmp; 
                    printf("%5d", tmp->vtx); 
                } 
                else       // 뭔가가 연결되있을때 
                {     // 노드를 연결시킴 
                    move->link = tmp; 
                    move = tmp; 
                    printf("%5d",tmp->vtx); 
                } 
            } 
        } 
        tmp->link = NULL;      // 마지막에 NULL값 
        puts("\n"); 
    } 

 // 잘연결 됐다면 위의 출력물과 같은게 출력되어야 한다. [Debug 소스] 
 /* for(x=0; x<MAX; x++)    
  { 
           move = graph[x]; 
           printf("V%d -----> ", x); 
           while(move) 
           { 
                    printf("%5d", move->vtx); 
                    move = move->link; 
           } 
           puts("\n"); 
  }*/ 
}  

// 깊이우선탐색 
void dfs(int v)  
{ 
    P_Node w; 
    mark[v] = TRUE; 
    printf("%3d",v); 
    for(w=graph[v]; w; w = w->link) 
        if(!mark[w->vtx]) 
            dfs(w->vtx); 
} 
//너비우선탐색 
void bfs(int v) 
{ 
    P_Node w; 
    int front,rear; 
    front = rear = -1; 
    printf("%3d",v); 
    mark[v] = TRUE; 
    enq(&rear, v); 
    while(front != rear){ 
        v = deq(&front); 
        for(w = graph[v]; w; w = w->link){ 
            if(!mark[w->vtx])  // 마킹되지않은 정점이면(FALSE) 
            { 
                printf("%3d",w->vtx); 
                enq(&rear,w->vtx); 
                mark[w->vtx] = TRUE; 
            } 
        } 
    } 
} 

////////////////// Q U E U E ////////////////// 
 void enq(int *rear,int vtx)      // 
{ 
        *rear = (*rear)%MAX;   //enqueue 
        Que[++(*rear)] = vtx; 
} 

int deq(int *front)    // dequeue 
{ 
    return Que[++(*front)%MAX]; 
} 

void Clear_mark(){ 
    int i; 
    for(i=0; i<MAX; i++){
        mark[i] = FALSE; 
    } 
} 