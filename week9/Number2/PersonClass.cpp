/*	�ǽ� 2�� : PersonClass.cpp
	�ۼ��� : 2019.10.25 ~ 10.27
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� Person Ŭ������ main�� ���� �ذ�
				1. �����ڸ� �ߺ� �ۼ��ϰ� ���α׷��� �ϼ��϶�.
				2. ����Ʈ �Ű� ������ ���� �ϳ��� �����ڸ� �ۼ��ϰ� ���α׷��� �ϼ��϶�.
*/

#include <iostream>
using namespace std;

class Person {		// Person Ŭ����
	int id;			
	double weight;
	string name;
public:
	Person(int id = 1, string name = "Grace", double weight = 20.5) { // 2�� ����Ʈ �Ű������� ���� �ϳ��� ������
		this->id = id;			// 3���� ��� ���� ���� ��
		this->name = name;		// �Ű������� ������ �ʱ�ȭ
		this->weight = weight;
	}	

	/*	
	Person();		// 1�� ������ �ߺ� �ۼ� , �Ű������� ���� ������
	Person(int id, string name);	// 1�� id�� name�� �Ű������� ������ ������
	Person(int id, string name, double weight);	//  1�� id�� weight�� name�� �Ű������� ������ ������ 
	*/
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

/*
Person::Person() { // 1�� �Ű������� ���� ������
	this->id = 1;			// ��°���� �°� �ʱ�ȭ
	this->name = "Grace";	 
	this->weight = 20.5;	 
}

Person::Person(int id, string name) { // 1�� id�� name�� �Ű������� ������ ������
	this->id = id;			// �Ű������� ������ �ʱ�ȭ
	this->name = name;		// �Ű������� ������ �ʱ�ȭ
	this->weight = 20.5;	// ��°���� �°� �ʱ�ȭ
}

Person::Person(int id, string name, double weight) {// 1�� id�� weight�� name�� �Ű������� ������ ������
	this->id = id;			// 3���� ��� ���� ���� ��
	this->name = name;		// �Ű������� ������ �ʱ�ȭ
	this->weight = weight;
}
*/

int main() {		// main �Լ�
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}
