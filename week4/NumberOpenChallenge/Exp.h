/*	실습 Open challenge : Exp.h, Exp.cpp, main.cpp
	작성일 : 2019.09.20
	작성자 : 20165153 이재성
	프로그램 설명 : 실수의 지수 표현 클래스 Exp 클래스. Exp.h, Exp.cpp, main.cpp로 분리하여 작성
*/

class Exp {		// 실수의 지수표현 클래스 Exp
	int base;	// (private) 베이스 숫자 base 선언
	int exp;	// (private) 지수 숫자 exp 선언
public:
	Exp();				// 매개변수 없는 생성자 -> 베이스와 지수 둘다 1
	Exp(int b);			// 매개변수가 하나만 있는 생성자 -> 베이스는 매개변수로 초기화, 지수는 1
	Exp(int b, int e);	// 매개변수가 두개 있는 생성자 -> 베이스와 지수 매개변수로 초기화
	//~Exp()	컴파일러에 의해 자동으로 소멸자가 주어짐
	int getValue();		// 지수 표현을 정수로 계산하여 반환
	int getBase();		// 베이스 값 반환
	int getExp();		// 지수 값 반환
	bool equals(Exp b);	// 두 객체의 값이 같은지 판별하여 반환
};