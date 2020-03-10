/*	�ǽ� 6�� : BaseArrayProject.cpp
	�ۼ��� : 2019.11.07 ~ 11.10
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� BaseArray Ŭ������ ��ӹ޾� �������� �۵��ϴ� MyStack Ŭ������ �ۼ��� ���α׷�
*/
#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;	// �迭�� ũ��
	int* mem;		// ���� �迭�� ����� ���� �޸��� ������
protected:			// �����ڰ� Protected�ΰͿ� �ָ�
	BaseArray( int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {		// BaseArray�� ��ӹ޴� MtStack Ŭ����
	int num;			// ���� ������ ũ�⸦ ������ ���� num
public:
	MyStack(int size) : BaseArray(size) { this->num = 0; } // �Ű������� �ִ� �����ڷ�, BaseArray�� �����ڿ� size���� ���� �ϰ� num���� 0���� �ʱ�ȭ
	void push(int n) { put(num++, n);  }		// ���� ���ÿ��� ���� �߰�, BaseArray�� ���� �ε����� �������ش�
	int capacity()   { return getCapacity(); }	// �迭�� �뷮�� ��ȯ�ϴ� capacity�Լ�
	int length()	 { return num; }			// ���� ������ ũ�⸦ ��ȯ�ϴ� lenght �Լ�
	int pop()		 { return get(--num); }		// ���ÿ��� pop�� ����� �ϴ� pop�Լ�
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);			// ���ÿ� Ǫ��
	}
	cout << "���ÿ뷮:" << mStack.capacity() << ", ����ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';		// ���ÿ��� ��
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}