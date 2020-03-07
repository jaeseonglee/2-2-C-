/*	실습 12번 : Dept.cpp
	작성일 : 2019.10.20 ~ 10.21
	작성자 : 20165153 이재성
	프로그램 설명: 학과를 나타내는 Dept클래스와 이를 활용하는 프로그램.
			실습문제 1. 주어진 실행결과가 나오도록 Dept클래스에 멤버들을 모두 구현하고, 전체 프로그램을 완성하라.
					2. Dept클래스에 복사 생성자가 작성되어 있지 않은 경우 컴파일은 되지만 프로그램 실행 끝에 실행 시간 오류가
					발생한다. 코드 어느 부분이 실행될때 복사 생성자가 호출되는지 설명하고, 복사 생성자가 없으면 왜 실행 오류가
					발생하는지 설명하라. - 코드 맨아래 주석에 설명
					3. Dept클래스에 복사 생성자를 제거하라. 복사 생성자가 없는 상황에서도 실행 오류가 발생하지 않게하려면 어느
					부분을 수정하면 될까? 극히 일부분의 수정으로 해결된다. 코드를 수정해보라.
*/

#include <iostream>
using namespace std;

class Dept {
	int size; // scores 배열의 크기
	int* scores;	// 동적 할당 받을 정수 배열의 주소
public:
	Dept(int size) {		// 생성자
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept);	// 복사 생성자
	~Dept();		// 소멸자
	int getSize() { return size; }
	void read();		// size만큼 키보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index);	// index의 학생의 성적이 60보다 크면 true 리턴
};

/*
Dept::Dept(const Dept& dept) { // 1번 복사 생성자 구현
	size = dept.size;		// size는 dept의 size를 저장
	scores = new int[size];	// size만큼의 크기로 scores를 동적 할당
	for (int i = 0; i < size; i++) {	// 반복문을 통해 배열의 각 값을 복사
		scores[i] = dept.scores[i];
	}
}
*/

Dept::~Dept() {	// 1번 소멸자 구현
	if (scores) // 할달받은 메모리가 있으면
		delete[] scores;		// 반환해준다
}

void Dept::read() {		// 1번 read함수 구현
	cout << size << "개 점수 입력>> ";	// size만큼 입력받는다.
	for (int i = 0; i < size; i++) {	// 반복문을 통해
		cin >> scores[i];		// scores의 값을 저장한다
	}
}

bool Dept::isOver60(int index) {	// 1번 isOver60 함수 구현
	if (scores[index] >= 60) return true;	// 60 이상은 60부터인데, 책에서는 60 초과의 결과를 출력하고 있다.
	else return false;				// 아무튼 60이상이면 true, 아니면 false 반환
}

//////////////////
// 3번 복사 생성자 전체를 주석처리함으로써 복사 생성자 제거
// countPass가 기존 복사 생성자를 통해 객체를 호출하기 때문에 참조자를 통해 main함수의 객체를 가리키도록 수정
int countPass(Dept& dept) {		// dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10); // 총 10명이 있는 학과 com
	com.read();	  // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
	int n = countPass(com);	// com학과에 60점이상으로 통과한 학생의 수를 리턴
	cout << "60점이상은 " << n << "명";
}


/* 2번 :	묵시적 복사 생성 중에는 값에 의한 호출로 객체가 전달될때는 복사 생성자가 호출되는데
	67줄에 int n = countPass(com); 여기서 countPass 함수가 com객체를 전달하는데 함수의 매개변수 객체가 생성될때
	복사 생성자가 자동으로 호출되기 때문에 2번까지의 프로그램에서는 복사생성자가 필요하다.
*/