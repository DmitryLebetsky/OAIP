#include <iostream>;
#include <string>;
using namespace std;


string intoSecondBase(int number) {
	string result = "";
	while (number >= 2) {
		result = to_string(number % 2) + result;
		number /= 2;
	}
	result = to_string(number) + result;
	return result;
}

bool isTwoDecimal(int number) {
	string inSecondBase = intoSecondBase(number);
	string stringNumber = to_string(number);
	for (int i = inSecondBase.size() - 1; i >= 0; i--)
	{
		if (stringNumber == inSecondBase.substr(i)) {
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	string result;
	cout << "¬ведите n: ";
	cin >> n;
	int i = 0;
	while (n != 0) {
		i++;
		if (isTwoDecimal(i)) {
			n--;
		}
	}
	cout << "n-ое двудес€тичное число: " << i;
	return 0;
}