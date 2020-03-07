/*	�ǽ� 8�� : TraceClass.cpp
	�ۼ��� : 2019.10.25 ~ 10.27
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ���൵���� ������ �����ϴ� Trace Ŭ������ ������ ���α׷�. �־��� f�Լ��� main�Լ��� �̿��Ͽ�
				Trace Ŭ���� �����Ͽ� ����� ����Ѵ�. ����� ������ 100���� �����Ѵ�.
*/

#include <iostream>
using namespace std;

class Trace {		// ������ �����ϴ� Trace Ŭ����
	static string tag[100];	// �±׸��� ������ string�� �迭 tag����
	static string info[100];// ������ ������ string�� �迭 info����
	static int index;		// �迭�� �ε����� ����Ű�� index
public:
	static void put(string tagName, string debugInfo);	// �±׸�� ����� ������ �����ϴ� put�Լ�
	static void print(string s = "");					// ������ ����ϴ� print �Լ� �Ű����� s�� ""���� ����Ʈ ������ ���´�
};

string Trace::tag[100] = {};	// static �������� ���� �������� �ʱ�ȭ���ش�
string Trace::info[100] = {};
int Trace::index = 0;

void Trace::put(string tagName, string debugInfo) {	// �±׸�� ����� ������ �����ϴ� put�Լ�
	if (index >= 100) {		// index�� 100�� �Ѿ��ٸ� 
		cout << "����� ������ �ʹ� �����ϴ�!" << endl;
		return ;			// �Լ� ����
	}
	tag[index] = tagName;	// �Ű������� �±׸��
	info[index] = debugInfo;	// ������ ������ �������ְ�
	index++;				// �ε������� ������Ų��.
}

void Trace::print(string s) {// ������ ����ϴ� print �Լ� �Ű����� s�� ""���� ����Ʈ ������ ���´�
	if (s == "") {			// ��� ����� ������ ����ϴ� ��� 
		cout << "----- ��� Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < index; i++) {		// �ݺ����� ���� ��� ����� ������ ����Ѵ�
			cout << tag[i] << ":" << info[i] << endl;
		}
	}
	else {	// �Ű������� ����Ʈ �� ��� �ٸ� ���� ����Ǿ��ٸ�
		cout << "----- "<< s <<"�±��� Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < index; i++) {	// �Ű������� ���� �̸��� �±׸�� �� ������ ����Ѵ�
			if( tag[i] == s) cout << tag[i] << ":" << info[i] << endl;
		}
	}
}

void f() {		// �������� �־��� �Լ� f. �� ���� ������ �Է¹޾� ���� ����ϴ� ���� ����� ������ �����Ѵ�
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");	// ����� ���� ����
	c = a + b;
	Trace::put("f()", "�� ���");	// ����� ���� ����
	cout << "���� " << c << endl;
}

int main() {		// �������� �־��� main �Լ� 
	Trace::put("main()", "���α׷� �����մϴ�");	// ����� ���� ����, "main()"�� �±װ� "���α׷� �����մϴ�"�� ������
	f();
	Trace::put("main()", "����");	// put()�� ù ��° �Ű� ������ �±��̰�
									// �� ��° �Ű� ������ ����� �����̴�.
	Trace::print("f()");	// "f()" �±׸� ���� ����� ������ ��� ����Ѵ�.
	Trace::print();			// ��� ����� ������ ����Ѵ�.
}