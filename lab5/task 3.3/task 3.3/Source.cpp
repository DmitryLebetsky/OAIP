#include <iostream>;
using namespace std;

// Count average function
double getAverage(int arr[], int arrSize) {
	double arrSum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		arrSum = arrSum + arr[i];
	}
	return arrSum / arrSize;
}

int main() {
	// создание, заполнение двумерного динамического массива
	int rows, cols;
	cout << "Enter rows count: " << endl;
	cin >> rows;
	cout << "Enter cols count: " << endl;
	cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter arr[" << i << "][" << j << "]:" << endl;
			cin >> arr[i][j];
		}
	}
	// Cout input array
	cout << "Your array: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	// ищем кол-во нечётных элементов в чётных столбах
	int oddCount = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j = j + 2)
		{
			if (arr[i][j] % 2 == 1) {
				oddCount++;
			}
		}
	}
	// создаём итоговый массив и заполняем его нечётными числами 
	int* oddArr = new int[oddCount];
	for (int i = 0, k = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j = j + 2)
		{
			if (arr[i][j] % 2 == 1)
			{
				oddArr[k] = arr[i][j];
				k++;
			}
		}
	}
	// Cout result array
	cout << "Odd array: " << endl;
	for (int i = 0; i < oddCount; i++)
	{
		cout << oddArr[i] << " ";
	}
	// Cout average value
	cout << endl << "Average: " << endl;
	cout << getAverage(oddArr, oddCount);
	// очистка за собой
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	delete[] oddArr;
	return 0;
}