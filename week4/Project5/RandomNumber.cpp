/*	실습 5번 : RandomNumber.cpp
	작성일 : 2019.09.19 ~ 09.20
	작성자 : 20165153 이재성
	프로그램 설명 : 랜덤 수를 발생시키는 Random클래스를 이용하여 랜덤한 정수 10개 출력하는 프로그램
				(Random클래스가 생성자,next(),nextInRange() 3개의 멤버함수를 가지도록 작성하고,
				main()함수와 합쳐 하나의 cpp파일로 구현)
*/

#include <iostream>
#include <cstdlib>	// 랜덤 정수를 발생시키기 위해서 cstdlib,ctime
#include <ctime>	// 두 헤더파일을 include, 본 실습문제에서 참조
using namespace std;

class Random {	// 랜덤 수를 발생시키는 Random클래스
public:
	Random();	// Random 클래스의 생성자
	int next();	// 0부터 RAND_MAX(32767)사이의 랜덤한 정수를 반환하는 함수
	int nextInRange(int start, int end); // 매개변수 start에서 end 사이의 랜덤한 정수를 반환하는 함수
};

Random::Random() {	// 생성자
	srand((unsigned)time(NULL)); // srand를 통해 난수 생성의 범위 지정,범위가 항상 바뀌게 하기 위해 현재 시간으로 지정
								//  unsigned를 통해 양의 숫자를 얻는다.
}								

int Random::next() {	// next 함수
	return rand(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 반환한다.
}

int Random::nextInRange(int start, int end) {	// nextInRange 함수
	return (rand() % (end - start + 1)) + start;// end와 start의 차로 나누면 나머지가 그 차만큼의 가짓수가 나오는데
						// 그러면 결과에서 숫자 end가 나오지 않게 되므로 +1을 해주어 나올 수 있는 가짓수(나머지)가 하나 더 나오게한다.
						// 그리고 start를 마지막에 더해주어 0부터 가짓수까지의 랜덤 숫자를 start부터 end까지 나오게해서 반환한다.
}

int main() {			// main 함수, 실습 문제에서 주어진 main 함수와 같다.
	Random r;			// 객체 생성
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;	// 0부터 32767까지의 랜덤 숫자를 출력한다고 출력
	for (int i = 0; i < 10; i++) {		// 반복문을 통해
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수를 next()함수를 통해 반환하고
		cout << n << ' '; // 출력한다.
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;	// 2부터 4까지의 랜덤 숫자를 출력한다고 출력
	for (int i = 0; i < 10; i++) {		// 위와같이 반복문을 통해 
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수를 nextInRange함수를 통해 반환하고
		cout << n << ' ';		// 값을 출력한다.
	}
	cout << endl;	// 줄바꿈
}