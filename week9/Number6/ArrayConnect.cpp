/*	실습 6번 : ArrayConnect.cpp
	작성일 : 2019.10.25 ~ 10.27
	작성자 : 20165153 이재성
	프로그램 설명: 동일한 크기의 배열을 반환하는 2개의 static 멤버 변수를 가진 ArrayUtility2 클래스를 만들고,
				이 클래스를 이용하여 주어진 결과와 같이 출력되도록 하는 프로그램
*/

#include <iostream>
using namespace std;

#define SIZE 5		//define문을 통해 SIZE를 5로 지정

class ArrayUtility2 {	// 배열을 새로 전달해주는 ArrayUtility2 클래스
public:
	// s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	static int* concat(int s1[], int s2[], int size);

	// s1에서 s2에 있는 모든 숫자를 모두 삭제한 새로운 배열을 동적생성하여 리턴.
	// 리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우 NULL 리턴
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {	// concat 함수 구현부
	int* newArr = new int[size];			// 동일한 크기의 두 배열을 합친 새로운 배열을 동적 할당
	for (int i = 0; i < size / 2; i++) {	// 반복문을 통해 s1의 값들을 복사
		newArr[i] = s1[i];
	}
	for (int i = 0; i < size / 2; i++) {	// 반복문을 통해 s2의 값들을 복사
		newArr[i + size / 2] = s2[i];
	}
	return newArr;		// size만큼 할당된 newArr 반환
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) { // remove 함수 구현부
	int* newArr;			// 새로운 정수형 포인터 선언
	for (int i = 0; i < size / 2; i++) {		// 중첩 반복문을 통해 두 배열의 차를 구한다
		for (int j = 0; j < size / 2; j++) {	
			if (s1[i] == s2[j]) {	// 배열 중 값이 같다면
				s1[i] = NULL;		// s1의 값을 NULL값으로 초기화
				break;		// 안쪽의 반복문을 빠져나간다
			}
		}
		if(s1[i] != NULL)	// s1의 값이 NULL이 아니라면
			retSize++;		// retSize 증가
	}

	if (retSize == 0) return NULL;	// retSize가 0이면 동적할당할 크기가 없으므로 NULL 리턴
	newArr = new int[retSize];		// retSize만큼의 새로운 배열로 동적 할당

	for (int i = 0, j = 0; i < size/2; i++) {	// 반복문을 통해 s1의 값을 복사
		if (s1[i] != NULL) {	// 단 NULL이 아닌 다른 값들을 복사
			newArr[j] = s1[i];	
			j++;		// 새로운 배열의 인덱스 증가
		}
	}

	return newArr;	// 위의 반복문을 거쳐 할당된 newArr 리턴
}

int main() {	// main 함수
	int x[SIZE];		// 입력으로 저장된 배열 x
	int y[SIZE];		// 입력으로 저장된 배열 y
	int* arr = nullptr;	// 정수형 포인터 arr 선언 및 초기화
	int* arr2 = nullptr;// 정수형 포인터 arr2 선언 및 초기화
	int retSize = 0;	// static형의 함수를 통해 값이 저장된 retSize
	int size = 0;		// 배열의 크기를 저장할 size 선인 및 초기화
	
	cout << "정수를 " << SIZE << " 개 입력하라. 배열 x에 삽입한다>>";
	for (int i = 0; i < SIZE; i++) {	// 반복문을 통해 x 초기화
		cin >> x[i];
	}
	
	cout << "정수를 " << SIZE << " 개 입력하라. 배열 y에 삽입한다>>";
	for (int i = 0; i < SIZE; i++) {	// 반복문을 통해 y 초기화
		cin >> y[i];
	}

	size = sizeof(x) / sizeof(x[0]) + sizeof(y) / sizeof(y[0]);	// 두 배열 크기의 합을 size에 저장
	arr = ArrayUtility2::concat(x, y, size);	// static함수 호출로 arr에 저장
	cout << "합친 정수의 배열을 출력한다" << endl;	
	for (int i = 0; i < size; i++) {		// arr의 결과 출력
		cout << arr[i] << " ";
	}

	arr2 = ArrayUtility2::remove(x, y, size, retSize);	// static 함수 호출로 arr2에 저장
	cout << endl << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 "<< retSize << endl;	// retSize와 함께
	for (int i = 0; i < retSize; i++) {		// arr2 출력
		cout << arr2[i] << " ";
	}

	delete [] arr;		// 동적 할당된 배열을 반환
	delete [] arr2;
}