#include <iostream>;
using namespace std;

int main() {
	const int N = 4;
	const int M = 5;
	int arr[N][M] = {
		{1, 5, 56, 75, 2},
		{5, 8, 5, 7, 3129},
		{3, 6, 213, 32, 321},
		{1, 2, 1, 32, 6},
	};
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; (j < i && j < M); j++)
		{
			result = result * arr[i][j];
		}
	}
	// INPUT DATA
	cout << "Input data: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "result: " << result;
	return 0;
}