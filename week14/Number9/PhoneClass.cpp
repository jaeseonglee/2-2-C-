/*	�ǽ� 9�� : PhoneClass.cpp
	�ۼ��� : 2019.11.28 ~ 12.02
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� Phone Ŭ������ ������ ��ü�� ������ϴµ� <<,>> �����ڸ� �ۼ��� ���α׷�
*/
#include <iostream>
#include <string>
using namespace std;

class Phone {		// ��ȭ��ȣ�� ǥ���ϴ� Ŭ����
	string name;
	string telnum;	// ��ȭ��ȣ���� '-'�� ���� ������ string
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend istream& operator >> (istream& ins, Phone& p);
	friend ostream& operator << (ostream& stream, Phone p);
};

istream& operator >> (istream& ins, Phone& p) {
	cout << "�̸�:";
	getline(ins, p.name);	// �� ���� �Է¹ޱ� ����

	cout << "��ȭ��ȣ:";
	getline(ins, p.telnum);

	cout << "�ּ�:";
	getline(ins, p.address);
	return ins;
}

ostream& operator << (ostream& stream, Phone p) {
	stream << "(" << p.name << "," << p.telnum << "," << p.address << ")";
	return stream;
}

int main() {
	Phone girl, boy;
	cin >> girl >> boy;		// ��ȭ ��ȣ�� Ű����κ��� �д´�.
	cout << girl << endl << boy << endl;	// ��ȭ��ȣ�� ����Ѵ�.
}