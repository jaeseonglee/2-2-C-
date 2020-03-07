/*	실습 8번 : Circle.h , Circle.cpp , main.cpp
	작성일 : 2019.09.26 ~ 09.27
	작성자 : 20165153 이재성
	프로그램 설명 : 실습 7번을 수정하는 문제로서, 사용자로부터 원의 개수를 입력받고 원의 개수만큼 반지름을 입력받는
					방식으로 수정한 프로그램. 원의 개수에 따라 동적으로 배열을 할당받아야함
					헤더파일과 클래스 파일은 변동이 없으나 메인함수만 수정
*/

class Circle {		// Circle 클래스 문제에서 주어진 코드와 같다
	int radius;		// 원의 반지름 값을 저장할 radius
public:
	void setRadius(int radius);	// 반지름을 설정하는 setRadius 함수
	double getArea();			// 면적을 반환할 getArea 함수
};