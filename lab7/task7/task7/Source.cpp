#include <iostream>;
using namespace std;

int getRemainder(unsigned int divident, unsigned int divisor) {
	if (divident == divisor) {
		return 0;
	}
	if (divident < divisor) {
		return divident;
	}
	unsigned int tempDivisor = divisor;
	while (tempDivisor <= divident) {
		tempDivisor <<= 1;
	}
	if (tempDivisor > divident) {
		tempDivisor >>= 1;
	}
	return getRemainder(divident - tempDivisor, divisor);
}

int main() {
	setlocale(LC_ALL, "Russian");
	unsigned int number;
	const unsigned int divisorsCount = 3;
	unsigned int divisors[divisorsCount] = { 3, 61, 131 };
	cout << "Введите число: ";
	cin >> number;
	for (int i = 0; i < divisorsCount; i++)
	{
		if (!getRemainder(number, divisors[i])) {
			cout << "Ваше число делится на " << divisors[i] << endl;
		}
		else {
			cout << "Ваше число не делится на " << divisors[i] << endl;
		}
	}
	return 0;
}