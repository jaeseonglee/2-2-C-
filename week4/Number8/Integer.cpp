/*	실습 8번 : Integer.cpp
	작성일 : 2019.09.19 ~ 09.20
	작성자 : 20165153 이재성
	프로그램 설명 : int 타입의 정수를 객체화한 Integer클래스 작성 및 모든 함수를 자동 인라인으로 작성하는 프로그램
*/

#include <iostream>
#include <string>		// stoi()함수를 쓰기위한 헤더파일 srting을 include
using namespace std;

class Integer {			// 클래스 Integer
	int num;			// (private) 생략 정수형 변수 num
public:					//  자동 인라인을 통해서 클래스의 선언부에 모든 함수를 직접 구현
	Integer(int n) {num = n;}			// 정수를 매개변수로 받는 생성자는 그 매개변수를 num에 저장
	Integer(string s) { num = stoi(s); }// string 타입으로 매개변수를 받는 생성자는 stoi 함수를 통해 정수로 변경후에 num에 저장

	int get() { return num; }			// num을 반환하는 get 함수
	void set(int n) { num = n; }		// 매개변수를 num에 저장하는 set 함수
	int isEven() {						// 짝수인가 아닌가를 반환하는 isEven함수
		if (num % 2 == 0) return true;	// num이 2로 나눈 나머지가 0이면(짝수면), int형 함수이기 때문에 1(ture) 반환
		else return false;				// 그게 아니라면 false 반환
	}
};

int main() {				// main함수,실습문제에서 주어진 main함수와 같다.
	Integer n(30);			// 정수를 매개변수로 갖는 객체 n 생성
	cout << n.get() << ' ';	// get함수를 통해 값을 출력
	n.set(50);				// set함수를 통해 50으로 변경
	cout << n.get() << ' ';	// 다시 get함수를 통해 값을 출력

	Integer m("300");		// 문자열을 매개변수로 갖는 객체 m 생성
	cout << m.get() << ' ';	// get함수를 통해 값을 출력
	cout << m.isEven();		// isEven함수를 통해	ture또는 flase 출력
}