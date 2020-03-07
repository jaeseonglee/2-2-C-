#include <iostream>
using namespace std;

#include "Exp.h"	// 선언부인 헤더파일 Exp.h를 include

Exp::Exp() {		// 매개변수 없는 생성자 -> 베이스와 지수 둘다 1
	base = 1;
	exp = 1;
}

Exp::Exp(int b) {	//매개변수가 하나만 있는 생성자 -> 베이스는 매개변수로 초기화, 지수는 1
	base = b;
	exp = 1;
}

Exp::Exp(int b, int e) {// 매개변수가 두개 있는 생성자 -> 베이스와 지수 매개변수로 초기화
	base = b;
	exp = e;
}

int Exp::getValue() {		// 값을 계산하여 반환하는 getValue() 함수
	int result = 1;			// 반환을 위해 값을 저장할 result 선언
	for (int i = 0; i < exp; i++) {	// 반복문을 통해 값을 계산
		result *= base;		// 지수만큼 베이스를 곱해준다.
	}
	return result;			// 계산된 결과를 반환
}

int Exp::getBase() { return base; }	// 베이스를 반환하는 getBase함수

int Exp::getExp() { return exp; }	// 지수를 반환하는 getExp함수

bool Exp::equals(Exp b) {			// 두 객체가 가지는 값을 비교하는 equsls함수
	if ( getValue() == b.getValue() ) { return true; }		// 값이 같으면 ture반환
	else return false;				// 다르면 false 반환
}