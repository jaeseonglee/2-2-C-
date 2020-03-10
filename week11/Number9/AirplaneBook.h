/*	�ǽ� 9�� : AirplaneBook.h, AirplaneBook.cpp, main.cpp
	�ۼ��� : 2019.11.09 ~ 11.11
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ���� ���� ���� ������ ����� �ʿ����. ����� ���� ���α׷����� �ۼ���
		�� ���α׷��� �ʿ��� Ŭ������ AirlineBook, Schedule, Seat�� 3���̸�, main�Լ��� ������ cpp���Ͽ� �ۼ��Ѵ�
		���� ����� �Է��� �����ϴ� Console Ŭ������ �ۼ��Ѵ�
		AirlineBook Ŭ���� :  Schedule ��ü 3�� ����. ���� �ý��� �۵�
		Schedule Ŭ���� : �ϳ��� �������� �����ϴ� Ŭ����, 8���� Seat ��ü ����, Seat ��ü�� ����,���,���� �� ����
		Seat Ŭ���� : �ϳ��� �¼��� �����ϴ� Ŭ����, ������ �̸� ����, �¼��� ���� ����, �ּ�,���� �� ����
		Console Ŭ���� : �޴��� ����ϴ� �Լ�,����ڷκ��� �޴� ����, ���� �ð�, ����� �̸�, �¼� ��ȣ ����
		�Է¹޴� ��� �Լ����� ����,������� static���� �ۼ��ϴ� ���� ����
*/
class Seat {		// �ϳ��� �¼� ������ ���� Seat Ŭ����
	string name;	// �¼��� ������ ����� �̸�
public:
	Seat();			// ������
	string getName(); // �̸��� ��ȯ�ϴ� getName �Լ�
	void setName(string name);	// �̸��� �����ϴ� setName �Լ�
};

class Schedule {	// ������ �ð����� �¼������� Ȯ���ϴ� Schedule Ŭ����
	Seat *seat;		// Seat ��ü ������ ����
	string timeBook;// ������ �ð���
public:
	Schedule();		// ������
	~Schedule();	// �Ҹ���
	void seatBook(int seatNum, string seatName); // �¼��� �����ϴ� seatBook �Լ�
	void setTimeBook(string timeBook);			 // �ð��븦 �����ϴ� seatTimeBook �Լ�
	void cancleSeat(int seatNum, string seatName);	// ������ ����ϴ� cancleSeat�Լ�
	void showSchedule();						 // ���� �ð����� ������ ����ϴ� showSchedule �Լ� 
};

class AirlineBook {		// ����� ���� ���α׷��� �����ϴ� AirlineBook �Լ�
	Schedule *schedule;	// Schedule ��ü ������ ����
public:
	AirlineBook();		// ������
	~AirlineBook();		// �Ҹ���
	void bookSystem();	// ���� ���α׷��� �����ϴ� bookSystem �Լ�
	void book();		// �����ϴ� book�Լ�
	void cancle();		// ������ ����ϴ� cancle �Լ�
	void show();		// ���� ���� ��Ȳ�� �����ִ� show �Լ�
};

class Console {				// ���â������ ����� ����ϴ� Console Ŭ���� 
public:
	static void welcome();	// ���α׷� ������ �˸��� welcome �Լ�
	static int menu();		// �޴��� �����ִ� menu �Լ�
	static int selectTime();// �ð��� �����϶���ϴ� selectTime �Լ�
	static int selectSeat();// �¼��� �����϶���ϴ� selectSeat �Լ�
	static string selectName();// �̸��� �Է¹޴� selectName �Լ�
	static void bye();		// ���α׷� ���Ḧ �˸��� bye �Լ�
};