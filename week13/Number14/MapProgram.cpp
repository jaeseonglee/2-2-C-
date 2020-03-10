/*	�ǽ� 14�� : MapProgram.cpp
	�ۼ��� : 2019.11.21 ~ 11.24
	�ۼ��� : 20165153 ���缺
	���α׷� ����: ��ȣ ���� �������α׷��� map�� �̿��Ͽ� �ۼ��� ���α׷�
*/
#include <iostream>
#include <map>			// map
#include <iterator>	
using namespace std;

void passwordManage(map<string,string>& m) {	// ��ȣ ���� �������α׷� �����ϴ� passwordManage �Լ�, main�� map�� ����
	int num = 0;		// � �׸��� �������� �Է¹޴� ���� num
	string name;		// �̸��� ������ name
	string password;	// ��ȣ�� ������ password

	cout << "***** ��ȣ ���� ���α׷� WHO�� �����մϴ� *****" << endl;	// ��ȣ ���� ���α׷� ����
	while (1) {			// ���� �ݺ���
		cout << "����:1, �˻�:2, ����:3>> ";			// �׸� ���
		cin >> num;								
		if (num == 1) {					// ����
			cout << "�̸� ��ȣ>> ";		// �̸��� ��ȣ�� �Է¹޴´�
			cin >> name >> password;	
			m.insert(make_pair(name, password));	// insert�� ���� map�� �߰�
			//m[name] = password;		// []�� ���� �Է��Ҽ��� �ִ�
		}
		else if (num == 2) {			// �˻�
			cout << "�̸�? ";			// �̸��� �Է¹ް�
			cin >> name;
			if (m.find(name) == m.end() ) {	// ���� �̸��� ��ϵǾ����� ������ 
				cout << "�Է��Ͻ� �̸��� ��ϵǾ����� �ʽ��ϴ�" << endl;
				continue;					// �˻� �׸� ����
			}
			while (1) {						// �˻縦 ���� ���� �ݺ���
				cout << "��ȣ? ";			// ��ȣ�� �Է¹޴´�
				cin >> password;
				if (password == m[name]) {	// �Է��� ��ȣ�� ���� �Էµ� �̸��� ��ȣ�� ���ٸ�
					cout << "���!!" << endl;		// ��� 
					break;					// ������ ���� �ݺ��� Ż��
				}
				else {						// �ٸ��ٸ�
					cout << "����~~" << endl;	// ���� ����� �ٽ� �ݺ�
				}
			}
		}
		else if (num == 3) {				// ����
			cout << "���α׷��� �����մϴ�..." << endl;	// �����Ѵٰ� �����
			return; // break;				// �Լ� ����
		}
		else {								// �׿��� ���ڰ� �ԷµǸ�
			cout << "�־��� �׸� �߿��� �������ּ���" << endl;	// �ٽ� �Է��ش޶�� ���
		}
	}
}


int main() {			// main �Լ�
	map<string, string> management;	// map ����
	passwordManage(management);		// passwordManage �Լ� ȣ��
}