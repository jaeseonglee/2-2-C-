/*	실습 8번 : MyIntStacClass.cpp
	작성일 : 2019.10.20
	작성자 : 20165153 이재성
	프로그램 설명 : 스택구조를 구현한 프로그램, 실습문제의 코드들에서 MyIntClass의 구현부를 작성한 코드이다.
*/

#include <iostream>
using namespace std;

class MyIntStack {
	int* p;		// 스택 메모리로 사용할 포인터
	int size;	// 스택의 최대 크기
	int tos;	// 스택의 탑을 가리키는 인덱스
public:
	MyIntStack();		// 기본 생성자
	MyIntStack(int size);	// 매개변수가 있는 생성자
	MyIntStack(const MyIntStack& s);	// 복사생성자
	~MyIntStack();		// 소멸자
	bool push(int n); // 정수 n을 스택에 푸시한다.
					  // 스택이 꽉 차 있으면 false를, 아니면 true 리턴
	bool pop(int& n); // 스택의 탑에 있는 값을 n에 팝한다.
					  // 만일 스택이 비어 있으면 false를, 아니면 true 리턴
};

MyIntStack::MyIntStack() {	// 기본 생성자
	p = nullptr;	 // 각각의 멤버들을 초기화해준다.
	size = 0;
	tos = 0;
}

MyIntStack::MyIntStack(int size) {	// 매개변수가 있는 생성자
	this->size = size;	// 매개변수로 받는 size를 size에 저장
	p = new int[size];	// size 만큼의 정수형 배열을 동적 생성
	tos = 0;			// 현재 스택의 탑의 인덱스는 0
}

MyIntStack::MyIntStack(const MyIntStack& s) {	// 복사생성자
	size = s.size;		// s의 size만큼 size를 저장	
	p = new int[size];	// size만큼의 정수형 배열을 동적 생성
	tos = s.tos;		// 현재 스택의 탑의 인덱스를 s의 tos만큼 저장
}

MyIntStack::~MyIntStack() {  // 소멸자
	if(p)
		delete[] p;		// 동적 할당된 p의 배열을 delete
}

bool MyIntStack::push(int n) {	// 스택에 푸시하는 push 함수
	if (size == tos) return false;	// 스택이 꽉차면 false
	else {				// 아니면 true 반환
		p[tos] = n;		// 현재 스택의 탑 인덱스에 해당하는 배열의 값에 n 저장
		tos++;			// 인덱스 증가
		return true;
	}
}

bool MyIntStack::pop(int& n) {	// 스택의 가장 탑의 값을 pop하는 pop함수
	if (tos == 0) return false;	//스택이 없으면 false 반환
	else {			// 아니면 true 반환
		tos--;		// 현재의 인덱스에 해당하는 값이 없으므로 -1 해준다.
		n = p[tos];	// 스택의 탑의 값을 n에 저장, 참조로 인한 호출로 main에 값이 전달됨
		return true;
	}
}

int main() {		// main 함수 , 실습문제에서 주어진 코드와 같다
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;		// 복사 생성
	b.push(30);

	int n;
	a.pop(n);	// 스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);	// 스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl;
}