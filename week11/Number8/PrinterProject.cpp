/*	�ǽ� 8�� : PrinterProject.cpp
	�ۼ��� : 2019.11.06 ~ 11.10
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �������� ��ӱ����� ������ PrinterProject ���α׷�
*/
#include <iostream>
using namespace std;

class Printer {				// �������� �⺻ ������ ������ Printer Ŭ����
	string model;			// �𵨸�
	string manufacturer;	// ������
	int printedCount;		// �μ� �ż�
	int availableCount;		// �μ� ���� �ܷ�
	string continueString;	// ����Ʈ ���� ���θ� �����ϴ� ����
protected:					// �Ļ�Ŭ�������� ���� ������ protected
	Printer(string model, string manufacturer, int availableCount);	// ������, �Ļ�Ŭ������ �����ں��� ���� ����ȴ�
	//~Printer();			// �Ҹ���, �Ļ�Ŭ������ �Ҹ��ڰ� ����ǰ� ����ȴ�
	void ptint(int pages);	// �������� ����� �ϴ� print �Լ�
	void show();			// �⺻������ ����ϴ� show �Լ�
public:						// ����Ʈ ���࿩�θ� main�Լ����� �����ϱ� ���� public���� ����
	bool continuePrint();	// ����Ʈ ���࿩�θ� �����ϴ� continuePrint �Լ�
};

Printer::Printer(string model, string manufacturer, int availableCount) {	// ������
	this->model = model;
	this->manufacturer = manufacturer;		// �Ű������� ���� ����� ����
	this->printedCount = 0;					// �μ� �ż��� 0���� ����
	this->availableCount = availableCount;
}

void Printer::show() {		// ���� �������� ������ ����ϴ� show �Լ�
	cout << model << " ," << manufacturer << " ,���� ���� " << availableCount << "�� ,";
}

void Printer::ptint(int pages) {	// ����� �����ϴ� print �Լ�
	if (availableCount < pages) {	// ���� �������� �� ���� ���̸� ����Ϸ� �ϸ�
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;	// ������ �����ϴٰ� ���
	}
	else {
		cout << "����Ʈ�Ͽ����ϴ�." << endl;	// ����� �����Կ� ����
		printedCount += pages;		// �μ� ���̿�
		availableCount -= pages;	// ���� ������ �ż��� ����
	}
}

bool Printer::continuePrint() {	// ��� ���θ� �����ϴ� continuePrint�Լ�
	while (1) {					// ���� ���θ� ���� ���� ���� �ݺ�
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> continueString;		
		if (continueString == "y") { // ����� �����Կ� ����
			cout << endl;
			return false;		// false ��ȯ
		}
		else if (continueString == "n") {	// ����� ���� ������
			return true;		// true ��ȯ
		}
		else {			// y,n�� �ƴϸ�
			cout << "(y/n) �߿� �Է����ּ���" << endl; // �ٽ� �Է��ش޶�� ���
		}
	}
}


class InkJetPrinter : virtual public Printer {		// InkJetPrinter Ŭ����, Printer Ŭ������ ��ӹް� ��ȣ�� ������ ���� virtual Ű���� ���
	int availableInk;	// ��ũ �ܷ�
public:
	InkJetPrinter(string model, string manufacturer,int availableCount, int ink) : Printer(model, manufacturer,availableCount) {
		this->availableInk = ink;				// ������, �Է¹��� �Ű������� Printer Ŭ������ �������ְ� ink�� ���� �ʱ�ȭ���ش�
	}
	void inkShow();					// ��ũ�� �������� ������ ����ϴ� inkShow �Լ�
	void printInkJet(int pages);	// ��ũ �������� ����� �����ϴ� printInkJet �Լ�
};

void InkJetPrinter::inkShow() {		// ��ũ�� �������� ������ ����ϴ� inkShow �Լ�
	show();			// �⺻ Ŭ������ show ȣ��
	cout << "���� ��ũ " << availableInk << endl; // ���� ��ũ���� ���
}

void InkJetPrinter::printInkJet(int pages) {	// ��ũ �������� ����� �����ϴ� printInkJet �Լ�
	if (availableInk < pages) {				// ��ũ �ܷ����� ���� ���̸� ����Ϸ��ϸ�
		cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;	// ��ũ�������� ��ºҰ�
	}
	else {
		ptint(pages);	// �⺻ Ŭ������ print ȣ��
		availableInk -= pages;	// ���� ��ũ���� ����
	}
}


class LaserPrinter : virtual public Printer {	// LaserPrinter Ŭ����, Printer Ŭ������ ��ӹް� ��ȣ�� ������ ���� virtual Ű���� ���
	int availableToner;		// ��� �ܷ�
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int toner) : Printer(model, manufacturer, availableCount) {
		this->availableToner = toner;		// ������, �Է¹��� �Ű������� Printer Ŭ������ �������ְ� toner�� ���� �ʱ�ȭ���ش�
	}
	void laserShow();				// ������ �������� ������ ����ϴ� laserShow �Լ�
	void printLaser(int pages);		// ������ �������� ����� �����ϴ� printLaser �Լ�
};

void LaserPrinter::laserShow() {	// ������ �������� ������ ����ϴ� laserShow �Լ�
	show();				// �⺻ Ŭ������ show ȣ��
	cout << "���� ��� " << availableToner << endl;	// ���� ��ʷ��� ���
}

void LaserPrinter::printLaser(int pages) {		// ������ �������� ����� �����ϴ� printLaser �Լ�
	if (availableToner < pages) {		// ��� �ܷ����� ���� ���̸� ����Ϸ��ϸ�
		cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;	// ��ʺ������� ��ºҰ�
	}
	else {
		ptint(pages);		// �⺻ Ŭ������ print ȣ��
		availableToner -= pages;	// ���� ��ʸ� ����
	}
}

int main() {		// main �Լ�
	int form = 0;	// � �����͸� �������� �����ϴ� form ����
	int num = 0;	// ������ ������� �����ϴ� num ����
	InkJetPrinter* inkJet = new InkJetPrinter("OfficeJet V40", "HP", 5, 10);	// ��ũ�� �����͸� ���� ����
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);		// ������ �����͸� ���� ����

	cout << "���� �۵����� 2 ���� ����Ʈ�� �Ʒ��� ����" << endl;		// ���� �۵����� �� �������� ������ ���
	cout << "��ũ�� : ";		inkJet->inkShow();		// �� ��ü�� ������ ���
	cout << "������ : ";		laser->laserShow();
	cout << endl;

	while (1) {		// ���ѹݺ���
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>"; // �����Ϳ� �μ� �ż� ����
		cin >> form >> num;		// �Է¹��� ���� ������ ����

		if (form == 1) {		// ��ũ�� ������ ����
			inkJet->printInkJet(num);	// ��ũ�� ������ ��� ���� Ȯ��
		}
		else if (form == 2) {	// ������ ������ ����
			laser->printLaser(num);		// ������ ������ ��� ���� Ȯ��
		}
		else {	// �� �����Ͱ� �ƴ� �ٸ� ���̸�
			cout << "�� ������ �߿� �������ּ���!!" << endl;
			continue;	// �ݺ��� �ٽ� ����
		}

		inkJet->inkShow();	// ��� ���� Ȯ�� ���Ŀ� �� ��ü�� ���� Ȯ��
		laser->laserShow();

		if (inkJet->continuePrint()) break;		// ����� ������ ���� Ȯ��
	}

	delete inkJet;	// ���ѹݺ��� ���Ŀ�
	delete laser;	// �� ��ü�� ��ȯ���ش�
}