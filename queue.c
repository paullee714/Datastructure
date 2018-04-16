#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int top = 0;

void queue_enqueue();
void queue_dequeue();
void queue_print();

int main() {
	int input;
	while (1){
		printf("\n\n1.Push (max 5) \n2.pop\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
		queue_enqueue(); 
		break;
		case 2:
		queue_dequeue(); 
		break;
		} 
		queue_print();
	}
    return 0;
}

void queue_enqueue() {
	int n, i;
	if (top < SIZE){
		top++;
		for (i = top - 1; i > 0; i--) {
			queue[i] = queue[i - 1];
		}
		printf("\ninput : ");
		scanf("%d", &n);
		queue[0] = n;
	}
	else{
		printf("큐 오버 플로우\n");
	}

}


void queue_dequeue() {
	if (top == 0) {
		printf("Empty\n\n");
	}
	else
	{
		top--;
		printf("pop : %d\n\n", queue[top]);
	}
}


void queue_print() {
	int i;
	for (i = 0; i < top; i++)
		printf("%d ", queue[i]);
}