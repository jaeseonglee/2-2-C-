/*	�ǽ� 9�� : BoardProgram.cpp
	�ۼ��� : 2019.10.27
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �Խ����� ������ ���α׷�. �������� ������ ��� �ۼ�, ���� �ø��� ��ɰ� ��±�ɸ� �����Ѵ�
*/

#include <iostream>
using namespace std;

#define SIZE 100	// define������ SIZE�� 100���� ����
	
class Board {		// �Խ����� �����ϴ� Board Ŭ����
	static string board[SIZE];	// �Խ����� �۵��� �����ϴ� board string �迭
	static int number;	// �Խñ��� ���� ������ number
public:
	static void add(string s);	// �Խ��ǿ� ������ �߰��ϴ� add
	static void print();		// �Խ����� ������ ����ϴ� print
};

string Board::board[SIZE] = {};	// board �迭 �ʱ�ȭ
int Board::number = 0;			// number �ʱ�ȭ

void Board::add(string s) {	// ������ �߰��ϴ� add �Լ�
	board[number] = s;	// number �ε����� �Ű������� ������ ����
	number++;			// number ����
}

void Board::print() {	// ������ ����ϴ� print �Լ�
	cout << "************* �Խ����Դϴ�. *************"<<endl;	
	for (int i = 0; i < number; i++) {	// �ݺ����� ���� �迭�� ������ ���
		cout << i << ": " << board[i] << endl;
	}
	cout << endl;	// ��� ����� ������ �ٹٲ�
}

int main() {		// main�Լ�
	//Board myBoard; // ��ü ������ ������ �����Դϴ�.
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}