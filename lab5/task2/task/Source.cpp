#include <iostream>;
#include <Windows.h>;
using namespace std;

int main() {
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef int (*count) (double arr[], int startIndex, int endIndex, int result); // создаём тип данных указателя на нашу функцию
	count countFunc;
	if (load != 0) {
		countFunc = (count)GetProcAddress(load, "count");
		int arrSize, result = 0;
		cout << "Enter size of array: " << endl;
		cin >> arrSize;
		double* arr = new double[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			cout << "Enter arr[" << i << "]: " << endl;
			cin >> arr[i];
		}
		int middleIndex = arrSize / 2;
		result = countFunc(arr, 0, middleIndex, 0) + countFunc(arr, middleIndex, arrSize, 0);
		cout << "result = " << result;
		delete[] arr;
		FreeLibrary(load);
	}
	return 0;
}