/*	실습 12번 : Ram.h , Ram.cpp , main.cpp
	작성일 : 2019.09.20
	작성자 : 20165153 이재성
	프로그램 설명 : 컴퓨터의 주기억장치를 모델링하는 클래스 Ram을 구현하려고 한다. Ram클래스는 데이터가
					기록될 메모리 공간과 크기 정보를 가지고, 주어진 주소에 데이터를 기록하고(write),
					주어진 주소로부터 데이터를 읽어온다(read).
					Ram.h ,Ram.cpp, main.cpp 파일로 분리하여 프로그램을 완성하라.
*/

class Ram {		// Ram 클래스, 주어진 실습문제와 같다
	char mem[100 * 1024];	// 100KB 메모리. 한 번지는 한 바이트이므로 char타입 사용
	int size;				// size 선언
public:
	Ram();	//mem 배열을 0으로 초기화하고 size를 100*1024로 초기화 하는 생성자 - Ram.cpp에서 구현
	~Ram();	// "메모리 제거됨" 문자열출력하는 소멸자 - Ram.cpp에서 구현
	char read(int address);					// address 주소의 메모리 바이트 리턴 - Ram.cpp에서 구현
	void write(int address, char value);	// address 주소에 한 바이트로 value 저장 -Ram.cpp에서 구현
};