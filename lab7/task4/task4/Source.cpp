#include <iostream>;
#include <Windows.h>;
#include <math.h>;
using namespace std;

string getSum(string firstNumber, string secondNumber, string base);
string getSubstraction(string firstNumber, string secondNumber, string base);

string getSum(string firstNumber, string secondNumber, string base) {
	if (firstNumber[0] == '-' && secondNumber[0] == '-') {
		return ("-" + getSum(firstNumber.substr(1), secondNumber.substr(1), base));
	}
	else if (firstNumber[0] == '-') {
		return getSubstraction(secondNumber, firstNumber.substr(1), base);
	}
	else if (secondNumber[0] == '-') {
		return getSubstraction(firstNumber, secondNumber.substr(1), base);
	}
	else {
		string sum = "";
		string biggestNumber = firstNumber.size() > secondNumber.size() ?
			firstNumber : secondNumber;
		string smallesNumber = firstNumber == biggestNumber ? secondNumber : firstNumber;
		int digitsDifferenceCount = abs(int(firstNumber.size() - secondNumber.size()));
		int excess = 0;
		for (int i = smallesNumber.size() - 1; i >= 0; i--)
		{
			int firstDigit = base.find(smallesNumber[i]);
			int secondDigit = base.find(biggestNumber[i + digitsDifferenceCount]);
			int digitsSum = firstDigit + secondDigit + excess;
			excess = 0;
			if (digitsSum >= base.size()) {
				digitsSum -= base.size();
				excess = 1;
			}
			sum = base[digitsSum] + sum;
		}
		for (int i = biggestNumber.size() - smallesNumber.size() - 1; i >= 0; i--)
		{
			int digitsSum = base.find(biggestNumber[i]) + excess;
			excess = 0;
			if (digitsSum >= base.size()) {
				digitsSum -= base.size();
				excess = 1;
			}
			sum = base[digitsSum] + sum;
		}
		return sum;
	}
}

string getSubstraction(string firstNumber, string secondNumber, string base) {
	string biggestNumber = firstNumber.size() >= secondNumber.size() ?
		firstNumber : secondNumber;
	string smallesNumber = firstNumber == biggestNumber ? secondNumber : firstNumber;
	if (biggestNumber[0] == '-' && smallesNumber[0] == '-') {
		return "-" + getSubstraction(biggestNumber.substr(1), smallesNumber.substr(1), base);
	}
	else if (biggestNumber[0] == '-') {
		return "-" + getSum(biggestNumber.substr(1), smallesNumber, base);
	}
	else if (smallesNumber[0] == '-') {
		return getSum(biggestNumber, smallesNumber.substr(1), base);
	}
	else {
		string substraction = "";
		int digitsDifferenceCount = abs(int(firstNumber.size() - secondNumber.size()));
		int loan = 0;
		for (int i = smallesNumber.size() - 1; i >= 0; i--)
		{
			int firstDigit = base.find(smallesNumber[i]);
			int secondDigit = base.find(biggestNumber[i + digitsDifferenceCount]);
			int digitsSubstraction = secondDigit - loan - firstDigit;
			loan = 0;
			if (digitsSubstraction < 0) {
				digitsSubstraction += base.size();
				loan = 1;
			}
			substraction = base[digitsSubstraction] + substraction;
		}
		for (int i = biggestNumber.size() - smallesNumber.size() - 1; i >= 0; i--)
		{
			int digitsSubstraction = base.find(biggestNumber[i]) - loan;
			loan = 0;
			if (digitsSubstraction < 0) {
				digitsSubstraction += base.size();
				loan = 1;
			}
			substraction = base[digitsSubstraction] + substraction;
		}
		if (loan > 0) {
			substraction = base[base.size() - 1] + substraction;
		}
		return substraction;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string numberInEleventh1, numberInEleventh2;
	string eleventhBase = "0123456789A";
	cout << "Введите 1е число в одиннадцатеричной системе счисления: ";
	cin >> numberInEleventh1;
	cout << "Введите 2е число в одиннадцатеричной системе счисления: ";
	cin >> numberInEleventh2;
	string sum = getSum(numberInEleventh1, numberInEleventh2, eleventhBase);
	cout << "SUM = " << sum << endl;
	string substraction = getSubstraction(numberInEleventh1, numberInEleventh2, eleventhBase);
	cout << "SUBSTRACTION = " << substraction;
	return 0;
}