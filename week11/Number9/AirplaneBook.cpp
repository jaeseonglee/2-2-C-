#include <iostream>
using namespace std;

#include "AirplaneBook.h"		// AirplaneBook ��������� include

Seat::Seat() { name = "---"; }	// Seat ������, �¼��� �̸��� �ʱ�ȭ�Ѵ�
string Seat::getName() { return name; }	// �̸��� �����Ѵ�
void Seat::setName(string name) { this->name = name; }	// �Ű������� ���� ������ name�� �ʱ�ȭ�Ѵ�

Schedule::Schedule() {	// Schedule ������
	seat = new Seat[8];	// 8���� Seat��ü�� ���� �Ҵ�
	timeBook = "00��";  // 00�÷� �ʱ�ȭ���ش�
}
Schedule::~Schedule() { delete[] seat; }	// �Ҹ���, �Ҵ���� seat�� ��ȯ�Ѵ� 
void Schedule::seatBook(int seatNum, string seatName) {	seat[seatNum-1].setName(seatName); }// �¼��� �����ϴ� seatBook �Լ�
void Schedule::setTimeBook(string timeBook) { this->timeBook = timeBook; } // �ð��븦 �����ϴ� seatTimeBook �Լ�
void Schedule::cancleSeat(int seatNum, string seatName) {	 // ������ ����ϴ� cancleSeat�Լ�
	if (seat[seatNum - 1].getName() != seatName) {		// ����� �̸��� �ٸ���
		cout << "����� �̸��� ����ġ, ���� ��� ����!" << endl;	// ���� ��ҿ� �����ߴٰ� ���
	}
	else {
		seat[seatNum - 1].setName("---");	// �ƴ϶�� ���������� ����Ѵ�
	}
}
void Schedule::showSchedule() {		// ���� �ð����� ������ ����ϴ� showSchedule �Լ� 
	cout << timeBook<<":\t";		// ���� �ð��� ���
	for (int i = 0; i < 8; i++) {	// �ݺ����� ����
		cout << seat[i].getName() << "\t";	// ������Ȳ�� ����Ѵ�
	}
	cout << endl;	// ����� ������ �ٹٲ�
}

AirlineBook::AirlineBook() { // AirlineBook ������
	schedule = new Schedule[3];		// 3���� Schedule ��ü�� �����Ҵ�
	schedule[0].setTimeBook("07��");// �Ҵ�� ������ schedule�� 
	schedule[1].setTimeBook("12��");// ������ �־��� �ð����
	schedule[2].setTimeBook("17��");// �ʱ�ȭ���ش�
}
AirlineBook::~AirlineBook() { delete[] schedule; } //  �Ҹ���, �Ҵ���� schedule�� ��ȯ
void AirlineBook::bookSystem() {	// ��ü ���� ���α׷��� bookSystem �Լ�
	int num = 0;				
	Console::welcome();			// ���α׷� ���� ��� 
	while (1) {			// ���ѹݺ���
		num = Console::menu();	// �޴� ���
		if (num == 1)		{ book();	}	// ��ȯ���� num���� ���� ����
		else if (num == 2)  { cancle(); }	// ���
		else if(num == 3)   { show(); 	}	// ����
		else if (num == 4)  {				// ����� �����Ѵ�
			Console::bye();		// ���ᰡ �ԷµǸ� ���α׷� ���Ḧ ����ϰ�
			break;				// �ݺ����� ����������
		}
	}
}
void AirlineBook::book() {	// �����ϴ� book�Լ�
	int index = 0;	
	int num = 0;
	string s = "";

	index = Console::selectTime(); // �ð��븦 �Է¹޴´�
	schedule[index - 1].showSchedule(); // �� �ð����� �������� ���
	
	num = Console::selectSeat();	// �¼� ��ȣ��
	s = Console::selectName();		// ������ �̸��� �Է¹ް�
	schedule[index - 1].seatBook(num,s);	// �����Ѵ�
}
void AirlineBook::cancle() {		// ������ ����ϴ� cancle �Լ�
	int index = 0;
	int num = 0;
	string s = "";

	index = Console::selectTime(); // �ð��븦 �Է¹޴´�
	schedule[index - 1].showSchedule(); // �� �ð����� �������� ���

	num = Console::selectSeat();	// �¼���ȣ��
	s = Console::selectName();		// ���� ����� �̸��� �Է¹ް�
	schedule[index - 1].cancleSeat(num, s);	// ��� ���θ� �����Ѵ�
}
void AirlineBook::show() {		// ���� ���� ��Ȳ�� �����ִ� show �Լ�
	schedule[0].showSchedule();
	schedule[1].showSchedule();
	schedule[2].showSchedule();
	cout << endl;		// ����� ������ �ٹٲ�
}

// ���α׷� ������ �˸��� welcome �Լ�
void Console::welcome() { cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****" << endl; }
int Console::menu() {	// �޴��� �����ִ� menu �Լ�
	int n;
	while (1) {			// ������ �޴��� �Էµ� ������ ���ѹݺ� 
		cout << endl << endl << "����:1, ���:2, ����:3, ������:4>> ";
		cin >> n;
		if (n == 1 || n == 2 || n == 3 || n == 4) { break; }	// �޴��߿� �ϳ��� �ԷµǸ� ����
		else { cout << "�־��� �޴����� �������ּ���" << endl; }
	}
	return n;	// �޴� ��ȣ ��ȯ
}
int Console::selectTime() {	// �ð��� �����϶���ϴ� selectTime �Լ�
	int n;
	while (1) {				// ������ �ð��� �Էµ� ������ ���ѹݺ� 
		cout << "07��:1, 12��:2, 17��:3>> ";
		cin >> n;
		if (n == 1 || n == 2 || n == 3) { break; }	// �ð��߿� �ϳ��� �ԷµǸ� ����
		else { cout << "�־��� �ð����� �������ּ���" << endl; }
	}
	return n;		// �ð� ��ȣ ��ȯ
}
int Console::selectSeat() {		// �¼��� �����϶���ϴ� selectSeat �Լ�
	int n;
	while (1) {					// ������ �¼���ȣ�� �Էµ� ������ ���ѹݺ� 
		cout << "�¼� ��ȣ>> ";
		cin >> n;
		if (n >= 1 && n <= 8) { break; }	// 1 ~ 8������ ��ȣ�� �ԷµǸ� ����
		else { cout << "1������ 8�� �¼� �߿��� �������ּ���" << endl; }
	}
	return n;		// �¼� ��ȣ ��ȯ
}
string Console::selectName() {	// �̸��� �Է¹޴� selectName �Լ�
	string s;
	cout << "�̸� �Է�>> ";
	cin >> s;		// �Է¹��� ����
	return s;		// ��ȯ���ش�
}
// ���α׷� ���Ḧ �˸��� bye �Լ�
void Console::bye() { cout << "���� �ý����� �����մϴ�." << endl; }