#include <iostream>
using namespace std;

#include "Sample.h"		// 헤더파일 include

Sample::Sample(int n) {	// 생성자
	size = n;			
	p = new int[n];		// n개 정수 배열의 동적 생성
 }

void Sample::read() {		// 키보드로부터 정수를 입력받은 read 함수	
	for (int i = 0; i < size; i++) { // 반복문을 통해
		cin >> p[i];		// cin으로 각 인덱스에 값을 저장한다.
	}
}

void Sample::write() {		// 입력된 정수 배열을 출력하는 write 함수
	for (int i = 0; i < size; i++) {	// 반복문을 통해
		cout << p[i] << " ";	// cout으로 배열을 출력한다
	}
	cout << endl;		// 모든 출력이 끝나면 줄바꿈
}

int Sample::big() {		// 배열에서 가장 큰 값을 리턴하는 big 함수
	int answer = p[0];	// 가장 큰 수를 리턴할 answer 변수에 첫번째 인덱스 값을 넣어준다
	for (int i = 1; i < size; i++) {	// 두번째 인덱스의 값부터 끝까지 반복문을 통해
		if (answer < p[i]) { answer = p[i]; }	// 가장 큰 수를 찾아 answer에 저장한다
	}
	return answer;		// 반복문을 통해 저장된 answer 리턴
}

Sample::~Sample() {}	// 소멸자