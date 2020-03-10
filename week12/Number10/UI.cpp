#include <iostream>
using namespace std;
#include "UI.h"

int UI::menu() {
	int num = 0;
	while (1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> num;
		if (num == 1 || num == 2 || num == 3 || num == 4) { return num; }
		else { cout << "주어진 메뉴 중에서 선택해주세요" << endl; }
	}
}
int UI::add() {
	int num = 0;
	while (1) {
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3) {	return num;	}
		else { cout << "세 도형 중에 선택해주세요" << endl; }
	}
}

int UI::deleteIndex() {
	int num = 0;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> num;
	return num;	
}