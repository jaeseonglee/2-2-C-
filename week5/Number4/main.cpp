#include <iostream>
using namespace std;

#include "Sample.h"		// Sample Ŭ���� ����� ���� ������� include

int main() {			// main�Լ�, �ǽ��������� �־��� �ڵ�� ����
	Sample s(10);		// 10�� ���� �迭�� ���� Sample ��ü ����
	s.read();			// Ű���忡�� ���� �迭 �ϱ�
	s.write();			// ���� �迭 ���
	cout << "���� ū ���� " << s.big() << endl;		// ���� ū �� ��� 
}