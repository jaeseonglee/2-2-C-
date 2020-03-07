/*	실습 6번 : FindFunc.cpp
	작성일 : 2019.10.20
	작성자 : 20165153 이재성
	프로그램 설명 : 주어진 find 함수를 통해 문자열 a에서 c를 찾아 문자 c가 있는 공간에 대한 참조를 하는 프로그램
				주어진 main 함수가 잘 실행되도록 find함수 작성
*/

#define _CRT_SECURE_NO_WARNINGS		// 문자열 함수를 사용하는데 있어 오류를 발생하지 않게 하는 define문
#include <iostream>
#include <cstring>		// 문자열 함수사용을 위해  include
using namespace std;

char& find(char a[], char c, bool& success);		// find 함수의 원형 선언

int main() {		// main 함수, 실습문제에서 주어진 main함수와 같다
	char s[] = "Mike";
	bool b = false;

	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';			// 'M'위치에 'm'기록
	cout << s << endl;	// "mike"가 출력됨
}

char& find(char a[], char c, bool& success) {
	success = strchr(a, c);		// strchr를 통해 문자열 a에 c의 여부에 따라 bool값 반환

	for (int i = 0; i < strlen(a); i++) {	// 반복문을 통해 반환값 결정
		if (a[i] == c)		// c와 같은 문자가 있으면
			return a[i];	// 그 인덱스에 해당하는 값 반환
	}

	return a[strlen(a)];	// 없으면 a의 가장 마지막 값인 NULL값으로 반환 
}