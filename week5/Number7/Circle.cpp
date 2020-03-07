#include <iostream>
using namespace std;

#include "Ciecle.h"		// 헤더파일 include

void Circle::setRadius(int radius) {	// 매개변수 raddius를
	this->radius = radius;		// this 포인터를 이용해 반지름을 저장한다
}								// C++에서는 this가 객체 자신에 대한 포인터로 사용한다

double Circle::getArea() {			// 면적을 리턴하는 getArea 함수
	return 3.14 * radius * radius;	// 파이 값을 3.14로 지정하고 원의 넓이를 구하는 식을 통해 반환
}