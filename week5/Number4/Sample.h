/*	C++ 프로그래밍 5주차 과제
	실습 4번 : Sample.h , Sample.cpp , main.cpp
	작성일 : 2019.09.26 ~ 09.27
	작성자 : 20165153 이재성
	프로그램 설명 : 실습문제에 주어진 Sample 클래스와 함께 main함수가 실행되도록한 프로그램
					키보드로부터 정수들을 입력받아 가장 큰 수를 출력하는 프로그램
*/

class Sample {		// Sample 클래스 선언부 문제에 주어진 클래스와 동일하다
	int* p;			// 정수형 포인터 p 선언
	int size;		// 정수형 변수 size 
public:
	Sample(int n);	// 생성자
	void read();	// 동적 할당받은 정수 배열 p에 사용자로부터 정수를 입력받음
	void write();	// 정수 배열을 화면에 출력
	int big();		// 정수 배열에서 가장 큰수 리턴
	~Sample();		// 소멸자
};