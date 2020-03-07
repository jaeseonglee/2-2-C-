/*	실습 4장의 1번 : Color.cpp
	작성일 : 2019.09.20
	작성자 : 20165153 이재성
	프로그램 설명 : 색의 3요소인 red,green,blue로 색을 추상화한 Color클래스 구현한 프로그램
*/

#include <iostream>
using namespace std;

class Color {				// 색의 3요소인 red,green,blue로 색을 추상화한 Color클래스
	int red, green, blue;	// 실습문제에 주어진 코드와 같다. 빈칸을 채우는 문제이기 때문에 (n)주석을 작성
public:
	Color() { red = green = blue = 0; }							// 매개변수가 없는 생성자는 변수들을 0으로 초기화
	Color(int r, int g, int b) { red = r; green = g; blue = b; }// 매개변수가 있으면 변수들을 매개변수들로 초기화
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }// 매개변수를 변수에 저장하는 setColor함수
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }	// 저장된 색의 3요소를 출력하는 show함수
};

int main() {						// main함수도 주어진 코드와 같다.
	Color screenColor(255, 0, 0);	// 빨간색의 screenColor 객체 생성
	Color* p;						// Color 타입의 포인터 변수 p 선언
	p = &screenColor;				// (1) p가 screenColor의 주소를 가지도록 코드 작성
	p->show();						// (2) p와 show()를 이용하여 screenColor 색 출력
	Color colors[3];				// (3) Color의 일차원 배열 colors 선언. 원소는 3개
	p = colors;						// (4) p가 colors 배열을 가리키도록 코드 작성
					// 주의: &를 붙이지 않는다. 포인터가 객체 배열을 가리킴!

	// (5) p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가 
	// 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
	p[0].setColor(255, 0, 0);	// 각각(r,g,b) 값을 가리키므로 
	p[1].setColor(0, 255, 0);	// 색깔에 해당하는 매개변수를 255로 입력
	p[2].setColor(0, 0, 255);

	// (6) p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for 문 이용
	for (int i = 0; i < 3; i++) {	// 반복문을 통해 객체 배열에 저장된 각각의 값 출력
		p[i].show();
	}
}