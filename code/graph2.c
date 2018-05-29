#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
//방향성 없는 그래프

typedef struct{//그래프 형식 정의
    int vn; //정점 개수
    int **matrix;//그래프 인접 행렬
    int weight;//그래프 weight 
}Graph;

Graph *MakeGraph();//그래프 만들기
void DeleteGRaph(Graph *graph);//그래프 소멸
void AddEdge(Graph *graph, int start, int goal); //간선 추가
void ViewNeighbors(Graph *g);//이웃 정점 보여주기
void ViewNeighbor(Graph *g,int vt);

int main(void){        
    Graph *graph;
    graph = MakeGraph();//그래프 만들기    
    ViewNeighbors(graph); //이웃 정점 보여주기
    DeleteGRaph(graph);//그래프 소멸
    return 0;
}

Graph *NewGraph(int max_vertex){
    int i = 0;
    Graph *graph = (Graph *)malloc(sizeof(Graph));//그래프 메모리 동적 할당
    graph->vn = max_vertex;//최대 정점 개수 설정
    graph->matrix = (int **)malloc(sizeof(int *)*max_vertex);//매트릭스 메모리 할당
    for (i = 0; i < max_vertex; i++){
        graph->matrix[i] = (int *)malloc(sizeof(int)*max_vertex);//매크릭스 [i-row] 메모리 할당
        memset(graph->matrix[i], 0, sizeof(int)*max_vertex);//메모리 0으로 초기화
    }
    return graph;
}

Graph *MakeGraph(){
    Graph *graph;
    graph = NewGraph(9);//그래프 동적 생성
    AddEdge(graph, 0, 1);//간선 추가
    AddEdge(graph, 0, 2);//간선 추가
    AddEdge(graph, 1, 2);//간선 추가
    AddEdge(graph, 1, 3);//간선 추가
    AddEdge(graph, 2, 4);//간선 추가
    AddEdge(graph, 3, 6);//간선 추가
    AddEdge(graph, 4, 5);//간선 추가
    AddEdge(graph, 4, 6);//간선 추가
    AddEdge(graph, 4, 7);//간선 추가
    AddEdge(graph, 6, 8);//간선 추가
    return graph;
}
void DeleteGRaph(Graph *graph){
    int i = 0;
    for (i = 0; i < graph->vn; i++){//최대 정점 개수만큼
        free(graph->matrix[i]);//매트릭스 [i-row]  메모리 소멸
    }
    free(graph->matrix);//매트릭스 메모리 해제
    free(graph);//그래프 메모리 해제
}
void AddEdge(Graph *graph, int start, int goal){
    graph->matrix[start][goal] = 1;//간선 설정
    graph->matrix[goal][start] = 1;//간선 설정
}
void ViewNeighbors(Graph *g){
    int i;    
    printf("=== 이웃 정점 ===\n");
    for (i = 0; i < g->vn; i++){
        printf("%d의 이웃: ",i);
        ViewNeighbor(g,i);//i정점의 이웃 보여주기
        printf("\n");
    }    
}
void ViewNeighbor(Graph *g,int vt){
    int i;
    for (i = 0; i < g->vn; i++)
    {
        if(g->matrix[vt][i]){
            printf("%d ",i);
        }
    }
}


