/*	실습 8번 : TraceClass.cpp
	작성일 : 2019.10.25 ~ 10.27
	작성자 : 20165153 이재성
	프로그램 설명: 실행도중의 정보를 저장하는 Trace 클래스를 구현한 프로그램. 주어진 f함수와 main함수를 이용하여
				Trace 클래스 구현하여 결과를 출력한다. 디버깅 정보는 100개로 제한한다.
*/

#include <iostream>
using namespace std;

class Trace {		// 정보를 저장하는 Trace 클래스
	static string tag[100];	// 태그명을 저장할 string형 배열 tag선언
	static string info[100];// 정보을 저장할 string형 배열 info선언
	static int index;		// 배열의 인덱스를 가리키는 index
public:
	static void put(string tagName, string debugInfo);	// 태그명과 디버깅 정보를 저장하는 put함수
	static void print(string s = "");					// 정보를 출력하는 print 함수 매개변수 s는 ""값을 디폴트 값으로 갖는다
};

string Trace::tag[100] = {};	// static 변수들을 각각 전역에서 초기화해준다
string Trace::info[100] = {};
int Trace::index = 0;

void Trace::put(string tagName, string debugInfo) {	// 태그명과 디버깅 정보를 저장하는 put함수
	if (index >= 100) {		// index가 100을 넘었다면 
		cout << "디버깅 정보가 너무 많습니다!" << endl;
		return ;			// 함수 종료
	}
	tag[index] = tagName;	// 매개변수의 태그명과
	info[index] = debugInfo;	// 정보의 값으로 저장해주고
	index++;				// 인덱스값을 증가시킨다.
}

void Trace::print(string s) {// 정보를 출력하는 print 함수 매개변수 s는 ""값을 디폴트 값으로 갖는다
	if (s == "") {			// 모든 디버깅 정보를 출력하는 경우 
		cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < index; i++) {		// 반복문을 통해 모든 디버깅 정보를 출력한다
			cout << tag[i] << ":" << info[i] << endl;
		}
	}
	else {	// 매개변수가 디폴트 값 대신 다른 값이 저장되었다면
		cout << "----- "<< s <<"태그의 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < index; i++) {	// 매개변수와 같은 이름의 태그명과 그 정보만 출력한다
			if( tag[i] == s) cout << tag[i] << ":" << info[i] << endl;
		}
	}
}

void f() {		// 문제에서 주어진 함수 f. 두 개의 정수를 입력받아 합을 계산하는 것을 디버깅 정보로 저장한다
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");	// 디버깅 정보 저장
	c = a + b;
	Trace::put("f()", "합 계산");	// 디버깅 정보 저장
	cout << "합은 " << c << endl;
}

int main() {		// 문제에서 주어진 main 함수 
	Trace::put("main()", "프로그램 시작합니다");	// 디버깅 정보 저장, "main()"이 태그고 "프로그램 시작합니다"가 정보다
	f();
	Trace::put("main()", "종료");	// put()의 첫 번째 매개 변수는 태그이고
									// 두 번째 매개 변수는 디버깅 정보이다.
	Trace::print("f()");	// "f()" 태그를 가진 디버깅 정보를 모두 출력한다.
	Trace::print();			// 모든 디버깅 정보를 출력한다.
}