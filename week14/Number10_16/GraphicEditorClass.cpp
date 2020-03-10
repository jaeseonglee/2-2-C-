/*	실습 10장 16번 : GraphicEditorClass.cpp
	작성일 : 2019.11.28 ~ 12.04
	작성자 : 20165153 이재성
	프로그램 설명: 9장 실습 문제 10번을 vector를 통해 재구성한 프로그램이다
*/
#include <iostream>
#include <vector>		// vector 사용
#include <iterator>		// erase 함수 사용시 iterator 사용
using namespace std;

class Shape {		// 추상 클래스 Shape
protected:
	virtual void draw() = 0;		// 순수 가상 함수
public:
	Shape() {  }		// 생성자
	virtual ~Shape() { }
	void paint() { draw(); }
};

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
	vector<Shape*> v;		// vector 사용
public:
	GraphicEditer() { }		// 생성자
	void insert(int num);	// 삽입 함수
	void indexDelete(int num);	// 삭제 함수
	void call();			// 그래픽 편집을 담당하는 call 함수
};


void GraphicEditer::insert(int num) {	// 입력받은 매개변수에 따라 도형을 그리는 insert 함수
	if (num == 1) {
		v.push_back(new Line());		// 1번이면 Line을 그린다
	}
	else if (num == 2) {
		v.push_back(new Circle());		// 2번이면 Circle을 그린다
	}
	else {
		v.push_back(new Rect());		// 3번이면 Rectangle을 그린다
	}
}

void GraphicEditer::indexDelete(int num) {	// 입력받은 값과 같은 인덱스를 삭제하는 indexDelete함수
	vector<Shape*>::iterator it;	// iterator 사용
	it = v.begin();		// 벡터의 시작값을 저장하고
	*it = *it + num;	// num만큼 증가시켜줘서 그 인덱스를 가리키게한다
	it = v.erase(it);
}

void GraphicEditer::call() {			// 전체 그래픽 편집기를 진행하는 call 함수
	cout << "그래픽 에디터입니다." << endl;	// 그래픽 에디터 시작을 알린다
	while (1) {						// 무한 반복문
		int num = UI::menu();		// 메뉴 출력

		if (num == 1) { insert(UI::add()); } 	// 1번이면 삽입
		else if (num == 2) { indexDelete(UI::deleteIndex()); }	// 2번이면 삭제
		else if (num == 3) {		// 3번이면 모두 보기
			for (int i = 0; i < v.size(); i++) {
				cout << i << ": ";
				v[i]->paint();		
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