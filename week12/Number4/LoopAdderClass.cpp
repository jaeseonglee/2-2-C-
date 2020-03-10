/*	�ǽ� 4�� : LoopAdderClass.cpp
	�ۼ��� : 2019.11.14 ~ 11.18
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� LoopAdderŬ������ ��ӹ޴� WhileLoopAdder Ŭ������ DoWhileLoopAdder Ŭ������ �ۼ��� ���α׷�
*/
#include <iostream>
using namespace std;

class LoopAdder {	// �߻� Ŭ����
	string name;	// ������ �̸�
	int x, y, sum;	// x���� y������ ���� sum
	void read();	// x, y���� �о� ���̴� �Լ�
	void write();	// sum�� ����ϴ� �Լ�
protected:
	LoopAdder(string name = "") { this->name = name; }	// ������ �̸��� �޴´�. �ʱ갪�� ""
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;	// ���� ���� �Լ�. ������ ���� ���� ���ϴ� �Լ�
public:
	void run();		// ������ �����ϴ� �Լ�
};

void LoopAdder::read() {		// x,y �Է�
	cout << name << ":" << endl;
	cout << "ó������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}

void LoopAdder::write() {		// ��� sum ���
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
}

void LoopAdder::run() {
	read();				// x,y�� �д´�
	sum = calculate();	// ������ ���鼭 ����Ѵ�.
	write();			// ��� sum�� ����Ѵ�
}

class WhileLoopAdder : public LoopAdder {	// WhileLoopAdder Ŭ����
protected:
	virtual int calculate();			// ��� ���� ���� �Լ�		
public:
	WhileLoopAdder(string name) : LoopAdder(name) {	}	// ������
};

int WhileLoopAdder::calculate() {		// ���� �Լ� ����
	int a = getX();
	int b = getY();
	int result = a;
	while (a != b) {			// while ���� ���� 
		result += ++a;			// a���� b������ ���� ���� ��ȯ
	}
	return result;
}

class DoWhileLoopAdder : public LoopAdder {	// DoWhileLoopAdder Ŭ����
protected:
	virtual int calculate();				// ��� ���� ���� �Լ�		
public:
	DoWhileLoopAdder(string name) : LoopAdder(name) { }	// ������
};

int DoWhileLoopAdder::calculate() {			// ���� �Լ� ����
	int a = getX();
	int b = getY();
	int result = a;	
	do {						// do while���� ����
		result += ++a;			// a���� b������ ���� ���� ��ȯ
	} while (a != b);
	return result;
}


int main() {				// �־��� main �Լ�
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");

	whileLoop.run();
	doWhileLoop.run();
}