/*	�ǽ� 10�� :StatisticsClass.cpp
	�ۼ��� : 2019.11.04 ~ 11.07
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ��踦 ���� StatisticsŬ������ ������ ���α׷� ,�־��� main�Լ��� �� ����ǵ��� !,<<,>>,~ ������ �Լ��� �ۼ�
*/
#include <iostream>
using namespace std;

class Statistics { // Statistics Ŭ����
	int *p;			// ���ο��� �����Ҵ��� ���� ������ ������ ����
	int size;		// �����͸� ũ�⸦ ����Ű�� size ����
public:
	Statistics();	// ������
	~Statistics() { delete[] p; }	// �Ҹ���, ���� �Ҵ� �޴� p�� ��ȯ���ش�
	bool operator!();				// !, <<, >> , ~  ������ �Լ� �ۼ��� ���� �����
	Statistics& operator<<(int num);
	void operator>>(int& avg);
	void operator~();
};

Statistics::Statistics() {	// ������
	p = new int[10];		// Ŭ���� ���ο��� int �迭�� �������� �Ҵ�޾� �����Ѵ�, ���⼭�� 10�� ũ��� �Ҵ�
	size = 0;				// size�� 0���� �ʱ�ȭ
}

bool Statistics::operator!() {		// ! ������ �Լ�
	if (size == 0) return true;		// sizer�� 0�̸� true 
	else return false;				// �ƴϸ� false ��ȯ
}

Statistics& Statistics::operator<<(int num) { // << ������ �Լ�
	p[size] = num;		// �Ű������� ���� ���� ���� �Ҵ�� p�� �������ش�
	size++;				// size �� ����
	return *this;		// �� ��ü�� ���� ����
}

void Statistics::operator>>(int& avg) {	// >> ������ �Լ�, �Ű������� ���� ���� ���� �������ֱ� ���� & ���
	int sum = 0;			// ���� ������ sum ���� �� 0���� �ʱ�ȭ
	for (int i = 0; i < size; i++) {
		sum += p[i];			// �ݺ����� ���� p�� ����� �迭�� ��� ������ �����ش�
	}
	avg = (int)(sum / size);	// sum�� size�� �������� ���� ���ڷ� �޾ƿ� avg�� ����, int�� ����ȯ�� Ȥ�ó� �ؼ� �����
}

void  Statistics::operator~() {	// ~ ������ �Լ�, ��¸� �ϱ� ������ ��ȯ���̳� �Ű������� ���� �ʿ����� �ʴ�
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";		// �ݺ����� ���� ���
	}
	cout << endl;
}

int main() {
	Statistics stat;
	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;

	int x[5];
	cout << "5 ���� ������ �Է��϶�>>";
	for (int i = 0; i < 5; i++) cin >> x[i];		// x[i]�� ���� �Է�

	for (int i = 0; i < 5; i++) stat << x[i];		// x[i]���� ��� ��ü�� �����Ѵ�.
	stat << 100 << 200;		// 100, 200�� ��� ��ü�� �����Ѵ�.
	~stat;				// ��� �����͸� ��� ����Ѵ�

	int avg;
	stat >> avg;		// ��� ��ü�κ��� ����� �޴´�
	cout << "avg=" << avg << endl;		// ����� ����Ѵ�
}
