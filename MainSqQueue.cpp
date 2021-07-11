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

void enQueue(SqQueue& Q, int elem) { // ��ӣ���β����
	if (Q.rear - Q.front >= MAXSIZE)
		exit(OVERFLOW);
	Q.elem[Q.rear] = elem;
	Q.rear++;
}

void deQueue(SqQueue& Q, int& elem) { // ���ӡ���ͷ����
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
int getHead(SqQueue& Q) { // ���ض�ͷԪ��
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