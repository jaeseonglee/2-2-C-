/*	실습 4번 : BiggerFunc.cpp
	작성일 : 2019.10.20
	작성자 : 20165153 이재성
	프로그램 설명 : 사용자로부터 두 정수를 입력받아 큰 값을 출력하는 프로그램
			주어진 bigger함수를 통해 작성
*/

#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) { // 두 정수를 비교하여 bool값을 반환하는 bigger함수
	if (a < b) big = b;	// 두 정수의 비교 , b의 값이 크면 b를 big에 저장
	else big = a;		// a가 크거나 같으면 big에 a를 저장

	if (a == b)	return true;	// 두 정수가 같으면 true 반환
	else return false;			// 그게 아니면 false 반환
}

int main() {		// main  함수
	int a = 0, b = 0;	// 정수형 변수 2개 선언 및 초기화
	int result = 0;		// 두 정수중에 더 큰값을 저장할 result
	
	cout << "a : ";		// 두 정수를 입력받는다.
	cin >> a;
	cout << "b : ";
	cin >> b;

	if (bigger(a, b, result))	// bigger함수 호출로 각각의 결과를 출력한다
		cout << a << " == " << b << "\t두 정수는 " << result <<"로 같다."<< endl;
	else
		cout << a << " != " << b << "\t큰 수는 " << result << endl;
}
