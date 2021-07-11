#include <iostream>
#define MAXSIZE 10

using namespace std;

typedef struct {
	int* elem;
	int front;
	int rear;
} CirQueue; // 牺牲一个存储单元，确保队空和队满区分

void initCirQueue(CirQueue& Q) {
	Q.elem = new int[MAXSIZE] {};
	Q.front = 0;
	Q.rear = 0;
}

void enQueue(CirQueue& Q, int elem) { // 入队，队尾操作
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		exit(OVERFLOW);
	Q.elem[Q.rear] = elem;
	Q.rear = (Q.rear + 1) % MAXSIZE;
}

void deQueue(CirQueue& Q, int& elem) { // 出队。队头操作
	if (Q.rear == Q.front)
		exit(UNDERFLOW);
	elem = Q.elem[Q.front];
	Q.elem[Q.front] = 0;
	Q.front = (Q.front + 1) % MAXSIZE;
}

bool QueueEmpty(CirQueue& Q) {
	return (Q.front == Q.rear ? true : false);
}

int QueueLength(CirQueue& Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int getHead(CirQueue& Q) { // 返回队头元素
	return Q.elem[Q.front];
}

void destroyQueue(CirQueue& Q) {
	delete[] Q.elem;
}

int main()
{
	CirQueue Q{};
	int e{ 0 };
	// cout << Q.front << " " << Q.rear << " " << Q.elem << endl;
	initCirQueue(Q);
	while ((Q.rear + 1) % MAXSIZE != Q.front) {
		cin >> e;
		enQueue(Q, e);
	}
	while (Q.front != Q.rear) {
		deQueue(Q, e);
		cout << e << " " ;
	}
	destroyQueue(Q);
	cin.get();
	cin.get();
	return 0;
}