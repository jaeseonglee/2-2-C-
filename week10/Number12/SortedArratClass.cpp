/*	�ǽ� 12�� : SortedArrayClass.cpp
	�ۼ��� : 2019.11.05 ~ 11.07
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ���� �迭�� �׻� ���������� �����ϴ� SortedArrayŬ������ ������ ���α׷�
*/

#include <iostream>
using namespace std;

class SortedArray {		// SortedArray Ŭ����
	int size;  // ���� �迭�� ũ��
	int* p;		// ���� �迭�� ���� ������
	void sort();	// ���� �迭�� ������������ ����
public:
	SortedArray();	// p�� NULL�� size�� 0���� �ʱ�ȭ
	SortedArray(SortedArray& src);	// ���� ������
	SortedArray(int p[], int size);	// ������. ���� �迭�� ũ�⸦ ���޹���
	~SortedArray();		// �Ҹ���
	SortedArray operator+(SortedArray& op2);		// ���� �迭�� op2 �迭 �߰�
	SortedArray& operator=(const SortedArray& op2);	// ���� �迭�� op2 �迭 ����
	void show();		// �迭�� ���� ���
};

void SortedArray::sort() {		// ������������ �����ϴ� sort �Լ�, Ŭ���������� private�� ����Ǿ���
	for (int i = 0; i < size - 1; i++) {
		for (int j = 1; j < size; j++) {	// ��ø �ݺ����� ���� �������� ����
			if (p[j-1] > p[j]) {
				int temp = p[j-1];
				p[j-1] = p[j];
				p[j] = temp;
			}
		}
	}
}


SortedArray::SortedArray() {	// ������
	p = nullptr;		// p�� NULL�� �ʱ�ȭ �϶�� �־����µ� nullptr�� �ʱ�ȭ�غô�
	size = 0;			// size�� 0���� �ʱ�ȭ
}

SortedArray::SortedArray(SortedArray& src) {	// ���� ������, ���� ����� �����Ѵ�
	this->size = src.size;		// size�� ���ڷ� ���� ��ü�� size�� �ʱ�ȭ
	p = new int[size];			// �����ʹ� ���� ���� �Ҵ��� ���� ������ְ�
	for (int i = 0; i < size; i++) {	// �� ������ �ݺ����� ���� ���� �����Ѵ�
		p[i] = src.p[i];
	}
}

SortedArray::SortedArray(int p[], int size) {	// �Ű������� �ִ� ������
	this->size = size;			// size�� �״�� �Ű����� size�� �����ϰ�
	this->p = new int[size];	// p�� ���� �Ҵ���
	for (int i = 0; i < size; i++) {	// �迭�� ����� �����Ѵ�
		this->p[i] = p[i];
	}
}

SortedArray::~SortedArray() {		// �Ҹ���
	if(p)
		delete [] p;	// p�� �Ҵ�޾����� ��ȯ���ش�
}

SortedArray SortedArray::operator+(SortedArray& op2) {	// +������ �Լ� , �� ��ü�� ��ģ��
	SortedArray temp;		// �� ��ü�� ���� ���ο� ��ü�� ��ȯ�� temp ����
	temp.size = this->size + op2.size;	// �� ��ü�� size�� ��ģ ũ��� �ʱ�ȭ
	temp.p = new int[temp.size];		// p�� �� ũ�⸸ŭ �Ҵ� 

	for (int i = 0; i < this->size; i++) {	// �� �ݺ����� ���� �� ��ü�� �ִ� p��
		temp.p[i] = this->p[i];
	}
	for (int i = 0; i < op2.size; i++) {	// ������ ������ temp�� p�� �������ش�
		temp.p[i + this->size ] = op2.p[i];
	}
	return temp;		// �׷��� ���� �ʱ�ȭ�� temp�� ��ȯ
}

SortedArray& SortedArray::operator=(const SortedArray& op2) { // =������	�Լ�, å�� ��Ʈ �����Ͽ� �ۼ��ߴ�
	delete[] this->p;			// ���� ������ p�� ��ȯ���ְ�
	this->size = op2.size;		// op2 ��ü�� �����ϱ� ���� �״�� ���� �ް�
	this->p = new int[this->size];		// p�� size ��ŭ �Ҵ�
	for (int i = 0; i < this->size; i++) {	// �ݺ����� ���� ���� ����
		this->p[i] = op2.p[i];
	}
	return *this;	// �׷��� �ٲ� ��ü �ڽ��� ��ȯ���ش�
}

void SortedArray::show() {	// �迭�� ����ϴ� show�Լ�
	sort();
	cout << "�迭 ��� : ";
	for (int i = 0; i < size; i++) {// �ݺ����� ���� �迭 ���
		cout << p[i] << " ";
	}
	cout << endl;
}

int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;		// +, = ������ �ۼ� �ʿ�
					// + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
	a.show();
	b.show();
	c.show();
}