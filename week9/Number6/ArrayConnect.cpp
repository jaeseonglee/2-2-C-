/*	�ǽ� 6�� : ArrayConnect.cpp
	�ۼ��� : 2019.10.25 ~ 10.27
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ������ ũ���� �迭�� ��ȯ�ϴ� 2���� static ��� ������ ���� ArrayUtility2 Ŭ������ �����,
				�� Ŭ������ �̿��Ͽ� �־��� ����� ���� ��µǵ��� �ϴ� ���α׷�
*/

#include <iostream>
using namespace std;

#define SIZE 5		//define���� ���� SIZE�� 5�� ����

class ArrayUtility2 {	// �迭�� ���� �������ִ� ArrayUtility2 Ŭ����
public:
	// s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	static int* concat(int s1[], int s2[], int size);

	// s1���� s2�� �ִ� ��� ���ڸ� ��� ������ ���ο� �迭�� ���������Ͽ� ����.
	// �����ϴ� �迭�� ũ��� retSize�� ����. retSize�� 0�� ��� NULL ����
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {	// concat �Լ� ������
	int* newArr = new int[size];			// ������ ũ���� �� �迭�� ��ģ ���ο� �迭�� ���� �Ҵ�
	for (int i = 0; i < size / 2; i++) {	// �ݺ����� ���� s1�� ������ ����
		newArr[i] = s1[i];
	}
	for (int i = 0; i < size / 2; i++) {	// �ݺ����� ���� s2�� ������ ����
		newArr[i + size / 2] = s2[i];
	}
	return newArr;		// size��ŭ �Ҵ�� newArr ��ȯ
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) { // remove �Լ� ������
	int* newArr;			// ���ο� ������ ������ ����
	for (int i = 0; i < size / 2; i++) {		// ��ø �ݺ����� ���� �� �迭�� ���� ���Ѵ�
		for (int j = 0; j < size / 2; j++) {	
			if (s1[i] == s2[j]) {	// �迭 �� ���� ���ٸ�
				s1[i] = NULL;		// s1�� ���� NULL������ �ʱ�ȭ
				break;		// ������ �ݺ����� ����������
			}
		}
		if(s1[i] != NULL)	// s1�� ���� NULL�� �ƴ϶��
			retSize++;		// retSize ����
	}

	if (retSize == 0) return NULL;	// retSize�� 0�̸� �����Ҵ��� ũ�Ⱑ �����Ƿ� NULL ����
	newArr = new int[retSize];		// retSize��ŭ�� ���ο� �迭�� ���� �Ҵ�

	for (int i = 0, j = 0; i < size/2; i++) {	// �ݺ����� ���� s1�� ���� ����
		if (s1[i] != NULL) {	// �� NULL�� �ƴ� �ٸ� ������ ����
			newArr[j] = s1[i];	
			j++;		// ���ο� �迭�� �ε��� ����
		}
	}

	return newArr;	// ���� �ݺ����� ���� �Ҵ�� newArr ����
}

int main() {	// main �Լ�
	int x[SIZE];		// �Է����� ����� �迭 x
	int y[SIZE];		// �Է����� ����� �迭 y
	int* arr = nullptr;	// ������ ������ arr ���� �� �ʱ�ȭ
	int* arr2 = nullptr;// ������ ������ arr2 ���� �� �ʱ�ȭ
	int retSize = 0;	// static���� �Լ��� ���� ���� ����� retSize
	int size = 0;		// �迭�� ũ�⸦ ������ size ���� �� �ʱ�ȭ
	
	cout << "������ " << SIZE << " �� �Է��϶�. �迭 x�� �����Ѵ�>>";
	for (int i = 0; i < SIZE; i++) {	// �ݺ����� ���� x �ʱ�ȭ
		cin >> x[i];
	}
	
	cout << "������ " << SIZE << " �� �Է��϶�. �迭 y�� �����Ѵ�>>";
	for (int i = 0; i < SIZE; i++) {	// �ݺ����� ���� y �ʱ�ȭ
		cin >> y[i];
	}

	size = sizeof(x) / sizeof(x[0]) + sizeof(y) / sizeof(y[0]);	// �� �迭 ũ���� ���� size�� ����
	arr = ArrayUtility2::concat(x, y, size);	// static�Լ� ȣ��� arr�� ����
	cout << "��ģ ������ �迭�� ����Ѵ�" << endl;	
	for (int i = 0; i < size; i++) {		// arr�� ��� ���
		cout << arr[i] << " ";
	}

	arr2 = ArrayUtility2::remove(x, y, size, retSize);	// static �Լ� ȣ��� arr2�� ����
	cout << endl << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ "<< retSize << endl;	// retSize�� �Բ�
	for (int i = 0; i < retSize; i++) {		// arr2 ���
		cout << arr2[i] << " ";
	}

	delete [] arr;		// ���� �Ҵ�� �迭�� ��ȯ
	delete [] arr2;
}