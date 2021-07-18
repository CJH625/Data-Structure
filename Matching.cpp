#include <iostream>
#define MAXSIZE 20

using namespace std;

typedef struct {
	char* base;
	char* top;
	int length;
} SqStack;

void initStack(SqStack& S) {
	S.base = new char[MAXSIZE] {}; // ��ʼ���ڴ�Ϊ��
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
	char e{}; // �ַ����������ʼ��
	int flag{ 1 };
	SqStack S;
	initStack(S);
	cin >> e; // ÿ�λ��Զ�ˢ�»�����
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
				popStack(S, e); // ��Ϊ�������壬���Կ��Ա�֤ջ�ҷ��Ų��ع���
				if (e == '{')
					flag = 0;
				break;
			default:
				cout << "Print Error!" << endl;
				break;
		}
		cin >> e; // Ϊ�����#ʹ�ã�������Ҫ��while�жϺ��ټ�⣬����default��������
	}
	if (EmptyStack(S) && flag == 1) // ��֤ջ���������
		cout << "Matching successfully!" << endl;
	else
		cout << "Matching unsuccessfully!" << endl;
	destroyStack(S);
	cin.get();
	cin.get();
	return 0;
}