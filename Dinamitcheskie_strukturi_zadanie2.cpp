#include <iostream>
#include <queue>        // подключаем заголовочный файл очереди
#include <string>       // заголовочный файл для работы со строками типа string
using namespace std;

void sravnenie(queue<int> queue1, queue<int> queue2);

int main()
{
	queue<int> queue1;
	queue<int> queue2;

	// добавили в очередь несколько элементов типа string
	queue1.push(1);
	queue1.push(2);
	queue1.push(3);

	queue2.push(1);
	queue2.push(2);
	queue2.push(3);

	sravnenie(queue1, queue2);
	return 0;
}

void sravnenie(queue<int> queue1, queue<int> queue2) {

	if (queue1 == queue2) {
		cout << "Queues are the same " << endl;
	}
	else cout << "Queues are not the same " << endl;

}
