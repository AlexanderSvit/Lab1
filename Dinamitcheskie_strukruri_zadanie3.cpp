#include <iostream>
#include <fstream>
using namespace std;
struct list {
	int x;
	list* next;
};
void push(list*& Head, int num);
void search(list*& Head, int num);
void out_list(list* Head);
int main(void) {
	list* node = nullptr;
	int n, x, numb;
	cout << "Enter n : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i + 1 << " element : ";
		cin >> x;
		push(node, x);
	}
	cout << "Enter number to search : ";
	cin >> numb;
	search(node, numb);
	out_list(node);
	return 0;
}
void out_list(list* Head) {
	list* q = Head;
	while (q) {
		cout << q->x << " ";
		q = q->next;
	}
	cout << endl;
}
void search(list*& Head, int num) {
	int choice = 0;
	if (Head
		== nullptr) {
		cout << "The list is empty";
	}
	list* q = Head;
	while (q) {
		if (q->x == num) {
			choice = 1;
		}
		if (q->next == nullptr)
			break;
		q = q->next;
	}
	if (choice)
		cout << "This number is listed" << endl;
	else
		cout << "Number not listed" << endl;
}
void push(list*& Head, int num) {
	list* temp;
	temp = new list;
	temp->x = num;
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
