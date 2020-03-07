/*	실습 9번 : Person.h , Person.cpp , main.cpp
	작성일 : 2019.09.26 ~ 09.27
	작성자 : 20165153 이재성
	프로그램 설명 : 이름과 전화번호를 입력받아 출력하고 검색하는 프로그램
*/	

class Person {		// Person 클래스, 실습문제에서 주어진 코드와 같다
	string name;	// 이름을 저장할 문자열 변수 name
	string tel;		// 전화번호를 저장할 문자열 변수 tel
public:
	Person();		// 생성자
	string getName();	// 이름을 반환하는 getName 함수
	string getTel();	// 전화번호를 반환하는 getTel 함수
	void set(string name, string tel);	// 이름과 전화번호를 저장할 set 함수
	~Person();		// 소멸자
};