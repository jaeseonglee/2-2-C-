/*	�ǽ� 12�� : Circle.cpp
	�ۼ��� : 2019.09.28
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : �ǽ��������� �־��� �� Ŭ������ ������ ��°���� ���� �������� �ڵ带 �ϼ��ϴ� �ǽ�
					���� �̸��� �������� �Է¹޾� �����ϰ�, �̸����� ���� �˻��ϰų� �Է¹��� �������� ū ������
					����ϴ� ���α׷� 
*/

#include <iostream>
#include <string>			// ���ڿ� ����� ���� include
using namespace std;

class Circle {			// Circle Ŭ���� 
	int radius = 0;		// ���� ������ ��
	string name = "";	// ���� �̸�
public:
	Circle() {  };		// �⺻ ������, ���� ����
	void setCircle(string name, int radius);	// �̸��� ������ ����
	double getArea() { return 3.14 * radius * radius; }	// ���� ���̸� ��ȯ�ϴ� getArea�Լ�
	string getName() { return name; }					// ���� �̸��� ��ȯ�ϴ� getName�Լ�
};

void Circle::setCircle(string name, int radius) {		// �Ű������� ��������� �����ϴ� setCircle �Լ�
	this->name = name;			// this�� ����ؼ� �Ű������� �ʱ�ȭ���ش�
	this->radius = radius;
}

class CircleManager {		// CircleManager Ŭ���� 
	Circle *p = nullptr;	// Circle �迭�� ���� ������
	int size = 0;			// �迭�� ũ��
public:
	CircleManager(int size);	// size ũ���� �迭�� ���� ����. ����ڷκ��� �Է¿Ϸ�
	~CircleManager();			// �Ҹ���
	void searchByName();		// ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
	void searchByArea();		// ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���

};

CircleManager::CircleManager(int size) {	// �Ű������� �ִ� ������
	this->size = size;			// �Ű������� ���� ���� size�� ����
	p = new Circle[size];		// �Է¹��� size��ŭ ��ü �迭�� �Ҵ����ش�
	
	string name = "";			// �Ʒ� �ݺ������� �̸��� �������� ������ ���� ����
	int radius = 0;

	for (int i = 0; i < size; i++) {	// �ݺ����� ���� �迭ũ�⸸ŭ
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";	// ������ ������ �Է¹޴´�
		cin >> name >> radius;			// ������ �Է¹��� ���� �־��ְ�
		p[i].setCircle(name, radius);	// �� �ε����� �̸��� �������� �Է����ش�
	}
}

void CircleManager::searchByName() {	// �Էµ� �̸����� ���� ã�� searchByName�Լ�
	string name = "";		// �̸��� �Է¹ޱ� ���� ���� ���� 
	int count = 0;			// ã�� ���ϸ� ���ٰ� ����ϱ� ���� ������ ���� count ���� �� 0���� �ʱ�ȭ

	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";	// ���� �̸��� �Է��ش޶�� ���
	cin >> name;						// name�� ����
	for (int i = 0; i < size; i++) {	// �ݺ����� ����
		if (name == p[i].getName()) {	// �Էµ� �̸��� ���� ���� �ִٸ�
			cout << name << "�� ������ " << p[i].getArea() << endl;	// ���� ������ ����ϰ�
			count++;		// count�� ������Ű��
			break;			// �ݺ����� ����������
		}
	}

	if (count == 0) {		// ���� ���� ã�� ���ߴٸ�
		cout << "�Է��Ͻ� �̸��� ��ġ�ϴ� ���� �����ϴ�!" << endl;	 // ���ٰ� ������ش�
	}
}

void CircleManager::searchByArea() {		// �Է¹��� �������� ū ���� ã�� searchByArea�Լ�
	int num = 0;			// ������ ������ ���� ����
	int count = 0;			// searchByName�� ���� ����� ���ٸ� ���ٰ� ����ϱ����� ���� �� �ʱ�ȭ
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> num;				// �Է¹��� ���� num�� ����
	cout << num << "���� ū ���� �˻��մϴ�." << endl;

	for (int i = 0; i < size; i++) {	// �ݺ����� ����
		if (num < p[i].getArea()) {		// �� �ε����� ����� ������ ������ �Է¹��� ������ ũ��
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ",";	// ���� �̸��� ������ ���
			count++;					// �׸��� count�� ���������ش�.
		}
	}

	if (count == 0) {	// �ƹ��͵� ������� ���ߴٸ�
		cout << "�Է��Ͻ� �������� ū ���� �����ϴ�!" << endl;	//����� ���ٰ� ������ش�
	}

	cout << endl;		// ��� ����� ������ �ٹٲ�
}

CircleManager::~CircleManager() {		// �Ҹ���
	delete [] p;			// �����Ҵ���� CircleManager�� p�� delete�� ���� ��ȯ���ش�.
}

int main() {			// main �Լ�
	int num = 0;		// ���� ������ �Է¹��� ���� num ���� �� 0���� �ʱ�ȭ
	CircleManager *p = nullptr;	// �����Ҵ� �ޱ����� ��ü ������ ���� p ���� �� �ʱ�ȭ

	cout << "���� ���� >> ";		// ���� ������ �Է��ش޶�� ���
	cin >> num;					// �Է¹��� ���� num�� �ʱ�ȭ
	p = new CircleManager(num);	// num���� CircleManager ��ü ���� �Ҵ�
	p->searchByName();			// �̸����� ���� �˻�
	p->searchByArea();			// �Է��� �������� ū���� �˻�
	p->~CircleManager();		// ��ü �������� �Ҹ��ڸ� ����
	delete p;					// main �Լ��� ������ p ��ȯ�� ���� delete���ش�
}

