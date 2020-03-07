/*	C++ 프로그래밍 2주차 과제
	실습 8번 : Number8.cpp
	작성일 : 2019.09.05 ~ 09.07
	작성자 : 20165153 이재성
	프로그램 설명 : 한 라인에 ';'으로 5개의 이름을 구분하여 입력받아.
					각 이름을 끊어내어 화면에 출력하고 가장 긴 이름을 찾는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS	// 아래쪽의 strlen,strtok,strcpy을 사용함에 있어 오류를 나타내지 않게하는 define문
#include <iostream>				// 표준 전처리문
using namespace std;
#include <cstring>				// 기존 C에서의 문자열 처리함수를 쓰기 위해 cstring을 사용한다.

#define SIZE 100				// define문을 통해 SIZE 100으로 지정

int main() {					// main함수
	char name[SIZE] = "";		// 5명의 이름을 저장할 문자 배열
	char longName[SIZE] = "";	// 가장 긴 이름을 저장할 문자 배열
	char temp[SIZE] = "";		// 반복문을 실행하면서 임시적으로 가장 긴 이름을 저장할 문자 배열

	cout << "5명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";	// 이름을 입력해달라고 출력
	cin.getline(name, SIZE, '\n');			// getline을 통해 name에 저장해준다.
	
	strcpy(longName, strtok(name, ";"));	// strtok을 통해서  첫번째로 입력된 이름을 longName에 저장해준다.
	cout << "1 : " << longName << endl;		// 첫번째 이름 출력

	for (int i = 2; i <= 5; i++) {			// 반복문을 통해 가장 긴 이름을 찾는다.
		strcpy(temp, strtok(NULL, ";"));	// strtok을 통해서 그 다음 ';'까지 이름을 temp에 저장
		cout << i << " : " << temp << endl;	// 반복문을 실행과 동시에 이름들을 츨력
		if (strlen(temp) > strlen(longName))	// strlen을 통해 길이를 구해서 조건문을 통해
			strcpy(longName, temp);			// 가장 긴 이름을 longName에 저장해준다.
	}

	cout << "가장 긴 이름은 " << longName << endl;	// 가장 긴 이름 출력
}