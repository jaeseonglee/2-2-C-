/*	C++ ���α׷��� 2���� ����
	�ǽ� 15�� : Number15.cpp
	�ۼ��� : 2019.09.05 ~ 09.07
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : +,-,*,/,%�� ���� 5Ģ ������ �� �� �ִ� ���α׷�
				������ �����ڴ� �ϳ��� ��ĭ���� �и��Ͽ� ����Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS	// C�� ���� ó���Լ��� ������ ������� �ʰ� �ϴ� define��
#include <iostream>				// ǥ�� ��ó����
using namespace std;
#include <cstring>				// C�� ���� ó���Լ��� ���� ���

#define SIZE 100				// define���� ���� SIZE 100���� ����

int main() {					//main �Լ�
	char word[SIZE] = "";		// ������� ������ word ���� �� �ʱ�ȭ
	char num1[SIZE] = "";		// ù��° ���� ���ڸ� ������ num1 ���� �� �ʱ�ȭ
	char num2[SIZE] = "";		// �ι�° ���� ���ڸ� ������ num1 ���� �� �ʱ�ȭ
	char temp[SIZE] = "";		// NULL���ڷ� �ʱ�ȭ�� �ӽ� ���� �迭
	char calculator = NULL;		// �����ڸ� ������ calculator
	int i, j;					// C++ ������ �ݺ������� ������ �����ϴ�
	int count = 0;				// ��ĭ Ƚ������ ���� �����ϱ� ���� count ���� �� 0���� �ʱ�ȭ

	while (1) {					// ���� �ݺ��� C++������ boolŸ���� ���� �����(true,false�� ����)
		cout << "? ";			// ������� �Է��ش޶�� ���
		cin.getline(word, SIZE, '\n');	// getline�� ���� ���� word�� ����

		for (i = 0, j = 0, count = 0; i < strlen(word); i++) {	//�ݺ����� ���� ������ �����ڸ� ����
			if (isspace(word[i])) {		// isspace�� ���� word[i]�� �����̸�
				count++;				// count�� ������Ű��
				continue;				// continue�� ���� �ݺ����� �ٽ� �ݺ��Ѵ�
			}							// isspace�� C���� ó�� �Լ��� -> cstring���
			else {						// ������ �ƴ϶��
				switch (count) {		
				case 0:					// ù��° ������ ������������ ���ڸ�
					num1[i] = word[i];	// num1�� �������ش�
					break;				
				case 1:					// �ι�° ������ ���� �����ڰ� �����Ƿ�
					calculator = word[i];	// calculator�� �������ش�
					break;
				case 2:					// ���� �ι��� �������� �������� �����Ƿ�
					num2[j++] = word[i];// num2�� �������ش�.
					break;
				default:				// �Է��� a + b(���� ������ ����)���°� �ƴ϶��
					cout << "�߸��� �Է�!!" << endl;		// �߸��� �Է��� �����
					return 0;			// ���α׷� ����
				}
			}
		}

		cout << num1 << " " << calculator << " " << num2 << " = ";	// ���� ����� ���

		switch (calculator) {	// � �����ڳĿ� ����
		case '+':
			cout << atoi(num1) + atoi(num2) << endl;		// ������� �� ���
			break;					// atoi()�Լ��� ���ڿ��� ������ �ٲ��ش�. ����93p 15�� �ϴ� ����
		case '-':
			cout << atoi(num1) - atoi(num2) << endl;		// ������� �� ���
			break;
		case '*':
			cout << atoi(num1) * atoi(num2) << endl;		// ������� �� ���
			break;
		case '/':
			cout << atoi(num1) / atoi(num2) << endl;		// ��������� �� ���
			break;
		case '%':
			cout << atoi(num1) % atoi(num2) << endl;		// ��������� �� ���
			break;
		default:								// 5Ģ������ �ƴ� �ٸ� ����
			cout << "�߸��� �Է�!!" << endl;		// �߸��� �Է��� �����
			return 0;			// ���α׷� ����
		}

		strncpy(num1, temp, strlen(num1));	// strncpy()�Լ��� ���ڿ��� �Ϻθ� �����ϴ� �Լ�
		strncpy(num2, temp, strlen(num2));	// ���⼭�� strncpt�� ���� num1�� num2�� temp�� ���������Ͽ�,
											// �� NULL���ڷ� �ʱ�ȭ���־� ���� �ݺ����� ���۸� ����شٴ� �����̴�
											// ���� �ٽ� �ڵ带 ���� �ٸ� ����� �ִ��� Ȯ��(19.09.07)
	}

}
