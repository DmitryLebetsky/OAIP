#include <iostream>;
#include <cmath>;
using namespace std;

int main() {
	int n, i, resultDigit, numberOfDigits = 0;
	cout << "enter integer n > 0" << endl;
	if (!(cin >> n) || cin.get() != '\n' || n <= 0) {
		cout << "Incorrect input. Try again!";
		return 0;
	}
	cout << "enter digit integer i >= 0: " << endl;
	if (!(cin >> i) || cin.get() != '\n' || i < 0) {
		cout << "Incorrect input. Try again!";
		return 0;
	}
	for (int p = 1; ; p = p * 10, ++numberOfDigits) {
		if (n / p == 0) {
			break;
		}
	}
	if (i >= numberOfDigits) {
		cout << "i digit doesn't exist" << endl;
		return 0;
	}
	else {
		resultDigit = (n / (int)powf(10, i)) % 10;
		cout << i << " digit is " << resultDigit << endl;
	}

	cout << "numberOfDigits = " << numberOfDigits;
	return 0;
}