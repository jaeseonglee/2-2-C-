/*	실습 6번 : RemoveFunc.cpp
	작성일 : 2019.11.21 ~ 11.24
	작성자 : 20165153 이재성
	프로그램 설명: 매개변수로 주어진 int 배열을 src에서 배열 minus에 들어있는 같은 정수를 모두 삭제한 새로운 int
		배열을 동적으로 할당받아 리턴한다. retSize는 remove()함수의 실행 결과를 리턴하는 배열의 크기를 전달받는다.
*/
#include <iostream>
using namespace std;

template <class T>			// template 선언
T* remove(T src[], T sizeSrc, T minus[], T sizeMinus, T& retSize) {	// remove 함수 일반화
	int index = 0;			// 새로운 배열의 인덱스
	T* result;				// 새로운 배열을 가리킬 포인터
	retSize = sizeSrc;		// retSize를 sizeSrc로 초기화

	for (int i = 0; i < sizeSrc; i++) {	// 중첩 반복문을 통해
		for (int j = 0; j < sizeMinus; j++) {	// 중복되는 원소를 제거
			if (src[i] == minus[j]) {	
				src[i] = NULL;		
				retSize--;		// 제거되는 만큼 retSize감소
			}
		}
	}
	
	result = new T[retSize];	// retSize 만큼 동적 할당
	for (int i = 0; i < sizeSrc; i++) {	// 반복문을 통해
		if (src[i] != NULL) {		// src의 남은 원소들을 복사
			result[index] = src[i];	// cnt값이 인덱스가 되어 복사
			index++;				// 복사할때 마다 인덱스 증가
		}
	}
	return result;			// 새로 할당된 배열 리턴
}

int main() {			// main 함수
	int num = 0;		
	int* temp = nullptr;	// remove 함수를 통해 반환되는 배열을 저장할 포인터
	int a[] = { 1,2,3,4 };	
	int b[] = { -3,5,10,1,2,3 };
	int aSize = sizeof(a) / sizeof(a[0]);
	int bSize = sizeof(b) / sizeof(b[0]);

	double num2 = 0;
	double* temp2 = nullptr;	// remove 함수를 통해 반환되는 배열을 저장할 포인터
	double c[] = { 1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9 };
	double d[] = { 3.5, 4.8, 1.0, 2.0, 3.0 };
	int cSize = sizeof(c) / sizeof(c[0]);
	int dSize = sizeof(d) / sizeof(d[0]);

	cout << "정수 배열 {" << a[0];
	for (int i = 1; i < aSize; i++) { cout << "," << a[i]; }
	cout << "}에서 정수 배열 {" << b[0];
	for (int i = 1; i < bSize; i++) { cout << "," << b[i]; }
	cout << "}을 뺍니다" << endl;			

	temp = remove(a, aSize, b, bSize, num);		// remove 함수를 통해 temp에 배열 전달
	for (int i = 0; i < num; i++) {	cout << temp[i] << " "; }	// 반복문을 통해 출력
	cout << endl << endl;

	printf("실수 배열 {%.1lf", c[0]);						  //cout << "실수 배열 {" << (float)c[0];
	for (int i = 1; i < cSize; i++) printf(", %.1lf", c[i]);  //{ cout << ", " << c[i]; }
	cout << "}에서 \n실수 배열 {" << d[0];
	for (int i = 1; i < dSize; i++) printf(", %.1lf", d[i]);  //{ cout << ", " << d[i]; }
	cout << "}을 뺍니다" << endl;

	temp2 = remove(c, (double)cSize, d, (double)dSize, num2);	// remove 함수를 통해 temp2에 배열 전달
	for (int i = 0; i < num2; i++) { cout << temp2[i] << " "; } // 반복문을 통해 출력

	if (temp)  delete[] temp;		// 할당된 배열 반환
	if (temp2) delete [] temp2;
}