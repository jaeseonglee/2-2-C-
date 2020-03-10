/*	�ǽ� 7�� :Shape7.cpp
	�ۼ��� : 2019.11.14 ~ 11.18
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� Shape Ŭ������ ��ӹ޴� Oval,Rect,TriangularŬ������ �ۼ��ϰ� �� ������ ���̸� ����ϴ� ���α׷�
*/

#include <iostream>
using namespace std;

#define PI 3.14				// define������ PI�� 3.14�� ����

class Shape {
protected:
	string name;		// ������ �̸�
	int width, height;	// ������ �����ϴ� �簢���� �ʺ�� ����
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() { return 0; }	// dummy �� ����
	string getName() { return name; }		// �̸� ����
};

class Oval : public Shape {		// Ÿ���� ǥ���ϴ� Oval Ŭ����
protected:
	double getArea() { return PI * width * height; }	// Shape�� ���� �Լ� �����ε�
public:
	Oval(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}	// ������
};


class Rect : public Shape {		// �簢���� ǥ���ϴ� Rect Ŭ����
protected:
	double getArea() { return  (double)width * height; }	// Shape�� ���� �Լ� �����ε�
public:
	Rect(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}	// ������
};

class Triangular : public Shape {	// �ﰢ���� ǥ���ϴ� Triangular Ŭ����
protected:
	double getArea() { return  width * height / 2; }		// Shape�� ���� �Լ� �����ε�
public:
	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}	// ������
};

int main() {			// �־��� main �Լ�
	Shape* p[3];
	p[0] = new Oval("��붱", 10, 20);
	p[1] = new Rect("����", 30, 40);
	p[2] = new Triangular("�佺Ʈ", 30, 40);

	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}