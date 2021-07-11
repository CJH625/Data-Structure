#include <iostream>
#define MAXSIZE 20

using namespace std;

typedef struct {
	int* elem;
	int front;
	int rear;
} SqQueue;

void initSqQueue(SqQueue& Q) {
	Q.elem = new int[MAXSIZE];
	Q.front = 0;
	Q.rear = 0;
}

void enQueue(SqQueue& Q, int elem) { // 入队，队尾操作
	if (Q.rear - Q.front >= MAXSIZE)
		exit(OVERFLOW);
	Q.elem[Q.rear] = elem;
	Q.rear++;
}

void deQueue(SqQueue& Q, int& elem) { // 出队。队头操作
	if (Q.rear == Q.front)
		exit(UNDERFLOW);
	elem = Q.elem[Q.front];
	Q.elem[Q.front] = 0;
	Q.front++;
}

bool QueueEmpty(SqQueue& Q) {
	return (Q.front == Q.rear ? true : false);
}

int QueueLength(SqQueue& Q) {
	return (Q.rear - Q.front);
}
int getHead(SqQueue& Q) { // 返回队头元素
	return Q.front;
}
void destroyQueue(SqQueue& Q) {
	delete []Q.elem;
}

int main()
{
	SqQueue Q{};
	return 0;
}