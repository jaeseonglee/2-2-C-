/*	실습 10번 :StatisticsClass.cpp
	작성일 : 2019.11.04 ~ 11.07
	작성자 : 20165153 이재성
	프로그램 설명: 통계를 내는 Statistics클래스를 구현한 프로그램 ,주어진 main함수가 잘 실행되도록 !,<<,>>,~ 연산자 함수를 작성
*/
#include <iostream>
using namespace std;

class Statistics { // Statistics 클래스
	int *p;			// 내부에서 동적할당을 위한 정수형 포인터 선언
	int size;		// 포인터를 크기를 가리키는 size 선언
public:
	Statistics();	// 생성자
	~Statistics() { delete[] p; }	// 소멸자, 동적 할당 받는 p를 반환해준다
	bool operator!();				// !, <<, >> , ~  연산자 함수 작성에 대한 선언부
	Statistics& operator<<(int num);
	void operator>>(int& avg);
	void operator~();
};

Statistics::Statistics() {	// 생성자
	p = new int[10];		// 클래스 내부에서 int 배열을 동적으로 할당받아 유지한다, 여기서는 10의 크기로 할당
	size = 0;				// size는 0으로 초기화
}

bool Statistics::operator!() {		// ! 연산자 함수
	if (size == 0) return true;		// sizer가 0이면 true 
	else return false;				// 아니면 false 반환
}

Statistics& Statistics::operator<<(int num) { // << 연산자 함수
	p[size] = num;		// 매개변수로 받은 값을 현재 할당된 p에 저장해준다
	size++;				// size 값 증가
	return *this;		// 이 객체의 참조 리턴
}

void Statistics::operator>>(int& avg) {	// >> 연산자 함수, 매개변수로 받은 값에 값을 전달해주기 위해 & 사용
	int sum = 0;			// 합을 저장할 sum 선언 및 0으로 초기화
	for (int i = 0; i < size; i++) {
		sum += p[i];			// 반복문을 통해 p에 저장된 배열의 모든 값들을 합해준다
	}
	avg = (int)(sum / size);	// sum을 size로 나누어준 값을 인자로 받아온 avg에 저장, int로 형변환은 혹시나 해서 써줬다
}

void  Statistics::operator~() {	// ~ 연산자 함수, 출력만 하기 때문에 반환값이나 매개변수는 따로 필요하지 않다
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";		// 반복문을 통해 출력
	}
	cout << endl;
}

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i];		// x[i]에 정수 입력

	for (int i = 0; i < 5; i++) stat << x[i];		// x[i]값을 통계 객체에 삽입한다.
	stat << 100 << 200;		// 100, 200을 통계 객체에 삽입한다.
	~stat;				// 통계 데이터를 모두 출력한다

	int avg;
	stat >> avg;		// 통계 객체로부터 평균을 받는다
	cout << "avg=" << avg << endl;		// 평균을 출력한다
}
