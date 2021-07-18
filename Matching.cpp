#include <iostream>
#define MAXSIZE 20

using namespace std;

typedef struct {
	char* base;
	char* top;
	int length;
} SqStack;

void initStack(SqStack& S) {
	S.base = new char[MAXSIZE] {}; // 初始化内存为零
	S.top = S.base;
	S.length = MAXSIZE;
}

void pushStack(SqStack& S, char elem) {
	if ((S.top - S.base) < S.length) {
		*S.top = elem;
		S.top++;
	}
	else
		exit(OVERFLOW);
}

void popStack(SqStack& S, char& elem) {
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

bool EmptyStack(SqStack S) {
	return (S.base == S.top ? true : false);
}

void destroyStack(SqStack& S) {
	delete[] S.base;
	S.base = nullptr;
}

int main()
{
	char e{}; // 字符变量必须初始化
	int flag{ 1 };
	SqStack S;
	initStack(S);
	cin >> e; // 每次会自动刷新缓冲区
	while (e != '#' && flag) {
		switch (e) {
			case '{':
			case '[':
				pushStack(S, e);
				break;
			case '}':
				popStack(S, e);
				if (e == ']')
					flag = 0;
				break;
			case ']':
				popStack(S, e); // 因为函数定义，所以可以保证栈右符号不必过多
				if (e == '{')
					flag = 0;
				break;
			default:
				cout << "Print Error!" << endl;
				break;
		}
		cin >> e; // 为了配合#使用，所以需要在while判断后再检测，否则default会错误输出
	}
	if (EmptyStack(S) && flag == 1) // 保证栈中无左符号
		cout << "Matching successfully!" << endl;
	else
		cout << "Matching unsuccessfully!" << endl;
	destroyStack(S);
	cin.get();
	cin.get();
	return 0;
}