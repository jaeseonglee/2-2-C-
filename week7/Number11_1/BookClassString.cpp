/*	실습 11번 : BookClass.cpp,BookClassString.cpp
	작성일 : 2019.10.20 ~ 10.21
	작성자 : 20165153 이재성
	프로그램 설명: 4. 문제 3에서 실행 오류가 발생하는 원인은 Book 클래스에서 C-스트링 방식으로 문자열을 다루었기 때문이다. 복사 생성자를 작성하지말고
				문자열을 string클래스를 사용하여, 문ㄴ제 3의 실행 오류가 발생하지 않도록 Book 클래스를 수정하라 - Number11_1에서 구현
*/

#include <iostream>
#include <string> // string 사용위해 include
using namespace std;

class Book {
	string title; // string으로 선언된 title
	int price; // 가격
public:
	Book(string title, int price);	// 문제에서 주어진대로 복사생성자는 생성하지 않는다.
	~Book() {}; // 동적 할당 받은 메모리가 없다 .
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(string title, int price) {// 생성자와 set함수 둘다 동적할당을 하지 않는다.
	this->title = title;
	this->price = price;
}

void Book::set(string title, int price) {
	this->title = title;	// 동적 할당을 하는게 아니므로 그냥 값을 새로 저장하면 된다.
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}