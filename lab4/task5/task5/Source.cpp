#include <iostream>;
using namespace std;

int main() {
	int rows, cols;
	cout << "enter rows count" << endl;
	cin >> rows;
	cout << "enter cols count" << endl;
	cin >> cols;
	int** arr = new int* [rows];
	int** resultArr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		resultArr[i] = new int[cols];
	}
	// INPUT DATA
	cout << "INPUT ARRAY: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	// COUNTING AND FILLING RESULTARR
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int neighborsCount = 0, neighborsSum = 0;
			if ((i - 1) >= 0 && (j - 1) >= 0) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i - 1][j - 1];
			}
			if ((i - 1) >= 0 && (j + 1) < cols) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i - 1][j + 1];
			}
			if ((i + 1) < rows && (j - 1) >= 0) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i + 1][j - 1];
			}
			if ((i + 1) < rows && (j + 1) < cols) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i + 1][j + 1];
			}
			if ((i - 1) >= 0) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i - 1][j];
			}
			if ((i + 1) < rows) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i + 1][j];
			}
			if ((j - 1) >= 0) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i][j - 1];
			}
			if ((j + 1) < cols) {
				neighborsCount = neighborsCount + 1;
				neighborsSum = neighborsSum + arr[i][j + 1];
			}
			/* cout << "arr[" << i << "][" << j << "]: " << arr[i][j] << endl;
			cout << "neighborsSum: " << neighborsSum << endl;
			cout << "neighborsCount: " << neighborsCount << endl; */
			resultArr[i][j] = neighborsSum / neighborsCount;
		}
	}

	// COUT RESULT
	cout << "Result matrix: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << resultArr[i][j] << "\t";
		}
		cout << endl;
	}

	// DELETE
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	for (int i = 0; i < rows; i++)
	{
		delete[] resultArr[i];
	}
	delete[] resultArr;
	return 0;
}