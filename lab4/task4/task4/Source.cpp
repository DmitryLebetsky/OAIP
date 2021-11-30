#include <iostream>;
using namespace std;

int main() {
	int rows, cols, minimumsCount = 0;
	cout << "enter rows count" << endl;
	cin >> rows;
	cout << "enter cols count" << endl;
	cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
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

	// counting of minimums
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (
				(((i-1)>=0 && (j-1)>=0) && (arr[i][j] >= arr[i-1][j-1]))
				|| ( ( (i-1)>=0 && (j+1)<cols ) && ( arr[i][j] >= arr[i-1][j+1] ) )
				|| (((i+1)<rows && (j-1)>=0) && (arr[i][j] >= arr[i+1][j-1]))
				|| (((i+1)<rows && (j+1)<cols) && (arr[i][j] >= arr[i+1][j+1]))
				|| ( (i-1)>=0 && (arr[i][j] >= arr[i-1][j]))
				|| ( (i+1)<rows && (arr[i][j] >= arr[i+1][j]) )
				|| ( (j-1)>=0 && (arr[i][j] >= arr[i][j-1]) )
				|| ( (j+1)<cols && (arr[i][j] >= arr[i][j+1]))
			) {
				continue;
			}
			else {
				minimumsCount = minimumsCount + 1;
			}
		}
	}

	cout << "Minimums count: " << minimumsCount;

	// DELETE
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}