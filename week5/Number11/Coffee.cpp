/*	�ǽ� 11�� : Coffee.cpp
	�ۼ��� : 2019.09.28
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : �ǽ��������� �־��� �� Ŭ������ ������ ��°���� ���� �������� �ڵ带 �ϼ��ϴ� �ǽ�
					Ŀ�����Ǳ⸦ �����ϴ� ���α׷�, �ֹ��� ���� Ŀ�Ǹ� ����ϰ� �ܷ�Ȯ�ΰ� �ܷ� ä������ �����Ѵ� 
					�ܷ��� ������� ����������� ����ϴ� ���� �ݺ����� ���α׷�
*/

#include <iostream>
using namespace std;

class Container {		// �� �ϳ��� ��Ÿ���� Ŭ����
	int size;			// ���� ���差, �ִ� ���差�� 10
public:
	Container() { size = 10; }		// �⺻ ������, size�� 10���� �ʱ�ȭ
	~Container() {  }				// �Ҹ���
	void fill() { size = 10; }		// �ִ뷮(10)���� ä���
	void consume() { size--; }		// 1��ŭ �Ҹ��ϱ�
	int getSize() { return size; }		// ���� ũ�� ����
	
};

class CoffeeVendingMachine {	// Ŀ�����Ǳ⸦ ǥ���ϴ� Ŭ����
	Container tong[3];			// tong[0]�� Ŀ��, tong[1]�� ��, tong[2]�� �������� ��Ÿ��
	void fill();				// 3���� ���� ��� 10���� ä��
	void selectEspresso();		// ���������Ҹ� ������ ���, Ŀ�� 1, �� 1 �Ҹ�
	void selectAmericano();		// �Ƹ޸�ī�븦 ������ ���, Ŀ�� 1, �� 2 �Ҹ�
	void selectSugarCoffee();	// ����Ŀ�Ǹ� ������ ���, Ŀ�� 1, �� 2 �Ҹ�, ���� 1 �Ҹ�
	void show();				// ���� Ŀ��, ��, ������ �ܷ� ���
	int countTong();			// �ܷ��� ������ ���ᰡ �����ϴٰ� ����ϴ� countTong �Լ�
public:
 	void run();		// Ŀ�� ���Ǳ� �۵�
};

void CoffeeVendingMachine::fill() {	// ���Ḧ ä��� fill�Լ�
	for (int i = 0; i < 3; i++) {	// �ݺ����� ���� ��ü�迭���� fill(Container�� �Լ�) �Լ��� ����
		tong[i].fill();				// tong�� size�� 10���� ä���ش�
	}	
	show();					// ä��� ���� �ܷ��� ���
}

void CoffeeVendingMachine::selectEspresso() {// ���������Ҹ� ����ϴ� selectEspersso �Լ�
	cout << "���������� �弼��" << endl;		 // ���������Ҹ� ����ϰ�
	tong[0].consume();		// ���� Ŀ�� 1�� �� 1�� �Ҹ�
	tong[1].consume();
}

void CoffeeVendingMachine::selectAmericano() {// �Ƹ޸�ī�븦 ����ϴ� selectAmericano �Լ�
	cout << "�Ƹ޸�ī�� �弼��" << endl;		// �Ƹ޸�ī�븦 ����ϰ�
	tong[0].consume();		// ���� Ŀ�� 1��
	tong[1].consume();		// �� 2�� �Ҹ�
	tong[1].consume();
}

void CoffeeVendingMachine::selectSugarCoffee() {// ����Ŀ�Ǹ� ����ϴ� selectSugarCoffee �Լ�
	cout << "����Ŀ�� �弼��" << endl;		// ����Ŀ�Ǹ� ����ϰ�
	tong[0].consume();		// ���� Ŀ�� 1
	tong[1].consume();		// �� 2
	tong[1].consume();
	tong[2].consume();		// ���� 1�� �Ҹ�
}

void CoffeeVendingMachine::show() {	// getSize�� ���� ������ �ܷ��� ����ϴ� show�Լ�
	cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl;
}

int CoffeeVendingMachine::countTong() {	// ���� tong�� �ܷ��� �ϳ��� ������ ��������� ����ϴ� countTong �Լ�
	for(int i = 0; i < 3; i++ ) {		// �ݺ����� ����
		if (tong[i].getSize() == 0) {	// size�� 0���� Ȯ��
			cout << "���ᰡ �����մϴ�" << endl;	// ���ᰡ �����ϴٰ� ���
			return 1;		// 1(ture) �� ����
		}
	}
	return 0;		// ���ᰡ ���������� 0(false)�� ����
}

void CoffeeVendingMachine::run(){	// Ŀ�����Ǳ⸦ �۵��ϴ� run�Լ�
	int num = 0;					// � ����� ���������� ������ ������ ���� num�� 0���� �ʱ�ȭ
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;	// Ŀ�����Ǳ⸦ �۵��Ѵٰ� ���
	
	while (true){		// ���� �ݺ��� , ���� ������ ���� �������� �ʾҴ�
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ�� 4:�ܷ�����, 5:ä���)>> ";
		cin >> num;		// �Է¹��� ���ڸ� num�� ����
		
		switch (num){	// �Է¹��� num�� ���� switch������ Ŀ�����Ǳ⸦ ����
		case 1:
			if (countTong()) { break; }	// �ܷ��� ������ ���� ������ ���
			selectEspresso();		// ���������� ���
			break;
		case 2:
			if (countTong()) { break; }	// �ܷ��� ������ ���� ������ ��� 
			else if (tong[2].getSize() == 1) {	// �׸��� �Ƹ޸�ī���� ��� ���� 1�� ��쿡�� ��������̹Ƿ�
				cout << "���ᰡ �����մϴ�" << endl;	// ���� ������ ����ϰ� 
				break;			// break ����
			}
			selectAmericano();		// �Ƹ޸�ī�� ���
			break;		
		case 3:
			if (countTong()) { break; }		// �ܷ��� ������ ���� ������ ��� 
			else if (tong[2].getSize() == 1) {	// �׸��� ����Ŀ���� ��� ���� 1�� ��쿡�� ��������̹Ƿ�
				cout << "���ᰡ �����մϴ�" << endl;	// ���� ������ ����ϰ� 
				break;			// break ����
			}
			selectSugarCoffee(); // ����Ŀ�� ���
			break;
		case 4:
			show();		// ���� ������� �ܷ� ���
			break;
		case 5:
			fill();		// ������� �ִ�� ä���ش�
			break;
		default:		// �ٸ� ���ڸ� �Է��ϸ� �ٽ� �Է��ش޶�� ���
			cout << "1���� 5�� ������ ��ȣ�� �Է����ּ���" << endl;
			break;
		}
	}	
}

int main() {		// main �Լ�
	CoffeeVendingMachine cvm;	// ��ü�� �����ϰ�
	cvm.run();					// �� ������ �������� �۵��� �ϴ� run�Լ�ȣ��� Ŀ�����Ǳ� �۵�
}