/*	�ǽ� 8�� : Shape.h
	�ۼ��� : 2019.11.18 ~ 11.19
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ������ �׷��� �����⸦ �ܼ� �������� ���� ���α׷�. ����,����,��κ���,������ 4���� ����� ������
					å�� �׸� 9-13�� �������� ������ ���α׷�
*/
#pragma
#include<iostream>
using namespace std;
class Shape {		// �߻� Ŭ���� Shape
	Shape* next;
protected:
	virtual void draw() = 0;		// ���� ���� �Լ�
public:
	Shape() { next = NULL; }
	virtual ~ Shape() { }
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
	void setNext(Shape* p) { this->next = p->next; }
};