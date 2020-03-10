/*	�ǽ� 8�� : CircleClassComparable.cpp
	�ۼ��� : 2019.11.21 ~ 11.24
	�ۼ��� : 20165153 ���缺
	���α׷� ����: Circle Ŭ������ Comparable Ŭ������ ����� ���� ������ �ߺ��� �ذ��ϰ� ����� ����ϴ� ���α׷�
*/
#include <iostream>
using namespace std;

class Comparable {		// Comparable Ŭ����
public:
	virtual bool operator > (Comparable& op2) = 0;		// ���� ���� �Լ�
	virtual bool operator < (Comparable& op2) = 0;		// ���� ���� �Լ�
	virtual bool operator == (Comparable& op2) = 0;		// ���� ���� �Լ�
};

class Circle : public Comparable{		// Circle Ŭ����
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator > (Comparable& op2);	// ���� ���� �Լ� ����
	bool operator < (Comparable& op2);
	bool operator == (Comparable& op2);
};

bool Circle::operator>(Comparable& op2) {
	Circle* p = (Circle*)&op2;
	if (radius > p->getRadius() ) return true;
	else return false;
}

bool Circle::operator < (Comparable& op2) {
	Circle * p = (Circle*)&op2;
	if (radius < p->getRadius()) return true;
	else return false;
}

bool Circle::operator == (Comparable& op2) {
	Circle* p = (Circle*)&op2;
	if (radius == p->getRadius()) return true;
	else return false;
}

template <class T>		// template ����
T bigger(T a, T b) {	// �� ���� �Ű� ������ ���Ͽ� ū ���� ����
	if (a > b) return a;
	else return b;
}

int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20�� 50�� ū ���� " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle�� pizza �� ū ���� �������� " << y.getRadius() << endl;
}