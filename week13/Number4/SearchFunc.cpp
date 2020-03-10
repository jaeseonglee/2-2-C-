/*	�ǽ� 4�� : SearchFunc.cpp
	�ۼ��� : 2019.11.21 ~ 11.24
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �迭���� ���Ҹ� �˻��ϴ� search() �Լ��� ���ø����� �ۼ��϶�. search()�� ù��° �Ű������� �˻��ϰ���
		�ϴ� ������ ���̰�, �ι�° �Ű� ������ �迭�̸�, �� ��° �Ű������� �迭�� �����̴�. search() �Լ��� �˻��� �����ϸ� 
		true��, �ƴϸ� false�� �����Ѵ�.
*/
#include <iostream>
using namespace std;

template <class T>			// template ����
bool search(T num, T arr[], T size) {	// search �Լ�
	for (int i = 0; i < size; i++) {	// �ݺ����� ���� 
		if (arr[i] == num) return true;	// �˻��� �����ϸ� true ����
	}
	return false;	// �����ϸ� false ����
}

int main() {		// main �Լ�
	int x[] = { 1,10,100,5,4 };	
	if (search(100, x, 5)) cout << "100�� �迭 x�� ���ԵǾ��ִ�";	// ���ǹ��� ���� 
	else cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�";				// ��¹��� �ٸ���
}