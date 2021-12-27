#include <iostream>;
#include <string>;
using namespace std;

string intoSecondBase(int number) {
	string result = "";
	string sign = number >= 0 ? "0" : "1";
	number = abs(number);
	while (number >= 2) {
		result = to_string(number % 2) + result;
		number /= 2;
	}
	result = sign + to_string(number) + result;
	return result;
}

string reverseNumber(string number) {
	if (number[0] == '0') {
		return number;
	}
	else {
		for (int i = 1; i < number.size(); i++)
		{
			number[i] = number[i] == '0' ? '1' : '0';
		}
		return number;
	}
}

string getSumInReverseCode(string number1, string number2) {
	string result = "";
	int excess = 0;
	for (int i = number1.size() - 1; i >= 0; i--)
	{
		int digit1 = (int)number1[i] - (int)'0';
		int digit2 = (int)number2[i] - (int)'0';
		int digitsSum = digit1 + digit2 + excess;
		excess = 0;
		if (digitsSum > 1) {
			digitsSum = 0;
			excess = 1;
		}
		result = to_string(digitsSum) + result;
	}
	if (excess) {
		for (int i = 0; i < number1.size(); i++)
		{
			number1[i] = '0';
		}
		number1[number1.size() - 1] = '1';
		return getSumInReverseCode(number1, result);
	}
	else {
		return result;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int number1, number2;
	string number1InSecond, number2InSecond, 
		number1InReverse, number2InReverse,
		sumInReverse, sumInSecond;
	cout << "Введите два числа: ";
	cin >> number1 >> number2;
	number1InSecond = intoSecondBase(number1);
	number2InSecond = intoSecondBase(number2);
	int biggestLength = number1InSecond.size() > number2InSecond.size() ?
		number1InSecond.size() : number2InSecond.size();
	while (number1InSecond.size() < biggestLength) {
		number1InSecond.insert(1, string("0"));
	}
	while (number2InSecond.size() < biggestLength) {
		number2InSecond.insert(1, string("0"));
	}
	cout << "Ваши числа в прямом коде:" << endl
		<< number1 << " = " << number1InSecond << endl
		<< number2 << " = " << number2InSecond << endl;
	number1InReverse = reverseNumber(number1InSecond);
	number2InReverse = reverseNumber(number2InSecond);
	cout << "Ваши числа в обратном коде:" << endl
		<< number1 << " = " << number1InReverse << endl
		<< number2 << " = " << number2InReverse << endl;
	sumInReverse = getSumInReverseCode(number1InReverse, number2InReverse);
	cout << "Сумма чисел в обратном коде: " << endl << sumInReverse << endl;
	sumInSecond = reverseNumber(sumInReverse);
	cout << "Сумма чисел в прямом коде: " << endl << sumInSecond;
	return 0;
}