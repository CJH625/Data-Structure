#include <iostream>
#define N 20
using namespace std;

typedef struct {
	int* elem;
	int length;
} SqList;

void initeList(SqList& L, int n) { // δ����ɹ�ʱ�쳣
	L.elem = new int[N];
	L.length = n;
	for (int i = 0; i < n; i++)
		cin >> L.elem[i];
}

void insertElem(SqList& L, int elem) { // Խ��ʱ�쳣
	if (L.length < N) {
		L.elem[L.length] = elem;
		L.length++;
	}
}

bool findElem(SqList L, int elem) {
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == elem)
			return true;
	return false;
}

int main()
{
	SqList La, Lb;
	int n1 = 4, n2 = 5;
	cout << "Please input La:" << endl;
	initeList(La, n1);
	cout << "Please input Lb:" << endl;
	initeList(Lb, n2);
	for (int i = 0; i < n2; i++) {
		if (findElem(La, Lb.elem[i])) {
			continue;
		}
		insertElem(La, Lb.elem[i]);
	}
	cout << "�ϲ���Ԫ��Ϊ:" << endl;
	for (int i = 0; i < La.length; i++)
		cout << La.elem[i] << " " ;
	cout << endl;
	cout << "�ϲ��󳤶�Ϊ:" << endl;
	cout << La.length << endl;
	delete[] La.elem;
	delete[] Lb.elem;
	cin.get();
	cin.get();
	return 0;
}


