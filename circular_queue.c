#include<stdio.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;
//error print function
void error(char *message){
    fprintf(stderr,"%s\n",message);
}
//initialize function
void init(QueueType *q){
    q->front = q->rear = 0;
}
//Check queue -> Empty
int is_empty(QueueType *q){
    return (q->front == q->rear);
}
//Check Queue -> Full
int is_full(QueueType *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE==q->front);
}
//insert function
void enqueue(QueueType *q,element item){
    if(is_full(q)){
        error("Queue Overflow!!!>>>>>>>>>>>>>>\n");
    }
    q->rear =(q->rear+1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}
//delete function
element dequeue(QueueType *q){
    if(is_empty(q)){
        error("Queue is Empty!!!>>>>>>>>>>>>>>>>\n");
    }
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    return q->queue[q->front];
}
//peek function
element peek(QueueType *q){
    if(is_empty(q)){
        error("Queue is Empty!!!>>>>>>>>>>>>>>>>\n");
    }
    return q->queue[(q->front+1)%MAX_QUEUE_SIZE];
}

int main(){
    QueueType q;
    init(&q);
    printf("front = %d , rear = %d\n",q.front,q.rear);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    printf("dequeue() = %d\n",dequeue(&q));
    printf("dequeue() = %d\n",dequeue(&q));
    printf("dequeue() = %d\n",dequeue(&q));
    printf("front = %d , rear = %d\n",q.front,q.rear);
    return 0;
}
