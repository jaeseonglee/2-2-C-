/*	�ǽ� 11�� : BookClass.cpp,BookClassString.cpp 
	�ۼ��� : 2019.10.20 ~ 10.21
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : å�� �̸��� ������ �����ϴ� Book Ŭ������ ���� ���α׷�
		�ǽ����� 1. Book Ŭ������ ������, �Ҹ���,set() �Լ��� �ۼ��϶�. set() �Լ��� ��� ���� title��
				�Ҵ�� �޸𸮰� ������ ���� ��ȯ�Ѵ�. �׸��� ���� ���ο� �޸𸮸� �Ҵ�ް� �̰��� �Ű������� ���޹��� å�̸��� �����Ѵ�.
				2. �����Ϸ��� �����ϴ� ����Ʈ ���� ������ �ڵ�� �����ΰ�?
				3. ����Ʈ ���� �����ڸ� ���� �� �Ʒ� main()�Լ��� ���� ������ �߻��Ѵ�. ���� ������ �߻����� �ʵ��� ���� ��������� �ۼ��϶�.
				4. ���� 3���� ���� ������ �߻��ϴ� ������ Book Ŭ�������� C-��Ʈ�� ������� ���ڿ��� �ٷ���� �����̴�. ���� �����ڸ� �ۼ���������
				���ڿ��� stringŬ������ ����Ͽ�, ������ 3�� ���� ������ �߻����� �ʵ��� Book Ŭ������ �����϶� - Number11_1���� ����
*/

#define _CRT_SECURE_NO_WARNINGS // // ���ڿ� �Լ��� ����ϴµ� �־� ������ �߻����� �ʰ� �ϴ� define�� 
#include <iostream>
#include <cstring>
using namespace std;

class Book {	// Book Ŭ����
	char* title; // ���� ���ڿ�
	int price; // ����
public:
	Book(const char* title, int price);	// ������
	Book(Book& b); // 3�� ���� ���� ������ 
	~Book();	// �Ҹ���
	void set(const char* title, int price);	
	void show() { cout << title << ' ' << price << "��" << endl; }
};

Book::Book(const char* title, int price) { // 1�� ������ ����
	int len = strlen(title);		// �Ű����� title�� ���̸�ŭ
	this->title = new char[len + 1]; // title�� ������ �Ҵ����ְ�
	strcpy(this->title, title);		// �Ű������� title�� �����Ѵ�.
	this->price = price;			// price�� �Ű����� price ���� ����
}

/*
Book::Book(Book& b) { // 2�� ����Ʈ ���� ������ ����
	title = b.title;
	price = b.price;
}
*/
Book::Book(Book& b) { // 3�� ���� ���� ������ ����
	int len = strlen(b.title);	// ��ü�� ����� ������ 
	title = new char[len + 1];	// �׸�ŭ �Ҵ��ϰ�
	strcpy(title, b.title);	// �����ؼ� �����Ѵ�.
	price = b.price;
}

Book::~Book() { // 1�� �Ҹ��� ����
	if (title)		// ���� �Ҵ�� title��
		delete [] title; // delete���־� ��ȯ���ش�.
}

void Book::set(const char* title, int price) { // 1�� set�Լ� ����
	if (this->title) // title�� �Ҵ�Ǿ� ������
		delete [] this->title; // ���� title�� �Ҵ�� �޸� ��ȯ
	
	int len = strlen(title);
	this->title = new char[len + 1]; // ���ο� �Ű����� title�� ���� �޸� �Ҵ�
	strcpy(this->title, title);
	this->price = price;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp; // ���� ������ ȣ���
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}