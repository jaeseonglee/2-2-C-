/*	�ǽ� 1��,4�� : BookClass.cpp
	�ۼ��� : 2019.11.04 ~ 11.06
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� BookŬ������ ������ �������� �־��� main�Լ��� ������ ������ ����ϰ�, å�� ������ ��Ÿ���� ���α׷��̴�.
*/

#include <iostream>
#include <string>		
using namespace std;

class Book {		// Book Ŭ����
	string title;	// å�� �̸�
	int price, pages;	// ���ݰ� ������
public:
	Book(string title = "", int price = 0, int pages = 0) {		// ������
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {		// å�� ������ ����ϴ� show �Լ�
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }		// ������ ��ȯ�ϴ� getTitle�Լ�
	//Book& operator +=(int price);		// 1-1�� Ŭ������ ��� �Լ��� ����
	//Book& operator -=(int price);		// 1-1�� Ŭ������ ��� �Լ��� ����
	friend Book& operator +=(Book& b, int price);	// 1-2�� Ŭ���� �ܺ� �Լ��� ����
	friend Book& operator -=(Book& b, int price);	// 1-2�� Ŭ���� �ܺ� �Լ��� ����
	friend bool operator<(string s, Book b);		// 4�� ���������� ���ϱ� ���� < ������ �Լ�
};

bool operator<(string s , Book b) {		// 4�� ���������� ���ϱ� ���� < ������ �Լ�
	return (s < b.getTitle()) ?  true : false;
}

/*
Book& Book::operator +=(int price) {// 1�� Ŭ������ ��� �Լ��� ����
	this->price += price;
	return *this;
}

Book& Book::operator -=(int price) {// 1�� Ŭ������ ��� �Լ��� ����
	this->price -= price;
	return *this;
}
*/

Book& operator +=(Book& b, int price) {// 1-2�� Ŭ���� �ܺ� �Լ��� ����
	b.price += price;
	return b;
}

Book& operator -=(Book& b, int price) {// 1-2�� Ŭ���� �ܺ� �Լ��� ����
	b.price -= price;
	return b;
}


int main() {
	/*
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;		// å a�� ���� 500�� ����
	b -= 500;		// å b�� ���� 500�� ����
	a.show();
	b.show();							// 1������ ����ϴ� main ��
	*/
	Book a("û��", 20000, 300);			// 4������ ����ϴ� ���ι�
	string b;
	cout << "å �̸��� �Է��ϼ���>>";
	getline(cin, b);	// Ű����κ��� ���ڿ��� å �̸��� �Է¹���
	if (b < a)
		cout << a.getTitle() << "�� " << b << "���� �ڿ� �ֱ���!"<< endl;
}