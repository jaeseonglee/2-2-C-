#include <iostream>
using namespace std;

#include "AirplaneBook.h"	// AirplaneBook 헤더파일을 include

int main() {			// main 함수
	AirlineBook *airBook = new AirlineBook();	// AirlineBook 객체 동적 할당 생성
	airBook->bookSystem();	// 예약 프로그램 진행
	delete airBook;			// 할당받은 객체 반환
}