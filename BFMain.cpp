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
	cout << "Please input main string S:" << endl; // 字符串从下标为1开始
	cin >> S.s >> S.length;
	cout << "Please input minor string T:" << endl;
	cin >> T.s >> T.length;
	int pos; // 从当前位置开始检索
	cout << "Please input position:" << endl;
	cin >> pos;
	int i = pos, j = 1; // 检索下标
	while (i < S.length && j < T.length) { // 字符检索是否抵达末尾
		if (S.s[i] == T.s[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2; // 主串回溯后移(i-(j-1)+1)
			j = 1; // 字串回溯
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