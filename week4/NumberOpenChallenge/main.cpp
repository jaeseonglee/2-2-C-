#include <iostream>
using namespace std;

#include "Exp.h"		// ExpŬ���� ����� ���� Exp.h include

int main() {		// main�Լ� 143p�� �־��� main�Լ��� ����.
	Exp a(3, 2);	// ���̽��� 3�̰� ������ 2�� ��ü
	Exp b(9);		// ���̽��� 9�̰� ������ 1�� ��ü
	Exp c;			// ���̽��� ���� �� �� 1�� ��ü

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;	// �� ��ü�� ���� ���� ���
	cout << "a�� ���̽� " << a.getBase() << ',' << "���� " << a.getExp() << endl;	// ��ü a�� ���̽��� ���� ���

	if (a.equals(b))		// a�� b�� ���� ���� ���Ѵ�.
		cout << "same" << endl;	// ������ same ���
	else
		cout << "not same" << endl;	// �ٸ��� not same ���
}