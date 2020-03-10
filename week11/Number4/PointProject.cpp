/*	�ǽ� 4�� :PointProject.cpp
	�ۼ��� : 2019.11.07 ~ 11.10
	�ۼ��� : 20165153 ���缺
	���α׷� ����: �־��� Point Ŭ������ ��ӹ޴� ColorPoint Ŭ���� �ۼ��ϰ� �־��� main �Լ��� ����ǵ����ϴ� ���α׷�
*/

#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {	// Point Ŭ������ ��ӹ޴� ColorPoint Ŭ����
	string s;			// ������ �����ϴ� ����
public:
	ColorPoint() : Point(0, 0) { this->s = "BLACK"; }		// �Ű������� ���� ������, Point �����ڿ� 0,0�� �����ϸ鼭 s�� BLACK���� �ʱ�ȭ
	ColorPoint(int x, int y) : Point(x, y) { this->s = "BLACK"; }	// �Ű������� �ִ� �����ڴ� Point �����ڿ� �Ű������� �����Ѵ�
	void show();		// ���� �Բ� ������ ����ϴ� show �Լ�
	void setPoint(int x, int y) { move(x, y); }	// �� ��ġ�� �ٲٴ� setPoint �Լ�
	void setColor(string s) {this->s = s; }	// ������ �ٲٴ� setColor �Լ�
};

void ColorPoint::show() {
	cout << s << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;	// ���� ���� ��ġ�� ������ ���
}

int main() {
	ColorPoint zeroPoint;	// BLACK ���� (0,0) ��ġ�� ��
	zeroPoint.show();	// zeroPoint�� ����Ѵ�

	ColorPoint cp(5, 5);	
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();	// cp�� ����Ѵ�
}