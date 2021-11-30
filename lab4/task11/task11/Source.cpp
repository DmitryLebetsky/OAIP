#include <iostream>;
using namespace std;

int main() {
	int n, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	cout << "Enter n: " << endl;
	cin >> n;
	int*** arr = new int** [n];
	for (int x = 0; x < n; x++)
	{
		arr[x] = new int* [n];
		for (int y = 0; y < n; y++)
		{
			arr[x][y] = new int[n];
			for (int z = 0; z < n; z++)
			{
				arr[x][y][z] = rand() % 10;
			}
		}

	}
	// COUT ARRAY
	for (int x = 0; x < n; x++)
	{
		cout << "x = " << x << ":" << endl;
		for (int y = 0; y < n; y++)
		{
			for (int z = 0; z < n; z++)
			{
				cout << arr[x][y][z] << "\t";
			}
			cout << endl;
		}
	}
	// COUNT
	for (int i = 0; i < n; i++)
	{
		sum1 = sum1 + arr[i][i][i]; // sum1 = (0,0,0) -> (n,n,n)
		sum2 = sum2 + arr[(n - 1) - i][i][i]; // sum2 = (n, 0, 0) -> (0, n, n)
		sum3 = sum3 + arr[(n - 1) - i][i][(n - 1) - i]; // sum3 = (n, 0, n) -> (0, n, 0)
		sum4 = sum4 + arr[i][i][(n - 1) - i]; // sum4 = (0, 0, n) -> (n, n, 0)
	}
	int biggestSum = sum1;
	if (sum2 > biggestSum)
	{
		biggestSum = sum2;
	}
	if (sum3 > biggestSum)
	{
		biggestSum = sum3;
	}
	if (sum4 > biggestSum) {
		biggestSum = sum4;
	}
	cout << "Biggest sum = " << biggestSum << endl;
	cout << "Diagonal is: ";
	if (biggestSum == sum1) {
		cout << "(0,0,0) -> (n,n,n)";
	} else if (biggestSum == sum2) {
		cout << "(n, 0, 0) -> (0, n, n)";
	} else if (biggestSum == sum3) {
		cout << "(n, 0, n) -> (0, n, 0)";
	} else {
		cout << "sum4 = (0, 0, n) -> (n, n, 0)";
	}
	// DELETING
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			delete[] arr[i][j];
		}
		delete arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		
	}
	delete[] arr;
	return 0;
}