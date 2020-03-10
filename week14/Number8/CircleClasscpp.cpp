/*	�ǽ� 8�� : CircleClass.cpp
	�ۼ��� : 2019.11.28 ~ 12.02
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� Circle Ŭ������ ������ <<,>>�����ڸ� �ۼ��� ���α׷�
*/
#include <iostream>
using namespace std;

class Circle {	// Circle Ŭ����
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") { this->radius = radius; this->name = name; }	// ������
	friend istream& operator >> (istream& ins, Circle& c);
	friend ostream& operator << (ostream& stream, Circle c);
};

istream& operator >> (istream& ins, Circle& c) {	// >> �Է¿� ���� ������ ������
	cout << "������ >> ";
	ins >> c.radius;
	cout << "�̸� >> ";
	ins >> c.name;
	return ins;
}

ostream& operator << (ostream& stream, Circle c) {	// << ��¿� ���� ������ ������
	stream << "(������" << c.radius << "�� " << c.name << ")";
	return stream;
}

int main() {
	Circle d, w;
	cin >> d >> w;			// Ű���� �Է��� �޾� ��ü d�� w�� �ϼ�
	cout << d << w << endl;	// ��ü d,w ���
}