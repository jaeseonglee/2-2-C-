/*	�ǽ� 4���� 1�� : Color.cpp
	�ۼ��� : 2019.09.20
	�ۼ��� : 20165153 ���缺
	���α׷� ���� : ���� 3����� red,green,blue�� ���� �߻�ȭ�� ColorŬ���� ������ ���α׷�
*/

#include <iostream>
using namespace std;

class Color {				// ���� 3����� red,green,blue�� ���� �߻�ȭ�� ColorŬ����
	int red, green, blue;	// �ǽ������� �־��� �ڵ�� ����. ��ĭ�� ä��� �����̱� ������ (n)�ּ��� �ۼ�
public:
	Color() { red = green = blue = 0; }							// �Ű������� ���� �����ڴ� �������� 0���� �ʱ�ȭ
	Color(int r, int g, int b) { red = r; green = g; blue = b; }// �Ű������� ������ �������� �Ű�������� �ʱ�ȭ
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }// �Ű������� ������ �����ϴ� setColor�Լ�
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }	// ����� ���� 3��Ҹ� ����ϴ� show�Լ�
};

int main() {						// main�Լ��� �־��� �ڵ�� ����.
	Color screenColor(255, 0, 0);	// �������� screenColor ��ü ����
	Color* p;						// Color Ÿ���� ������ ���� p ����
	p = &screenColor;				// (1) p�� screenColor�� �ּҸ� �������� �ڵ� �ۼ�
	p->show();						// (2) p�� show()�� �̿��Ͽ� screenColor �� ���
	Color colors[3];				// (3) Color�� ������ �迭 colors ����. ���Ҵ� 3��
	p = colors;						// (4) p�� colors �迭�� ����Ű���� �ڵ� �ۼ�
					// ����: &�� ������ �ʴ´�. �����Ͱ� ��ü �迭�� ����Ŵ!

	// (5) p�� setColor()�� �̿��Ͽ� colors[0], colors[1], colors[2]�� 
	// ���� ����, �ʷ�, �Ķ����� �������� �ڵ� �ۼ�
	p[0].setColor(255, 0, 0);	// ����(r,g,b) ���� ����Ű�Ƿ� 
	p[1].setColor(0, 255, 0);	// ���� �ش��ϴ� �Ű������� 255�� �Է�
	p[2].setColor(0, 0, 255);

	// (6) p�� show()�� �̿��Ͽ� colors �迭�� ��� ��ü�� �� ���. for �� �̿�
	for (int i = 0; i < 3; i++) {	// �ݺ����� ���� ��ü �迭�� ����� ������ �� ���
		p[i].show();
	}
}