#include <iostream>
using namespace std;

#include "Tower.h"	// Ŭ���� Tower�� ����ϱ� ���� include

int main() {		// main�Լ�, �ǹ� �������� �־��� main �Լ��� ����.

	Tower myTower;	// 1����
	Tower seoulTower(100);	// 100����
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}