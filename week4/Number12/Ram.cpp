#include <iostream>
using namespace std;

#include "Ram.h"		// ������� ������� Ram.h�� include

Ram::Ram() {	// mem �迭�� 0���� �ʱ�ȭ�ϰ� size�� 100*1024�� �ʱ�ȭ �ϴ� ������
	for (int i = 0; i < 100 * 1024; i++) { mem[i] = 0; }	// �ݺ����� ���� 0���� �ʱ�ȭ
	size = 100 * 1024;
}

Ram::~Ram() {	// "�޸� ���ŵ�" ���ڿ�����ϴ� �Ҹ���
	cout << "�޸� ���ŵ�" << endl;	// �޸� ���ŵ��̶�� ����ϰ� �ٹٲ�
}

char Ram::read(int address) {	// address �ּ��� �޸� ����Ʈ ����
	return mem[address];		// �ش� �ּҿ� �´� �ε����� ���� ��ȯ�Ѵ�.
}

void Ram::write(int address, char value) {	// address �ּҿ� �� ����Ʈ�� value ����
	mem[address] = value;		// �ش� �ּҿ� �´� �ε����� ���� �����Ѵ�.
}