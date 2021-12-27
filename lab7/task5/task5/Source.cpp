#include <iostream>;
#include <string>;
using namespace std;

int findElement(int* arr, const int arrSize, int element) {
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == element) return i;
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int arabicNumber;
	string romanNumber = "";
	const int arabicSystemSize = 30;
	int arabicSystem[arabicSystemSize] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		20, 30, 40, 50, 60, 70, 80, 90,
		100, 200, 300, 400, 500, 600, 700,
		800, 900, 1000, 2000, 3000
	};
	string romanSystem[] = {
		"I", "II", "III", "IV", "V", "VI", "VII",
		"VIII", "IX", "X", "XX", "XXX", "XL", "L",
		"LX", "LXX", "LXXX", "XC", "C", "CC", "CCC",
		"CD", "D", "DC", "DCC", "DCCC", "CM", "M", "MM", "MMM"
	};
	do
	{
		cout << "¬ведите число в арабской системе (1 - 3999): ";
		cin >> arabicNumber;
	} while (!(arabicNumber > 0 && arabicNumber < 4000));
	int i = 0;
	while (arabicNumber > 0) {
		int digit = arabicNumber % 10;
		arabicNumber /= 10;
		if (digit != 0) {
			int index = findElement(arabicSystem, arabicSystemSize, digit * pow(10, i));
			romanNumber = romanSystem[index] + romanNumber;
		}
		i++;
	}
	cout << "„исло в римской записи: " << romanNumber << endl;
	return 0;
}