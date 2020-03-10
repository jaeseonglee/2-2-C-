/*	실습 11번 :StackClass.cpp
	작성일 : 2019.11.05 ~ 11.07
	작성자 : 20165153 이재성
	프로그램 설명: 스택을 구현한 프로그램, push연산용으로 << 연산자를, pop연산용으로 >>연산자를, 스택이 비어있는지 확인하기 위해 ! 연산자를 작성
*/
#include <iostream>
using namespace std;

class Stack {	// Stack 클래스
	int* p;		// 정수형 포인터 선언, 스택을 의미한다
	int size;	// 스택의 크기를 저장할 size;
public:
	Stack();	// 생성자
	~Stack() { delete[] p; } // 소멸자 , 동적 할당된 p를 반환한다
	Stack& operator<<(int num);	// << 연산자 함수, push연산의 역할을 한다
	void operator>>(int& num);	// >> 연산자 함수, pop연산의 역할을 한다
	bool operator!();			// ! 연산자 함수 , 스택이 비어있는지 확인해서 bool값을 반환한다
};

Stack::Stack() {		// 생성자
	p = new int[10];	// 스택의 크기를 10으로 동적 할당
	size = 0;			// size는 0으로 초기화
}

Stack& Stack::operator<<(int num) {	// << 연산자 함수
	p[size] = num;		// 매개변수로 받은 값을 현재 할당된 p에 저장해준다
	size++;				// size 값 증가
	return *this;		// 이 객체의 참조 리턴
}

void Stack::operator>>(int& num) {	// >> 연산자 함수
	size--;			// size의 값을 1 줄여주고
	num = p[size];	// 인자로 받은 num에 저장, pop연산의 역할을 한다
}

bool Stack::operator!() {	// !연산자 함수
	if (size == 0) return true;	// size가 0이면 true 반환
	else return false;			// 아니면 false를 반환
}

int main() {		// main 함수
	Stack stack;	
	stack << 3 << 5 << 10;		// 3,5,10을 순서대로 푸시
	while (true) {
		if (!stack) break;		// 스택 empty
		int x;
		stack >> x;				// 스택의 탑에 있는 정수 팝
		cout << x << ' ';
	}
	cout << endl;
}