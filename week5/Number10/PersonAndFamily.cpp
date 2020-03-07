/*	�ǽ� 10�� : PersonAndFamily.cpp
	�ۼ��� : 2019.09.27
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : �ǽ��������� �־��� �ڵ忡�� �ʿ��� ��������� �Լ����� �߰���Ű�� ����
					�߰��� �ڵ�� �ּ��տ� @�� �ٿ��� ����
					����� ���� �̸��� �� �������� �̸��� �����ϰ� ����ϴ� ���α׷�
*/

#include <iostream>
#include <string>		// string Ŭ������ ����ϱ� ���� include
using namespace std;

class Person {		// Person Ŭ����, �ǽ��������� �־��� �ڵ�� �Ϻ� ����
	string name;	// �̸��� �����ϴ� ���ڿ� ���� name
public:
	Person() { name = ""; }			// @ �⺻������ �߰�, Family���� �⺻�����ڷ� �����Ҷ� �ʿ�
	Person(string name) { this->name = name; }	// �� �ڵ忡���� �⺻�����ڷ� ��ü �迭�� ��������� ������ ��� �ʿ����
	string getName() { return name; }			// name�� �����ϴ� getName�Լ�
	void setName(string name) { this->name = name; }	// @setName �߰�, name�� ���� setter�� �ʿ��ϴ�
};

class Family {		//Family Ŭ����, ���������� �ǽ��������� �־��� �ڵ�� �Ϻ� ����
	Person *p;		// Person �迭 ������
	int size;		// Person �迭�� ũ��, ���� ������ ��
	string name;		// @�����ڿ��� name�� �ִµ� Family Ŭ������ name�� ���� ���� �ʾ� �߰�
public:
	Family(string name, int size);		// size ������ŭ Person �迭 ���� ����
	void show();			// ��� ���� ������ ���
	void setName(int index, string name); // @main�Լ��� setname�� �ִµ� Ŭ�������� ��� �߰�
	~Family();				// �Ҹ���
};

Family::Family(string name, int size) {	// @������ ������ �߰�
	p = new Person[size];		// @��ü ������ �迭 p�� �����Ϸ��µ� Person�� �⺻������ �ʿ�
	this->name = name;			// @������ ������ this���� ����
	this->size = size;
}

void Family::show() {			// @show ������ �߰�
	cout << name + "������ ������ ���� " << size << "�� �Դϴ�." << endl;
	for (int i = 0; i < size; i++) {		// @�ݺ����� ���� ���
		cout << p[i].getName() << '\t';		// @getName�� ���� �� �������� �̸��� ����Ѵ�.
	}
	cout << endl;			// ��� ����� ������ �ٹٲ�
}

void Family::setName(int index, string name) { // @setName������ �߰�
	p[index].setName(name);		// @Family�� �̸��� �ƴ϶� Person�� �̸��� �����ϱ����� Person�� setName�� �ʿ�
	//p[index] = new Person(name); �̹� Family���� �⺻�����ڷ� 3���� �迭�� ����������� �̷��� ���� ����
}

Family::~Family() {		// @�Ҹ��� ������ �߰�
	delete [] p;			// @new�� �Ҵ�� p�� ��ȯ���ش�
}

int main() {				// main �Լ�, �ǽ������� ����
	Family *simpson = new Family("Simpson", 3); // 3������ ������ Simpson ����
	simpson->setName(0, "Mr. Simpson");		// setName�� ���� �̸��� �����Ѵ�
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();		// show�� ���� ���
	delete simpson;			// main�Լ������� simpson�̶�� ������ ��ü�� new�� �Ҵ�Ǿ� ��ȯ���ش�.
}