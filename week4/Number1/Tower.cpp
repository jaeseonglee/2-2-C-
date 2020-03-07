#include <iostream>		
using namespace std;

#include "Tower.h"	// 선언부인 헤더파일 Tower.h을 include

Tower::Tower() {	//	Tower 클래스의 구현부, 생성자와 함수를 구현한다.
	height = 1;		// 매개변수 없이 객체의 생성시에는 높이를 1로 지정
}

Tower::Tower(int h) {	// 매개변수가 있는 생성자의 경우에는
	height = h;		// 그 매개변수를 높이로 저장한다.
}

int Tower::getHeight() {// getHeight를 통해 
	return height;		// 높이(height)를 반환
}