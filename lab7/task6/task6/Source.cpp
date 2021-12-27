#include <iostream>;
using namespace std;

int getDigitsSum(int number) {
	int digitsSum = 0;
	while (number > 0)
	{
		digitsSum += number % 10;
		number /= 10;
	}
	return digitsSum;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int result = 0, n;
	cout << "������� n: ";
	cin >> n;
	int currentDigitsSum = 1;
	for (int i = 1; i <= n; i++)
	{
		int nextDigitsSum = getDigitsSum(i + 1);
		if (nextDigitsSum < currentDigitsSum) result++;
		currentDigitsSum = nextDigitsSum;
	}
	cout << "���������� ���������� ����� �� 1 �� " << n << " ����� " << result;
	return 0;
}