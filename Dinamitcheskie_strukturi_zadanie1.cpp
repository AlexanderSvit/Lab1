#include <iostream>
#include <fstream>
using namespace std;
struct list {
	int x;
	list* next;
};
void pop(list*& Head);
void compare(list*& Head1, list*& Head2);
void push(list*& Head, int data);
void out_list(list* Head);
void del(list*& Head1);
int main() {
	char file[] = "File.txt";
	int k, l;
	list* node = nullptr;
	list* node_1 = nullptr;
	for (int i = 1; i < 6; i++) {
		cout << "Enter " << i << " element 1 : ";
		cin >> k;
		push(node, k);
	}
	for (int i = 1; i < 4; i++) {
		cout << "Enter " << i << " element 2 : ";
		cin >> l;
		push(node_1, l);
	}
	cout << "list 1 : " << endl;
	out_list(node);
	cout << "list 2 : " << endl;
	out_list(node_1);
	compare(node, node_1);
}
void compare(list*& Head1, list*& Head2) {
	list* temp1;
	list* temp2;
	temp1 = Head1;
	temp2 = Head2;
	while (temp1->x != temp2->x && temp1->next != nullptr) {
		pop(temp1);
	}
	while (temp1->x == temp2->x) {
		if (temp2->next == nullptr) {
			cout << "The second stage is part of the first, and list 2 was delete" << endl;
			while (temp2) {
				temp2 = remove(x);
				cout << temp2->x << " ";
				temp2 = temp2->next;
			}
			break;
		}
		pop(temp1);
		pop(temp2);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (temp1->x != temp2->x) {
		cout << "The second stage is not part of the first" << endl;
	}
}
void out_list(list* Head) {
	list* q = Head;
	while (q) {
		cout << q->x << " ";
		q = q->next;
	}
	cout << endl;
}
void push(list*& Head, int data) {
	list* temp;
	temp = new list;
	temp->x = data;
	temp->next = nullptr;
	if (Head == nullptr) {
		Head = temp;
	}
	else {
		list* q = Head;
		while (q) {
			if (q->next == nullptr)
				break;
			q = q->next;
		}
		q->next = temp;
	}
}
void pop(list*& Head) {
	list* q = Head;
	Head = q->next;
	delete q;
}
