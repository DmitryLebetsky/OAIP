#include <iostream>;
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int N, result = 0;
	cout << "������� ���������� �����������: " << endl;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cout << "������� ���������� ������� � " << i + 1 << " ����������: ";
		cin >> arr[i];
		result = result + arr[i];
	}
	result = result - (N - 1);
	cout << "���������� ������� ��� ����������� ����������: " << result;
	delete[] arr;
	return 0;
}