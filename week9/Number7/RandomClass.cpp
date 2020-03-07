/*	실습 7번 : RandomClass.cpp
	작성일 : 2019.10.25 ~ 10.27
	작성자 : 20165153 이재성
	프로그램 설명: Rondom 클래스를 활용하여 랜덤한 값을 출력하는 프로그램 
*/


#include <iostream>
#include <ctime>		
#include <cstdlib>
using namespace std;

class Rondom {	// 난수를 발생시키는 Rondom 클래스
public:
	//항상 다른 랜덤 수를 발생시키기 위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(0)); }	// 씨드 설정
	static int nextInt(int min = 0, int max = 32767);	// min과 max 사이의 랜덤 정수 리턴
	static char nextAlphabet();	// 랜덤 알파벳 문자 리턴
	static double nextDouble();	// 0보다 크거나 같고 1보다 적은 랜덤 실수 리턴
};

int Rondom::nextInt(int min, int max) {	// 랜덤 정수를 리턴하는 nextInt함수
	int n = rand() % (max-min) + min;	// man과 max사이의 값중에 하나를 가진다
	return n;		// n 리턴
}

char Rondom::nextAlphabet() {	// 랜덤 알파벳을 리턴하는 nextAlphabet함수
	char c = rand() % 2;		// 대문자를 출력할지 소문자를 출력할지 결정
	if(c == 0) c = rand() % 26 + 65;// 대문자 출력, A = 65 Z = 90 이므로 0부터 25까지 랜덤숫자중 65를 더해준다
	else c = rand() % 26 + 97;		// 소문자 출력, a = 97 z = 122 이므로 0부터 25까지 랜덤숫자중 97을 더해준다
	return c;		// ASCII 코드의 상에서의 숫자로 저장된 c 리턴
}

double Rondom::nextDouble() {	// 랜덤 실수를 리턴하는 nextDouble 함수
	double d = rand() / (double)RAND_MAX;	// 랜덤 정수의 최대값 32767(RAND_MAX)로 랜덤 값을 나눈 값을 출력
	return d;		// double형의 d 리턴
}

int main() {		// main 함수
	Rondom::seed();	// seed 함수를 통해 먼저 씨드를 설정해준다
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {		// 랜덤 정수 10개 출력
		cout<<Rondom::nextInt(1, 100) <<" ";
	}

	cout <<endl << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {	// 랜덤 알파벳 10개 출력
		cout << Rondom::nextAlphabet() << " ";
	}

	cout << endl << "랜덤한 실수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {	// 랜덤 실수 10개 출력
		cout << Rondom::nextDouble() << " ";
		if (i == 4 || i == 9) cout << endl;	// 실수 5개씩 출력후 줄바꿈
	}
}