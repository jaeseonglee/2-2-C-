#include <iostream>
using namespace std;

#include "Sample.h"		// Sample 클래스 사용을 위해 헤더파일 include

int main() {			// main함수, 실습문제에서 주어진 코드와 같다
	Sample s(10);		// 10개 정수 배열을 가진 Sample 객체 생성
	s.read();			// 키보드에서 정수 배열 일기
	s.write();			// 정수 배열 출력
	cout << "가장 큰 수는 " << s.big() << endl;		// 가장 큰 수 출력 
}