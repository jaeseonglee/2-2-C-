/*	�ǽ� 9�� : Person.h , Person.cpp , main.cpp
	�ۼ��� : 2019.09.26 ~ 09.27
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : �̸��� ��ȭ��ȣ�� �Է¹޾� ����ϰ� �˻��ϴ� ���α׷�
*/	

class Person {		// Person Ŭ����, �ǽ��������� �־��� �ڵ�� ����
	string name;	// �̸��� ������ ���ڿ� ���� name
	string tel;		// ��ȭ��ȣ�� ������ ���ڿ� ���� tel
public:
	Person();		// ������
	string getName();	// �̸��� ��ȯ�ϴ� getName �Լ�
	string getTel();	// ��ȭ��ȣ�� ��ȯ�ϴ� getTel �Լ�
	void set(string name, string tel);	// �̸��� ��ȭ��ȣ�� ������ set �Լ�
	~Person();		// �Ҹ���
};