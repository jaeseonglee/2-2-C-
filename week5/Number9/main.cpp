#include <iostream>
#include <string>		// string Ŭ���� ��뿡 �ʿ��� �ڵ�
using namespace std;

#include "Person.h"		// Person Ŭ���� ����� ���� include

#define SIZE 3			// define������ SIZE�� 3�� ����

int main() {			// main �Լ�
	Person *p = new Person[SIZE];	// ��ü ������ �迭 ����,�⺻ �����ڷ� �����ȴ�
	string name = "";		// �̸��� ������ ���ڿ� ���� name
	string tel = "";		// ��ȭ��ȣ�� ������ ���ڿ� ���� tel

	cout << "�̸��� ��ȭ��ȣ�� �Է����ּ���" << endl;	// �̸��� ��ȭ��ȣ�� �Է��ش޶�� ���

	for (int i = 0; i < SIZE; i++) {// �ݺ����� ����
		cout << "��� " << i+1 << ">> ";		
		cin >> name >> tel;			// 3���� ��ü�� ������ ���� �Է¹޴´�.
		p[i].set(name, tel);		// �Է¹��� ���� �� �ε����� set�Լ��� ���� ����
	}

	cout << "��� ����� �̸��� ";	// ��� ��ü ���
	for (int i = 0; i < SIZE; i++) {	
		cout << p[i].getName() << " ";	// getName�� ���� �� �ε����� �ִ� �̸��� ���
	}

	cout << endl << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";	
	cin >> name;			// Ű���尡 ã�� �̸��� name�� ����

	for (int i = 0; i < SIZE; i++) {	//�ݺ����� ���� �˻�
		if (name == p[i].getName()) {	// C++������ '==' �����ڸ� ���� ���ڿ� �񱳿��갡��,����� boolean��
			cout << "��ȭ��ȣ�� ";
			cout << p[i].getTel() << endl;	// ���ǹ��� �����ϴ� ���� ã���� getTel�� ���� ��ȭ��ȣ ���
			break;
		}
		if (i == SIZE - 1) { cout << "�߸��� �̸��Դϴ�!!" << endl; }
	}
	
	delete [] p;		// delete ���� ���� �Ҵ���� �迭�� ��ȯ
}