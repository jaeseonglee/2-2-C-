#include <iostream>
using namespace std;

#include "AirplaneBook.h"		// AirplaneBook 헤더파일을 include

Seat::Seat() { name = "---"; }	// Seat 생성자, 좌석의 이름을 초기화한다
string Seat::getName() { return name; }	// 이름을 리턴한다
void Seat::setName(string name) { this->name = name; }	// 매개변수로 받은 값으로 name을 초기화한다

Schedule::Schedule() {	// Schedule 생성자
	seat = new Seat[8];	// 8개의 Seat객체를 동적 할당
	timeBook = "00시";  // 00시로 초기화해준다
}
Schedule::~Schedule() { delete[] seat; }	// 소멸자, 할당받은 seat를 반환한다 
void Schedule::seatBook(int seatNum, string seatName) {	seat[seatNum-1].setName(seatName); }// 좌석을 예약하는 seatBook 함수
void Schedule::setTimeBook(string timeBook) { this->timeBook = timeBook; } // 시간대를 저장하는 seatTimeBook 함수
void Schedule::cancleSeat(int seatNum, string seatName) {	 // 예약을 취소하는 cancleSeat함수
	if (seat[seatNum - 1].getName() != seatName) {		// 예약된 이름과 다르면
		cout << "예약된 이름과 불일치, 예약 취소 실패!" << endl;	// 예약 취소에 실패했다고 출력
	}
	else {
		seat[seatNum - 1].setName("---");	// 아니라면 정상적으로 취소한다
	}
}
void Schedule::showSchedule() {		// 현재 시간대의 예약을 출력하는 showSchedule 함수 
	cout << timeBook<<":\t";		// 현재 시간대 출력
	for (int i = 0; i < 8; i++) {	// 반복문을 통해
		cout << seat[i].getName() << "\t";	// 예약현황을 출력한다
	}
	cout << endl;	// 출력이 끝나면 줄바꿈
}

AirlineBook::AirlineBook() { // AirlineBook 생성자
	schedule = new Schedule[3];		// 3개의 Schedule 객체를 동적할당
	schedule[0].setTimeBook("07시");// 할당된 각각의 schedule의 
	schedule[1].setTimeBook("12시");// 각각의 주어진 시간대로
	schedule[2].setTimeBook("17시");// 초기화해준다
}
AirlineBook::~AirlineBook() { delete[] schedule; } //  소멸자, 할당받은 schedule을 반환
void AirlineBook::bookSystem() {	// 전체 예약 프로그램을 bookSystem 함수
	int num = 0;				
	Console::welcome();			// 프로그램 시작 출력 
	while (1) {			// 무한반복문
		num = Console::menu();	// 메뉴 출력
		if (num == 1)		{ book();	}	// 반환받은 num값에 따라 예약
		else if (num == 2)  { cancle(); }	// 취소
		else if(num == 3)   { show(); 	}	// 보기
		else if (num == 4)  {				// 종료로 진행한다
			Console::bye();		// 종료가 입력되면 프로그램 종료를 출력하고
			break;				// 반복문을 빠져나간다
		}
	}
}
void AirlineBook::book() {	// 예약하는 book함수
	int index = 0;	
	int num = 0;
	string s = "";

	index = Console::selectTime(); // 시간대를 입력받는다
	schedule[index - 1].showSchedule(); // 그 시간대의 스케쥴을 출력
	
	num = Console::selectSeat();	// 좌석 번호와
	s = Console::selectName();		// 예약자 이름을 입력받고
	schedule[index - 1].seatBook(num,s);	// 예약한다
}
void AirlineBook::cancle() {		// 예약을 취소하는 cancle 함수
	int index = 0;
	int num = 0;
	string s = "";

	index = Console::selectTime(); // 시간대를 입력받는다
	schedule[index - 1].showSchedule(); // 그 시간대의 스케쥴을 출력

	num = Console::selectSeat();	// 좌석번호와
	s = Console::selectName();		// 예약 취소자 이름을 입력받고
	schedule[index - 1].cancleSeat(num, s);	// 취소 여부를 결정한다
}
void AirlineBook::show() {		// 현재 예약 상황을 보여주는 show 함수
	schedule[0].showSchedule();
	schedule[1].showSchedule();
	schedule[2].showSchedule();
	cout << endl;		// 출력이 끝나면 줄바꿈
}

// 프로그램 시작을 알리는 welcome 함수
void Console::welcome() { cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl; }
int Console::menu() {	// 메뉴를 보여주는 menu 함수
	int n;
	while (1) {			// 지정된 메뉴가 입력될 때까지 무한반복 
		cout << endl << endl << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
		cin >> n;
		if (n == 1 || n == 2 || n == 3 || n == 4) { break; }	// 메뉴중에 하나가 입력되면 종료
		else { cout << "주어진 메뉴에서 선택해주세요" << endl; }
	}
	return n;	// 메뉴 번호 반환
}
int Console::selectTime() {	// 시간을 선택하라고하는 selectTime 함수
	int n;
	while (1) {				// 지정된 시간이 입력될 때까지 무한반복 
		cout << "07시:1, 12시:2, 17시:3>> ";
		cin >> n;
		if (n == 1 || n == 2 || n == 3) { break; }	// 시간중에 하나가 입력되면 종료
		else { cout << "주어진 시간에서 선택해주세요" << endl; }
	}
	return n;		// 시간 번호 반환
}
int Console::selectSeat() {		// 좌석을 선택하라고하는 selectSeat 함수
	int n;
	while (1) {					// 지정된 좌석번호가 입력될 때까지 무한반복 
		cout << "좌석 번호>> ";
		cin >> n;
		if (n >= 1 && n <= 8) { break; }	// 1 ~ 8사이의 번호가 입력되면 종료
		else { cout << "1번부터 8번 좌석 중에서 선택해주세요" << endl; }
	}
	return n;		// 좌석 번호 반환
}
string Console::selectName() {	// 이름을 입력받는 selectName 함수
	string s;
	cout << "이름 입력>> ";
	cin >> s;		// 입력받은 값을
	return s;		// 반환해준다
}
// 프로그램 종료를 알리는 bye 함수
void Console::bye() { cout << "예약 시스템을 종료합니다." << endl; }