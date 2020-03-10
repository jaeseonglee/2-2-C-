/*	실습 12번 : CoffeeVendingMachine.cpp
	작성일 : 2019.12.04 ~ 07
	작성자 : 20165153 이재성
	프로그램 설명: 커피 자판기 시뮬레이터를 C++로 작성한 프로그램. 자판기는 보통 커피, 설탕 커피, 블랙 커피 3종류만 판매한다.
*/
#include <iostream>
using namespace std;
#define SIZE 3			// define문을 통해 SIZE를 3으로 지정

class CoffeeVendingMachine {	// CoffeeVendingMachine 클래스
	int* coffee = nullptr;		// 커피 설탕 크림
	int *sugar = nullptr;		// 물 컵에 대한 포인터 선언
	int *cream = nullptr;
	int *water = nullptr;
	int *cup = nullptr;
public:
	CoffeeVendingMachine() {	// 생성자 
		coffee = new int[SIZE];	// 모든 재료들을
		sugar = new int[SIZE];	// 할당해주고
		cream = new int[SIZE];
		water = new int[SIZE];
		cup = new int[SIZE];
		fill();					// fill 함수를 통해 모든 값을 1로 초기화
		cout << "-----명품 커피 자판기켭니다.-----" << endl;
	}
	~CoffeeVendingMachine() {	// 소멸자
		delete[] coffee;		// 생성자에서 할당한 포인터들을
		delete[] sugar;			// 반환해준다
		delete[] cream;
		delete[] water;
		delete[] cup;
		cout << "-----명품 커피 자판기끕니다.-----" << endl << "이용해주셔서 감사합니다." << endl;
	}
	void status();				// 현재 재료들의 상태를 출력하는 status 함수
	void fill();				// 재료들의 통을 채우는 fill 함수
	void normalCoffee();		// 보통 커피를 만드는 normalCoffee 함수
	void sugarCoffee();			// 설탕 커피를 만드는 sugarCoffee 함수
	void blackCoffee();			// 블랙 커피를 만드는 blackCoffee 함수
	void sell();				// 커피 자판기 판매기능을 맡는 sell 함수
};	

void CoffeeVendingMachine::status() {	// 재료들의 상태가 각각 다를 수 있기 때문에 
	cout << "Coffee\t";					// 재료들 마다 각각의 반복문을 통해 현재 값 출력
	for (int i = 0; i < SIZE; i++) { 
		if(coffee[i] != 0)
			cout << "*"; 
	}
	
	cout << endl << "Sugar\t";
	for (int i = 0; i < SIZE; i++) {
		if (sugar[i] != 0)
			cout << "*";
	}

	cout << endl << "CREAM\t";
	for (int i = 0; i < SIZE; i++) {
		if (cream[i] != 0)
			cout << "*";
	}

	cout << endl << "Water\t";
	for (int i = 0; i < SIZE; i++) {
		if (water[i] != 0)
			cout << "*";
	}

	cout << endl << "Cup\t";
	for (int i = 0; i < SIZE; i++) {
		if (cup[i] != 0)
			cout << "*";
	}
	cout << endl << endl;
}

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < SIZE; i++) {	// 생성자에서 할당된 포인터에
		coffee[i] = 1;		// 전부 1로 초기화 해준다
		sugar[i] = 1;
		cream[i] = 1;
		water[i] = 1;
		cup[i] = 1;
	}
}

void CoffeeVendingMachine::normalCoffee() {
	if (coffee[0] == 0 || water[0] == 0 || cup[0] == 0) {	// 재료가 하나라도 부족하면
		cout << "재료가 부족합니다!! 임의로 모든 통을 채웁니다. ~~ 다시 선택해주세요" << endl;
		fill();		// 임의로 채워주고
		return;		// 함수 종료
	}

	for (int i = SIZE - 1; i >= 0; i--) {	// 위의 조건문을 지나쳐오면 각 재료들을 하나씩 소비
		if (coffee[i] == 1) {
			coffee[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (water[i] == 1) {
			water[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cup[i] == 1) {
			cup[i] = 0;
			break;
		}
	}
	cout << "맛있는 보통 커피 나왔습니다~~" << endl;
}

void CoffeeVendingMachine::sugarCoffee() {
	if (coffee[0] == 0 || sugar[0] == 0 || water[0] == 0 || cup[0] == 0) {	// 재료가 하나라도 부족하면
		cout << "재료가 부족합니다!! 임의로 모든 통을 채웁니다. ~~ 다시 선택해주세요" << endl;
		fill();		// 임의로 채워주고
		return;		// 함수 종료
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (coffee[i] == 1) {
			coffee[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (sugar[i] == 1) {
			sugar[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (water[i] == 1) {
			water[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cup[i] == 1) {
			cup[i] = 0;
			break;
		}
	}
	cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
}
void CoffeeVendingMachine::blackCoffee() {
	if (coffee[0] == 0 || sugar[0] == 0 || cream[0] == 0 || water[0] == 0 || cup[0] == 0) {	// 재료가 하나라도 부족하면
		cout << "재료가 부족합니다!! 임의로 모든 통을 채웁니다. ~~ 다시 선택해주세요" << endl;
		fill();		// 임의로 채워주고
		return;		// 함수 종료
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (coffee[i] == 1) {
			coffee[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (sugar[i] == 1) {
			sugar[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cream[i] == 1) {
			cream[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (water[i] == 1) {
			water[i] = 0;
			break;
		}
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		if (cup[i] == 1) {
			cup[i] = 0;
			break;
		}
	}
	cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
}


void CoffeeVendingMachine::sell() {
	int num = 0;		// 입력받기 위한 변수 num
	while (1) {			// 무한 반복문
		status();		// 먼저 상태를 출력
		cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>> ";
		cin >> num;		// 메뉴를 입력받고
		if (num == 0) normalCoffee();		// 보통 커피
		else if (num == 1) sugarCoffee();	// 설탕 커피
		else if (num == 2) blackCoffee();	// 블랙 커피
		else if (num == 3) {				// 모든 통 채우기
			cout << "모든 통을 채웁니다.~~" << endl;
			fill(); 
		}
		else if (num == 4) break;		// 유일한 종료 조건
	}
}

int main() {			// main 함수
	CoffeeVendingMachine *cvm = new CoffeeVendingMachine();	// CoffeeVendingMachine 생성 및 할당
	cvm->sell();		// sell함수를 통해 판매 진행 
	delete cvm;			// 반환하면서 종료
}