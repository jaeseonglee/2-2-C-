/*	�ǽ� 11�� : BookClass.cpp,BookClassString.cpp
	�ۼ��� : 2019.10.20 ~ 10.21
	�ۼ��� : 20165153 ���缺
	���α׷� ����: 4. ���� 3���� ���� ������ �߻��ϴ� ������ Book Ŭ�������� C-��Ʈ�� ������� ���ڿ��� �ٷ���� �����̴�. ���� �����ڸ� �ۼ���������
				���ڿ��� stringŬ������ ����Ͽ�, ������ 3�� ���� ������ �߻����� �ʵ��� Book Ŭ������ �����϶� - Number11_1���� ����
*/

#include <iostream>
#include <string> // string ������� include
using namespace std;

class Book {
	string title; // string���� ����� title
	int price; // ����
public:
	Book(string title, int price);	// �������� �־������ ��������ڴ� �������� �ʴ´�.
	~Book() {}; // ���� �Ҵ� ���� �޸𸮰� ���� .
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }
};

Book::Book(string title, int price) {// �����ڿ� set�Լ� �Ѵ� �����Ҵ��� ���� �ʴ´�.
	this->title = title;
	this->price = price;
}

void Book::set(string title, int price) {
	this->title = title;	// ���� �Ҵ��� �ϴ°� �ƴϹǷ� �׳� ���� ���� �����ϸ� �ȴ�.
	this->price = price;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}