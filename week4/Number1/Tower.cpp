#include <iostream>		
using namespace std;

#include "Tower.h"	// ������� ������� Tower.h�� include

Tower::Tower() {	//	Tower Ŭ������ ������, �����ڿ� �Լ��� �����Ѵ�.
	height = 1;		// �Ű����� ���� ��ü�� �����ÿ��� ���̸� 1�� ����
}

Tower::Tower(int h) {	// �Ű������� �ִ� �������� ��쿡��
	height = h;		// �� �Ű������� ���̷� �����Ѵ�.
}

int Tower::getHeight() {// getHeight�� ���� 
	return height;		// ����(height)�� ��ȯ
}