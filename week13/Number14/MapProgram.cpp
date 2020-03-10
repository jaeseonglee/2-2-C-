/*	실습 14번 : MapProgram.cpp
	작성일 : 2019.11.21 ~ 11.24
	작성자 : 20165153 이재성
	프로그램 설명: 암호 관리 응용프로그램을 map을 이용하여 작성한 프로그램
*/
#include <iostream>
#include <map>			// map
#include <iterator>	
using namespace std;

void passwordManage(map<string,string>& m) {	// 암호 관리 응용프로그램 실행하는 passwordManage 함수, main의 map을 참조
	int num = 0;		// 어떤 항목을 실행할지 입력받는 변수 num
	string name;		// 이름을 저장할 name
	string password;	// 암호를 저장할 password

	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;	// 암호 관리 프로그램 시작
	while (1) {			// 무한 반복문
		cout << "삽입:1, 검사:2, 종료:3>> ";			// 항목 출력
		cin >> num;								
		if (num == 1) {					// 삽입
			cout << "이름 암호>> ";		// 이름과 암호를 입력받는다
			cin >> name >> password;	
			m.insert(make_pair(name, password));	// insert를 통해 map에 추가
			//m[name] = password;		// []를 통해 입력할수도 있다
		}
		else if (num == 2) {			// 검사
			cout << "이름? ";			// 이름을 입력받고
			cin >> name;
			if (m.find(name) == m.end() ) {	// 만약 이름이 등록되어있지 않으면 
				cout << "입력하신 이름은 등록되어있지 않습니다" << endl;
				continue;					// 검사 항목 종료
			}
			while (1) {						// 검사를 위한 무한 반복문
				cout << "암호? ";			// 암호를 입력받는다
				cin >> password;
				if (password == m[name]) {	// 입력한 암호와 먼저 입력된 이름의 암호가 같다면
					cout << "통과!!" << endl;		// 통과 
					break;					// 안쪽의 무한 반복문 탈출
				}
				else {						// 다르다면
					cout << "실패~~" << endl;	// 실패 출력후 다시 반복
				}
			}
		}
		else if (num == 3) {				// 종료
			cout << "프로그램을 종료합니다..." << endl;	// 종료한다고 출력후
			return; // break;				// 함수 종료
		}
		else {								// 그외의 숫자가 입력되면
			cout << "주어진 항목 중에서 선택해주세요" << endl;	// 다시 입력해달라고 출력
		}
	}
}


int main() {			// main 함수
	map<string, string> management;	// map 선언
	passwordManage(management);		// passwordManage 함수 호출
}