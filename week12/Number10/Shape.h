/*	실습 8번 : Shape.h
	작성일 : 2019.11.18 ~ 11.19
	작성자 : 20165153 이재성
	프로그램 설명: 간단한 그래픽 편집기를 콘솔 바탕으로 만든 프로그램. 삽입,삭제,모두보기,종료의 4가지 기능을 가지며
					책의 그림 9-13을 바탕으로 구현한 프로그램
*/
#pragma
#include<iostream>
using namespace std;
class Shape {		// 추상 클래스 Shape
	Shape* next;
protected:
	virtual void draw() = 0;		// 순수 가상 함수
public:
	Shape() { next = NULL; }
	virtual ~ Shape() { }
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
	void setNext(Shape* p) { this->next = p->next; }
};