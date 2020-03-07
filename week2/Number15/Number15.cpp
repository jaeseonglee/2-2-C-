/*	C++ 프로그래밍 2주차 과제
	실습 15번 : Number15.cpp
	작성일 : 2019.09.05 ~ 09.07
	작성자 : 20165153 이재성
	프로그램 설명 : +,-,*,/,%의 정수 5칙 연산을 할 수 있는 프로그램
				정수와 연산자는 하나의 빈칸으로 분리하여 계산한다.
*/
#define _CRT_SECURE_NO_WARNINGS	// C의 문자 처리함수가 오류를 출력하지 않게 하는 define문
#include <iostream>				// 표준 전처리문
using namespace std;
#include <cstring>				// C의 문자 처리함수를 위해 사용

#define SIZE 100				// define문을 통해 SIZE 100으로 지정

int main() {					//main 함수
	char word[SIZE] = "";		// 연산식을 저장할 word 선언 및 초기화
	char num1[SIZE] = "";		// 첫번째 항의 숫자를 저장할 num1 선언 및 초기화
	char num2[SIZE] = "";		// 두번째 항의 숫자를 저장할 num1 선언 및 초기화
	char temp[SIZE] = "";		// NULL문자로 초기화된 임시 문자 배열
	char calculator = NULL;		// 연산자를 저장할 calculator
	int i, j;					// C++ 에서는 반복문에서 선언이 가능하다
	int count = 0;				// 빈칸 횟수마다 값을 저장하기 위한 count 선언 및 0으로 초기화

	while (1) {					// 무한 반복문 C++에서는 bool타입이 새로 생겼다(true,false도 존재)
		cout << "? ";			// 연산식을 입력해달라고 출력
		cin.getline(word, SIZE, '\n');	// getline을 통해 식을 word에 저장

		for (i = 0, j = 0, count = 0; i < strlen(word); i++) {	//반복문을 통해 정수와 연산자를 저장
			if (isspace(word[i])) {		// isspace를 통해 word[i]가 공백이면
				count++;				// count를 증가시키고
				continue;				// continue를 통해 반복문을 다시 반복한다
			}							// isspace도 C문자 처리 함수다 -> cstring사용
			else {						// 공백이 아니라면
				switch (count) {		
				case 0:					// 첫번째 공백이 오기전까지의 숫자를
					num1[i] = word[i];	// num1에 저장해준다
					break;				
				case 1:					// 두번째 공백이 오면 연산자가 나오므로
					calculator = word[i];	// calculator에 저장해준다
					break;
				case 2:					// 공백 두번이 지나가면 정수만이 남으므로
					num2[j++] = word[i];// num2에 저장해준다.
					break;
				default:				// 입력이 a + b(정수 연산자 정수)형태가 아니라면
					cout << "잘못된 입력!!" << endl;		// 잘못된 입력을 출력후
					return 0;			// 프로그램 종료
				}
			}
		}

		cout << num1 << " " << calculator << " " << num2 << " = ";	// 연산 결과를 출력

		switch (calculator) {	// 어떤 연산자냐에 따라서
		case '+':
			cout << atoi(num1) + atoi(num2) << endl;		// 덧셈계산 및 출력
			break;					// atoi()함수로 문자열을 정수로 바꿔준다. 교재93p 15번 하단 참조
		case '-':
			cout << atoi(num1) - atoi(num2) << endl;		// 뺄셈계산 및 출력
			break;
		case '*':
			cout << atoi(num1) * atoi(num2) << endl;		// 곱셈계산 및 출력
			break;
		case '/':
			cout << atoi(num1) / atoi(num2) << endl;		// 나눗셈계산 및 출력
			break;
		case '%':
			cout << atoi(num1) % atoi(num2) << endl;		// 나머지계산 및 출력
			break;
		default:								// 5칙연산이 아닌 다른 경우는
			cout << "잘못된 입력!!" << endl;		// 잘못된 입력을 출력후
			return 0;			// 프로그램 종료
		}

		strncpy(num1, temp, strlen(num1));	// strncpy()함수는 문자열의 일부를 복사하는 함수
		strncpy(num2, temp, strlen(num2));	// 여기서는 strncpt를 통해 num1과 num2를 temp로 복사저장하여,
											// 즉 NULL문자로 초기화해주어 다음 반복때에 버퍼를 비워준다는 느낌이다
											// 향후 다시 코드를 볼때 다른 방법이 있는지 확인(19.09.07)
	}

}
