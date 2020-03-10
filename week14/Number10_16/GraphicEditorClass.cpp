/*	�ǽ� 10�� 16�� : GraphicEditorClass.cpp
	�ۼ��� : 2019.11.28 ~ 12.04
	�ۼ��� : 20165153 ���缺
	���α׷� ����: 9�� �ǽ� ���� 10���� vector�� ���� �籸���� ���α׷��̴�
*/
#include <iostream>
#include <vector>		// vector ���
#include <iterator>		// erase �Լ� ���� iterator ���
using namespace std;

class Shape {		// �߻� Ŭ���� Shape
protected:
	virtual void draw() = 0;		// ���� ���� �Լ�
public:
	Shape() {  }		// ������
	virtual ~Shape() { }
	void paint() { draw(); }
};

class Circle : public Shape {		// Circle Ŭ����
protected:
	virtual void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {			// Rect Ŭ����
protected:
	virtual void draw() { cout << "Rectangle" << endl; }
};

class Line : public Shape {			// Line Ŭ����
protected:
	virtual void draw() { cout << "Line" << endl; }
};

class UI {				// UI Ŭ����
public:
	UI() {  }			// ������
	static int menu();	// �޴� ���
	static int add();	// ���� 
	static int deleteIndex();	// ����
};

int UI::menu() {		// �Է¹��� �׸� ��ȣ�� ��ȯ�ϴ� menu �Լ�
	int num = 0;
	while (1) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3 || num == 4) { return num; }
		else { cout << "�־��� �޴� �߿��� �������ּ���" << endl; }
	}
}
int UI::add() {			// � �׸��� �߰����� �Է¹޴� add �Լ�
	int num = 0;
	while (1) {
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> num;
		if (num == 1 || num == 2 || num == 3) { return num; }
		else { cout << "�� ���� �߿� �������ּ���" << endl; }
	}
}

int UI::deleteIndex() {		// ������ �ε����� �Է¹޴� deleteIndex �Լ�
	int num = 0;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> num;
	return num;
}

class GraphicEditer {		// GraphicEditer  Ŭ����
	vector<Shape*> v;		// vector ���
public:
	GraphicEditer() { }		// ������
	void insert(int num);	// ���� �Լ�
	void indexDelete(int num);	// ���� �Լ�
	void call();			// �׷��� ������ ����ϴ� call �Լ�
};


void GraphicEditer::insert(int num) {	// �Է¹��� �Ű������� ���� ������ �׸��� insert �Լ�
	if (num == 1) {
		v.push_back(new Line());		// 1���̸� Line�� �׸���
	}
	else if (num == 2) {
		v.push_back(new Circle());		// 2���̸� Circle�� �׸���
	}
	else {
		v.push_back(new Rect());		// 3���̸� Rectangle�� �׸���
	}
}

void GraphicEditer::indexDelete(int num) {	// �Է¹��� ���� ���� �ε����� �����ϴ� indexDelete�Լ�
	vector<Shape*>::iterator it;	// iterator ���
	it = v.begin();		// ������ ���۰��� �����ϰ�
	*it = *it + num;	// num��ŭ ���������༭ �� �ε����� ����Ű���Ѵ�
	it = v.erase(it);
}

void GraphicEditer::call() {			// ��ü �׷��� �����⸦ �����ϴ� call �Լ�
	cout << "�׷��� �������Դϴ�." << endl;	// �׷��� ������ ������ �˸���
	while (1) {						// ���� �ݺ���
		int num = UI::menu();		// �޴� ���

		if (num == 1) { insert(UI::add()); } 	// 1���̸� ����
		else if (num == 2) { indexDelete(UI::deleteIndex()); }	// 2���̸� ����
		else if (num == 3) {		// 3���̸� ��� ����
			for (int i = 0; i < v.size(); i++) {
				cout << i << ": ";
				v[i]->paint();		
			}
		}
		else if (num == 4) {		// 4���̸� ������ ����, menu �Լ����� 4���� ���� �̿ܿ� ���� �ʴ´�
			break;
		}
	}
}

int main() {		// main �Լ�
	GraphicEditer* ge = new GraphicEditer;	// GraphicEditer ����
	ge->call();		// ������ ����
	delete ge;		// ��ȯ
}