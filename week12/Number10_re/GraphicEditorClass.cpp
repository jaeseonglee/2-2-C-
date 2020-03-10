/*	실습 10번 : GraphicEditorClass.cpp
	작성일 : 2019.11.18 ~ 11.19
	작성자 : 20165153 이재성
	프로그램 설명: 간단한 그래픽 편집기를 콘솔 바탕으로 만든 프로그램. 삽입,삭제,모두보기,종료의 4가지 기능을 가지며
					책의 그림 9-13을 바탕으로 구현한 프로그램
*/
#include <iostream>
using namespace std;

class Shape {		// 추상 클래스 Shape
	Shape* next;	
protected:
	virtual void draw() = 0;		// 순수 가상 함수
public:
	Shape() { next = NULL; }		// 생성자
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

class Circle : public Shape {		// Circle 클래스
protected:
	virtual void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {			// Rect 클래스
protected:
	virtual void draw() { cout << "Rectangle" << endl; }
};

class Line : public Shape {			// Line 클래스
protected:
	virtual void draw() { cout << "Line" << endl; }
};

class UI {				// UI 클래스
public:
	UI() {  }			// 생성자
	static int menu();	// 메뉴 출력
	static int add();	// 삽입 
	static int deleteIndex();	// 삭제
};

int UI::menu() {		// 입력받은 항목 번호를 반환하는 menu 함수
	int num = 0;
	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3 || num == 4) { return num; }
		else { cout << "주어진 메뉴 중에서 선택해주세요" << endl; }
	}
}
int UI::add() {			// 어떤 그림을 추가할지 입력받는 add 함수
	int num = 0;
	while (1) {
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3) { return num; }
		else { cout << "세 도형 중에 선택해주세요" << endl; }
	}
}

int UI::deleteIndex() {		// 삭제할 인덱스를 입력받는 deleteIndex 함수
	int num = 0;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> num;
	return num;
}

class GraphicEditer {		// GraphicEditer  클래스
	Shape* pStart;			// 첫번째 그림
	Shape* pLast;			// 마지막 그림
	int index;				// 그림의 인덱스(개수)
	void insert(int num);	// 삽입 함수
	void indexDelete(int num);	// 삭제 함수
public:
	GraphicEditer() { pStart = pLast = NULL; index = 0; }	// 생성자
	void call();			// 그래픽 편집을 담당하는 call 함수
};

void GraphicEditer::insert(int num) {	// 입력받은 매개변수에 따라 도형을 그리는 insert 함수
	if (num == 1) {				// 1번이면 Line을 그린다
		if (index == 0) {
			pStart = new Line();	
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Line());
		}
	}
	else if (num == 2) {		// 2번이면 Circle을 그린다
		if (index == 0) {
			pStart = new Circle();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Circle());
		}
	}
	else if (num == 3) {		// 3번이면 Rectangle을 그린다
		if (index == 0) {
			pStart = new Rect();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Rect());
		}
	}
	index++;		// 조건문을 마치면 index를 올려준다
}

void GraphicEditer::indexDelete(int num) { // 입력받은 값과 같은 인덱스를 삭제하는 indexDelete함수
	if (num > index) {				// 현재 마지막 인덱스보다 높은 값을 입력하면
		cout << "인덱스를 초과한 값입니다" << endl;	// 초과했다고 출력
		return;			// 함수 종료
	}

	if (num == 0) {		// 삭제할 인덱스가 0이라면
		pStart = pStart->getNext();		// 첫번째 항목을 바로 다음 항목을 가리킨다
		index--;			// index 값을 줄여주고
		return;				// 함수 종료
	}

	Shape* temp = pStart;		// 위의 두가지의 경우가 아니라면
	Shape* deleteShape = pStart;	// 임의의 두 포인터에 첫번째를 카리킨다
	for (int i = 0; i < num; i++) {	// 반복문을 통해 
		temp = deleteShape;			// 입력받은 num-1의 도형을 가리키게 하고
		deleteShape = deleteShape->getNext(); // num의 인덱스를 가진 도형을 저장
	}
	temp->setNext(deleteShape);		// num-1의 도형이 num의 인덱스를 가진 도형의 다음 도형을 가리키게 해준다
	index--;		// 인덱스를 줄여주고
	delete deleteShape;	// num이 가리키는 도형을 반환해준다
}

void GraphicEditer::call() {			// 전체 그래픽 편집기를 진행하는 call 함수
	cout << "그래픽 에디터입니다." << endl;	// 그래픽 에디터 시작을 알린다
	while (1) {						// 무한 반복문
		int num = UI::menu();		// 메뉴 출력

		if (num == 1) {	insert(UI::add()); } 	// 1번이면 삽입
		else if (num == 2) { indexDelete(UI::deleteIndex()); }	// 2번이면 삭제
		else if (num == 3) {		// 3번이면 모두 보기
			Shape* temp = pStart;
			for (int i = 0; i < index; i++) {	// 반복문을 통해 index까지 도형을 보여준다
				cout << i << ": ";
				temp->paint();
				temp = temp->getNext();
			}
		}
		else if (num == 4) {		// 4번이면 편집기 종료, menu 함수에서 4개의 숫자 이외에 받지 않는다
			break;
		}
	}
}

int main() {		// main 함수
	GraphicEditer* ge = new GraphicEditer;	// GraphicEditer 생성
	ge->call();		// 편집기 진행
	delete ge;		// 반환
}