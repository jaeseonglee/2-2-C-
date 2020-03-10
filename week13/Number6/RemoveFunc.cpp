/*	�ǽ� 6�� : RemoveFunc.cpp
	�ۼ��� : 2019.11.21 ~ 11.24
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �Ű������� �־��� int �迭�� src���� �迭 minus�� ����ִ� ���� ������ ��� ������ ���ο� int
		�迭�� �������� �Ҵ�޾� �����Ѵ�. retSize�� remove()�Լ��� ���� ����� �����ϴ� �迭�� ũ�⸦ ���޹޴´�.
*/
#include <iostream>
using namespace std;

template <class T>			// template ����
T* remove(T src[], T sizeSrc, T minus[], T sizeMinus, T& retSize) {	// remove �Լ� �Ϲ�ȭ
	int index = 0;			// ���ο� �迭�� �ε���
	T* result;				// ���ο� �迭�� ����ų ������
	retSize = sizeSrc;		// retSize�� sizeSrc�� �ʱ�ȭ

	for (int i = 0; i < sizeSrc; i++) {	// ��ø �ݺ����� ����
		for (int j = 0; j < sizeMinus; j++) {	// �ߺ��Ǵ� ���Ҹ� ����
			if (src[i] == minus[j]) {	
				src[i] = NULL;		
				retSize--;		// ���ŵǴ� ��ŭ retSize����
			}
		}
	}
	
	result = new T[retSize];	// retSize ��ŭ ���� �Ҵ�
	for (int i = 0; i < sizeSrc; i++) {	// �ݺ����� ����
		if (src[i] != NULL) {		// src�� ���� ���ҵ��� ����
			result[index] = src[i];	// cnt���� �ε����� �Ǿ� ����
			index++;				// �����Ҷ� ���� �ε��� ����
		}
	}
	return result;			// ���� �Ҵ�� �迭 ����
}

int main() {			// main �Լ�
	int num = 0;		
	int* temp = nullptr;	// remove �Լ��� ���� ��ȯ�Ǵ� �迭�� ������ ������
	int a[] = { 1,2,3,4 };	
	int b[] = { -3,5,10,1,2,3 };
	int aSize = sizeof(a) / sizeof(a[0]);
	int bSize = sizeof(b) / sizeof(b[0]);

	double num2 = 0;
	double* temp2 = nullptr;	// remove �Լ��� ���� ��ȯ�Ǵ� �迭�� ������ ������
	double c[] = { 1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9 };
	double d[] = { 3.5, 4.8, 1.0, 2.0, 3.0 };
	int cSize = sizeof(c) / sizeof(c[0]);
	int dSize = sizeof(d) / sizeof(d[0]);

	cout << "���� �迭 {" << a[0];
	for (int i = 1; i < aSize; i++) { cout << "," << a[i]; }
	cout << "}���� ���� �迭 {" << b[0];
	for (int i = 1; i < bSize; i++) { cout << "," << b[i]; }
	cout << "}�� ���ϴ�" << endl;			

	temp = remove(a, aSize, b, bSize, num);		// remove �Լ��� ���� temp�� �迭 ����
	for (int i = 0; i < num; i++) {	cout << temp[i] << " "; }	// �ݺ����� ���� ���
	cout << endl << endl;

	printf("�Ǽ� �迭 {%.1lf", c[0]);						  //cout << "�Ǽ� �迭 {" << (float)c[0];
	for (int i = 1; i < cSize; i++) printf(", %.1lf", c[i]);  //{ cout << ", " << c[i]; }
	cout << "}���� \n�Ǽ� �迭 {" << d[0];
	for (int i = 1; i < dSize; i++) printf(", %.1lf", d[i]);  //{ cout << ", " << d[i]; }
	cout << "}�� ���ϴ�" << endl;

	temp2 = remove(c, (double)cSize, d, (double)dSize, num2);	// remove �Լ��� ���� temp2�� �迭 ����
	for (int i = 0; i < num2; i++) { cout << temp2[i] << " "; } // �ݺ����� ���� ���

	if (temp)  delete[] temp;		// �Ҵ�� �迭 ��ȯ
	if (temp2) delete [] temp2;
}