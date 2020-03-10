/*	실습 8번 : CircleClassComparable.cpp
	작성일 : 2019.11.21 ~ 11.24
	작성자 : 20165153 이재성
	프로그램 설명: Circle 클래스를 Comparable 클래스의 상속을 통해 연산자 중복을 해결하고 결과를 출력하는 프로그램
*/
#include <iostream>
using namespace std;

class Comparable {		// Comparable 클래스
public:
	virtual bool operator > (Comparable& op2) = 0;		// 순수 가상 함수
	virtual bool operator < (Comparable& op2) = 0;		// 순수 가상 함수
	virtual bool operator == (Comparable& op2) = 0;		// 순수 가상 함수
};

class Circle : public Comparable{		// Circle 클래스
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator > (Comparable& op2);	// 순수 가상 함수 구현
	bool operator < (Comparable& op2);
	bool operator == (Comparable& op2);
};

bool Circle::operator>(Comparable& op2) {
	Circle* p = (Circle*)&op2;
	if (radius > p->getRadius() ) return true;
	else return false;
}

bool Circle::operator < (Comparable& op2) {
	Circle * p = (Circle*)&op2;
	if (radius < p->getRadius()) return true;
	else return false;
}

bool Circle::operator == (Comparable& op2) {
	Circle* p = (Circle*)&op2;
	if (radius == p->getRadius()) return true;
	else return false;
}

template <class T>		// template 선언
T bigger(T a, T b) {	// 두 개의 매개 변수를 비교하여 큰 값을 리턴
	if (a > b) return a;
	else return b;
}

int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}