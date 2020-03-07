/*	실습 11번 : BookClass.cpp,BookClassString.cpp 
	작성일 : 2019.10.20 ~ 10.21
	작성자 : 20165153 이재성
	프로그램 설명 : 책과 이름과 가격을 저장하는 Book 클래스에 대한 프로그램
		실습문제 1. Book 클래스의 생성자, 소멸자,set() 함수를 작성하라. set() 함수는 멤버 변수 title에
				할당된 메모리가 있으면 먼저 반환한다. 그리고 나서 새로운 메모리를 할당받고 이곳에 매개변수로 전달받은 책이름을 저장한다.
				2. 컴파일러가 삽입하는 디폴트 복사 생성자 코드는 무엇인가?
				3. 디폴트 복사 생성자만 있을 때 아래 main()함수는 실행 오류가 발생한다. 실행 오류가 발생하지 않도록 깊은 복사생성자 작성하라.
				4. 문제 3에서 실행 오류가 발생하는 원인은 Book 클래스에서 C-스트링 방식으로 문자열을 다루었기 때문이다. 복사 생성자를 작성하지말고
				문자열을 string클래스를 사용하여, 문ㄴ제 3의 실행 오류가 발생하지 않도록 Book 클래스를 수정하라 - Number11_1에서 구현
*/

#define _CRT_SECURE_NO_WARNINGS // // 문자열 함수를 사용하는데 있어 오류를 발생하지 않게 하는 define문 
#include <iostream>
#include <cstring>
using namespace std;

class Book {	// Book 클래스
	char* title; // 제목 문자열
	int price; // 가격
public:
	Book(const char* title, int price);	// 생성자
	Book(Book& b); // 3번 깊은 복사 생성자 
	~Book();	// 소멸자
	void set(const char* title, int price);	
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price) { // 1번 생성자 구현
	int len = strlen(title);		// 매개변수 title의 길이만큼
	this->title = new char[len + 1]; // title의 공간을 할당해주고
	strcpy(this->title, title);		// 매개변수의 title을 복사한다.
	this->price = price;			// price에 매개변수 price 값을 저장
}

/*
Book::Book(Book& b) { // 2번 디폴트 복사 생성자 구현
	title = b.title;
	price = b.price;
}
*/
Book::Book(Book& b) { // 3번 깊은 복사 생성자 구현
	int len = strlen(b.title);	// 객체에 저장된 값으로 
	title = new char[len + 1];	// 그만큼 할당하고
	strcpy(title, b.title);	// 복사해서 생성한다.
	price = b.price;
}

Book::~Book() { // 1번 소멸자 구현
	if (title)		// 동적 할당된 title을
		delete [] title; // delete해주어 반환해준다.
}

void Book::set(const char* title, int price) { // 1번 set함수 구현
	if (this->title) // title가 할당되어 있으면
		delete [] this->title; // 현재 title에 할당된 메모리 반환
	
	int len = strlen(title);
	this->title = new char[len + 1]; // 새로운 매개변수 title에 대해 메모리 할당
	strcpy(this->title, title);
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; // 복사 생성자 호출됨
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}