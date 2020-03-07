/*	실습 10번 : PersonAndFamily.cpp
	작성일 : 2019.09.27
	작성자 : 20165153 이재성
	프로그램 설명 : 실습문제에서 주어진 코드에서 필요한 멤버변수와 함수들을 추가시키는 문제
					추가된 코드는 주석앞에 @를 붙여서 구분
					저장된 가족 이름과 그 구성원의 이름을 저장하고 출력하는 프로그램
*/

#include <iostream>
#include <string>		// string 클래스를 사용하기 위한 include
using namespace std;

class Person {		// Person 클래스, 실습문제에서 주어진 코드와 일부 같다
	string name;	// 이름을 저장하는 문자열 변수 name
public:
	Person() { name = ""; }			// @ 기본생성자 추가, Family에서 기본생성자로 선언할때 필요
	Person(string name) { this->name = name; }	// 이 코드에서는 기본생성자로 객체 배열이 만들어지기 때문에 사실 필요없다
	string getName() { return name; }			// name을 리턴하는 getName함수
	void setName(string name) { this->name = name; }	// @setName 추가, name에 대한 setter가 필요하다
};

class Family {		//Family 클래스, 마찬가지로 실습문제에서 주어진 코드와 일부 같다
	Person *p;		// Person 배열 포인터
	int size;		// Person 배열의 크기, 가족 구성원 수
	string name;		// @생성자에는 name이 있는데 Family 클래스가 name을 갖고 있지 않아 추가
public:
	Family(string name, int size);		// size 개수만큼 Person 배열 동적 생성
	void show();			// 모든 가족 구성원 출력
	void setName(int index, string name); // @main함수에 setname이 있는데 클래스에는 없어서 추가
	~Family();				// 소멸자
};

Family::Family(string name, int size) {	// @생성자 구현부 추가
	p = new Person[size];		// @객체 포인터 배열 p를 생성하려는데 Person의 기본생성자 필요
	this->name = name;			// @각각의 변수에 this통해 저장
	this->size = size;
}

void Family::show() {			// @show 구현부 추가
	cout << name + "가족은 다음과 같이 " << size << "명 입니다." << endl;
	for (int i = 0; i < size; i++) {		// @반복문을 통해 출력
		cout << p[i].getName() << '\t';		// @getName을 통해 각 구성원의 이름을 출력한다.
	}
	cout << endl;			// 모든 출력이 끝나면 줄바꿈
}

void Family::setName(int index, string name) { // @setName구현부 추가
	p[index].setName(name);		// @Family의 이름이 아니라 Person에 이름을 저장하기위해 Person의 setName이 필요
	//p[index] = new Person(name); 이미 Family에서 기본생성자로 3개의 배열이 만들어졌으니 이렇게 쓰면 오류
}

Family::~Family() {		// @소멸자 구현부 추가
	delete [] p;			// @new로 할당된 p를 반환해준다
}

int main() {				// main 함수, 실습문제와 같다
	Family *simpson = new Family("Simpson", 3); // 3명으로 구성된 Simpson 가족
	simpson->setName(0, "Mr. Simpson");		// setName을 통해 이름을 저장한다
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();		// show를 통해 출력
	delete simpson;			// main함수에서도 simpson이라는 포인터 객체가 new로 할당되어 반환해준다.
}