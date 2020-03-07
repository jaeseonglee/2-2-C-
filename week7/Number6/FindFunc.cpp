/*	�ǽ� 6�� : FindFunc.cpp
	�ۼ��� : 2019.10.20
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : �־��� find �Լ��� ���� ���ڿ� a���� c�� ã�� ���� c�� �ִ� ������ ���� ������ �ϴ� ���α׷�
				�־��� main �Լ��� �� ����ǵ��� find�Լ� �ۼ�
*/

#define _CRT_SECURE_NO_WARNINGS		// ���ڿ� �Լ��� ����ϴµ� �־� ������ �߻����� �ʰ� �ϴ� define��
#include <iostream>
#include <cstring>		// ���ڿ� �Լ������ ����  include
using namespace std;

char& find(char a[], char c, bool& success);		// find �Լ��� ���� ����

int main() {		// main �Լ�, �ǽ��������� �־��� main�Լ��� ����
	char s[] = "Mike";
	bool b = false;

	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����." << endl;
		return 0;
	}
	loc = 'm';			// 'M'��ġ�� 'm'���
	cout << s << endl;	// "mike"�� ��µ�
}

char& find(char a[], char c, bool& success) {
	success = strchr(a, c);		// strchr�� ���� ���ڿ� a�� c�� ���ο� ���� bool�� ��ȯ

	for (int i = 0; i < strlen(a); i++) {	// �ݺ����� ���� ��ȯ�� ����
		if (a[i] == c)		// c�� ���� ���ڰ� ������
			return a[i];	// �� �ε����� �ش��ϴ� �� ��ȯ
	}

	return a[strlen(a)];	// ������ a�� ���� ������ ���� NULL������ ��ȯ 
}