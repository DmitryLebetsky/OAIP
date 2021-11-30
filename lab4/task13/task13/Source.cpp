#include <iostream>;
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int N, result = 0;
	cout << "Введите количество удлинителей: " << endl;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cout << "Введите количество розеток в " << i + 1 << " удлинителе: ";
		cin >> arr[i];
		result = result + arr[i];
	}
	result = result - (N - 1);
	cout << "Количество розеток при оптимальном соединении: " << result;
	delete[] arr;
	return 0;
}