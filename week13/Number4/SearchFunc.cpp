/*	실습 4번 : SearchFunc.cpp
	작성일 : 2019.11.21 ~ 11.24
	작성자 : 20165153 이재성
	프로그램 설명: 배열에서 원소를 검색하는 search() 함수를 템플릿으로 작성하라. search()의 첫번째 매개변수는 검색하고자
		하는 원소의 값이고, 두번째 매개 변수는 배열이며, 세 번째 매개변수는 배열의 개수이다. search() 함수가 검색에 성공하면 
		true를, 아니면 false를 리턴한다.
*/
#include <iostream>
using namespace std;

template <class T>			// template 선언
bool search(T num, T arr[], T size) {	// search 함수
	for (int i = 0; i < size; i++) {	// 반복문을 통해 
		if (arr[i] == num) return true;	// 검색에 성공하면 true 리턴
	}
	return false;	// 실패하면 false 리턴
}

int main() {		// main 함수
	int x[] = { 1,10,100,5,4 };	
	if (search(100, x, 5)) cout << "100이 배열 x에 포함되어있다";	// 조건문에 따라 
	else cout << "100이 배열 x에 포함되어 있지 않다";				// 출력문이 다르다
}