/*	C++ ���α׷��� 2���� ����
	�ǽ� 8�� : Number8.cpp
	�ۼ��� : 2019.09.05 ~ 09.07
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : �� ���ο� ';'���� 5���� �̸��� �����Ͽ� �Է¹޾�.
					�� �̸��� ����� ȭ�鿡 ����ϰ� ���� �� �̸��� ã�� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS	// �Ʒ����� strlen,strtok,strcpy�� ����Կ� �־� ������ ��Ÿ���� �ʰ��ϴ� define��
#include <iostream>				// ǥ�� ��ó����
using namespace std;
#include <cstring>				// ���� C������ ���ڿ� ó���Լ��� ���� ���� cstring�� ����Ѵ�.

#define SIZE 100				// define���� ���� SIZE 100���� ����

int main() {					// main�Լ�
	char name[SIZE] = "";		// 5���� �̸��� ������ ���� �迭
	char longName[SIZE] = "";	// ���� �� �̸��� ������ ���� �迭
	char temp[SIZE] = "";		// �ݺ����� �����ϸ鼭 �ӽ������� ���� �� �̸��� ������ ���� �迭

	cout << "5���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << endl << ">>";	// �̸��� �Է��ش޶�� ���
	cin.getline(name, SIZE, '\n');			// getline�� ���� name�� �������ش�.
	
	strcpy(longName, strtok(name, ";"));	// strtok�� ���ؼ�  ù��°�� �Էµ� �̸��� longName�� �������ش�.
	cout << "1 : " << longName << endl;		// ù��° �̸� ���

	for (int i = 2; i <= 5; i++) {			// �ݺ����� ���� ���� �� �̸��� ã�´�.
		strcpy(temp, strtok(NULL, ";"));	// strtok�� ���ؼ� �� ���� ';'���� �̸��� temp�� ����
		cout << i << " : " << temp << endl;	// �ݺ����� ����� ���ÿ� �̸����� ����
		if (strlen(temp) > strlen(longName))	// strlen�� ���� ���̸� ���ؼ� ���ǹ��� ����
			strcpy(longName, temp);			// ���� �� �̸��� longName�� �������ش�.
	}

	cout << "���� �� �̸��� " << longName << endl;	// ���� �� �̸� ���
}