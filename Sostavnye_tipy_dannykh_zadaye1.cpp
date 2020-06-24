#include <iostream>

using namespace std;

template <typename T>
void swap(T* a, T* b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}
//-----------------------------------------------------------------------------
template <typename T>
T* getMin(T* begin, T* end) {
	T* min = begin;
	for (T* p = begin + 1; p <= end; ++p) {
		if (*p < *min) {
			min = p;
		}
	}
	return min;
}
//-----------------------------------------------------------------------------
template <typename T>
T* hill(T a[], const unsigned n) {
	bool toFirst = true;
	T* head = a;
	T* tail = a + n - 1;

	while (head < tail) {
		T* min = getMin(head, tail);

		if (toFirst) {
			swap(head++, min);
		}
		else {
			swap(tail--, min);
		}
		toFirst = !toFirst;
	}
	return a;
}
//-----------------------------------------------------------------------------
template<typename T>
void print(T a[], const unsigned n) {
	for (unsigned i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}
//-----------------------------------------------------------------------------
int main() {
	float a[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
	unsigned na = sizeof(a) / sizeof(*a);

	float b[] = { 9.9, 8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1 };
	unsigned nb = sizeof(b) / sizeof(*b);

	int c[] = { 1, 9, 2, 8, 3, 7, 4, 6, 5 };
	unsigned nc = sizeof(c) / sizeof(*c);

	print(hill(a, na), na);
	print(hill(b, nb), nb);
	print(hill(c, nc), nc);

	return 0;
}
