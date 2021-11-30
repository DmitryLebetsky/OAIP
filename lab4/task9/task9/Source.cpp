#include <iostream>;
using namespace std;

int main() {
	int N;
	cout << "Enter matrixes size: " << endl;
	cin >> N;
	int** A = new int* [N];
	int** B = new int* [N];
	int** result = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[N];
		B[i] = new int[N];
		result[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}
	// COUT matrix A
	cout << "Matrix A: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	// COUT matrix B
	cout << "Matrix B: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	// COUNT RESULT
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int currentEl = 0;
			for (int p = 0; p < N; p++)
			{
				currentEl = currentEl + A[i][p] * B[p][j];
			}
			result[i][j] = currentEl;
		}
	}
	// COUT RESULT
	cout << "RESULT: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}
	// DELETING
	for (int i = 0; i < N; i++)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] result[i];
	}
	delete[] result;
	delete[] A;
	delete[] B;
	return 0;
}