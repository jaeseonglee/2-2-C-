/*	�ǽ� 5�� : RandomNumber.cpp
	�ۼ��� : 2019.09.19 ~ 09.20
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : ���� ���� �߻���Ű�� RandomŬ������ �̿��Ͽ� ������ ���� 10�� ����ϴ� ���α׷�
				(RandomŬ������ ������,next(),nextInRange() 3���� ����Լ��� �������� �ۼ��ϰ�,
				main()�Լ��� ���� �ϳ��� cpp���Ϸ� ����)
*/

#include <iostream>
#include <cstdlib>	// ���� ������ �߻���Ű�� ���ؼ� cstdlib,ctime
#include <ctime>	// �� ��������� include, �� �ǽ��������� ����
using namespace std;

class Random {	// ���� ���� �߻���Ű�� RandomŬ����
public:
	Random();	// Random Ŭ������ ������
	int next();	// 0���� RAND_MAX(32767)������ ������ ������ ��ȯ�ϴ� �Լ�
	int nextInRange(int start, int end); // �Ű����� start���� end ������ ������ ������ ��ȯ�ϴ� �Լ�
};

Random::Random() {	// ������
	srand((unsigned)time(NULL)); // srand�� ���� ���� ������ ���� ����,������ �׻� �ٲ�� �ϱ� ���� ���� �ð����� ����
								//  unsigned�� ���� ���� ���ڸ� ��´�.
}								

int Random::next() {	// next �Լ�
	return rand(); // 0���� RAND_MAX(32767) ������ ������ ���� ��ȯ�Ѵ�.
}

int Random::nextInRange(int start, int end) {	// nextInRange �Լ�
	return (rand() % (end - start + 1)) + start;// end�� start�� ���� ������ �������� �� ����ŭ�� �������� �����µ�
						// �׷��� ������� ���� end�� ������ �ʰ� �ǹǷ� +1�� ���־� ���� �� �ִ� ������(������)�� �ϳ� �� �������Ѵ�.
						// �׸��� start�� �������� �����־� 0���� ������������ ���� ���ڸ� start���� end���� �������ؼ� ��ȯ�Ѵ�.
}

int main() {			// main �Լ�, �ǽ� �������� �־��� main �Լ��� ����.
	Random r;			// ��ü ����
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;	// 0���� 32767������ ���� ���ڸ� ����Ѵٰ� ���
	for (int i = 0; i < 10; i++) {		// �ݺ����� ����
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ������ next()�Լ��� ���� ��ȯ�ϰ�
		cout << n << ' '; // ����Ѵ�.
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;	// 2���� 4������ ���� ���ڸ� ����Ѵٰ� ���
	for (int i = 0; i < 10; i++) {		// ���Ͱ��� �ݺ����� ���� 
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ������ nextInRange�Լ��� ���� ��ȯ�ϰ�
		cout << n << ' ';		// ���� ����Ѵ�.
	}
	cout << endl;	// �ٹٲ�
}