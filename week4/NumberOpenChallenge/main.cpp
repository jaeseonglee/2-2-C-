#include <iostream>
using namespace std;

#include "Exp.h"		// Exp클래스 사용을 위해 Exp.h include

int main() {		// main함수 143p에 주어진 main함수와 같다.
	Exp a(3, 2);	// 베이스가 3이고 지수가 2인 객체
	Exp b(9);		// 베이스가 9이고 지수가 1인 객체
	Exp c;			// 베이스와 지수 둘 다 1인 객체

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;	// 세 객체가 가진 값을 출력
	cout << "a의 베이스 " << a.getBase() << ',' << "지수 " << a.getExp() << endl;	// 객체 a의 베이스와 지수 출력

	if (a.equals(b))		// a와 b가 가진 값을 비교한다.
		cout << "same" << endl;	// 같으면 same 출력
	else
		cout << "not same" << endl;	// 다르면 not same 출력
}