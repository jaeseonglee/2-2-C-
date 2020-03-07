#include <iostream>
using namespace std;

#include "Person.h"		// 헤더파일 include

Person::Person() {	// 생성자
	name = "";		// NULL값으로 초기화해준다
	tel = "";
}

string Person::getName() { return name; }// 각각 이름과
string Person::getTel() { return tel; }	 // 전화번호를 반환

void Person::set(string name, string tel) {	// 이름과 전화번호를 저장하는 tel함수
	this->name = name;		// this를 이용해서 private인 두 변수에 저장해준다
	this->tel = tel;
}

Person::~Person() {}		// 소멸자