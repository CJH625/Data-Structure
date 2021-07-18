#include <iostream>
#include <array>
#define MAXSIZE 20

using namespace std;

typedef struct {
	// array<char, 10> name; // 字符数组初始化{null}
	string name; // 字符串类型
	char sex; // 字符变量初始化{'\0'},空字符，asii码为零
} Person;

typedef struct {
	Person* elem;
	int front;
	int rear;
} SqQueue;

void initSqQueue(SqQueue& Q) {
	Q.elem = new Person[MAXSIZE]{};
	Q.front = 0;
	Q.rear = 0;
}

void enQueue(SqQueue& Q, Person elem) { // 入队，队尾操作
	if (Q.rear - Q.front >= MAXSIZE)
		exit(OVERFLOW);
	Q.elem[Q.rear] = elem;
	Q.rear++;
}

void deQueue(SqQueue& Q, Person& elem) { // 出队。队头操作
	if (Q.rear == Q.front)
		exit(UNDERFLOW);
	elem = Q.elem[Q.front];
	Q.elem[Q.front] = {"\0", '\0'};
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
	delete[]Q.elem;
}

/*
	cin，当读取缓存区时，发现有换行符，忽略并清除，空格不视为字符
	cin.getline，读取缓存区完毕时，清除换行符，空格视为字符
	cin.get，不忽略且清除换行符，空格视为字符，返回值为int，只能读入字符，根据参数不同，可读取字符或字符串
	注意: 空字符(null,'\0') 和 ' ' 和 '0'三者asc码并不相同
			换行符'\n' , 回车符'\r'
*/

int main()
{
	SqQueue MDancers, FDancers;	
	Person mDancer{}, fDancer{};
	initSqQueue(MDancers);
	initSqQueue(FDancers);
	cout << "Please input Man Dancer:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> mDancer.name >> mDancer.sex;
		enQueue(MDancers, mDancer);
	}
	cout << "Please input Woman Dancer:" << endl;
	for(int i = 0; i < 3; i++) {
		cin >> fDancer.name >> fDancer.sex;
		enQueue(FDancers, fDancer);
	}
	cout << "Print result:" << endl;
	while (!QueueEmpty(MDancers) && !QueueEmpty(FDancers)) {
		deQueue(MDancers, mDancer);
		deQueue(FDancers, fDancer);
		cout << mDancer.name << " " << fDancer.name << endl;
	} 
	cout << "The next:" << endl;
	if (QueueEmpty(MDancers)) {
		cout << FDancers.elem[getHead(FDancers)].name << endl;
	}
	else {
		cout << MDancers.elem[getHead(MDancers)].name << endl;
	}
	destroyQueue(MDancers);
	destroyQueue(FDancers);
	cin.get();
	cin.get();
	return 0;
}