#include "GraphicEditer.h"

void GraphicEditer::insert(int num) {
	if (num == 1) {
		if (index == 0) {
			pStart = new Line();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Line());
		}
	}
	else if (num == 2) {
		if (index == 0) {
			pStart = new Circle();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Circle());
		}
	}
	else if (num == 3) {
		if (index == 0) {
			pStart = new Rect();
			pLast = pStart;
		}
		else {
			pLast = pLast->add(new Rect());
		}
	}
	index++;
}

void GraphicEditer::indexDelete(int num) {
	if (num > index) {
		cout << "인덱스를 초과한 값입니다" << endl;
		return;
	}

	if (num == 0) {
		pStart = pStart->getNext();
		index--;
		return;
	}

	Shape* temp = pStart;
	Shape* deleteShape = pStart;
	for (int i = 0; i < num; i++) {
		temp = deleteShape;
		deleteShape = deleteShape->getNext();
	}
	temp->setNext(deleteShape);
	index--;

	delete deleteShape;
}

void GraphicEditer::call() {
	cout << "그래픽 에디터입니다." << endl;
	while (1) {
		int num = UI::menu();

		if (num == 1) {
			num = UI::add();
			insert(num);
		}
		else if (num == 2) { indexDelete(UI::deleteIndex()); }
		else if (num == 3) {
			Shape* temp = pStart;
			for (int i = 0; i < index; i++) {
				cout << i << ": ";
				temp->paint();
				temp = temp->getNext();
			}
		}
		else if (num == 4) {
			break;
		}
	}
}