/*	실습 8번 : PrinterProject.cpp
	작성일 : 2019.11.06 ~ 11.10
	작성자 : 20165153 이재성
	프로그램 설명: 프린터의 상속구조를 구현한 PrinterProject 프로그램
*/
#include <iostream>
using namespace std;

class Printer {				// 프린터의 기본 정보를 가지는 Printer 클래스
	string model;			// 모델명
	string manufacturer;	// 제조사
	int printedCount;		// 인쇄 매수
	int availableCount;		// 인쇄 종이 잔량
	string continueString;	// 프린트 진행 여부를 저장하는 변수
protected:					// 파생클래스까지 접근 가능한 protected
	Printer(string model, string manufacturer, int availableCount);	// 생성자, 파생클래스의 생성자보다 먼저 실행된다
	//~Printer();			// 소멸자, 파생클래스의 소멸자가 실행되고 실행된다
	void ptint(int pages);	// 프린터의 출력을 하는 print 함수
	void show();			// 기본정보를 출력하는 show 함수
public:						// 프린트 진행여부를 main함수에서 진행하기 위해 public으로 선언
	bool continuePrint();	// 프린트 진행여부를 결정하는 continuePrint 함수
};

Printer::Printer(string model, string manufacturer, int availableCount) {	// 생성자
	this->model = model;
	this->manufacturer = manufacturer;		// 매개변수로 받은 값들로 저장
	this->printedCount = 0;					// 인쇄 매수는 0으로 저장
	this->availableCount = availableCount;
}

void Printer::show() {		// 현재 프린터의 정보를 출력하는 show 함수
	cout << model << " ," << manufacturer << " ,남은 종이 " << availableCount << "장 ,";
}

void Printer::ptint(int pages) {	// 출력을 진행하는 print 함수
	if (availableCount < pages) {	// 남은 용지보다 더 많은 종이를 출력하려 하면
		cout << "용지가 부족하여 프린트할 수 없습니다" << endl;	// 용지가 부족하다고 출력
	}
	else {
		cout << "프린트하였습니다." << endl;	// 출력을 진행함에 따라
		printedCount += pages;		// 인쇄 종이와
		availableCount -= pages;	// 남은 종이의 매수를 변경
	}
}

bool Printer::continuePrint() {	// 출력 여부를 진행하는 continuePrint함수
	while (1) {					// 진행 여부를 묻기 위해 무한 반복
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> continueString;		
		if (continueString == "y") { // 출력을 진행함에 따라
			cout << endl;
			return false;		// false 반환
		}
		else if (continueString == "n") {	// 출력을 하지 않으면
			return true;		// true 반환
		}
		else {			// y,n가 아니면
			cout << "(y/n) 중에 입력해주세요" << endl; // 다시 입력해달라고 출력
		}
	}
}


class InkJetPrinter : virtual public Printer {		// InkJetPrinter 클래스, Printer 클래스를 상속받고 모호성 방지를 위해 virtual 키워드 사용
	int availableInk;	// 잉크 잔량
public:
	InkJetPrinter(string model, string manufacturer,int availableCount, int ink) : Printer(model, manufacturer,availableCount) {
		this->availableInk = ink;				// 생성자, 입력받은 매개변수를 Printer 클래스에 전달해주고 ink의 값을 초기화해준다
	}
	void inkShow();					// 잉크젯 프린터의 정보를 출력하는 inkShow 함수
	void printInkJet(int pages);	// 잉크 프린터의 출력을 진행하는 printInkJet 함수
};

void InkJetPrinter::inkShow() {		// 잉크젯 프린터의 정보를 출력하는 inkShow 함수
	show();			// 기본 클래스의 show 호출
	cout << "남은 잉크 " << availableInk << endl; // 남은 잉크량을 출력
}

void InkJetPrinter::printInkJet(int pages) {	// 잉크 프린터의 출력을 진행하는 printInkJet 함수
	if (availableInk < pages) {				// 잉크 잔량보다 많은 종이를 출력하려하면
		cout << "잉크가 부족하여 프린트할 수 없습니다" << endl;	// 잉크부족으로 출력불가
	}
	else {
		ptint(pages);	// 기본 클래스의 print 호출
		availableInk -= pages;	// 남은 잉크량을 변경
	}
}


class LaserPrinter : virtual public Printer {	// LaserPrinter 클래스, Printer 클래스를 상속받고 모호성 방지를 위해 virtual 키워드 사용
	int availableToner;		// 토너 잔량
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int toner) : Printer(model, manufacturer, availableCount) {
		this->availableToner = toner;		// 생성자, 입력받은 매개변수를 Printer 클래스에 전달해주고 toner의 값을 초기화해준다
	}
	void laserShow();				// 레이저 프린터의 정보를 출력하는 laserShow 함수
	void printLaser(int pages);		// 레이저 프린터의 출력을 진행하는 printLaser 함수
};

void LaserPrinter::laserShow() {	// 레이저 프린터의 정보를 출력하는 laserShow 함수
	show();				// 기본 클래스의 show 호출
	cout << "남은 토너 " << availableToner << endl;	// 남은 토너량을 출력
}

void LaserPrinter::printLaser(int pages) {		// 레이저 프린터의 출력을 진행하는 printLaser 함수
	if (availableToner < pages) {		// 토너 잔량보다 많은 종이를 출력하려하면
		cout << "토너가 부족하여 프린트할 수 없습니다" << endl;	// 토너부족으로 출력불가
	}
	else {
		ptint(pages);		// 기본 클래스의 print 호출
		availableToner -= pages;	// 남은 토너를 변경
	}
}

int main() {		// main 함수
	int form = 0;	// 어떤 프린터를 선택할지 저장하는 form 변수
	int num = 0;	// 몇장을 출력할지 저장하는 num 변수
	InkJetPrinter* inkJet = new InkJetPrinter("OfficeJet V40", "HP", 5, 10);	// 잉크젯 프린터를 동적 생성
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);		// 레이저 프린터를 동적 생성

	cout << "현재 작동중인 2 대의 프린트는 아래와 같다" << endl;		// 현재 작동중인 두 프린터의 정보를 출력
	cout << "잉크젯 : ";		inkJet->inkShow();		// 각 객체의 정보를 출력
	cout << "레이저 : ";		laser->laserShow();
	cout << endl;

	while (1) {		// 무한반복문
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>"; // 프린터와 인쇄 매수 선택
		cin >> form >> num;		// 입력받은 값을 변수에 저장

		if (form == 1) {		// 잉크젯 프린터 선택
			inkJet->printInkJet(num);	// 잉크젯 프린터 출력 여부 확인
		}
		else if (form == 2) {	// 레이저 프린터 선택
			laser->printLaser(num);		// 레이저 프린터 출력 여부 확인
		}
		else {	// 두 프린터가 아닌 다른 값이면
			cout << "두 프린터 중에 선택해주세요!!" << endl;
			continue;	// 반복문 다시 진행
		}

		inkJet->inkShow();	// 출력 여부 확인 이후에 두 객체의 정보 확인
		laser->laserShow();

		if (inkJet->continuePrint()) break;		// 출력을 더할지 말지 확인
	}

	delete inkJet;	// 무한반복문 이후에
	delete laser;	// 두 객체를 반환해준다
}