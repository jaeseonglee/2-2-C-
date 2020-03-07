#include <iostream>
using namespace std;

#include "Tower.h"	// 클래스 Tower를 사용하기 위해 include

int main() {		// main함수, 실문 문제에서 주어진 main 함수와 같다.

	Tower myTower;	// 1미터
	Tower seoulTower(100);	// 100미터
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}