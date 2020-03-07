/*	�ǽ� 14�� : GamblingGame.cpp
	�ۼ��� : 2019.09.28
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : �λ���� �ϴ� �׺� ������ ������ ���α׷�. ������ �̸��� �ʱ⿡ �Է¹ް�,
					���� ������ �ڽ��� ���ʿ��� <Enter. Ű�� ġ�� ������ 3���� ���� �����ǰ�
					��� ������ ���� ������ ���ӿ��� �̱�� �ȴ�. ������ ������ �ʹ� ũ�� 3���� ���ڰ�
					��ġ�� ���ɼ��� ���� ������ ������ 0~2�� �����Ѵ�.
					������ PlayerŬ������ �ۼ��ϰ� 2���� ������ �迭�� �����϶�. ������ GamblingGame Ŭ������ �ۼ��Ѵ�.
*/

#include <iostream>
#include <string>	// ���ڿ� ����� ���� string
#include <cstdlib>	// ���� ������ �߻���Ű�� ���ؼ� cstdlib,ctime
#include <ctime>
using namespace std;

#define SIZE 3		// define������ SIZE�� 3���� ����

class Player {		// Palyer Ŭ����
	string name = "";	// Palyer�� �̸��� ������ name
public:
	Player() { };		// ������
	~Player() { };		// �Ҹ���
 	void setName(string name) {	this->name = name; }	// �Ű������� ���� ������ �̸��� ������ setName �Լ�
	string getName() { return name; }	// �̸��� ��ȯ�ϴ� getName�Լ�
};

class GamblingGame {	// GamblingGame Ŭ����
	Player p[2];		// �θ��̼� ������ �����Ϲǿ� ũ�Ⱑ 2�� �迭 ����
	int ranNum[SIZE] = {};	// ������ 3���� ������ ������ ������ �迭 ���� �� �ʱ�ȭ
public:
	GamblingGame();		// ������
	~GamblingGame() { };//�Ҹ���
	void play();		// ������ �����ϴ� play�Լ�
};

GamblingGame::GamblingGame() {		// ������
	srand((unsigned)time(NULL));	// ó�� �����ڸ� ȣ���� �� ���� ���� ������ �������ش�.
}

void GamblingGame::play() {		// ������ �����ϴ� play �Լ�
	int playerTurn = 0;			// ���ʸ� ��Ÿ���� ������ ���� playerTurn
	string enterKey = "";		// �ٹٲ� ����(Entet)�� �Է¹��� enterKey
	string name = "";			// �̸��� ������ name 

	cout << "***** �׺� ������ �����մϴ�. *****" << endl;	// ������ �����Ѵٰ� ���
	cout << "ù��° ���� �̸�>>";	// ù��° �����̸��� �Է��ش޶�� ���
	cin >> name;
	p[0].setName(name);			// ù��° ���� �̸��� ����

	cout << "�ι�° ���� �̸�>>";	// �ι�° �����̸��� �Է��ش޶�� ���
	cin >> name;
	p[1].setName(name);			// �ι�° ���� �̸��� ����
	getchar();					// �ι�° ���� �̸��� �����ϸ鼭 ����Ű�� �ԷµǴµ� ���⼭ ���۸� ����ֱ� ���� ���

	while (true) {				// ������ �����ϴ� ���� �ݺ���. �� ������ �¸��ϸ� �ݺ��� �����Ѵ�
		cout << p[playerTurn].getName() << ": <Enter>";		// Enter�� �Է��ش޶�� ���
		getline(cin, enterKey);			// ����Ʈ���� Enter���� �̿��ؼ� getline���� �Է¹޴´�.
		
		cout << "\t\t";					// �� �ι��ϰ� ���
		for (int i = 0; i < SIZE; i++) {// �ݺ����� ���� �����迭�� ���� �ʱ�ȭ���ش�.
			ranNum[i] = rand() % 3;		// �������� �־��� ��� 0~2������ ������ �ʱ�ȭ
			cout << ranNum[i] << "\t";		// �ʱ�ȭ�� �� �ε��� �� ���
		}

		if ((ranNum[0] == ranNum[1]) && ranNum[1] == ranNum[2]) {	// �迭�� ��� ���� ���� ���̶��
			cout << p[playerTurn].getName() << "�� �¸�!!" << endl;	// ���� ������ �¸��Ѵ�
			break;		// �׸��� �ݺ����� ����������
		}
		else {				// �¸������� �������� ��������
			cout << "�ƽ�����!" << endl;	// �ƽ����� ���
		}

		if (playerTurn) { playerTurn--; }	// �� ������ ���ʸ� ����������
		else { playerTurn++; }				// ���� �����ϰų� ���ҽ�Ű�鼭 ���ʸ� �ְ�޴´�
	}
}

int main() {			// main�Լ�	
	GamblingGame p;		// ��ü�� ����
	p.play();			// play�Լ��� ȣ�������μ� ��������
}