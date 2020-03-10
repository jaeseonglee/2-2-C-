/*	실습 7번 :Shape7.cpp
	작성일 : 2019.11.14 ~ 11.18
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 Shape 클래스를 상속받는 Oval,Rect,Triangular클래스를 작성하고 각 도형의 넓이를 출력하는 프로그램
*/

#include <iostream>
using namespace std;

#define PI 3.14				// define문으로 PI를 3.14로 지정

class Shape {
protected:
	string name;		// 도형의 이름
	int width, height;	// 도형이 내접하는 사각형의 너비와 높이
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() { return 0; }	// dummy 값 리턴
	string getName() { return name; }		// 이름 리턴
};

class Oval : public Shape {		// 타원을 표현하는 Oval 클래스
protected:
	double getArea() { return PI * width * height; }	// Shape의 가상 함수 오버로딩
public:
	Oval(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}	// 생성자
};


class Rect : public Shape {		// 사각형을 표현하는 Rect 클래스
protected:
	double getArea() { return  (double)width * height; }	// Shape의 가상 함수 오버로딩
public:
	Rect(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}	// 생성자
};

class Triangular : public Shape {	// 삼각형을 표현하는 Triangular 클래스
protected:
	double getArea() { return  width * height / 2; }		// Shape의 가상 함수 오버로딩
public:
	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}	// 생성자
};

int main() {			// 주어진 main 함수
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);

	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}