include <iostream>
#include <fstream>
using namespace std;
struct list {
	int x;
	list* next;
};
void out_list(list* Head);
void push(list*& Head, int number);
void delete_elemet_of_list(list*& Head, int num);
int main(void) {
	int k, n, e;
	list* node = nullptr;
	cout << "Enter n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i + 1 << " element : ";
		cin >> k;
		push(node, k);
	}
	out_list(node);
	cout << "Enter E : ";
	cin >> e;
	delete_elemet_of_list(node, e);
	out_list(node);
	return 0;
}
void delete_elemet_of_list(list*& Head, int num) {
	list* q = Head;
	list* q_1;
	if (q->x == num && q->next != nullptr) {
		q_1 = q->next;
		if (q_1->x != num) {
			q->next = q_1->next;
			delete q_1;
		}
	}
	while (q) {
		if (q->next == nullptr)
			break;
		q = q->next;
		if (q->x == num && q->next != nullptr) {
			q_1 = q->next;
			if (q_1->x != num) {
				q->next = q_1->next;
				delete q_1;
			}
		}
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
void push(list*& Head, int number) {
	list* temp = new list;
	temp->x = number;
	temp->next = nullptr;
	if (Head == nullptr)
		Head = temp;
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
