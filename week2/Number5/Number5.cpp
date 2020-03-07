/*	C++ 프로그래밍 2주차 과제
	실습 5번 : Number5.cpp
	작성일 : 2019.09.05 ~ 09.07
	작성자 : 20165153 이재성
	프로그램 설명 : Enter키가 입력될 때까지 문자들을 읽고, 입력된 문자'x'의 개수를 화면에 출력하는 프로그램
*/

#include <iostream>		// C++ 표준 입출력 전처리문
using namespace std;	// using 지시어를 통해 std 생략

#define SIZE 100		// define문을 통해 SIZE 100으로 지정

int main() {				// main함수, C++에서는 return 0;를 생략가능
	char word[SIZE] = "";	// 문자 배열 word 선언 및 NULL로 초기화
	int count = 0;			// int형 변수 count 선언 및 0으로 초기화

	cout << "문자들을 입력하라(100개 미만)."<<endl;	// cout을 통해 문자들을 입력하라고 출력, endl은 줄바꿈
	cin.getline(word, SIZE, '\n');					// cin.getline을 통해 word에 키보드로부터 받은 값을 저장

	for (int i = 0; i < SIZE; i++) {	// C++에서는 중간에 변수 선언이 가능해서 java와 유사한 면이 있다.
		if (word[i] == 'x' )				//strcmp를 사용하려면 #define <cstring> 을 지정해서 사용
			count++;					// 반복문을 통해 word중에서 x가 몇개 있는지 세어준다.
	}

	cout << "x의 개수는" << count << "입니다." << endl;	// C++에서 재정의?된 << 을 통해 중간에 변수도 출력해준다.
}