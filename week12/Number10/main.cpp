#include <iostream>
using namespace std;

class Shape {		// �߻� Ŭ���� Shape
	Shape* next;
protected:
	virtual void draw() = 0;		// ���� ���� �Լ�
public:
	Shape() { next = NULL; }
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

class Circle : public Shape {
protected:
	virtual void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {
protected:
	virtual void draw() { cout << "Rectangle" << endl; }
};

class Line : public Shape {
protected:
	virtual void draw() { cout << "Line" << endl; }
};

class UI {
public:
	UI() {  }
	static int menu();
	static int add();
	static int deleteIndex();
};

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
		if (num == 1 || num == 2 || num == 3) { return num; }
		else { cout << "�� ���� �߿� �������ּ���" << endl; }
	}
}

int UI::deleteIndex() {
	int num = 0;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> num;
	return num;
}

class GraphicEditer {
	Shape* pStart;
	Shape* pLast;
	int index;
	void insert(int num);
	void indexDelete(int num);
public:
	GraphicEditer() { pStart = pLast = NULL; index = 0; }
	void call();
};

void GraphicEditer::insert(int num) {
	if (num == 1) {
		if (index == 0) {
			pStart = new Line();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Line());
		}
	}
	else if (num == 2) {
		if (index == 0) {
			pStart = new Circle();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Circle());
		}
	}
	else if (num == 3) {
		if (index == 0) {
			pStart = new Rect();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Rect());
		}
	}
	index++;
}

void GraphicEditer::indexDelete(int num) {
	if (num > index) {
		cout << "�ε����� �ʰ��� ���Դϴ�" << endl;
		return;
	}

	if (num == 0) {
		pStart = pStart->getNext();
		index--;
		return;
	}

	Shape* temp = pStart;
	Shape* deleteShape = pStart;
	for (int i = 0; i < num; i++) {
		temp = deleteShape;
		deleteShape = deleteShape->getNext();
	}
	temp->setNext(deleteShape);
	index--;

	delete deleteShape;
}

void GraphicEditer::call() {
	cout << "�׷��� �������Դϴ�." << endl;
	while (1) {
		int num = UI::menu();

		if (num == 1) {
			num = UI::add();
			insert(num);
		}
		else if (num == 2) { indexDelete(UI::deleteIndex()); }
		else if (num == 3) {
			Shape* temp = pStart;
			for (int i = 0; i < index; i++) {
				cout << i << ": ";
				temp->paint();
				temp = temp->getNext();
			}
		}
		else if (num == 4) {
			break;
		}
	}
}

int main() {
	GraphicEditer* ge = new GraphicEditer;
	ge->call();
	delete ge;
}