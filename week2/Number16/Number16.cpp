/*	C++ ���α׷��� 2���� ����
	�ǽ� 16�� : Number16.cpp
	�ۼ��� : 2019.09.05 ~ 09.07
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : ���� �ؽ�Ʈ�� �Է¹޾� ���ĺ� ������׷��� �׸��� ���α׷�
				�빮�ڴ� �ҹ��ڷ� �����ϸ�, �ؽ�Ʈ �Է��� ���� ';'���ڷ� �Ѵ�
*/
#define _CRT_SECURE_NO_WARNINGS	// C�� ���� ó���Լ��� ������ ������� �ʰ� �ϴ� define��
#include <iostream>				// ǥ�� ��ó����
using namespace std;
#include <cstring>				// C�� ���� ó���Լ��� ���� ���

#define SIZE 10000				// define���� ���� SIZE 10000���� ����

int main() {					// main �Լ�
	char text[SIZE] = "";		// ���� �ؽ�Ʈ�� ������ text ���� �� �ι��ڷ� �ʱ�ȭ
	int countAlpha[26] = {};	// ���ĺ��� ��Ÿ�� Ƚ���� ������ int�� �迭 countAlpha ���� �� �ʱ�ȭ
	int num = 0 ;				// ASCII �ڵ�� char���� ����Ͽ� ������ ������ num ���� �� 0���� �ʱ�ȭ
	int count = 0;				// �˹ٺ� ������ ������ count ���� �� 0���� �ʱ�ȭ
	int size = sizeof(countAlpha) / sizeof(countAlpha[0]);	// countAlpha�� ũ�⸦ ����ϴ� size

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;	// �ؽ�Ʈ�� �Է��ش޶�� ���
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�." << endl;
	cin.getline(text, SIZE, ';');			// �Է¹��� �ؽ�Ʈ�� text�� ����
	
	for (int i = 0; i < strlen(text); i++) {	// �ݺ����� ���� countAlpha�� ������ �����Ѵ�
		if (isalpha(text[i])) {					// ���� ���ĺ��� �ԷµǾ��°��� �Ǵ�(isalpha)
			if (isupper(text[i])) {				// �׸��� �빮���ΰ��� �Ǵ�9isupper)
				text[i] = tolower(text[i]);		// �� ���ǹ��� ���ļ� ���� �ҹ��ڸ� �ٽ� �������ش�
			}
			num = text[i] - (char)97;			// �ҹ��ڶ�� ASCII�ڵ忡�� 'a'�� 97�̱⿡
												// text[i]�� 'a'��� 0�� �����Ƿ� 
			countAlpha[num]++;					// countAlpha[0]�� ���� �ϳ� ���������ش�
												// �̷��� �ҹ��ڵ��� �󵵸� ����Ͽ� countAlpha�� �������ش�
		}
	}
	
	for (int i = 0; i < size; i++) {			// C++�� �߰��� ���� ���� ����
		count += countAlpha[i];					// �ݺ����� ���� ���ĺ� ���� count�� ����
	}
	cout << "�� ���ĺ� �� " << count << endl << endl;// �� ���ĺ� ���� strlen�� ���� ���

	for (int i = 0; i < size; i++) {			// ����� ����ϴ� �ݺ���
		cout << (char)(97 + i) << " (" << countAlpha[i] << ")\t: ";		//a���� z���� ���
												// countAlpha�� ������ ���� ���� ������ش�
		for (int j = 0; j < countAlpha[i]; j++) {	// �׸��� �� �ε����� �ش��ϴ� ����ŭ
			cout << "*";							// '*'�� ������ش�
		}
		cout << endl;								// �� ����� ������ �ٹٲ�
	}
}