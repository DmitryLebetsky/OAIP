#include <iostream>;
#include <string>;
#include <Windows.h>;
using namespace std;

// I ������
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string numberInEleventh;
	int numberInTenth = 0;
	cout << "������� ����� � ����������������� ������� ���������: ";
	cin >> numberInEleventh;
	for (size_t i = 0; i < numberInEleventh.size(); i++)
	{
		int digit = (numberInEleventh[i] == 'A') ? 10 : ((int)numberInEleventh[i] - (int)'0');
		numberInTenth += digit * pow(11, numberInEleventh.size() - 1 - i);
	}
	cout << "���� ����� � ���������� ������� ���������: " << numberInTenth << endl;
	int a = numberInTenth;
	int seventhSize = 1;
	do {
		a /= 7;
		seventhSize++;
	} while (a >= 7);
	int* numberInSeventh = new int[seventhSize];
	numberInSeventh[seventhSize - 1] = a;
	int j = 0;
	do
	{
		numberInSeventh[j] = numberInTenth % 7;
		numberInTenth /= 7;
		j++;
	} while (numberInTenth >= 7);
	cout << "���� ����� � ���������� ������� ���������: ";
	for (int i = seventhSize - 1; i >= 0; i--)
	{
		cout << numberInSeventh[i];
	}
	delete[] numberInSeventh;
	return 0;
}

/* int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string numberInEleventh;
	int numberInTenth = 0;
	int numberInSeventh = 0;
	cout << "������� ����� � ����������������� ������� ���������: ";
	cin >> numberInEleventh;
	for (int i = 0; i < numberInEleventh.size(); i++)
	{
		int digit = (numberInEleventh[i] == 'A') ? 10 : ((int)numberInEleventh[i] - (int)'0');
		cout << endl << "digit = " << numberInEleventh[i];
		numberInTenth += digit * pow(11, numberInEleventh.size() - 1 - i);
	}
	cout << "���� ����� � ����������: " << numberInTenth << endl;
	int i = 0;
	do
	{
		numberInSeventh += (numberInTenth % 7) * pow(10, i);
		i++;
		numberInTenth /= 7;
		
	} while (numberInTenth >= 7);
	numberInSeventh += numberInTenth * pow(10, i);
	cout << "���� ����� � ���������� = " << numberInSeventh << endl;
	return 0;
} */