/*	실습 9번 : AirplaneBook.h, AirplaneBook.cpp, main.cpp
	작성일 : 2019.11.09 ~ 11.11
	작성자 : 20165153 이재성
	프로그램 설명: 종합 응용 연습 문제로 상속이 필요없다. 비행기 예약 프로그램으로 작성됨
		이 프로그램에 필요한 클래스는 AirlineBook, Schedule, Seat의 3개이며, main함수는 별도의 cpp파일에 작성한다
		또한 사용자 입력을 전담하는 Console 클래스를 작성한다
		AirlineBook 클래스 :  Schedule 객체 3개 생성. 예약 시스템 작동
		Schedule 클래스 : 하나의 스케쥴을 구현하는 클래스, 8개의 Seat 객체 생성, Seat 객체에 예약,취소,보기 등 관리
		Seat 클래스 : 하나의 좌석을 구현하는 클래스, 예약자 이름 저장, 좌석에 대한 예약, 최소,보기 등 관리
		Console 클래스 : 메뉴를 출력하는 함수,사용자로부터 메뉴 선택, 비행 시간, 사용자 이름, 좌석 번호 등을
		입력받는 멤버 함수들을 구현,멤버들은 static으로 작성하는 것이 좋다
*/
class Seat {		// 하나의 좌석 정보를 갖는 Seat 클래스
	string name;	// 좌석에 예약한 사람의 이름
public:
	Seat();			// 생성자
	string getName(); // 이름을 반환하는 getName 함수
	void setName(string name);	// 이름을 저장하는 setName 함수
};

class Schedule {	// 지정된 시간대의 좌석예약을 확인하는 Schedule 클래스
	Seat *seat;		// Seat 객체 포인터 생성
	string timeBook;// 지정된 시간대
public:
	Schedule();		// 생성자
	~Schedule();	// 소멸자
	void seatBook(int seatNum, string seatName); // 좌석을 예약하는 seatBook 함수
	void setTimeBook(string timeBook);			 // 시간대를 저장하는 seatTimeBook 함수
	void cancleSeat(int seatNum, string seatName);	// 예약을 취소하는 cancleSeat함수
	void showSchedule();						 // 현재 시간대의 예약을 출력하는 showSchedule 함수 
};

class AirlineBook {		// 비행기 예약 프로그램을 진행하는 AirlineBook 함수
	Schedule *schedule;	// Schedule 객체 포인터 생성
public:
	AirlineBook();		// 생성자
	~AirlineBook();		// 소멸자
	void bookSystem();	// 예약 프로그램을 진행하는 bookSystem 함수
	void book();		// 예약하는 book함수
	void cancle();		// 예약을 취소하는 cancle 함수
	void show();		// 현재 예약 상황을 보여주는 show 함수
};

class Console {				// 출력창에서의 출력을 담당하는 Console 클래스 
public:
	static void welcome();	// 프로그램 시작을 알리는 welcome 함수
	static int menu();		// 메뉴를 보여주는 menu 함수
	static int selectTime();// 시간을 선택하라고하는 selectTime 함수
	static int selectSeat();// 좌석을 선택하라고하는 selectSeat 함수
	static string selectName();// 이름을 입력받는 selectName 함수
	static void bye();		// 프로그램 종료를 알리는 bye 함수
};