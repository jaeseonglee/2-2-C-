/*	�ǽ� 10�� : GraphicEditorClass.cpp
	�ۼ��� : 2019.11.18 ~ 11.19
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ������ �׷��� �����⸦ �ܼ� �������� ���� ���α׷�. ����,����,��κ���,������ 4���� ����� ������
					å�� �׸� 9-13�� �������� ������ ���α׷�
*/
#include <iostream>
using namespace std;

class Shape {		// �߻� Ŭ���� Shape
	Shape* next;	
protected:
	virtual void draw() = 0;		// ���� ���� �Լ�
public:
	Shape() { next = NULL; }		// ������
	virtual ~Shape() { }			
	void paint() { draw(); }
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
	void setNext(Shape* p) { this->next = p->next; }
};

Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}

class Circle : public Shape {		// Circle Ŭ����
protected:
	virtual void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {			// Rect Ŭ����
protected:
	virtual void draw() { cout << "Rectangle" << endl; }
};

class Line : public Shape {			// Line Ŭ����
protected:
	virtual void draw() { cout << "Line" << endl; }
};

class UI {				// UI Ŭ����
public:
	UI() {  }			// ������
	static int menu();	// �޴� ���
	static int add();	// ���� 
	static int deleteIndex();	// ����
};

int UI::menu() {		// �Է¹��� �׸� ��ȣ�� ��ȯ�ϴ� menu �Լ�
	int num = 0;
	while (1) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3 || num == 4) { return num; }
		else { cout << "�־��� �޴� �߿��� �������ּ���" << endl; }
	}
}
int UI::add() {			// � �׸��� �߰����� �Է¹޴� add �Լ�
	int num = 0;
	while (1) {
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3) { return num; }
		else { cout << "�� ���� �߿� �������ּ���" << endl; }
	}
}

int UI::deleteIndex() {		// ������ �ε����� �Է¹޴� deleteIndex �Լ�
	int num = 0;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> num;
	return num;
}

class GraphicEditer {		// GraphicEditer  Ŭ����
	Shape* pStart;			// ù��° �׸�
	Shape* pLast;			// ������ �׸�
	int index;				// �׸��� �ε���(����)
	void insert(int num);	// ���� �Լ�
	void indexDelete(int num);	// ���� �Լ�
public:
	GraphicEditer() { pStart = pLast = NULL; index = 0; }	// ������
	void call();			// �׷��� ������ ����ϴ� call �Լ�
};

void GraphicEditer::insert(int num) {	// �Է¹��� �Ű������� ���� ������ �׸��� insert �Լ�
	if (num == 1) {				// 1���̸� Line�� �׸���
		if (index == 0) {
			pStart = new Line();	
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Line());
		}
	}
	else if (num == 2) {		// 2���̸� Circle�� �׸���
		if (index == 0) {
			pStart = new Circle();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Circle());
		}
	}
	else if (num == 3) {		// 3���̸� Rectangle�� �׸���
		if (index == 0) {
			pStart = new Rect();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Rect());
		}
	}
	index++;		// ���ǹ��� ��ġ�� index�� �÷��ش�
}

void GraphicEditer::indexDelete(int num) { // �Է¹��� ���� ���� �ε����� �����ϴ� indexDelete�Լ�
	if (num > index) {				// ���� ������ �ε������� ���� ���� �Է��ϸ�
		cout << "�ε����� �ʰ��� ���Դϴ�" << endl;	// �ʰ��ߴٰ� ���
		return;			// �Լ� ����
	}

	if (num == 0) {		// ������ �ε����� 0�̶��
		pStart = pStart->getNext();		// ù��° �׸��� �ٷ� ���� �׸��� ����Ų��
		index--;			// index ���� �ٿ��ְ�
		return;				// �Լ� ����
	}

	Shape* temp = pStart;		// ���� �ΰ����� ��찡 �ƴ϶��
	Shape* deleteShape = pStart;	// ������ �� �����Ϳ� ù��°�� ī��Ų��
	for (int i = 0; i < num; i++) {	// �ݺ����� ���� 
		temp = deleteShape;			// �Է¹��� num-1�� ������ ����Ű�� �ϰ�
		deleteShape = deleteShape->getNext(); // num�� �ε����� ���� ������ ����
	}
	temp->setNext(deleteShape);		// num-1�� ������ num�� �ε����� ���� ������ ���� ������ ����Ű�� ���ش�
	index--;		// �ε����� �ٿ��ְ�
	delete deleteShape;	// num�� ����Ű�� ������ ��ȯ���ش�
}

void GraphicEditer::call() {			// ��ü �׷��� �����⸦ �����ϴ� call �Լ�
	cout << "�׷��� �������Դϴ�." << endl;	// �׷��� ������ ������ �˸���
	while (1) {						// ���� �ݺ���
		int num = UI::menu();		// �޴� ���

		if (num == 1) {	insert(UI::add()); } 	// 1���̸� ����
		else if (num == 2) { indexDelete(UI::deleteIndex()); }	// 2���̸� ����
		else if (num == 3) {		// 3���̸� ��� ����
			Shape* temp = pStart;
			for (int i = 0; i < index; i++) {	// �ݺ����� ���� index���� ������ �����ش�
				cout << i << ": ";
				temp->paint();
				temp = temp->getNext();
			}
		}
		else if (num == 4) {		// 4���̸� ������ ����, menu �Լ����� 4���� ���� �̿ܿ� ���� �ʴ´�
			break;
		}
	}
}

int main() {		// main �Լ�
	GraphicEditer* ge = new GraphicEditer;	// GraphicEditer ����
	ge->call();		// ������ ����
	delete ge;		// ��ȯ
}