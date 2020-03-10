/*	실습 12번 : SortedArrayClass.cpp
	작성일 : 2019.11.05 ~ 11.07
	작성자 : 20165153 이재성
	프로그램 설명: 정수 배열을 항상 증가순으로 유지하는 SortedArray클래스를 구현한 프로그램
*/

#include <iostream>
using namespace std;

class SortedArray {		// SortedArray 클래스
	int size;  // 현재 배열의 크기
	int* p;		// 정수 배열에 대한 포인터
	void sort();	// 정수 배열을 오름차순으로 정렬
public:
	SortedArray();	// p는 NULL로 size는 0으로 초기화
	SortedArray(SortedArray& src);	// 복사 생성자
	SortedArray(int p[], int size);	// 생성자. 정수 배열과 크기를 전달받음
	~SortedArray();		// 소멸자
	SortedArray operator+(SortedArray& op2);		// 현재 배열에 op2 배열 추가
	SortedArray& operator=(const SortedArray& op2);	// 현재 배열에 op2 배열 복사
	void show();		// 배열의 원소 출력
};

void SortedArray::sort() {		// 오름차순으로 정렬하는 sort 함수, 클래스내에서 private로 선언되었다
	for (int i = 0; i < size - 1; i++) {
		for (int j = 1; j < size; j++) {	// 중첩 반복문을 통해 오름차순 정렬
			if (p[j-1] > p[j]) {
				int temp = p[j-1];
				p[j-1] = p[j];
				p[j] = temp;
			}
		}
	}
}


SortedArray::SortedArray() {	// 생성자
	p = nullptr;		// p는 NULL로 초기화 하라고 주어졌는데 nullptr로 초기화해봤다
	size = 0;			// size는 0으로 초기화
}

SortedArray::SortedArray(SortedArray& src) {	// 복사 생성자, 깊은 복사로 진행한다
	this->size = src.size;		// size는 인자로 들어온 객체의 size로 초기화
	p = new int[size];			// 포인터는 먼저 동적 할당을 통해 만들어주고
	for (int i = 0; i < size; i++) {	// 그 다음에 반복문을 통해 값을 저장한다
		p[i] = src.p[i];
	}
}

SortedArray::SortedArray(int p[], int size) {	// 매개변수가 있는 생성자
	this->size = size;			// size는 그대로 매개변수 size로 저장하고
	this->p = new int[size];	// p는 동적 할당후
	for (int i = 0; i < size; i++) {	// 배열의 값들로 저장한다
		this->p[i] = p[i];
	}
}

SortedArray::~SortedArray() {		// 소멸자
	if(p)
		delete [] p;	// p가 할당받았으면 반환해준다
}

SortedArray SortedArray::operator+(SortedArray& op2) {	// +연산자 함수 , 두 객체를 합친다
	SortedArray temp;		// 두 객체를 합쳐 새로운 객체를 반환할 temp 선언
	temp.size = this->size + op2.size;	// 두 객체의 size를 합친 크기로 초기화
	temp.p = new int[temp.size];		// p도 그 크기만큼 할당 

	for (int i = 0; i < this->size; i++) {	// 두 반복문을 통해 두 객체에 있는 p의
		temp.p[i] = this->p[i];
	}
	for (int i = 0; i < op2.size; i++) {	// 각각의 값들을 temp의 p에 저장해준다
		temp.p[i + this->size ] = op2.p[i];
	}
	return temp;		// 그렇게 새로 초기화된 temp를 반환
}

SortedArray& SortedArray::operator=(const SortedArray& op2) { // =연산자	함수, 책의 힌트 참고하여 작성했다
	delete[] this->p;			// 먼저 기존의 p를 반환해주고
	this->size = op2.size;		// op2 객체를 복사하기 위해 그대로 값을 받고
	this->p = new int[this->size];		// p는 size 만큼 할당
	for (int i = 0; i < this->size; i++) {	// 반복문을 통해 값을 저장
		this->p[i] = op2.p[i];
	}
	return *this;	// 그렇게 바뀐 객체 자신을 반환해준다
}

void SortedArray::show() {	// 배열을 출력하는 show함수
	sort();
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++) {// 반복문을 통해 배열 출력
		cout << p[i] << " ";
	}
	cout << endl;
}

int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;		// +, = 연산자 작성 필요
					// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
	a.show();
	b.show();
	c.show();
}