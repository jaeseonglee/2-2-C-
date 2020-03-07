/*	실습 2번 : PersonClass.cpp
	작성일 : 2019.10.25 ~ 10.27
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 Person 클래스와 main를 갖고 해결
				1. 생성자를 중복 작성하고 프로그램을 완성하라.
				2. 디폴트 매개 변수를 가진 하나의 생성자를 작성하고 프로그램을 완성하라.
*/

#include <iostream>
using namespace std;

class Person {		// Person 클래스
	int id;			
	double weight;
	string name;
public:
	Person(int id = 1, string name = "Grace", double weight = 20.5) { // 2번 디폴트 매개변수를 가진 하나의 생성자
		this->id = id;			// 3개의 멤버 변수 전부 다
		this->name = name;		// 매개변수의 값으로 초기화
		this->weight = weight;
	}	

	/*	
	Person();		// 1번 생성자 중복 작성 , 매개변수가 없는 생성자
	Person(int id, string name);	// 1번 id와 name을 매개변수로 가지는 생성자
	Person(int id, string name, double weight);	//  1번 id와 weight와 name을 매개변수로 가지는 생성자 
	*/
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

/*
Person::Person() { // 1번 매개변수가 없는 생성자
	this->id = 1;			// 출력결과에 맞게 초기화
	this->name = "Grace";	 
	this->weight = 20.5;	 
}

Person::Person(int id, string name) { // 1번 id와 name을 매개변수로 가지는 생성자
	this->id = id;			// 매개변수의 값으로 초기화
	this->name = name;		// 매개변수의 값으로 초기화
	this->weight = 20.5;	// 출력결과에 맞게 초기화
}

Person::Person(int id, string name, double weight) {// 1번 id와 weight와 name을 매개변수로 가지는 생성자
	this->id = id;			// 3개의 멤버 변수 전부 다
	this->name = name;		// 매개변수의 값으로 초기화
	this->weight = weight;
}
*/

int main() {		// main 함수
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}
