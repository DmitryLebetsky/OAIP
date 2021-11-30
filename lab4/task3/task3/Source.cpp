#include <iostream>;
using namespace std;

int main() {
	int N, M;
	cout << "enter rows count" << endl;
	cin >> N;
	cout << "enter cols count" << endl;
	cin >> M;
	int* biggestArr = new int[N]; // массив наибольших чисел каждой строки;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < N; i++) // заполнение массива наибольших чисел
	{
		int biggestNumberFromRow = arr[i][0];
		for (int j = 0; j < M; j++)
		{
			if (biggestNumberFromRow < arr[i][j]) {
				biggestNumberFromRow = arr[i][j];
			}
		}
		biggestArr[i] = biggestNumberFromRow;
	}

	// INPUT DATA
	cout << "INPUT DATA:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "biggestArr: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << biggestArr[i] << " ";
	}
	cout << endl;

	// SORT
	for (int i = 1; i < N; i++) // count of buble cycles is (n - 1);
	{
		for (int j = 0; j < (N - 1); j++)
		{
			if (biggestArr[j] > biggestArr[j + 1]) {
				int temp = biggestArr[j];
				biggestArr[j] = biggestArr[j + 1];
				biggestArr[j + 1] = temp;

				int* tempArr = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tempArr;
			}
		}
	}


	// AFTER SORT
	// BIGGEST ARR AFTER SORT
	cout << "biggestArr AFTER SORT: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << biggestArr[i] << " ";
	}
	cout << endl;
	// Matrix after sort (result)
	cout << "Result:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}


	// Delete
	delete[] biggestArr;
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}