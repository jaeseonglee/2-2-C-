#include <iostream>
using namespace std;

#include "Person.h"		// ������� include

Person::Person() {	// ������
	name = "";		// NULL������ �ʱ�ȭ���ش�
	tel = "";
}

string Person::getName() { return name; }// ���� �̸���
string Person::getTel() { return tel; }	 // ��ȭ��ȣ�� ��ȯ

void Person::set(string name, string tel) {	// �̸��� ��ȭ��ȣ�� �����ϴ� tel�Լ�
	this->name = name;		// this�� �̿��ؼ� private�� �� ������ �������ش�
	this->tel = tel;
}

Person::~Person() {}		// �Ҹ���