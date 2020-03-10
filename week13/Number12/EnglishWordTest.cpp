/*	�ǽ� 12�� : EnglishWordTest.cpp
	�ۼ��� : 2019.11.21 ~ 11.24
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ���� ���� �׽�Ʈ ���α׷�. ���� �ܾ�� �ѱ� �ܾ�� �����Ǵ� Word Ŭ������ �ۼ��ϰ�, vector<Word> v;��
		���͸� �����ϰ� , ���α׷� ������ �������� Word ��ü�� ���׾� ������ �д�. �׸��� �����ϰ� ����ڿ��� ������ ������ 
		4���� ���� �� ������ ������ 3���� ���Ϳ� �ִ� �ܾ��߿��� �����ϰ� �����Ѵ�. �̹������� iterator�� ����� �ʿ䰡 ����.
*/
#include <iostream>
#include <vector>		// ����
#include <ctime>		// time
#include <cstdlib>		// ���� ����
using namespace std;

class Word {			// ���� �ܾ�� �ѱ� �ܾ�� �����Ǵ� Word Ŭ����
	string english;		// ���� �ܾ�
	string korean;		// �ѱ� �ܾ�
public:
	Word(string eng, string kor) {	// ������
		english = eng;
		korean = kor;
	}
	string getEnglish() { return english; }	// �� ������ ���� getter �Լ�
	string getKorean() { return korean; }
};

void engKorTest(vector<Word>& v) {	// ���� ���� �׽�Ʈ ���α׷��� �����ϴ� engKorTest�Լ�, main�� ���͸� �����ڸ� ���� ����
	int num = 0;		// ó�� ���ÿ� ���� ���� �����ϴ� ���� num
	int answer = 0;		// ���� �׽�Ʈ���� ������ �ε����� ���� �Ǵ� ��ȣ�� �����ϴ� ���� answer
	int temp = 0;		// ���� ������ ���� ���� �ӽ������� ������ ���� temp
	int result = 0;		// ���� �׽�Ʈ���� ����ڿ��� ���� �Է¹��� ���� result
	int index[4];		// ���� �׽�Ʈ���� ���⿡�� ���� int�� �迭 index
	string engWord;		// ���� ���Կ��� ���� �ܾ �Է¹��� ���� engWord
	string korWord;		// ���� ���Կ��� �ѱ� �ܾ �Է¹��� ���� korWord

	cout << "***** ���� ���� �׽�Ʈ�� �����մϴ�. *****" << endl;		// ���� �׽�Ʈ ����
	while (1) {			// ���� �ݺ���
		cout << "���� ����: 1, ���� �׽�Ʈ : 2, ���α׷� ����:�׿�Ű >> ";	
		cin >> num;		

		if (num == 1) {				// ���� ����
			cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��" << endl;
			while (1) {				// ���� �ݺ���
				cout << "���� >>";	// ���� �ܾ� �Է�
				cin >> engWord;		
				if (engWord == "exit") {	// ���⼭ exit�� �ԷµǸ�
					cout << endl << endl;	// �ٹٲ� ���ְ� 
					break;					// ���� �ܰ踦 �����Ѵ�(������ ���� �ݺ��� ����)
				}	
				cout << "�ѱ� >>";	// �ѱ� �ܾ� �Է�
				cin >> korWord;
				v.push_back(Word(engWord, korWord));	// �Էµ� �� �ܾ ���Ϳ� ����
			}
		}

		else if (num == 2) {		// ���� �׽�Ʈ
			cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� Ű �Է½� ����." << endl;
			while (1) {				// ���� �ݺ���
				answer = rand() % v.size();		// �������� ���� �ܾ� ����
				cout << v[answer].getEnglish() << "?" << endl;	// ���� �ܾ� ���
				index[0] = answer;				// ���� �ܾ��� �ε����� index[0]�� ����

				for (int i = 1; i < 4; i++) {		// ��ø �ݺ����� ���� �ٸ� ������� ����, 0���� �����̱� ������ 1������ ����
					index[i] = rand() % v.size();	// �������� �ܾ� ����
					for (int j = 0; j < i; j++) {	// �ߺ��� Ȯ���ϴ� �ݺ���
						if (index[j] == index[i] ) {// ������ �ε����� ������ ������ �ε��� ���� ������
							i--;					// i�� ���� �ٿ��ְ�
							break;					// ������ �ݺ��� Ż��
						}
					}
				}

				temp = rand() % 4;					// ������ ����� �������� �ϱ� ���� temp�� ������ ����(0~3)
				for (int i = 1; i <= 4; i++) {		// �ݺ����� ���� ���⸦ ���� ���
					cout << "(" << i << ") " << v[index[temp]].getKorean() << " ";
					if (temp == 0) {				// temp�� ������ �ε��� 0���� ����Ǿ�����
						temp = 4;					// 4�� �ʱ�ȭ ���ְ�
						answer = i;					// �ε����� ������ִ� answer�� ������ ��ȣ�� �������ش�
					}
					temp--;							// ���� �ϳ�����Ҷ����� temp�� ����
				}
				
				cout << ":>";						// ����ڷκ��� ������ ��ȣ�� �Է¹޴´�
				cin >> result;				
				if (result < 1 || result > 4) {		// 1 ~ 4������ �ٸ� ��ȣ�� �ԷµǸ�
					cout << endl;					// �ٹٲ� ���ְ�
					break;							// ���� �׽�Ʈ�� �����Ѵ�
				}
				if (result  == answer) { cout << "Excellent !!" << endl; }	// �Էµ� ��ȣ�� answer�� ����� ��ȣ�� ������ ����
				else { cout << "No. !!" << endl; }	// �װ� �ƴ϶�� ���� 
			}
		}
		else {				// 1,2���� �ƴ� �ٸ� ��ȣ�� �ԷµǸ�
			cout << "���α׷� ����" << endl;	// ���α׷� ����
			return;			// ���� �ݺ����� ���������� �Լ� ����
			// break; 
		}
	}
}

int main() {				// main �Լ�
	vector<Word> v;			// Word Ŭ������ vector ����
	v.push_back(Word("human", "�ΰ�"));		// �־��� �����ڷḦ ����
	v.push_back(Word("society", "��ȸ"));	// vector�� ���Ҹ� �������ش�
	v.push_back(Word("dall", "����"));
	v.push_back(Word("emotion", "����"));
	v.push_back(Word("painting", "�׸�"));
	v.push_back(Word("trade", "�ŷ�"));
	v.push_back(Word("baby", "�Ʊ�"));
	v.push_back(Word("stock", "�ֽ�"));
	v.push_back(Word("bear", "��"));
	v.push_back(Word("dall", "����"));
	v.push_back(Word("animal", "����"));
	v.push_back(Word("lover", "����"));
	v.push_back(Word("photo", "����"));
	v.push_back(Word("love", "���"));
	v.push_back(Word("oneself", "�ڱ�"));

	srand(time(NULL));		// ������ �õ尪 ����
	engKorTest(v);			// engKorTest �Լ� ȣ��
}