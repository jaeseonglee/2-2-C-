/*	�ǽ� 4�� : BiggerFunc.cpp
	�ۼ��� : 2019.10.20
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : ����ڷκ��� �� ������ �Է¹޾� ū ���� ����ϴ� ���α׷�
			�־��� bigger�Լ��� ���� �ۼ�
*/

#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) { // �� ������ ���Ͽ� bool���� ��ȯ�ϴ� bigger�Լ�
	if (a < b) big = b;	// �� ������ �� , b�� ���� ũ�� b�� big�� ����
	else big = a;		// a�� ũ�ų� ������ big�� a�� ����

	if (a == b)	return true;	// �� ������ ������ true ��ȯ
	else return false;			// �װ� �ƴϸ� false ��ȯ
}

int main() {		// main  �Լ�
	int a = 0, b = 0;	// ������ ���� 2�� ���� �� �ʱ�ȭ
	int result = 0;		// �� �����߿� �� ū���� ������ result
	
	cout << "a : ";		// �� ������ �Է¹޴´�.
	cin >> a;
	cout << "b : ";
	cin >> b;

	if (bigger(a, b, result))	// bigger�Լ� ȣ��� ������ ����� ����Ѵ�
		cout << a << " == " << b << "\t�� ������ " << result <<"�� ����."<< endl;
	else
		cout << a << " != " << b << "\tū ���� " << result << endl;
}
