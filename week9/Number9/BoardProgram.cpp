/*	실습 9번 : BoardProgram.cpp
	작성일 : 2019.10.27
	작성자 : 20165153 이재성
	프로그램 설명: 게시판을 구현한 프로그램. 문제에서 제시한 대로 작성, 글을 올리는 기능과 출력기능만 존재한다
*/

#include <iostream>
using namespace std;

#define SIZE 100	// define문으로 SIZE를 100으로 지정
	
class Board {		// 게시판을 구현하는 Board 클래스
	static string board[SIZE];	// 게시판의 글들을 저장하는 board string 배열
	static int number;	// 게시글의 수를 저장할 number
public:
	static void add(string s);	// 게시판에 내용을 추가하는 add
	static void print();		// 게시판의 내용을 출력하는 print
};

string Board::board[SIZE] = {};	// board 배열 초기화
int Board::number = 0;			// number 초기화

void Board::add(string s) {	// 내용을 추가하는 add 함수
	board[number] = s;	// number 인덱스에 매개변수의 내용을 저장
	number++;			// number 증가
}

void Board::print() {	// 내용을 출력하는 print 함수
	cout << "************* 게시판입니다. *************"<<endl;	
	for (int i = 0; i < number; i++) {	// 반복문을 통해 배열의 내용을 출력
		cout << i << ": " << board[i] << endl;
	}
	cout << endl;	// 모든 출력이 끝나면 줄바꿈
}

int main() {		// main함수
	//Board myBoard; // 객체 생성은 컴파일 오류입니다.
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}