/*	�ǽ� 7�� : MatrixClass.cpp
	�ۼ��� : 2019.11.04 ~ 11.06
	�ۼ��� : 20165153 ���缺
	���α׷� ����: 2���� ����� �߻�ȭ�� Matrix Ŭ������ Ȱ���ϴ� ���α׷�
*/

#include <iostream>
using namespace std;

#define SIZE 4		// define���� ���� SIZE�� 4�� ����

class Matrix {		// Matrix Ŭ����
	int arr[SIZE];	// ������ �迭 ����
public:
	Matrix() { arr[0], arr[1], arr[2], arr[3] = 0; }	// �Ű������� ���� �����ڴ� �迭�� ������ 0���� �ʱ�ȭ���ش�
	Matrix(int a, int b, int c, int d);				//	������
	void show();					// �迭�� ����ϴ� show �Լ�
	//void operator<<(int *array);	// << ������ �Լ�	7-1�� ����Լ��� ����
	//void operator>>(int* array);	// >> ������ �Լ�	7-1�� ����Լ��� ����
	friend Matrix& operator<<(Matrix& m, int* array);		// 7-2�� ������ �Լ��� ����
	friend void operator>>(Matrix m, int* array);		// 7-2�� ������ �Լ��� ����

};

Matrix::Matrix(int a, int b, int c, int d) {	// ������
	arr[0] = a;		// �Ű������� ������ ������ �迭�� �ε����� ����
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
}

void Matrix::show() {			// �迭�� ����ϴ� show �Լ�
	cout << "Matrix = { ";		
	for (int i = 0; i < SIZE; i++) {		// �ݺ����� ���� ���
		cout << arr[i] << " ";
	}
	cout << " }" << endl;
}
/*7-1�� ����Լ��� ����
void Matrix::operator<<(int* array) {	// << ������ �Լ�
	for (int i = 0; i < SIZE; i++) {
		arr[i] = array[i];		// �Ű������� ���� �迭�� ������ Matrix�� �迭 ������ ���� �����Ѵ�
	}
}

void Matrix::operator>>(int* array) {	// >> ������ �Լ� , �����͸� ���� �ּҸ� �޾ƿ´�
	for (int i = 0; i < SIZE; i++) {	// Matrix�� �迭�� ������ ������ �Ű������� ���� �迭�� �����Ѵ�
		array[i] = arr[i];
	}
}
*/

Matrix& operator<<(Matrix& m, int *array) {		// 7-2�� ������ �Լ��� ����, �� ��쿡�� ��ü�� ��ȯ�ϵ��� �ϰ� ���ش�
	for (int i = 0; i < SIZE; i++) {
		//m.arr[i] = array[i];		// �Ű������� ���� �迭�� ������ Matrix�� �迭 ������ ���� �����Ѵ�
		m.arr[i] = array[i];
	}
	return m;
}

void operator>>(Matrix m, int* array) {	// 7-2�� ������ �Լ��� ����
	for (int i = 0; i < SIZE; i++) {	// Matrix�� �迭�� ������ ������ �Ű������� ���� �迭�� �����Ѵ�
		array[i] = m.arr[i];
	}
}

int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[SIZE], y[SIZE] = { 1,2,3,4 };		// 2���� ����� 4���� ���� ��
	a >> x;		// a�� �� ���Ҹ� �迭 x�� ����. x[]�� {4,3,2,1}
	b << y;		// �迭 y�� ���� ���� b�� �� ���ҿ� ����

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';	// x[] ��� 
	cout << endl;
	b.show();
}
