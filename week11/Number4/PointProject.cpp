/*	실습 4번 :PointProject.cpp
	작성일 : 2019.11.07 ~ 11.10
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 Point 클래스를 상속받는 ColorPoint 클래스 작성하고 주어진 main 함수가 실행되도록하는 프로그램
*/

#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {	// Point 클래스를 상속받는 ColorPoint 클래스
	string s;			// 색상을 저장하는 변수
public:
	ColorPoint() : Point(0, 0) { this->s = "BLACK"; }		// 매개변수가 없는 생성자, Point 생성자에 0,0을 전달하면서 s를 BLACK으로 초기화
	ColorPoint(int x, int y) : Point(x, y) { this->s = "BLACK"; }	// 매개변수가 있는 생성자는 Point 생성자에 매개변수를 전달한다
	void show();		// 점과 함께 색상을 출력하는 show 함수
	void setPoint(int x, int y) { move(x, y); }	// 점 위치를 바꾸는 setPoint 함수
	void setColor(string s) {this->s = s; }	// 색상을 바꾸는 setColor 함수
};

void ColorPoint::show() {
	cout << s << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;	// 현재 점의 위치와 색상을 출력
}

int main() {
	ColorPoint zeroPoint;	// BLACK 색에 (0,0) 위치의 점
	zeroPoint.show();	// zeroPoint를 출력한다

	ColorPoint cp(5, 5);	
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();	// cp를 출력한다
}