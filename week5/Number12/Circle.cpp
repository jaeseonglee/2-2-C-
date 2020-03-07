/*	실습 12번 : Circle.cpp
	작성일 : 2019.09.28
	작성자 : 20165153 이재성
	프로그램 설명 : 실습문제에서 주어진 두 클래스를 가지고 출력결과와 같이 나오도록 코드를 완성하는 실습
					원의 이름과 반지름을 입력받아 저장하고, 이름으로 원을 검색하거나 입력받은 면적보다 큰 원들을
					출력하는 프로그램 
*/

#include <iostream>
#include <string>			// 문자열 사용을 위해 include
using namespace std;

class Circle {			// Circle 클래스 
	int radius = 0;		// 원의 반지름 값
	string name = "";	// 원의 이름
public:
	Circle() {  };		// 기본 생성자, 생략 가능
	void setCircle(string name, int radius);	// 이름과 반지름 설정
	double getArea() { return 3.14 * radius * radius; }	// 원의 넓이를 반환하는 getArea함수
	string getName() { return name; }					// 원의 이름을 반환하는 getName함수
};

void Circle::setCircle(string name, int radius) {		// 매개변수를 멤버변수에 저장하는 setCircle 함수
	this->name = name;			// this를 사용해서 매개변수로 초기화해준다
	this->radius = radius;
}

class CircleManager {		// CircleManager 클래스 
	Circle *p = nullptr;	// Circle 배열에 대한 포인터
	int size = 0;			// 배열의 크기
public:
	CircleManager(int size);	// size 크기의 배열을 동적 생성. 사용자로부터 입력완료
	~CircleManager();			// 소멸자
	void searchByName();		// 사용자로부터 원의 이름을 입력받아 면적 출력
	void searchByArea();		// 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력

};

CircleManager::CircleManager(int size) {	// 매개변수가 있는 생성자
	this->size = size;			// 매개변수로 받은 값을 size에 저장
	p = new Circle[size];		// 입력받은 size만큼 객체 배열을 할당해준다
	
	string name = "";			// 아래 반복문에서 이름과 반지름을 저장할 변수 선언
	int radius = 0;

	for (int i = 0; i < size; i++) {	// 반복문을 통해 배열크기만큼
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";	// 원들의 정보를 입력받는다
		cin >> name >> radius;			// 변수에 입력받은 값을 넣어주고
		p[i].setCircle(name, radius);	// 각 인덱스에 이름과 반지름을 입력해준다
	}
}

void CircleManager::searchByName() {	// 입력된 이름으로 원을 찾는 searchByName함수
	string name = "";		// 이름을 입력받기 위한 변수 선언 
	int count = 0;			// 찾지 못하면 없다고 출력하기 위해 정수형 변수 count 선언 및 0으로 초기화

	cout << "검색하고자 하는 원의 이름 >> ";	// 원의 이름을 입력해달라고 출력
	cin >> name;						// name에 저장
	for (int i = 0; i < size; i++) {	// 반복문을 통해
		if (name == p[i].getName()) {	// 입력된 이름과 같은 원이 있다면
			cout << name << "의 면적은 " << p[i].getArea() << endl;	// 원의 면적을 출력하고
			count++;		// count를 증가시키고
			break;			// 반복문을 빠져나간다
		}
	}

	if (count == 0) {		// 만약 원을 찾지 못했다면
		cout << "입력하신 이름과 일치하는 원이 없습니다!" << endl;	 // 없다고 출력해준다
	}
}

void CircleManager::searchByArea() {		// 입력받은 면적보다 큰 원을 찾는 searchByArea함수
	int num = 0;			// 면적을 저장할 변수 선언
	int count = 0;			// searchByName과 같이 결과가 없다면 없다고 출력하기위해 선언 및 초기화
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> num;				// 입력받은 값을 num에 저장
	cout << num << "보다 큰 원을 검색합니다." << endl;

	for (int i = 0; i < size; i++) {	// 반복문을 통해
		if (num < p[i].getArea()) {		// 각 인덱스에 저장된 원들의 면적이 입력받은 값보다 크면
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";	// 원의 이름과 면적을 출력
			count++;					// 그리고 count를 증가시켜준다.
		}
	}

	if (count == 0) {	// 아무것도 출력하지 못했다면
		cout << "입력하신 면적보다 큰 원이 없습니다!" << endl;	//결과가 없다고 출력해준다
	}

	cout << endl;		// 모든 출력이 끝나면 줄바꿈
}

CircleManager::~CircleManager() {		// 소멸자
	delete [] p;			// 동적할당받은 CircleManager의 p를 delete를 통해 반환해준다.
}

int main() {			// main 함수
	int num = 0;		// 원의 개수를 입력받은 변수 num 선언 및 0으로 초기화
	CircleManager *p = nullptr;	// 동적할당 받기위해 객체 포인터 변수 p 선언 및 초기화

	cout << "원의 개수 >> ";		// 원의 개수를 입력해달라고 출력
	cin >> num;					// 입력받은 값을 num에 초기화
	p = new CircleManager(num);	// num으로 CircleManager 객체 동적 할당
	p->searchByName();			// 이름으로 원을 검색
	p->searchByArea();			// 입력한 면적보다 큰원을 검샘
	p->~CircleManager();		// 객체 생성자의 소멸자를 실행
	delete p;					// main 함수의 포인터 p 반환을 위해 delete해준다
}

