/*	�ǽ� 11�� :StackClass.cpp
	�ۼ��� : 2019.11.05 ~ 11.07
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ������ ������ ���α׷�, push��������� << �����ڸ�, pop��������� >>�����ڸ�, ������ ����ִ��� Ȯ���ϱ� ���� ! �����ڸ� �ۼ�
*/
#include <iostream>
using namespace std;

class Stack {	// Stack Ŭ����
	int* p;		// ������ ������ ����, ������ �ǹ��Ѵ�
	int size;	// ������ ũ�⸦ ������ size;
public:
	Stack();	// ������
	~Stack() { delete[] p; } // �Ҹ��� , ���� �Ҵ�� p�� ��ȯ�Ѵ�
	Stack& operator<<(int num);	// << ������ �Լ�, push������ ������ �Ѵ�
	void operator>>(int& num);	// >> ������ �Լ�, pop������ ������ �Ѵ�
	bool operator!();			// ! ������ �Լ� , ������ ����ִ��� Ȯ���ؼ� bool���� ��ȯ�Ѵ�
};

Stack::Stack() {		// ������
	p = new int[10];	// ������ ũ�⸦ 10���� ���� �Ҵ�
	size = 0;			// size�� 0���� �ʱ�ȭ
}

Stack& Stack::operator<<(int num) {	// << ������ �Լ�
	p[size] = num;		// �Ű������� ���� ���� ���� �Ҵ�� p�� �������ش�
	size++;				// size �� ����
	return *this;		// �� ��ü�� ���� ����
}

void Stack::operator>>(int& num) {	// >> ������ �Լ�
	size--;			// size�� ���� 1 �ٿ��ְ�
	num = p[size];	// ���ڷ� ���� num�� ����, pop������ ������ �Ѵ�
}

bool Stack::operator!() {	// !������ �Լ�
	if (size == 0) return true;	// size�� 0�̸� true ��ȯ
	else return false;			// �ƴϸ� false�� ��ȯ
}

int main() {		// main �Լ�
	Stack stack;	
	stack << 3 << 5 << 10;		// 3,5,10�� ������� Ǫ��
	while (true) {
		if (!stack) break;		// ���� empty
		int x;
		stack >> x;				// ������ ž�� �ִ� ���� ��
		cout << x << ' ';
	}
	cout << endl;
}