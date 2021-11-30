#include <iostream>;
using namespace std;

int main() {
	int n, terraceSize;
	cout << "Enter odd integer n:" << endl;
	cin >> n;
	terraceSize = 2 * n - 1;
	int minBorderOfMagicSquare = (terraceSize - n) / 2;
	int maxBorderOfMagicSquare = minBorderOfMagicSquare + n - 1;
	int** terrace = new int* [terraceSize];
	for (int i = 0; i < terraceSize; i++)
	{
		terrace[i] = new int[terraceSize];
		for (int p = 0; p < terraceSize; p++)
		{
			terrace[i][p] = 0;
		}
	}
	// COUT terrace
	cout << "TERRACE: " << endl;
	for (int i = 0; i < terraceSize; i++)
	{
		for (int p = 0; p < terraceSize; p++)
		{
			cout << terrace[i][p] << "\t";
		}
		cout << endl;
	}
	int centerIndex = terraceSize / 2;
	// Filling whole terrace with 1-25
	int currentDigitToFill = 1;
	for (int x = centerIndex, y = 0; x < terraceSize; x++, y++)
	{
		for (int i = 0; i < n; i++) {
			terrace[x - i][y + i] = currentDigitToFill;
			currentDigitToFill++;
		}
	}
	// COUT terrace
	cout << "TERRACE: " << endl;
	for (int i = 0; i < terraceSize; i++)
	{
		for (int p = 0; p < terraceSize; p++)
		{
			cout << terrace[i][p] << "\t";
		}
		cout << endl;
	}
	// Filling magic square
	for (int x = centerIndex, y = 0; x < terraceSize; x++, y++)
	{
		for (int i = 0; i < n; i++) {
			int cellX = x - i;
			int cellY = y + i;
			if (cellX < minBorderOfMagicSquare) {
				int putIntoX = cellX + n;
				terrace[putIntoX][cellY] = terrace[cellX][cellY];
				terrace[cellX][cellY] = 0;
			}
			if (cellX > maxBorderOfMagicSquare) {
				int putIntoX = cellX - n;
				terrace[putIntoX][cellY] = terrace[cellX][cellY];
				terrace[cellX][cellY] = 0;
			}
			if (cellY < minBorderOfMagicSquare) {
				int putIntoY = cellY + n;
				terrace[cellX][putIntoY] = terrace[cellX][cellY];
				terrace[cellX][cellY] = 0;
			}
			if (cellY > maxBorderOfMagicSquare) {
				int putIntoY = cellY - n;
				terrace[cellX][putIntoY] = terrace[cellX][cellY];
				terrace[cellX][cellY] = 0;
			}
		}
	}
	// COUT terrace
	cout << "TERRACE: " << endl;
	for (int i = 0; i < terraceSize; i++)
	{
		for (int p = 0; p < terraceSize; p++)
		{
			cout << terrace[i][p] << "\t";
		}
		cout << endl;
	}
	// COUT MAGIC SQUARE
	cout << "MAGIC SQUARE" << endl;
	for (int i = minBorderOfMagicSquare; i <= maxBorderOfMagicSquare; i++)
	{
		for (int p = minBorderOfMagicSquare; p <= maxBorderOfMagicSquare; p++)
		{
			cout << terrace[i][p] << "\t";
		}
		cout << endl;
	}
	// DELETING
	for (int i = 0; i < terraceSize; i++)
	{
		delete[] terrace[i];
	}
	delete[] terrace;
	return 0;
}