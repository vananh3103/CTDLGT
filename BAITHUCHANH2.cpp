// BAITHUCHANH2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    int info;
    Node* next;
};

struct LinkedList {
    Node* head;
};

void init(LinkedList&l) {
    l.head = nullptr;
}

//them phan tu vao dau danh sach
Node* createNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;

}
void addHead(LinkedList&l, int x) {
    Node* p = createNode(x);
    p->next = l.head;
    l.head = p;
}

bool isEmpty(LinkedList l) {
    return l.head = nullptr;
}
void printList(LinkedList l) {
    if (isEmpty(l))
    {
        cout << "Danh sach rong\n";
    }
    Node* p = l.head;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
   
}

//xoa phan tu dau trong danh sach
void delHead(LinkedList &l) {
    if (!isEmpty(l))
    {
        Node* p = l.head;
        l.head = l.head->next;
        p->next = nullptr;
        delete p;
    }
}
//tim kiem phan tu x co gia tri key
Node* search(LinkedList l, int key) {
    Node* p = l.head;
    while (p != nullptr)
    {
        if (p->info == key) {
            return p;
            p = p->next;
        }
        return p;
    }
}
//them phan tu x vao phia sau phan tu co gia tri key 
void insertAfter(LinkedList l, int x, int key) {
    Node* q = search(l, key);
    if (q != nullptr) {
        Node* p = createNode(x);
        q->next = p->next;
        q->next = p;
    }
 }
//xoa phan tu cuoi
void delTail(LinkedList&l) {
    Node* p = l.head;
    if (!isEmpty(l))
    {
        if (l.head->next==nullptr)
        {
            delete p;
        }
        else
        {
            Node* q = nullptr;
            while (p->next!=nullptr)
            {
                q = p;
                p = p->next;
                
            }
            q->next = nullptr;
            delete p;

        }
    }
 
   
}
//Them phan tu cuoi
void addTail(LinkedList& l, int x) {
    Node* p = createNode(x);
    if (isEmpty(l))
    {
        l.head = p;
    }
    else
    {

        Node* q = l.head;
        while (q->next!=nullptr)
        {
            q = q->next;

        }
        q->next = p;
    }
}

//giai phong bo nho
void destroyList(LinkedList& l) {
    while (!isEmpty(l))
    {
        delHead(l);
        delTail(l);
    }
}
int main()
{
    LinkedList l;
    init(l);
    addHead(l, 5);
    addHead(l, 7);
    addHead(l, 3);
    addHead(l, 1);
    addHead(l, 0);
    addHead(l, 5);
    printList(l);
    delHead(l);
    printList(l);

    cout << "=====================XOA DUOI====================\n";
    delTail(l);
    printList(l);
  
}

