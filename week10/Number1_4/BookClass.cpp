/*	실습 1번,4번 : BookClass.cpp
	작성일 : 2019.11.04 ~ 11.06
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 Book클래스와 각각의 문제에서 주어진 main함수의 내용을 가지고 출력하고, 책의 정보를 나타내는 프로그램이다.
*/

#include <iostream>
#include <string>		
using namespace std;

class Book {		// Book 클래스
	string title;	// 책의 이름
	int price, pages;	// 가격과 페이지
public:
	Book(string title = "", int price = 0, int pages = 0) {		// 생성자
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {		// 책의 정보를 출력하는 show 함수
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }		// 제목을 반환하는 getTitle함수
	//Book& operator +=(int price);		// 1-1번 클래스의 멤버 함수로 구현
	//Book& operator -=(int price);		// 1-1번 클래스의 멤버 함수로 구현
	friend Book& operator +=(Book& b, int price);	// 1-2번 클래스 외부 함수로 구현
	friend Book& operator -=(Book& b, int price);	// 1-2번 클래스 외부 함수로 구현
	friend bool operator<(string s, Book b);		// 4번 사전순으로 비교하기 위해 < 연산자 함수
};

bool operator<(string s , Book b) {		// 4번 사전순으로 비교하기 위해 < 연산자 함수
	return (s < b.getTitle()) ?  true : false;
}

/*
Book& Book::operator +=(int price) {// 1번 클래스의 멤버 함수로 구현
	this->price += price;
	return *this;
}

Book& Book::operator -=(int price) {// 1번 클래스의 멤버 함수로 구현
	this->price -= price;
	return *this;
}
*/

Book& operator +=(Book& b, int price) {// 1-2번 클래스 외부 함수로 구현
	b.price += price;
	return b;
}

Book& operator -=(Book& b, int price) {// 1-2번 클래스 외부 함수로 구현
	b.price -= price;
	return b;
}


int main() {
	/*
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;		// 책 a의 가격 500원 증가
	b -= 500;		// 책 b의 가격 500원 감소
	a.show();
	b.show();							// 1번에서 사용하는 main 문
	*/
	Book a("청춘", 20000, 300);			// 4번에서 사용하는 메인문
	string b;
	cout << "책 이름을 입력하세요>>";
	getline(cin, b);	// 키보드로부터 문자열로 책 이름을 입력받음
	if (b < a)
		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!"<< endl;
}