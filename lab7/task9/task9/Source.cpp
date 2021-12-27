#include <iostream>;
#include <string>;
using namespace std;

string intoThirdBase(int number) {
	string result = "";
	number = abs(number);
	while (number >= 3) {
		result = to_string(number % 3) + result;
		number /= 3;
	}
	result = to_string(number) + result;
	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int number;
	string numberInThirdBase;
	cout << "¬ведите число: ";
	cin >> number;
	numberInThirdBase = intoThirdBase(number);
	for (int i = numberInThirdBase.size() - 1; i > 0; i--)
	{
		int digit = (int)numberInThirdBase[i] - (int)'0';
		if (!digit) {
			int j = i;
			do
			{
				j--;
			} while (numberInThirdBase[j] == '0');
			numberInThirdBase[j] = (char)(numberInThirdBase[j] - 1);
			numberInThirdBase[i] = '3';
		}
	}
	int i = 0;
	for (i; i < numberInThirdBase.size(); i++)
	{
		if (numberInThirdBase[i] != '0') break;
	}
	numberInThirdBase = numberInThirdBase.substr(i);
	cout << "„исло в системе счислени€ {1, 2, 3} = " << numberInThirdBase << endl;
	return 0;
}