/*	�ǽ� 3�� : BigFunc.cpp
	�ۼ��� : 2019.10.25 ~ 10.27
	�ۼ��� : 20165153 ���缺
	���α׷� ����: big�Լ��� ȣ���ϴ� �־��� main�Լ��� ���� �ذ�
				1. big() �Լ��� 2�� �ߺ��Ͽ� �ۼ��ϰ� ���α׷��� �ϼ��϶�
				2. ����Ʈ �Ű������� ���� �ϳ��� �Լ��� big()�� �ۼ��ϰ� ���α׷��� �ϼ��϶�
*/

#include <iostream>
using namespace std;

/*
int big(int a, int b) {	// 1�� �ִ밪�� 100�� big �Լ�
	if (a > 100 || b > 100) return 100;
	else return (a > b) ? a : b;
}

int big(int a, int b, int c) { // 1�� �ִ밪�� c�� big �Լ�
	if (a > c || b > c) return c;
	else return (a > b) ? a : b;
}
*/

int big(int a, int b, int c = 100) { // 2�� ����Ʈ �Ű����� c�� ���� �ϳ��� big�Լ�
	if (a > c || b > c) return c;		// �� ���߿� c���� ū ���� �ִٸ� c ����
	else return (a > b) ? a : b;		// �ƴ϶�� ���� ���Ͽ� ū �� ����
}

int main() {
	int x = big(3, 5);		// 3�� 5 �� ū �� 5�� �ִ밪 100���� �����Ƿ�, 5����
	int y = big(300, 60);	// 300�� 60 �� ū �� 300�� �ִ밪 100���� ũ����, 100 ����
	int z = big(30, 60, 50);// 30�� 60 �� ū �� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
	cout << x << ' ' << y << ' ' << z << endl;
}
