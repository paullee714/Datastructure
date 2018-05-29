//Program.c
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
 
typedef struct{//그래프 형식 정의
    int vn; //정점 개수
    int **matrix;//그래프 인접 행렬
} Graph;


Graph *NewGraph(int max_vertex);//그래프 동적 생성
void DeleteGraph(Graph *graph);//그래프 소멸
void AddEdge(Graph *graph, int start, int goal);//간선 추가
void ViewGraph(Graph *graph);//그래프 정보 출력
void ViewIndegree(Graph *g);//진입차수 확인
void ViewOutdegree(Graph *g);//진출차수 확인
 
int main(void)
{        
    Graph *graph;
    graph = NewGraph(6);//그래프 동적 생성
    AddEdge(graph, 0, 1);//간선 추가
    AddEdge(graph, 3, 1);//간선 추가
    AddEdge(graph, 2, 4);//간선 추가
    AddEdge(graph, 4, 2);//간선 추가
    ViewGraph(graph);
    ViewIndegree(graph); //진입차수 확인
    ViewOutdegree(graph);//진출차수 확인    
    DeleteGraph(graph);//그래프 소멸    
    return 0;    
}

Graph *NewGraph(int max_vertex)
{
    int i = 0;
    Graph *graph = (Graph *)malloc(sizeof(Graph));//그래프 메모리 동적 할당
    graph->vn = max_vertex;//최대 정점 개수 설정
    graph->matrix = (int **)malloc(sizeof(int *)*max_vertex);//매트릭스 메모리 할당
    for (i = 0; i < max_vertex; i++)
    {
        graph->matrix[i] = (int *)malloc(sizeof(int)*max_vertex);//매크릭스 [i-row] 메모리 할당
        memset(graph->matrix[i], 0, sizeof(int)*max_vertex);//메모리 0으로 초기화
    }
    return graph;
}
void DeleteGraph(Graph *graph)
{
    int i = 0;
    
    for (i = 0; i < graph->vn; i++)//최대 정점 개수만큼
    {
        free(graph->matrix[i]);//매트릭스 [i-row]  메모리 소멸
    }
    free(graph->matrix);//매트릭스 메모리 해제
    free(graph);//그래프 메모리 해제
}
void AddEdge(Graph *graph, int start, int goal)
{
    graph->matrix[start][goal] = 1;//간선설정
}
void ViewGraph(Graph *graph)
{
    int i =0;
    int j =0;
    for(i=0;i<graph->vn;i++)
    {
        printf("%d 에서 갈 수 있는 정점:",i);
        for(j=0;j<graph->vn;j++)
        {
            if(graph->matrix[i][j])
            {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}
void ViewIndegree(Graph *g)
{
    int i, j;
    int degree;
    printf("In-degree\n");
    for (i = 0; i < g->vn; i++)
    {
        degree = 0;//0으로 설정
        for (j = 0; j < g->vn; j++)
        {
            if (g->matrix[j][i])//올 수 있는 곳이 있으면
            {
                degree++;//차수 1 증가
            }
        }
        printf("%d ", degree);//차수 출력
    }
    printf("\n");

}
void ViewOutdegree(Graph *g)
{
    int i, j;
    int degree;
    printf("Out-degree\n");
    for (i = 0; i < g->vn; i++)
    {
        degree = 0;//0으로 설정
        for (j = 0; j < g->vn; j++)
        {
            if (g->matrix[i][j])//갈 수 있는 곳이 있으면
            {
                degree++;//차수 1 증가
            }
        }
        printf("%d ", degree);//차수 출력
    }
    printf("\n");
}