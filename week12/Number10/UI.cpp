#include <iostream>
using namespace std;
#include "UI.h"

int UI::menu() {
	int num = 0;
	while (1) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
		cin >> num;
		if (num == 1 || num == 2 || num == 3 || num == 4) { return num; }
		else { cout << "�־��� �޴� �߿��� �������ּ���" << endl; }
	}
}
int UI::add() {
	int num = 0;
	while (1) {
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3) {	return num;	}
		else { cout << "�� ���� �߿� �������ּ���" << endl; }
	}
}

int UI::deleteIndex() {
	int num = 0;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> num;
	return num;	
}