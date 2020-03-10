/*	실습 6번 : BaseArrayProject.cpp
	작성일 : 2019.11.07 ~ 11.10
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 BaseArray 클래스를 상속받아 스택으로 작동하는 MyStack 클래스를 작성한 프로그램
*/
#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;	// 배열의 크기
	int* mem;		// 정수 배열을 만들기 위한 메모리의 포인터
protected:			// 생성자가 Protected인것에 주목
	BaseArray( int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {		// BaseArray를 상속받는 MtStack 클래스
	int num;			// 현재 스택의 크기를 저장할 변수 num
public:
	MyStack(int size) : BaseArray(size) { this->num = 0; } // 매개변수가 있는 생성자로, BaseArray의 생성자에 size값을 전달 하고 num값을 0으로 초기화
	void push(int n) { put(num++, n);  }		// 현재 스택에서 값을 추가, BaseArray의 값과 인덱스를 전달해준다
	int capacity()   { return getCapacity(); }	// 배열의 용량을 반환하는 capacity함수
	int length()	 { return num; }			// 현재 스택의 크기를 반환하는 lenght 함수
	int pop()		 { return get(--num); }		// 스택에서 pop의 기능을 하는 pop함수
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);			// 스택에 푸시
	}
	cout << "스택용량:" << mStack.capacity() << ", 스택크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';		// 스택에서 팝
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}