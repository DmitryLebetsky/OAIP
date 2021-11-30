#include <iostream>;
#include <cmath>;
#include "../StaticLib/Header.h";
using namespace std;

int main() {
	int size;
	double m = 0, D = 0;
	cout << "Enter 23: ";
	if (!(cin >> size) || cin.get() != '\n' || size != 23) {
		cout << "Incorrect input.";
		return 0;
	}
	double* arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = calculateA(i);
		cout << "a[" << i << "] = " << arr[i] << endl;
		m = m + arr[i];
	}
	m = m / size;
	for (int i = 0; i < size; i++)
	{
		D = D + pow(arr[i] - m, 2);
	}
	D = D / size;
	cout << "m = " << m << endl;
	cout << "D = " << D;
	delete[] arr;
	return 0;
}