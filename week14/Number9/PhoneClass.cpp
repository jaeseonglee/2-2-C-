/*	실습 9번 : PhoneClass.cpp
	작성일 : 2019.11.28 ~ 12.02
	작성자 : 20165153 이재성
	프로그램 설명: 주어진 Phone 클래스를 가지고 객체를 입출력하는데 <<,>> 연산자를 작성한 프로그램
*/
#include <iostream>
#include <string>
using namespace std;

class Phone {		// 전화번호를 표현하는 클래스
	string name;
	string telnum;	// 전화번호에도 '-'가 들어가기 때문에 string
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend istream& operator >> (istream& ins, Phone& p);
	friend ostream& operator << (ostream& stream, Phone p);
};

istream& operator >> (istream& ins, Phone& p) {
	cout << "이름:";
	getline(ins, p.name);	// 한 줄을 입력받기 위해

	cout << "전화번호:";
	getline(ins, p.telnum);

	cout << "주소:";
	getline(ins, p.address);
	return ins;
}

ostream& operator << (ostream& stream, Phone p) {
	stream << "(" << p.name << "," << p.telnum << "," << p.address << ")";
	return stream;
}

int main() {
	Phone girl, boy;
	cin >> girl >> boy;		// 전화 번호르 키보드로부터 읽는다.
	cout << girl << endl << boy << endl;	// 전화번호를 출력한다.
}