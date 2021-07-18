#include <iostream>
#include <array>
#define MAXSIZE 20

using namespace std;

typedef struct {
	// array<char, 10> name; // �ַ������ʼ��{null}
	string name; // �ַ�������
	char sex; // �ַ�������ʼ��{'\0'},���ַ���asii��Ϊ��
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

void enQueue(SqQueue& Q, Person elem) { // ��ӣ���β����
	if (Q.rear - Q.front >= MAXSIZE)
		exit(OVERFLOW);
	Q.elem[Q.rear] = elem;
	Q.rear++;
}

void deQueue(SqQueue& Q, Person& elem) { // ���ӡ���ͷ����
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
int getHead(SqQueue& Q) { // ���ض�ͷԪ��
	return Q.front;
}
void destroyQueue(SqQueue& Q) {
	delete[]Q.elem;
}

/*
	cin������ȡ������ʱ�������л��з������Բ�������ո���Ϊ�ַ�
	cin.getline����ȡ���������ʱ��������з����ո���Ϊ�ַ�
	cin.get����������������з����ո���Ϊ�ַ�������ֵΪint��ֻ�ܶ����ַ������ݲ�����ͬ���ɶ�ȡ�ַ����ַ���
	ע��: ���ַ�(null,'\0') �� ' ' �� '0'����asc�벢����ͬ
			���з�'\n' , �س���'\r'
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