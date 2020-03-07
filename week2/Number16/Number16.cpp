/*	C++ 프로그래밍 2주차 과제
	실습 16번 : Number16.cpp
	작성일 : 2019.09.05 ~ 09.07
	작성자 : 20165153 이재성
	프로그램 설명 : 영문 텍스트를 입력받아 알파벳 히스토그램을 그리는 프로그램
				대문자는 소문자로 집계하며, 텍스트 입력의 끝은 ';'문자로 한다
*/
#define _CRT_SECURE_NO_WARNINGS	// C의 문자 처리함수가 오류를 출력하지 않게 하는 define문
#include <iostream>				// 표준 전처리문
using namespace std;
#include <cstring>				// C의 문자 처리함수를 위해 사용

#define SIZE 10000				// define문을 통해 SIZE 10000으로 지정

int main() {					// main 함수
	char text[SIZE] = "";		// 영문 텍스트를 저장할 text 선언 및 널문자로 초기화
	int countAlpha[26] = {};	// 알파벳이 나타난 횟수를 저장할 int형 배열 countAlpha 선언 및 초기화
	int num = 0 ;				// ASCII 코드로 char형을 계산하여 정수로 저장할 num 선언 및 0으로 초기화
	int count = 0;				// 알바벳 개수를 저장할 count 선언 및 0으로 초기화
	int size = sizeof(countAlpha) / sizeof(countAlpha[0]);	// countAlpha의 크기를 계산하는 size

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;	// 텍스트를 입력해달라고 출력
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
	cin.getline(text, SIZE, ';');			// 입력받은 텍스트를 text에 저장
	
	for (int i = 0; i < strlen(text); i++) {	// 반복문을 통해 countAlpha를 값들을 저장한다
		if (isalpha(text[i])) {					// 먼저 알파벳이 입력되었는가를 판단(isalpha)
			if (isupper(text[i])) {				// 그리고 대문자인가를 판단9isupper)
				text[i] = tolower(text[i]);		// 두 조건문을 거쳐서 나온 소문자를 다시 저장해준다
			}
			num = text[i] - (char)97;			// 소문자라면 ASCII코드에서 'a'가 97이기에
												// text[i]가 'a'라면 0이 나오므로 
			countAlpha[num]++;					// countAlpha[0]의 값을 하나 증가시켜준다
												// 이렇게 소문자들의 빈도를 계산하여 countAlpha를 저장해준다
		}
	}
	
	for (int i = 0; i < size; i++) {			// C++은 중간에 변수 선언 가능
		count += countAlpha[i];					// 반복문을 통해 알파벳 수를 count에 저장
	}
	cout << "총 알파벳 수 " << count << endl << endl;// 총 알파벳 수를 strlen을 통해 출력

	for (int i = 0; i < size; i++) {			// 결과를 출력하는 반복문
		cout << (char)(97 + i) << " (" << countAlpha[i] << ")\t: ";		//a부터 z까지 출력
												// countAlpha의 각각의 값을 같이 출력해준다
		for (int j = 0; j < countAlpha[i]; j++) {	// 그리고 각 인덱스에 해당하는 값만큼
			cout << "*";							// '*'을 출력해준다
		}
		cout << endl;								// 각 출력이 끝나면 줄바꿈
	}
}