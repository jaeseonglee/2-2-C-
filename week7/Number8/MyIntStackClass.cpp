/*	�ǽ� 8�� : MyIntStacClass.cpp
	�ۼ��� : 2019.10.20
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : ���ñ����� ������ ���α׷�, �ǽ������� �ڵ�鿡�� MyIntClass�� �����θ� �ۼ��� �ڵ��̴�.
*/

#include <iostream>
using namespace std;

class MyIntStack {
	int* p;		// ���� �޸𸮷� ����� ������
	int size;	// ������ �ִ� ũ��
	int tos;	// ������ ž�� ����Ű�� �ε���
public:
	MyIntStack();		// �⺻ ������
	MyIntStack(int size);	// �Ű������� �ִ� ������
	MyIntStack(const MyIntStack& s);	// ���������
	~MyIntStack();		// �Ҹ���
	bool push(int n); // ���� n�� ���ÿ� Ǫ���Ѵ�.
					  // ������ �� �� ������ false��, �ƴϸ� true ����
	bool pop(int& n); // ������ ž�� �ִ� ���� n�� ���Ѵ�.
					  // ���� ������ ��� ������ false��, �ƴϸ� true ����
};

MyIntStack::MyIntStack() {	// �⺻ ������
	p = nullptr;	 // ������ ������� �ʱ�ȭ���ش�.
	size = 0;
	tos = 0;
}

MyIntStack::MyIntStack(int size) {	// �Ű������� �ִ� ������
	this->size = size;	// �Ű������� �޴� size�� size�� ����
	p = new int[size];	// size ��ŭ�� ������ �迭�� ���� ����
	tos = 0;			// ���� ������ ž�� �ε����� 0
}

MyIntStack::MyIntStack(const MyIntStack& s) {	// ���������
	size = s.size;		// s�� size��ŭ size�� ����	
	p = new int[size];	// size��ŭ�� ������ �迭�� ���� ����
	tos = s.tos;		// ���� ������ ž�� �ε����� s�� tos��ŭ ����
}

MyIntStack::~MyIntStack() {  // �Ҹ���
	if(p)
		delete[] p;		// ���� �Ҵ�� p�� �迭�� delete
}

bool MyIntStack::push(int n) {	// ���ÿ� Ǫ���ϴ� push �Լ�
	if (size == tos) return false;	// ������ ������ false
	else {				// �ƴϸ� true ��ȯ
		p[tos] = n;		// ���� ������ ž �ε����� �ش��ϴ� �迭�� ���� n ����
		tos++;			// �ε��� ����
		return true;
	}
}

bool MyIntStack::pop(int& n) {	// ������ ���� ž�� ���� pop�ϴ� pop�Լ�
	if (tos == 0) return false;	//������ ������ false ��ȯ
	else {			// �ƴϸ� true ��ȯ
		tos--;		// ������ �ε����� �ش��ϴ� ���� �����Ƿ� -1 ���ش�.
		n = p[tos];	// ������ ž�� ���� n�� ����, ������ ���� ȣ��� main�� ���� ���޵�
		return true;
	}
}

int main() {		// main �Լ� , �ǽ��������� �־��� �ڵ�� ����
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;		// ���� ����
	b.push(30);

	int n;
	a.pop(n);	// ���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n);	// ���� b ��
	cout << "���� b���� ���� �� " << n << endl;
}