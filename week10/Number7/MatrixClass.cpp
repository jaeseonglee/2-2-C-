/*	실습 7번 : MatrixClass.cpp
	작성일 : 2019.11.04 ~ 11.06
	작성자 : 20165153 이재성
	프로그램 설명: 2차원 행렬을 추상화한 Matrix 클래스를 활용하는 프로그램
*/

#include <iostream>
using namespace std;

#define SIZE 4		// define문을 통해 SIZE를 4로 지정

class Matrix {		// Matrix 클래스
	int arr[SIZE];	// 정수형 배열 선언
public:
	Matrix() { arr[0], arr[1], arr[2], arr[3] = 0; }	// 매개변수가 없는 생성자는 배열의 값들을 0으로 초기화해준다
	Matrix(int a, int b, int c, int d);				//	생성자
	void show();					// 배열을 출력하는 show 함수
	//void operator<<(int *array);	// << 연산자 함수	7-1번 멤버함수로 구현
	//void operator>>(int* array);	// >> 연산자 함수	7-1번 멤버함수로 구현
	friend Matrix& operator<<(Matrix& m, int* array);		// 7-2번 프렌드 함수로 구현
	friend void operator>>(Matrix m, int* array);		// 7-2번 프렌드 함수로 구현

};

Matrix::Matrix(int a, int b, int c, int d) {	// 생성자
	arr[0] = a;		// 매개변수의 값들을 각각의 배열에 인덱스에 저장
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
}

void Matrix::show() {			// 배열을 출력하는 show 함수
	cout << "Matrix = { ";		
	for (int i = 0; i < SIZE; i++) {		// 반복문을 통해 출력
		cout << arr[i] << " ";
	}
	cout << " }" << endl;
}
/*7-1번 멤버함수로 구현
void Matrix::operator<<(int* array) {	// << 연산자 함수
	for (int i = 0; i < SIZE; i++) {
		arr[i] = array[i];		// 매개변수로 받은 배열의 값들을 Matrix의 배열 각각에 값에 저장한다
	}
}

void Matrix::operator>>(int* array) {	// >> 연산자 함수 , 포인터를 통해 주소를 받아온다
	for (int i = 0; i < SIZE; i++) {	// Matrix의 배열의 각각의 값들을 매개변수로 받은 배열에 저장한다
		array[i] = arr[i];
	}
}
*/

Matrix& operator<<(Matrix& m, int *array) {		// 7-2번 프렌드 함수로 구현, 이 경우에는 객체를 반환하도록 하게 해준다
	for (int i = 0; i < SIZE; i++) {
		//m.arr[i] = array[i];		// 매개변수로 받은 배열의 값들을 Matrix의 배열 각각에 값에 저장한다
		m.arr[i] = array[i];
	}
	return m;
}

void operator>>(Matrix m, int* array) {	// 7-2번 프렌드 함수로 구현
	for (int i = 0; i < SIZE; i++) {	// Matrix의 배열의 각각의 값들을 매개변수로 받은 배열에 저장한다
		array[i] = m.arr[i];
	}
}

int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[SIZE], y[SIZE] = { 1,2,3,4 };		// 2차원 행렬의 4개의 원소 값
	a >> x;		// a의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1}
	b << y;		// 배열 y의 원소 값을 b의 각 원소에 설정

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';	// x[] 출력 
	cout << endl;
	b.show();
}
