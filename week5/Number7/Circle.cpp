#include <iostream>
using namespace std;

#include "Ciecle.h"		// ������� include

void Circle::setRadius(int radius) {	// �Ű����� raddius��
	this->radius = radius;		// this �����͸� �̿��� �������� �����Ѵ�
}								// C++������ this�� ��ü �ڽſ� ���� �����ͷ� ����Ѵ�

double Circle::getArea() {			// ������ �����ϴ� getArea �Լ�
	return 3.14 * radius * radius;	// ���� ���� 3.14�� �����ϰ� ���� ���̸� ���ϴ� ���� ���� ��ȯ
}