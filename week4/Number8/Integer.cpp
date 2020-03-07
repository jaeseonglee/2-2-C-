/*	�ǽ� 8�� : Integer.cpp
	�ۼ��� : 2019.09.19 ~ 09.20
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : int Ÿ���� ������ ��üȭ�� IntegerŬ���� �ۼ� �� ��� �Լ��� �ڵ� �ζ������� �ۼ��ϴ� ���α׷�
*/

#include <iostream>
#include <string>		// stoi()�Լ��� �������� ������� srting�� include
using namespace std;

class Integer {			// Ŭ���� Integer
	int num;			// (private) ���� ������ ���� num
public:					//  �ڵ� �ζ����� ���ؼ� Ŭ������ ����ο� ��� �Լ��� ���� ����
	Integer(int n) {num = n;}			// ������ �Ű������� �޴� �����ڴ� �� �Ű������� num�� ����
	Integer(string s) { num = stoi(s); }// string Ÿ������ �Ű������� �޴� �����ڴ� stoi �Լ��� ���� ������ �����Ŀ� num�� ����

	int get() { return num; }			// num�� ��ȯ�ϴ� get �Լ�
	void set(int n) { num = n; }		// �Ű������� num�� �����ϴ� set �Լ�
	int isEven() {						// ¦���ΰ� �ƴѰ��� ��ȯ�ϴ� isEven�Լ�
		if (num % 2 == 0) return true;	// num�� 2�� ���� �������� 0�̸�(¦����), int�� �Լ��̱� ������ 1(ture) ��ȯ
		else return false;				// �װ� �ƴ϶�� false ��ȯ
	}
};

int main() {				// main�Լ�,�ǽ��������� �־��� main�Լ��� ����.
	Integer n(30);			// ������ �Ű������� ���� ��ü n ����
	cout << n.get() << ' ';	// get�Լ��� ���� ���� ���
	n.set(50);				// set�Լ��� ���� 50���� ����
	cout << n.get() << ' ';	// �ٽ� get�Լ��� ���� ���� ���

	Integer m("300");		// ���ڿ��� �Ű������� ���� ��ü m ����
	cout << m.get() << ' ';	// get�Լ��� ���� ���� ���
	cout << m.isEven();		// isEven�Լ��� ����	ture�Ǵ� flase ���
}