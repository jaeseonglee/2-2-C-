#include <iostream>
#include <string>		// string 클래스 사용에 필요한 코드
using namespace std;

#include "Person.h"		// Person 클래스 사용을 위해 include

#define SIZE 3			// define문으로 SIZE에 3을 저장

int main() {			// main 함수
	Person *p = new Person[SIZE];	// 객체 포인터 배열 선언,기본 생성자로 생성된다
	string name = "";		// 이름을 저장할 문자열 변수 name
	string tel = "";		// 전화번호를 저장할 문자열 변수 tel

	cout << "이름과 전화번호를 입력해주세요" << endl;	// 이름과 전화번호를 입력해달라고 출력

	for (int i = 0; i < SIZE; i++) {// 반복문을 통해
		cout << "사람 " << i+1 << ">> ";		
		cin >> name >> tel;			// 3개의 객체에 저장할 값을 입력받는다.
		p[i].set(name, tel);		// 입력받은 값을 각 인덱스에 set함수를 통해 저장
	}

	cout << "모든 사람의 이름은 ";	// 모든 객체 출력
	for (int i = 0; i < SIZE; i++) {	
		cout << p[i].getName() << " ";	// getName을 통해 각 인덱스에 있는 이름을 출력
	}

	cout << endl << "전화번호 검색합니다. 이름을 입력하세요>>";	
	cin >> name;			// 키보드가 찾는 이름을 name에 저장

	for (int i = 0; i < SIZE; i++) {	//반복문을 통해 검색
		if (name == p[i].getName()) {	// C++에서는 '==' 연산자를 통해 문자열 비교연산가능,결과는 boolean형
			cout << "전화번호는 ";
			cout << p[i].getTel() << endl;	// 조건문에 부합하는 값을 찾으면 getTel을 통해 전화번호 출력
			break;
		}
		if (i == SIZE - 1) { cout << "잘못된 이름입니다!!" << endl; }
	}
	
	delete [] p;		// delete 문을 통해 할당받은 배열을 반환
}