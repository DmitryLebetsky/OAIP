#include <iostream>;
#include <string>;
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int number;
	string numberInSecond = "";
	cout << "������� �����: ";
	cin >> number;
	string sign = number >= 0 ? "0" : "1";
	number = abs(number);
	while (number >= 2) {
		numberInSecond = to_string(number % 2) + numberInSecond;
		number /= 2;
	}
	numberInSecond = to_string(number) + numberInSecond;
	cout << "������ ��� �����: " << sign + numberInSecond;
	return 0;
}