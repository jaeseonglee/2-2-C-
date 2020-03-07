/*	실습 3번 : BigFunc.cpp
	작성일 : 2019.10.25 ~ 10.27
	작성자 : 20165153 이재성
	프로그램 설명: big함수를 호출하는 주어진 main함수를 갖고 해결
				1. big() 함수를 2개 중복하여 작성하고 프로그램을 완성하라
				2. 디폴트 매개변수를 가진 하나의 함수로 big()을 작성하고 프로그램을 완성하라
*/

#include <iostream>
using namespace std;

/*
int big(int a, int b) {	// 1번 최대값이 100인 big 함수
	if (a > 100 || b > 100) return 100;
	else return (a > b) ? a : b;
}

int big(int a, int b, int c) { // 1번 최대값이 c인 big 함수
	if (a > c || b > c) return c;
	else return (a > b) ? a : b;
}
*/

int big(int a, int b, int c = 100) { // 2번 디폴트 매개변수 c를 가진 하나의 big함수
	if (a > c || b > c) return c;		// 두 값중에 c보다 큰 수가 있다면 c 리턴
	else return (a > b) ? a : b;		// 아니라면 수를 비교하여 큰 수 리턴
}

int main() {
	int x = big(3, 5);		// 3과 5 중 큰 값 5는 최대값 100보다 작으므로, 5리턴
	int y = big(300, 60);	// 300과 60 중 큰 값 300이 최대값 100보다 크르모, 100 리턴
	int z = big(30, 60, 50);// 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
	cout << x << ' ' << y << ' ' << z << endl;
}
