#include <iostream>
using namespace std;

#include "AirplaneBook.h"	// AirplaneBook ��������� include

int main() {			// main �Լ�
	AirlineBook *airBook = new AirlineBook();	// AirlineBook ��ü ���� �Ҵ� ����
	airBook->bookSystem();	// ���� ���α׷� ����
	delete airBook;			// �Ҵ���� ��ü ��ȯ
}