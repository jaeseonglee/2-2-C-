#include <iostream>
using namespace std;

#include "Ciecle.h"		// Circle 클래스 사용을 위해 Circle include

int main() {			// main 함수
	Circle *c = nullptr;			// 실습 8) 동적할당을 위해 객체 포인터 생성
	int count = 0;		// 면적이 100보다 큰 원이 있으면 개수를 증가시키는 count 변수
	int rid = 0;		// 키보드로부터 반지름을 저장할 변수 rid 
	int num = 0;		// 실습 8) 키보드로부터 원의 개수를 입력받은 변수 num

	cout << "원의 개수 >> ";		// 실습 8) 원의 개수를 입력받아
	cin >> num;			// 실습8) num에 저장
	c = new Circle[num];// 입력받은 num받은 객체 포인터 배열로 저장
	
	for (int i = 0; i < num; i++) { // 반복문을 통해 원의 반지름을 입력받고 면적이 100보다 큰지 계산
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> rid;			// 반지름을 cin을 통해 입력받고
		c[i].setRadius(rid);	// 객체의 각 인덱스에 반지름으로 설정해준다.
		if (c[i].getArea() > 100) { count++; }	// 조건문을 통해 면적이 100보다 크면 count 값을 증가
	}

	cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;	// 면적이 100보다 큰 원의 개수를 출력
}