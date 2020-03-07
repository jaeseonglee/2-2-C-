/*	C++ 프로그래밍 2주차 과제
	실습 12번 : Number12.cpp
	작성일 : 2019.09.05 ~ 09.07
	작성자 : 20165153 이재성
	프로그램 설명 : 기존의 C에서 프로그램을 수정한 프로그램
				숫자를 입력받으면 1부터 그 숫자까지의 합을 출력한다.
*/
#define CRT_SECURE_NO_WARINGS	// C의 문자 처리함수가 오류를 출력하지 않게 하는 define문
#include <iostream>				// 표준 전처리문 // C에서는 #include <stdio.h>
using namespace std;

int sum(int a, int b);			// 1부터 입력받은 숫자까지 더하는 sum함수 선언

int main() {					// main함수
	int n = 0;					// 숫자를 저장할 정수형 변수 n 선언 및 0으로 초기화
	cout << "끝 수를 입력하세요 >>";	// printf대신 cout을 사용하여 출력한다
	cin >> n;						// scanf대신 cin을 사용하여 입력받는다
	cout << "1부터 " << n << "까지의 합은 " << sum(1, n) << "입니다." << endl;	
								// sum 함수를 %d 가 아닌 <<사이에 넣어줌으로써 사용하지 않게 해준다
}

int sum(int a, int b) {			// 1부터 입력받은 숫자까지 더하는 sum함수
	int k, res = 0;				// k를 반복문 안에서 선언해줄 수 있다
	for (k = a; k <= b; k++) {	// 1부터 입력받은 숫자까지 더해주는 반복문
		res += k;				// 그 값들을 res에 저장해준다
	}
	return res;				// 반복문을 통해 얻은 res를 반환
}

