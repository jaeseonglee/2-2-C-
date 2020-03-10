/*	�ǽ� 12�� : CoffeeVendingMachine.cpp
	�ۼ��� : 2019.12.04 ~ 07
	�ۼ��� : 20165153 ���缺
	���α׷� ����: Ŀ�� ���Ǳ� �ùķ����͸� C++�� �ۼ��� ���α׷�. ���Ǳ�� ���� Ŀ��, ���� Ŀ��, �� Ŀ�� 3������ �Ǹ��Ѵ�.
*/
#include <iostream>
using namespace std;
#define SIZE 3			// define���� ���� SIZE�� 3���� ����

class CoffeeVendingMachine {	// CoffeeVendingMachine Ŭ����
	int* coffee = nullptr;		// Ŀ�� ���� ũ��
	int *sugar = nullptr;		// �� �ſ� ���� ������ ����
	int *cream = nullptr;
	int *water = nullptr;
	int *cup = nullptr;
public:
	CoffeeVendingMachine() {	// ������ 
		coffee = new int[SIZE];	// ��� ������
		sugar = new int[SIZE];	// �Ҵ����ְ�
		cream = new int[SIZE];
		water = new int[SIZE];
		cup = new int[SIZE];
		fill();					// fill �Լ��� ���� ��� ���� 1�� �ʱ�ȭ
		cout << "-----��ǰ Ŀ�� ���Ǳ��մϴ�.-----" << endl;
	}
	~CoffeeVendingMachine() {	// �Ҹ���
		delete[] coffee;		// �����ڿ��� �Ҵ��� �����͵���
		delete[] sugar;			// ��ȯ���ش�
		delete[] cream;
		delete[] water;
		delete[] cup;
		cout << "-----��ǰ Ŀ�� ���Ǳ���ϴ�.-----" << endl << "�̿����ּż� �����մϴ�." << endl;
	}
	void status();				// ���� ������ ���¸� ����ϴ� status �Լ�
	void fill();				// ������ ���� ä��� fill �Լ�
	void normalCoffee();		// ���� Ŀ�Ǹ� ����� normalCoffee �Լ�
	void sugarCoffee();			// ���� Ŀ�Ǹ� ����� sugarCoffee �Լ�
	void blackCoffee();			// �� Ŀ�Ǹ� ����� blackCoffee �Լ�
	void sell();				// Ŀ�� ���Ǳ� �Ǹű���� �ô� sell �Լ�
};	

void CoffeeVendingMachine::status() {	// ������ ���°� ���� �ٸ� �� �ֱ� ������ 
	cout << "Coffee\t";					// ���� ���� ������ �ݺ����� ���� ���� �� ���
	for (int i = 0; i < SIZE; i++) { 
		if(coffee[i] != 0)
			cout << "*"; 
	}
	
	cout << endl << "Sugar\t";
	for (int i = 0; i < SIZE; i++) {
		if (sugar[i] != 0)
			cout << "*";
	}

	cout << endl << "CREAM\t";
	for (int i = 0; i < SIZE; i++) {
		if (cream[i] != 0)
			cout << "*";
	}

	cout << endl << "Water\t";
	for (int i = 0; i < SIZE; i++) {
		if (water[i] != 0)
			cout << "*";
	}

	cout << endl << "Cup\t";
	for (int i = 0; i < SIZE; i++) {
		if (cup[i] != 0)
			cout << "*";
	}
	cout << endl << endl;
}

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < SIZE; i++) {	// �����ڿ��� �Ҵ�� �����Ϳ�
		coffee[i] = 1;		// ���� 1�� �ʱ�ȭ ���ش�
		sugar[i] = 1;
		cream[i] = 1;
		water[i] = 1;
		cup[i] = 1;
	}
}

void CoffeeVendingMachine::normalCoffee() {
	if (coffee[0] == 0 || water[0] == 0 || cup[0] == 0) {	// ��ᰡ �ϳ��� �����ϸ�
		cout << "��ᰡ �����մϴ�!! ���Ƿ� ��� ���� ä��ϴ�. ~~ �ٽ� �������ּ���" << endl;
		fill();		// ���Ƿ� ä���ְ�
		return;		// �Լ� ����
	}

	for (int i = SIZE - 1; i >= 0; i--) {	// ���� ���ǹ��� �����Ŀ��� �� ������ �ϳ��� �Һ�
		if (coffee[i] == 1) {
			coffee[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (water[i] == 1) {
			water[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cup[i] == 1) {
			cup[i] = 0;
			break;
		}
	}
	cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
}

void CoffeeVendingMachine::sugarCoffee() {
	if (coffee[0] == 0 || sugar[0] == 0 || water[0] == 0 || cup[0] == 0) {	// ��ᰡ �ϳ��� �����ϸ�
		cout << "��ᰡ �����մϴ�!! ���Ƿ� ��� ���� ä��ϴ�. ~~ �ٽ� �������ּ���" << endl;
		fill();		// ���Ƿ� ä���ְ�
		return;		// �Լ� ����
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (coffee[i] == 1) {
			coffee[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (sugar[i] == 1) {
			sugar[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (water[i] == 1) {
			water[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cup[i] == 1) {
			cup[i] = 0;
			break;
		}
	}
	cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
}
void CoffeeVendingMachine::blackCoffee() {
	if (coffee[0] == 0 || sugar[0] == 0 || cream[0] == 0 || water[0] == 0 || cup[0] == 0) {	// ��ᰡ �ϳ��� �����ϸ�
		cout << "��ᰡ �����մϴ�!! ���Ƿ� ��� ���� ä��ϴ�. ~~ �ٽ� �������ּ���" << endl;
		fill();		// ���Ƿ� ä���ְ�
		return;		// �Լ� ����
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (coffee[i] == 1) {
			coffee[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (sugar[i] == 1) {
			sugar[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cream[i] == 1) {
			cream[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (water[i] == 1) {
			water[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cup[i] == 1) {
			cup[i] = 0;
			break;
		}
	}
	cout << "���ִ� �� Ŀ�� ���Խ��ϴ�~~" << endl;
}


void CoffeeVendingMachine::sell() {
	int num = 0;		// �Է¹ޱ� ���� ���� num
	while (1) {			// ���� �ݺ���
		status();		// ���� ���¸� ���
		cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>> ";
		cin >> num;		// �޴��� �Է¹ް�
		if (num == 0) normalCoffee();		// ���� Ŀ��
		else if (num == 1) sugarCoffee();	// ���� Ŀ��
		else if (num == 2) blackCoffee();	// �� Ŀ��
		else if (num == 3) {				// ��� �� ä���
			cout << "��� ���� ä��ϴ�.~~" << endl;
			fill(); 
		}
		else if (num == 4) break;		// ������ ���� ����
	}
}

int main() {			// main �Լ�
	CoffeeVendingMachine *cvm = new CoffeeVendingMachine();	// CoffeeVendingMachine ���� �� �Ҵ�
	cvm->sell();		// sell�Լ��� ���� �Ǹ� ���� 
	delete cvm;			// ��ȯ�ϸ鼭 ����
}