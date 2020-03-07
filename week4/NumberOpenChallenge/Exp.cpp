#include <iostream>
using namespace std;

#include "Exp.h"	// ������� ������� Exp.h�� include

Exp::Exp() {		// �Ű����� ���� ������ -> ���̽��� ���� �Ѵ� 1
	base = 1;
	exp = 1;
}

Exp::Exp(int b) {	//�Ű������� �ϳ��� �ִ� ������ -> ���̽��� �Ű������� �ʱ�ȭ, ������ 1
	base = b;
	exp = 1;
}

Exp::Exp(int b, int e) {// �Ű������� �ΰ� �ִ� ������ -> ���̽��� ���� �Ű������� �ʱ�ȭ
	base = b;
	exp = e;
}

int Exp::getValue() {		// ���� ����Ͽ� ��ȯ�ϴ� getValue() �Լ�
	int result = 1;			// ��ȯ�� ���� ���� ������ result ����
	for (int i = 0; i < exp; i++) {	// �ݺ����� ���� ���� ���
		result *= base;		// ������ŭ ���̽��� �����ش�.
	}
	return result;			// ���� ����� ��ȯ
}

int Exp::getBase() { return base; }	// ���̽��� ��ȯ�ϴ� getBase�Լ�

int Exp::getExp() { return exp; }	// ������ ��ȯ�ϴ� getExp�Լ�

bool Exp::equals(Exp b) {			// �� ��ü�� ������ ���� ���ϴ� equsls�Լ�
	if ( getValue() == b.getValue() ) { return true; }		// ���� ������ ture��ȯ
	else return false;				// �ٸ��� false ��ȯ
}