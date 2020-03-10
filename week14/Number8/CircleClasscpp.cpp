/*	실습 8번 : CircleClass.cpp
	작성일 : 2019.11.28 ~ 12.02
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 Circle 클래스를 가지고 <<,>>연산자를 작성한 프로그램
*/
#include <iostream>
using namespace std;

class Circle {	// Circle 클래스
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") { this->radius = radius; this->name = name; }	// 생성자
	friend istream& operator >> (istream& ins, Circle& c);
	friend ostream& operator << (ostream& stream, Circle c);
};

istream& operator >> (istream& ins, Circle& c) {	// >> 입력에 대한 연산자 재정의
	cout << "반지름 >> ";
	ins >> c.radius;
	cout << "이름 >> ";
	ins >> c.name;
	return ins;
}

ostream& operator << (ostream& stream, Circle c) {	// << 출력에 대한 연산자 재정의
	stream << "(반지름" << c.radius << "인 " << c.name << ")";
	return stream;
}

int main() {
	Circle d, w;
	cin >> d >> w;			// 키보드 입력을 받아 객체 d와 w를 완성
	cout << d << w << endl;	// 객체 d,w 출력
}