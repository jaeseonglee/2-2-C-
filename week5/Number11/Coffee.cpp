/*	실습 11번 : Coffee.cpp
	작성일 : 2019.09.28
	작성자 : 20165153 이재성
	프로그램 설명 : 실습문제에서 주어진 두 클래스를 가지고 출력결과와 같이 나오도록 코드를 완성하는 실습
					커피자판기를 구현하는 프로그램, 주문에 따라 커피를 출력하고 잔량확인과 잔량 채우기까지 구현한다 
					잔량이 없을경우 원료부족까지 출력하는 무한 반복문인 프로그램
*/

#include <iostream>
using namespace std;

class Container {		// 통 하나를 나타내는 클래스
	int size;			// 현재 저장량, 최대 저장량은 10
public:
	Container() { size = 10; }		// 기본 생성자, size를 10으로 초기화
	~Container() {  }				// 소멸자
	void fill() { size = 10; }		// 최대량(10)으로 채우기
	void consume() { size--; }		// 1만큼 소모하기
	int getSize() { return size; }		// 현재 크기 리턴
	
};

class CoffeeVendingMachine {	// 커피자판기를 표현하는 클래스
	Container tong[3];			// tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통을 나타냄
	void fill();				// 3개의 통을 모두 10으로 채움
	void selectEspresso();		// 에스프레소를 선택한 경우, 커피 1, 물 1 소모
	void selectAmericano();		// 아메리카노를 선택한 경우, 커피 1, 물 2 소모
	void selectSugarCoffee();	// 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
	void show();				// 현재 커피, 물, 설탕의 잔량 출력
	int countTong();			// 잔량이 없으면 원료가 부족하다고 출력하는 countTong 함수
public:
 	void run();		// 커피 자판기 작동
};

void CoffeeVendingMachine::fill() {	// 원료를 채우는 fill함수
	for (int i = 0; i < 3; i++) {	// 반복문을 통해 객체배열들의 fill(Container의 함수) 함수를 통해
		tong[i].fill();				// tong의 size를 10으로 채워준다
	}	
	show();					// 채우고 나면 잔량을 출력
}

void CoffeeVendingMachine::selectEspresso() {// 에스프레소를 출력하는 selectEspersso 함수
	cout << "에스프레소 드세요" << endl;		 // 에스프레소를 출력하고
	tong[0].consume();		// 각각 커피 1과 물 1을 소모
	tong[1].consume();
}

void CoffeeVendingMachine::selectAmericano() {// 아메리카노를 출력하는 selectAmericano 함수
	cout << "아메리카노 드세요" << endl;		// 아메리카노를 출력하고
	tong[0].consume();		// 각각 커피 1과
	tong[1].consume();		// 물 2를 소모
	tong[1].consume();
}

void CoffeeVendingMachine::selectSugarCoffee() {// 설탕커피를 출력하는 selectSugarCoffee 함수
	cout << "설탕커피 드세요" << endl;		// 설탕커피를 출력하고
	tong[0].consume();		// 각각 커피 1
	tong[1].consume();		// 물 2
	tong[1].consume();
	tong[2].consume();		// 설탕 1을 소모
}

void CoffeeVendingMachine::show() {	// getSize를 통해 현재의 잔량을 출력하는 show함수
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

int CoffeeVendingMachine::countTong() {	// 현재 tong의 잔량이 하나라도 없으면 원료부족을 출력하는 countTong 함수
	for(int i = 0; i < 3; i++ ) {		// 반복문을 통해
		if (tong[i].getSize() == 0) {	// size가 0인지 확인
			cout << "원료가 부족합니다" << endl;	// 원료가 부족하다고 출력
			return 1;		// 1(ture) 를 리턴
		}
	}
	return 0;		// 원료가 남아있으면 0(false)를 리턴
}

void CoffeeVendingMachine::run(){	// 커피자판기를 작동하는 run함수
	int num = 0;					// 어떤 기능을 실행할지를 저장할 정수형 변수 num을 0으로 초기화
	cout << "***** 커피자판기를 작동합니다. *****" << endl;	// 커피자판기를 작동한다고 출력
	
	while (true){		// 무한 반복문 , 종료 조건은 따로 설정하지 않았다
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피 4:잔량보기, 5:채우기)>> ";
		cin >> num;		// 입력받은 숫자를 num에 저장
		
		switch (num){	// 입력받은 num을 통해 switch문으로 커피자판기를 실행
		case 1:
			if (countTong()) { break; }	// 잔량이 없으면 원료 부족을 출력
			selectEspresso();		// 에스프래소 출력
			break;
		case 2:
			if (countTong()) { break; }	// 잔량이 없으면 원료 부족을 출력 
			else if (tong[2].getSize() == 1) {	// 그리고 아메리카노의 경우 물이 1일 경우에도 원료부족이므로
				cout << "원료가 부족합니다" << endl;	// 원료 부족을 출력하고 
				break;			// break 실행
			}
			selectAmericano();		// 아메리카노 출력
			break;		
		case 3:
			if (countTong()) { break; }		// 잔량이 없으면 원료 부족을 출력 
			else if (tong[2].getSize() == 1) {	// 그리고 설탕커피의 경우 물이 1일 경우에도 원료부족이므로
				cout << "원료가 부족합니다" << endl;	// 원료 부족을 출력하고 
				break;			// break 실행
			}
			selectSugarCoffee(); // 설탕커피 출력
			break;
		case 4:
			show();		// 현재 원료들의 잔량 출력
			break;
		case 5:
			fill();		// 원료들을 최대로 채워준다
			break;
		default:		// 다른 숫자를 입력하면 다시 입력해달라고 출력
			cout << "1번과 5번 사이의 번호를 입력해주세요" << endl;
			break;
		}
	}	
}

int main() {		// main 함수
	CoffeeVendingMachine cvm;	// 객체를 생성하고
	cvm.run();					// 이 파일의 실질적인 작동을 하는 run함수호출로 커피자판기 작동
}