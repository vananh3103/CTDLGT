#include <iostream>
using namespace std;



struct Node {
	//Vung thong tin
	int info;
	//Vung lien ket
	Node* next;
	Node* pre;
};

struct DoublyLinkedList {
	Node* head;
	Node* tail;
};

//Khoi tao rong
void init(DoublyLinkedList & dl) {
	dl.head = NULL;
	dl.tail = NULL;
}

//Kiem tra danh sach rong?
bool isEmpty(DoublyLinkedList dl) {
	return dl.head==NULL && dl.tail == NULL;
}

//Them phan tu vao dau danh sach
Node* createNode(int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	p->pre = nullptr;
	return p;
}
void addHead(DoublyLinkedList& dl, int x) {
	Node* p = createNode(x);
	if (isEmpty(dl)) {
		dl.head = p;
		dl.tail = p;
		return;
	}
	else
	{

		p->next = dl.head;
		dl.head->pre = p;
		dl.head = p;
	}
}

void addTail(DoublyLinkedList& dl, int x) {
	Node* p = createNode(x);
	if (isEmpty(dl)) {
		dl.head = p;
		dl.tail = p;

	}
	else
	{
		p->pre = dl.tail;
		dl.tail->next = p;
	}
	dl.tail = p;
}

//Duyet danh sach xuat ra man hinh
void printListFromHead(DoublyLinkedList dl) {
	if (isEmpty(dl)) {
		cout << "Danh sach rong!\n";
		return;
	}

	Node* p = dl.head;

	while (p != nullptr) {
		cout << p->info<<" ";
		p = p->next;
	}

	cout << endl;
}

void printListFromTail(DoublyLinkedList dl) {
	if (isEmpty(dl)) {
		cout << "Danh sach rong!\n";
		return;
	}

	Node* p = dl.tail;

	while (p != nullptr) {
		cout << p->info << " ";
		p = p->pre;
	}

	cout << endl;
}
	//Xoa phan tu cuoi danh sach
void delTail(DoublyLinkedList& dl) {
	if (dl.head == nullptr)
	{
		return;
	}
	Node* q = dl.tail;
	dl.tail = dl.tail->pre;
	if (dl.tail != nullptr)
	{
		dl.tail->next = nullptr;
	}
	else
		dl.head = nullptr;
	q->pre = nullptr;
	delete q;

	//while (q->next != nullptr) {
	//	q = q->next;
	//}

	//if (q->next== nullptr) {
	//	q->next = nullptr;
	//	q->pre = nullptr;
	//}

	//delete q;

}
//xoa phan tu dau 
void delHead(DoublyLinkedList& dl)
{
	if (dl.head==nullptr)
	{
		return;
	}
	Node* p = dl.head;
	dl.head = dl.head->next;
	dl.head->pre = nullptr;
	delete p;

	/*Node* q = dl.tail;

	while (q->pre != nullptr) {
		q = q->pre;
	}
	if (q->pre == nullptr) {
		q->next = nullptr;
		q->pre = nullptr;
	}

	delete q;*/

}
//Giai phong vung nho
void destroyList(DoublyLinkedList& dl) {
	while (!isEmpty(dl)) {
		delTail(dl);
	}
}
int main() {
	DoublyLinkedList dl;
	init(dl);
	addHead(dl, 9);
	addHead(dl, 8);
	addHead(dl, 5);
	addHead(dl, 1);
	addTail(dl, 10);
	addHead(dl, 0);
	addTail(dl, 11);
	addHead(dl, 7);
	printListFromHead(dl);
	delTail(dl);
	printListFromHead(dl);
	delHead(dl);
	printListFromHead(dl);
	//printListFromTail(dl);
	//destroyList(dl);
	//printListFromHead(dl);
}
