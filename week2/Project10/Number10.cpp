/*	C++ 프로그래밍 2주차 과제
	실습 10번 : Number10.cpp
	작성일 : 2019.09.05 ~ 09.07
	작성자 : 20165153 이재성
	프로그램 설명 : 문자열을 하나 입력받고 문자열의 부분 문자열을 하나씩 늘려가며 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS	// C의 문자 처리함수가 오류를 출력하지 않게 하는 define문
#include <iostream>				// 표준 전처리문
using namespace std;
#include <cstring>				// C의 문자 처리함수를 위해 사용

#define SIZE 100				// define문을 통해 SIZE 100으로 지정

int main() {					// main함수
	char word[100] = "";		// 문자열을 입력받을 word 선언 및 초기화

	cout << "문자열 입력>>";		// 문자열을 입력해달라고 출력
	cin >> word;				// 입력받은 문자열을 word에 저장

	for (int i = 0; i < strlen(word); i++) {// 중첩 반복문을 통해 하나씩 늘려가며 출력
		for (int j = 0; j <= i; j++) {		// 문자를 출력하는 반복문
			cout << word[j];				// 하나씩 문자를 늘려가며 출력한다
		}
		cout << endl;						// 한 행의 출력이 끝나면 줄바꿈
	}
}