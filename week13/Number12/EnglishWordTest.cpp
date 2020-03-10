/*	실습 12번 : EnglishWordTest.cpp
	작성일 : 2019.11.21 ~ 11.24
	작성자 : 20165153 이재성
	프로그램 설명: 영어 어휘 테스트 프로그램. 영어 단어와 한글 단어로 구성되는 Word 클래스를 작성하고, vector<Word> v;로
		벡터를 생성하고 , 프로그램 내에서 여려개의 Word 객체를 백테어 삽입해 둔다. 그리고 랜덤하게 사용자에게 문제를 던지며 
		4개의 보기 중 정답을 제외한 3개는 벡터에 있는 단어중에서 랜덤하게 선택한다. 이문제에서 iterator는 사용할 필요가 없다.
*/
#include <iostream>
#include <vector>		// 벡터
#include <ctime>		// time
#include <cstdlib>		// 난수 생성
using namespace std;

class Word {			// 영어 단어와 한글 단어로 구성되는 Word 클래스
	string english;		// 영어 단어
	string korean;		// 한글 단어
public:
	Word(string eng, string kor) {	// 생성자
		english = eng;
		korean = kor;
	}
	string getEnglish() { return english; }	// 각 변수에 대한 getter 함수
	string getKorean() { return korean; }
};

void engKorTest(vector<Word>& v) {	// 영어 어휘 테스트 프로그램을 실행하는 engKorTest함수, main의 벡터를 참조자를 통해 접근
	int num = 0;		// 처음 선택에 대한 값을 저장하는 변수 num
	int answer = 0;		// 어휘 테스트에서 정답의 인덱스를 저장 또는 번호를 저장하는 변수 answer
	int temp = 0;		// 난수 생성을 통한 값을 임시적으로 저장할 변수 temp
	int result = 0;		// 어휘 테스트에서 사용자에게 답을 입력받을 변수 result
	int index[4];		// 어휘 테스트에서 보기에서 사용될 int형 배열 index
	string engWord;		// 어휘 삽입에서 영어 단어를 입력받은 변수 engWord
	string korWord;		// 어휘 삽입에서 한글 단어를 입력받은 변수 korWord

	cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;		// 어휘 테스트 시작
	while (1) {			// 무한 반복문
		cout << "어휘 삽입: 1, 어휘 테스트 : 2, 프로그램 종료:그외키 >> ";	
		cin >> num;		

		if (num == 1) {				// 어휘 삽입
			cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
			while (1) {				// 무한 반복문
				cout << "영어 >>";	// 영어 단어 입력
				cin >> engWord;		
				if (engWord == "exit") {	// 여기서 exit이 입력되면
					cout << endl << endl;	// 줄바꿈 해주고 
					break;					// 삽입 단계를 종료한다(안쪽의 무한 반복문 종료)
				}	
				cout << "한글 >>";	// 한글 단어 입력
				cin >> korWord;
				v.push_back(Word(engWord, korWord));	// 입력된 두 단어를 벡터에 저장
			}
		}

		else if (num == 2) {		// 어휘 테스트
			cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 키 입력시 종료." << endl;
			while (1) {				// 무한 반복문
				answer = rand() % v.size();		// 랜덤으로 정답 단어 선택
				cout << v[answer].getEnglish() << "?" << endl;	// 정답 단어 출력
				index[0] = answer;				// 정답 단어의 인덱스를 index[0]에 저장

				for (int i = 1; i < 4; i++) {		// 중첩 반복문을 통해 다른 보기들을 선택, 0번은 정답이기 때문에 1번부터 시작
					index[i] = rand() % v.size();	// 랜덤으로 단어 선택
					for (int j = 0; j < i; j++) {	// 중복을 확인하는 반복문
						if (index[j] == index[i] ) {// 정답의 인덱스를 포함해 이전의 인덱스 값과 같으면
							i--;					// i의 값을 줄여주고
							break;					// 안쪽의 반복문 탈출
						}
					}
				}

				temp = rand() % 4;					// 보기의 출력을 랜덤으로 하기 위해 temp에 랜덤값 저장(0~3)
				for (int i = 1; i <= 4; i++) {		// 반복문을 통해 보기를 랜덤 출력
					cout << "(" << i << ") " << v[index[temp]].getKorean() << " ";
					if (temp == 0) {				// temp가 정답의 인덱스 0번을 저장되었으면
						temp = 4;					// 4로 초기화 해주고
						answer = i;					// 인덱스가 저장되있던 answer에 보기의 번호를 저장해준다
					}
					temp--;							// 보기 하나출력할때마다 temp값 감소
				}
				
				cout << ":>";						// 사용자로부터 정답의 번호를 입력받는다
				cin >> result;				
				if (result < 1 || result > 4) {		// 1 ~ 4번외의 다른 번호가 입력되면
					cout << endl;					// 줄바꿈 해주고
					break;							// 어휘 테스트를 종료한다
				}
				if (result  == answer) { cout << "Excellent !!" << endl; }	// 입력된 번호와 answer에 저장된 번호가 같으면 정답
				else { cout << "No. !!" << endl; }	// 그게 아니라면 오답 
			}
		}
		else {				// 1,2번이 아닌 다른 번호가 입력되면
			cout << "프로그램 종료" << endl;	// 프로그램 종료
			return;			// 무한 반복문을 빠져나가고 함수 종료
			// break; 
		}
	}
}

int main() {				// main 함수
	vector<Word> v;			// Word 클래스형 vector 선언
	v.push_back(Word("human", "인간"));		// 주어진 강의자료를 토대로
	v.push_back(Word("society", "사회"));	// vector에 원소를 삽입해준다
	v.push_back(Word("dall", "인형"));
	v.push_back(Word("emotion", "감정"));
	v.push_back(Word("painting", "그림"));
	v.push_back(Word("trade", "거래"));
	v.push_back(Word("baby", "아기"));
	v.push_back(Word("stock", "주식"));
	v.push_back(Word("bear", "곰"));
	v.push_back(Word("dall", "인형"));
	v.push_back(Word("animal", "동물"));
	v.push_back(Word("lover", "애인"));
	v.push_back(Word("photo", "사진"));
	v.push_back(Word("love", "사랑"));
	v.push_back(Word("oneself", "자기"));

	srand(time(NULL));		// 난수의 시드값 결정
	engKorTest(v);			// engKorTest 함수 호출
}