/*	C++ 프로그래밍 4주차 과제
	실습 1번 : Tower.h , Tower.cpp , main.cpp
	작성일 : 2019.09.19 ~ 09.20
	작성자 : 20165153 이재성
	프로그램 설명 : 생성자를 통해 높이를 지정해주고, 높이가 얼마인지 출력하는 프로그램
*/

class Tower {		// 헤더파일 Tower.h에서 Tower 클래스의 선언부
	int height;		// C++에서는 디폴트 접근지정자는 private이다.
public:
	Tower();		// 실습 문제에서 주어진 main함수로 보아 생성자 2개가 필요하다.
	Tower(int h);	// 매개변수가 없는 생성자와 있는 생성자
	int getHeight();	// private로 지정된 높이를 알 수 있게하는 getHight
};