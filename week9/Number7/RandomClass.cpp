/*	�ǽ� 7�� : RandomClass.cpp
	�ۼ��� : 2019.10.25 ~ 10.27
	�ۼ��� : 20165153 ���缺
	���α׷� ����: Rondom Ŭ������ Ȱ���Ͽ� ������ ���� ����ϴ� ���α׷� 
*/


#include <iostream>
#include <ctime>		
#include <cstdlib>
using namespace std;

class Rondom {	// ������ �߻���Ű�� Rondom Ŭ����
public:
	//�׻� �ٸ� ���� ���� �߻���Ű�� ���� seed�� �����ϴ� �Լ�
	static void seed() { srand((unsigned)time(0)); }	// ���� ����
	static int nextInt(int min = 0, int max = 32767);	// min�� max ������ ���� ���� ����
	static char nextAlphabet();	// ���� ���ĺ� ���� ����
	static double nextDouble();	// 0���� ũ�ų� ���� 1���� ���� ���� �Ǽ� ����
};

int Rondom::nextInt(int min, int max) {	// ���� ������ �����ϴ� nextInt�Լ�
	int n = rand() % (max-min) + min;	// man�� max������ ���߿� �ϳ��� ������
	return n;		// n ����
}

char Rondom::nextAlphabet() {	// ���� ���ĺ��� �����ϴ� nextAlphabet�Լ�
	char c = rand() % 2;		// �빮�ڸ� ������� �ҹ��ڸ� ������� ����
	if(c == 0) c = rand() % 26 + 65;// �빮�� ���, A = 65 Z = 90 �̹Ƿ� 0���� 25���� ���������� 65�� �����ش�
	else c = rand() % 26 + 97;		// �ҹ��� ���, a = 97 z = 122 �̹Ƿ� 0���� 25���� ���������� 97�� �����ش�
	return c;		// ASCII �ڵ��� �󿡼��� ���ڷ� ����� c ����
}

double Rondom::nextDouble() {	// ���� �Ǽ��� �����ϴ� nextDouble �Լ�
	double d = rand() / (double)RAND_MAX;	// ���� ������ �ִ밪 32767(RAND_MAX)�� ���� ���� ���� ���� ���
	return d;		// double���� d ����
}

int main() {		// main �Լ�
	Rondom::seed();	// seed �Լ��� ���� ���� ���带 �������ش�
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++) {		// ���� ���� 10�� ���
		cout<<Rondom::nextInt(1, 100) <<" ";
	}

	cout <<endl << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++) {	// ���� ���ĺ� 10�� ���
		cout << Rondom::nextAlphabet() << " ";
	}

	cout << endl << "������ �Ǽ� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++) {	// ���� �Ǽ� 10�� ���
		cout << Rondom::nextDouble() << " ";
		if (i == 4 || i == 9) cout << endl;	// �Ǽ� 5���� ����� �ٹٲ�
	}
}