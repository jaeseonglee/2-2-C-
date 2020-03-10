/*	�ǽ� 9�� : PrinterProject.cpp
	�ۼ��� : 2019.11.18 ~ 11.19
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �������� ��ӱ����� ������ PrinterProject ���α׷�. 11������ ���α׷����� �޸� �Լ� �������̵��� �Ἥ �ۼ�
*/

#include <iostream>
using namespace std;

class Printer {				// �������� �⺻ ������ ������ Printer Ŭ����
protected:					// �Ļ�Ŭ�������� ���� ������ protected
	string model;			// �𵨸�
	string manufacturer;	// ������
	string continueString;	// ����Ʈ ���� ���θ� �����ϴ� ����
	int printedCount;		// �μ� �ż�
	int availableCount;		// �μ� ���� �ܷ�
	Printer(string model, string manufacturer, int availableCount);	// ������, �Ļ�Ŭ������ �����ں��� ���� ����ȴ�
	virtual void print(int pages) = 0; 	// �������� ����� �ϴ� print �Լ�
	virtual void show() = 0;			// �⺻������ ����ϴ� show �Լ�
public:						// ����Ʈ ���࿩�θ� main�Լ����� �����ϱ� ���� public���� ����
	bool continuePrint();	// ����Ʈ ���࿩�θ� �����ϴ� continuePrint �Լ�
};

Printer::Printer(string model, string manufacturer, int availableCount) {	// ������
	this->model = model;
	this->manufacturer = manufacturer;		// �Ű������� ���� ����� ����
	this->printedCount = 0;					// �μ� �ż��� 0���� ����
	this->availableCount = availableCount;
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

class InkJetPrinter : public Printer {		// InkJetPrinter Ŭ����, Printer Ŭ������ ��ӹް� ��ȣ�� ������ ���� virtual Ű���� ���
	int availableInk;	// ��ũ �ܷ�
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int ink) : Printer(model, manufacturer, availableCount) {
		this->availableInk = ink;				// ������, �Է¹��� �Ű������� Printer Ŭ������ �������ְ� ink�� ���� �ʱ�ȭ���ش�
	}
	virtual void print(int pages);
	virtual void show();
};

void InkJetPrinter::print(int pages) {
	if (availableCount < pages) {	// ���� �������� �� ���� ���̸� ����Ϸ� �ϸ�
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;	// ������ �����ϴٰ� ���
	}else if (availableInk < pages) {				// ��ũ �ܷ����� ���� ���̸� ����Ϸ��ϸ�
		cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;	// ��ũ�������� ��ºҰ�
	}
	else {
		cout << "����Ʈ�Ͽ����ϴ�." << endl;	// ����� �����Կ� ����
		printedCount += pages;		// �μ� ���̿�
		availableCount -= pages;	// ���� ������ �ż��� ����
		availableInk -= pages;	// ���� ��ũ���� ����
	}
}

void InkJetPrinter::show() {// ���� �������� ������ ����ϴ� show �Լ�
	cout << model << " ," << manufacturer << " ,���� ���� " << availableCount << "�� ,���� ��ũ " << availableInk << endl;
}

class LaserPrinter : public Printer {	// LaserPrinter Ŭ����, Printer Ŭ������ ��ӹް� ��ȣ�� ������ ���� virtual Ű���� ���
	int availableToner;		// ��� �ܷ�
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int toner) : Printer(model, manufacturer, availableCount) {
		this->availableToner = toner;		// ������, �Է¹��� �Ű������� Printer Ŭ������ �������ְ� toner�� ���� �ʱ�ȭ���ش�
	}
	virtual void print(int pages);
	virtual void show();
};

void LaserPrinter::print(int pages) {	
	if (availableCount < pages) {	// ���� �������� �� ���� ���̸� ����Ϸ� �ϸ�
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;	// ������ �����ϴٰ� ���
	}
	else if (availableToner < pages) {		// ��� �ܷ����� ���� ���̸� ����Ϸ��ϸ�
		cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�" << endl;	// ��ʺ������� ��ºҰ�
	}
	else {
		cout << "����Ʈ�Ͽ����ϴ�." << endl;	// ����� �����Կ� ����
		printedCount += pages;		// �μ� ���̿�
		availableCount -= pages;	// ���� ������ �ż��� ����
		availableToner = availableToner - (int)(pages/2);	// ���� ��ʸ� ���� // 11�����ʹ� �޸� 2��� ��� �ϳ��� ���
	}
}

void LaserPrinter::show() {// ���� �������� ������ ����ϴ� show �Լ�
	cout << model << " ," << manufacturer << " ,���� ���� " << availableCount << "�� ,���� ��� " << availableToner << endl;
}

int main() {		// main �Լ�
	int form = 0;	// � �����͸� �������� �����ϴ� form ����
	int num = 0;	// ������ ������� �����ϴ� num ����
	InkJetPrinter* inkJet = new InkJetPrinter("OfficeJet V40", "HP", 5, 10);	// ��ũ�� �����͸� ���� ����
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);		// ������ �����͸� ���� ����

	cout << "���� �۵����� 2 ���� ����Ʈ�� �Ʒ��� ����" << endl;		// ���� �۵����� �� �������� ������ ���
	cout << "��ũ�� : ";		inkJet->show();		// �� ��ü�� ������ ���
	cout << "������ : ";		laser->show();
	cout << endl;

	while (1) {		// ���ѹݺ���
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>"; // �����Ϳ� �μ� �ż� ����
		cin >> form >> num;		// �Է¹��� ���� ������ ����

		if (form == 1) {		// ��ũ�� ������ ����
			inkJet->print(num);	// ��ũ�� ������ ��� ���� Ȯ��
		}
		else if (form == 2) {	// ������ ������ ����
			laser->print(num);		// ������ ������ ��� ���� Ȯ��
		}
		else {	// �� �����Ͱ� �ƴ� �ٸ� ���̸�
			cout << "�� ������ �߿� �������ּ���!!" << endl;
			continue;	// �ݺ��� �ٽ� ����
		}

		inkJet->show();	// ��� ���� Ȯ�� ���Ŀ� �� ��ü�� ���� Ȯ��
		laser->show();

		if (inkJet->continuePrint()) break;		// ����� ������ ���� Ȯ��
	}

	delete inkJet;	// ���ѹݺ��� ���Ŀ�
	delete laser;	// �� ��ü�� ��ȯ���ش�
}