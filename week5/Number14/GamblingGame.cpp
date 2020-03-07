/*	실습 14번 : GamblingGame.cpp
	작성일 : 2019.09.28
	작성자 : 20165153 이재성
	프로그램 설명 : 두사람이 하는 겜블링 게임을 구현한 프로그램. 선수의 이름을 초기에 입력받고,
					선가 번갈아 자신의 차례에서 <Enter. 키를 치면 랜덤한 3개의 수가 생성되고
					모두 동일한 수가 나오면 게임에서 이기게 된다. 숫자의 범위가 너무 크면 3개의 숫자가
					일치할 가능성이 낮아 숫자의 범위를 0~2로 제한한다.
					선수는 Player클래스로 작성하고 2명의 선수는 배열로 구성하라. 게임은 GamblingGame 클래스로 작성한다.
*/

#include <iostream>
#include <string>	// 문자열 사용을 위해 string
#include <cstdlib>	// 랜덤 정수를 발생시키기 위해서 cstdlib,ctime
#include <ctime>
using namespace std;

#define SIZE 3		// define문으로 SIZE를 3으로 지정

class Player {		// Palyer 클래스
	string name = "";	// Palyer의 이름을 저장할 name
public:
	Player() { };		// 생성자
	~Player() { };		// 소멸자
 	void setName(string name) {	this->name = name; }	// 매개변수로 받은 값으로 이름을 저장할 setName 함수
	string getName() { return name; }	// 이름을 반환하는 getName함수
};

class GamblingGame {	// GamblingGame 클래스
	Player p[2];		// 두명이서 게임을 진행하므오 크기가 2인 배열 생성
	int ranNum[SIZE] = {};	// 랜덤한 3개의 정수를 저장할 정수형 배열 선언 및 초기화
public:
	GamblingGame();		// 생성자
	~GamblingGame() { };//소멸자
	void play();		// 게임을 진행하는 play함수
};

GamblingGame::GamblingGame() {		// 생성자
	srand((unsigned)time(NULL));	// 처음 생성자를 호출할 때 난수 생성 범위를 지정해준다.
}

void GamblingGame::play() {		// 게임을 진행하는 play 함수
	int playerTurn = 0;			// 차례를 나타내는 정수형 변수 playerTurn
	string enterKey = "";		// 줄바꿈 문자(Entet)를 입력받을 enterKey
	string name = "";			// 이름을 저장할 name 

	cout << "***** 겜블링 게임을 시작합니다. *****" << endl;	// 게임을 시작한다고 출력
	cout << "첫번째 선수 이름>>";	// 첫번째 선수이름을 입력해달라고 출력
	cin >> name;
	p[0].setName(name);			// 첫번째 선수 이름을 저장

	cout << "두번째 선수 이름>>";	// 두번째 선수이름을 입력해달라고 출력
	cin >> name;
	p[1].setName(name);			// 두번째 선수 이름을 저장
	getchar();					// 두번째 선수 이름을 저장하면서 엔터키가 입력되는데 여기서 버퍼를 비워주기 위해 사용

	while (true) {				// 게임을 진행하는 무한 반복문. 한 선수가 승리하면 반복을 종료한다
		cout << p[playerTurn].getName() << ": <Enter>";		// Enter를 입력해달라고 출력
		getline(cin, enterKey);			// 디폴트값인 Enter임을 이용해서 getline으로 입력받는다.
		
		cout << "\t\t";					// 탭 두번하고 출력
		for (int i = 0; i < SIZE; i++) {// 반복문을 통해 정수배열에 값을 초기화해준다.
			ranNum[i] = rand() % 3;		// 문제에서 주어진 대로 0~2사이의 값으로 초기화
			cout << ranNum[i] << "\t";		// 초기화된 각 인덱스 값 출력
		}

		if ((ranNum[0] == ranNum[1]) && ranNum[1] == ranNum[2]) {	// 배열의 모든 값이 같은 값이라면
			cout << p[playerTurn].getName() << "님 승리!!" << endl;	// 현재 선수가 승리한다
			break;		// 그리고 반복문을 빠져나간다
		}
		else {				// 승리조건을 만족하지 못했으면
			cout << "아쉽군요!" << endl;	// 아쉽군요 출력
		}

		if (playerTurn) { playerTurn--; }	// 한 선수가 차례를 끝낼때마다
		else { playerTurn++; }				// 값을 증가하거나 감소시키면서 차례를 주고받는다
	}
}

int main() {			// main함수	
	GamblingGame p;		// 객체를 생성
	p.play();			// play함수를 호출함으로서 게임진행
}