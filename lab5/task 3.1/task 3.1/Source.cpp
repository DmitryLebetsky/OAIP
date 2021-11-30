#include <iostream>;
using namespace std;

int productOfArrayElements(int arr[], int arrSize) { // Функция нахождения произведения элемнтов массива
	int result = 1;
	for (int i = 0; i < arrSize; i++)
	{
		result = result * arr[i];
	}
	return result;
}

int main() {
	int rows, cols;
	cout << "Enter 5: " << endl;
	if (!(cin >> rows) || cin.get() != '\n' || rows != 5) {
		cout << "Incorrect input";
		return 0;
	}
	cout << "Enter 6: " << endl;
	if (!(cin >> cols) || cin.get() != '\n' || cols != 6) {
		cout << "Incorrect input";
		return 0;
	}
	// Создаём двумерный динамический массив и заполняем его
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
	// Вывести исходный массив
	cout << "YOUR ARRAY: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	// Считаем число чётных чисел на главной диагонали
	int evenNumbersCount = 0; // количество чётных чисел
	for (int i = 0; i < rows; i++)
	{
		if (arr[i][i] % 2 == 0) {
			evenNumbersCount++;
		}
	}
	// Создаём массив из чётных чисел главной диагонали и заполняем его
	int* resultArr = new int[evenNumbersCount];
	for (int i = 0, j = 0; i < rows; i++)
	{
		if (arr[i][i] % 2 == 0) {
			resultArr[j] = arr[i][i];
			j++;
		}
	}
	// Выводим итоговый массив
	cout << "Result Array: ";
	for (int i = 0; i < evenNumbersCount; i++)
	{
		cout << resultArr[i] << " ";
	}
	cout << endl;
	// Ищем произведение элемнтов и выводим
	cout << "Production of elements: " << productOfArrayElements(resultArr, evenNumbersCount) << endl;
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	delete[] resultArr;
	return 0;
}