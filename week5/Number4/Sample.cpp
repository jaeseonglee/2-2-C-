#include <iostream>
using namespace std;

#include "Sample.h"		// ������� include

Sample::Sample(int n) {	// ������
	size = n;			
	p = new int[n];		// n�� ���� �迭�� ���� ����
 }

void Sample::read() {		// Ű����κ��� ������ �Է¹��� read �Լ�	
	for (int i = 0; i < size; i++) { // �ݺ����� ����
		cin >> p[i];		// cin���� �� �ε����� ���� �����Ѵ�.
	}
}

void Sample::write() {		// �Էµ� ���� �迭�� ����ϴ� write �Լ�
	for (int i = 0; i < size; i++) {	// �ݺ����� ����
		cout << p[i] << " ";	// cout���� �迭�� ����Ѵ�
	}
	cout << endl;		// ��� ����� ������ �ٹٲ�
}

int Sample::big() {		// �迭���� ���� ū ���� �����ϴ� big �Լ�
	int answer = p[0];	// ���� ū ���� ������ answer ������ ù��° �ε��� ���� �־��ش�
	for (int i = 1; i < size; i++) {	// �ι�° �ε����� ������ ������ �ݺ����� ����
		if (answer < p[i]) { answer = p[i]; }	// ���� ū ���� ã�� answer�� �����Ѵ�
	}
	return answer;		// �ݺ����� ���� ����� answer ����
}

Sample::~Sample() {}	// �Ҹ���