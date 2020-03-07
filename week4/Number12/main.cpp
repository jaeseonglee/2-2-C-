#include <iostream>
using namespace std;

#include "Ram.h"	// 클래스 Ram를 사용하기 위해 include

int main() {		// main함수, 실문 문제에서 주어진 main 함수와 같다.
	Ram ram;		// 객체 ram 생성
	ram.write(100, 20);	// 100 번지에 20 저장
	ram.write(101, 30);	// 101 번지에 20 저장
	char res = ram.read(100) + ram.read(101);	// 20+30 = 50
	ram.write(102, res);		// 102번지에 50저장
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl; //102번지 값 출력
}