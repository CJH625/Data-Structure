#include <iostream>
#include <string>

using namespace std;

typedef struct {
	string s;
	int length;
} SString;

int main()
{
	SString S{}, T{};
	cout << "Please input main string S:" << endl; // �ַ������±�Ϊ1��ʼ
	cin >> S.s >> S.length;
	cout << "Please input minor string T:" << endl;
	cin >> T.s >> T.length;
	int pos; // �ӵ�ǰλ�ÿ�ʼ����
	cout << "Please input position:" << endl;
	cin >> pos;
	int i = pos, j = 1; // �����±�
	while (i < S.length && j < T.length) { // �ַ������Ƿ�ִ�ĩβ
		if (S.s[i] == T.s[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2; // �������ݺ���(i-(j-1)+1)
			j = 1; // �ִ�����
		}
	}
	if (j == T.length)
		cout << "The position is " << (i - (T.length - 1)) << endl;
	else
		cout << "Matching unsuccessfully!" << endl;
	cin.get();
	cin.get();
	return 0;
}