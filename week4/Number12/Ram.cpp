#include <iostream>
using namespace std;

#include "Ram.h"		// 선언부인 헤더파일 Ram.h을 include

Ram::Ram() {	// mem 배열을 0으로 초기화하고 size를 100*1024로 초기화 하는 생성자
	for (int i = 0; i < 100 * 1024; i++) { mem[i] = 0; }	// 반복문을 통해 0으로 초기화
	size = 100 * 1024;
}

Ram::~Ram() {	// "메모리 제거됨" 문자열출력하는 소멸자
	cout << "메모리 제거됨" << endl;	// 메모리 제거됨이라고 출력하고 줄바꿈
}

char Ram::read(int address) {	// address 주소의 메모리 바이트 리턴
	return mem[address];		// 해당 주소에 맞는 인덱스의 값을 반환한다.
}

void Ram::write(int address, char value) {	// address 주소에 한 바이트로 value 저장
	mem[address] = value;		// 해당 주소에 맞는 인덱스의 값에 저장한다.
}