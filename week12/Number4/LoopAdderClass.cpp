/*	실습 4번 : LoopAdderClass.cpp
	작성일 : 2019.11.14 ~ 11.18
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 LoopAdder클래스를 상속받는 WhileLoopAdder 클래스와 DoWhileLoopAdder 클래스를 작성한 프로그램
*/
#include <iostream>
using namespace std;

class LoopAdder {	// 추상 클래스
	string name;	// 루프의 이름
	int x, y, sum;	// x에서 y까지의 합은 sum
	void read();	// x, y값을 읽어 들이는 함수
	void write();	// sum을 출력하는 함수
protected:
	LoopAdder(string name = "") { this->name = name; }	// 루프의 이름을 받는다. 초깃값은 ""
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;	// 순수 가상 함수. 루프를 돌며 합을 구하는 함수
public:
	void run();		// 연산을 진행하는 함수
};

void LoopAdder::read() {		// x,y 입력
	cout << name << ":" << endl;
	cout << "처음에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::write() {		// 결과 sum 출력
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run() {
	read();				// x,y를 읽는다
	sum = calculate();	// 루프를 돌면서 계산한다.
	write();			// 결과 sum을 출력한다
}

class WhileLoopAdder : public LoopAdder {	// WhileLoopAdder 클래스
protected:
	virtual int calculate();			// 상속 받은 가상 함수		
public:
	WhileLoopAdder(string name) : LoopAdder(name) {	}	// 생성자
};

int WhileLoopAdder::calculate() {		// 가상 함수 구현
	int a = getX();
	int b = getY();
	int result = a;
	while (a != b) {			// while 문을 통해 
		result += ++a;			// a부터 b까지의 합을 구해 반환
	}
	return result;
}

class DoWhileLoopAdder : public LoopAdder {	// DoWhileLoopAdder 클래스
protected:
	virtual int calculate();				// 상속 받은 가상 함수		
public:
	DoWhileLoopAdder(string name) : LoopAdder(name) { }	// 생성자
};

int DoWhileLoopAdder::calculate() {			// 가상 함수 구현
	int a = getX();
	int b = getY();
	int result = a;	
	do {						// do while문을 통해
		result += ++a;			// a부터 b까지의 합을 구해 반환
	} while (a != b);
	return result;
}


int main() {				// 주어진 main 함수
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");

	whileLoop.run();
	doWhileLoop.run();
}