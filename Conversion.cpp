#include <iostream>
#define MAXVALUE 20
#define OCT 8

using namespace std;

typedef struct {
	int* base;
	int* top;
	int length;
} SqStack;

void initStack(SqStack& S) {
	S.base = new int[MAXVALUE] {}; // 初始化内存为零
	S.top = S.base;
	S.length = MAXVALUE;
}

void pushStack(SqStack& S, int elem) {
	if ((S.top - S.base) < S.length) {
		*S.top = elem;
		S.top++;
	}
	else
		exit(OVERFLOW);
}

void popStack(SqStack& S, int& elem) {
	if (S.top != S.base) {
		S.top--;
		elem = *S.top;
		*S.top = 0;
	}
	else
		exit(UNDERFLOW);
}

int getElem(SqStack S) {
	return *(S.top - 1);
}

void destroyStack(SqStack& S) {
	delete[] S.base;
	S.base = nullptr;
}

int main()
{
	SqStack S;
	int n, e;
	cin >> n;
	initStack(S);
	while (n != 0) {
		pushStack(S, n % OCT);
		n /= OCT;
	}
	while (S.top != S.base) {
		popStack(S, e);
		cout << e << " " ;
	}
	destroyStack(S);
	cin.get();
	cin.get();
	return 0;
}