#include <iostream>;
using namespace std;

int main() {
	int rows, cols;
	const int STAR_CODE = 42;
	cout << "Enter number of rows: " << endl;
	cin >> rows;
	cout << "Enter number of cols: " << endl;
	cin >> cols;
	char** arr = new char* [rows];
	int** resultArr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[cols];
		resultArr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = (rand() % 10) < 5 ? '*' : '.';
		}
	}
	// COUT INPUT ARRAY
	cout << "INPUT ARRAY: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == '*') {
				resultArr[i][j] = STAR_CODE;
				continue;
			}
			int bombsCount = 0;
			if ((i - 1) >= 0 && (j - 1) >= 0 && arr[i - 1][j - 1] == '*') {
				bombsCount++;
			}
			if ((i - 1) >= 0 && (j + 1) < cols && arr[i - 1][j + 1] == '*') {
				bombsCount++;
			}
			if ((i + 1) < rows && (j - 1) >= 0 && arr[i + 1][j - 1] == '*') {
				bombsCount++;
			}
			if ((i + 1) < rows && (j + 1) < cols && arr[i + 1][j + 1] == '*') {
				bombsCount++;
			}
			if ((i - 1) >= 0 && arr[i - 1][j] == '*') {
				bombsCount++;
			}
			if ((i + 1) < rows && arr[i + 1][j] == '*') {
				bombsCount++;
			}
			if ((j - 1) >= 0 && arr[i][j - 1] == '*') {
				bombsCount++;
			}
			if ((j + 1) < cols && arr[i][j + 1] == '*') {
				bombsCount++;
			}
			resultArr[i][j] = bombsCount;
		}
	}
	// COUT RESULT
	cout<< "RESULT: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (resultArr[i][j] == STAR_CODE) {
				cout << (char)resultArr[i][j] << "\t";
			}
			else {
				cout << resultArr[i][j] << "\t";
			}
		}
		cout << endl;
	}
	// DELETING
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
		delete[] resultArr[i];
	}
	delete[] arr;
	delete[] resultArr;
	return 0;
}