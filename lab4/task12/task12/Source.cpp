#include <iostream>;
using namespace std;

int main() {
	int size;
	cout << "Enter array size: " << endl;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> arr[i];
	}
	// cout input data
	cout << "Source array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	// deleting dublicates
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) {
				arr[i] = arr[size-1];
				i--;
				size--;
				break;
			}
		}
	}
	// cout result
	cout << endl << "Result array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	// deleting
	delete[] arr;
	return 0;
}