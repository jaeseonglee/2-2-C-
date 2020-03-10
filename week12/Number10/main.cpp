#include <iostream>
using namespace std;

class Shape {		// 추상 클래스 Shape
	Shape* next;
protected:
	virtual void draw() = 0;		// 순수 가상 함수
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
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> num;
		if (num == 1 || num == 2 || num == 3 || num == 4) { return num; }
		else { cout << "주어진 메뉴 중에서 선택해주세요" << endl; }
	}
}
int UI::add() {
	int num = 0;
	while (1) {
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3) { return num; }
		else { cout << "세 도형 중에 선택해주세요" << endl; }
	}
}

int UI::deleteIndex() {
	int num = 0;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
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
		cout << "인덱스를 초과한 값입니다" << endl;
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
	cout << "그래픽 에디터입니다." << endl;
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