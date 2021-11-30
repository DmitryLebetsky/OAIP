#include <iostream>;
using namespace std;

int main() {
	const int rows = 3, cols = 4; // !!!!!!!!!!!!!!!!!!!!! int rows, cols;
	/*cout << "enter rows count" << endl;
	cin >> rows;
	cout << "enter cols count" << endl;
	cin >> cols;*/
	// int** arr = new int* [rows];
	int arr[rows][cols] = { // !!!!!!!!!!!!!!!!!!!!!!!!!!!1
		{5, 8, 9, 8},
		{6, 7, 10, 7},
		{3, 9, 1, 5},
	};
	int** resultArr = new int* [rows];
	/*for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	} */
	for (int i = 0; i < rows; i++)
	{
		resultArr[i] = new int[cols];
	}
	// COUT INPUT DATA
	cout << "INPUT ARRAY: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	// Filling resultArr
	resultArr[0][0] = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = i ? 0 : 1; j < cols; j++)
		{
			int biggestElement = arr[i][j];
			for (int k = 0; k <= i; k++)
			{
				for (int h = 0; h <= j; h++)
				{
					if (arr[k][h] > biggestElement) {
						biggestElement = arr[k][h];
					}
				}
			}
			resultArr[i][j] = biggestElement;
		}
	}
	// COUT RESULT
	cout << "RESULT ARRAY: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << resultArr[i][j] << "\t";
		}
		cout << endl;
	}
	// DELETING
	/*for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;*/
	for (int i = 0; i < rows; i++)
	{
		delete[] resultArr[i];
	}
	delete[] resultArr;
	return 0;
}