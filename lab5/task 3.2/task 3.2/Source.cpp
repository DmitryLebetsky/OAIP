#include <iostream>;
using namespace std;

int* revertArray(int arr[], int arrSize) {
	int* result = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		result[i] = arr[arrSize - 1 - i];
	}
	return result;
}

int main() {
	// create and fill array
	int size;
	cout << "Enter size: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter arr[" << i << "]: " << endl;
		cin >> arr[i];
	}
	// cout your array
	cout << "Your array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	// count number of zeros and cout their indexes
	int zerosCount = 0;
	cout << endl << "Indexes of zeros: " << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0) {
			cout << i << " ";
			zerosCount++;
		}
	}
	if (zerosCount == 0) {
		cout << "-";
	}
	cout << endl << "Zeros count: " << zerosCount;
	// revert array
	cout << endl << "Reverted array: ";
	int* revertedArray = revertArray(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << revertedArray[i] << " ";
	}
	delete[] revertedArray;
	delete[] arr;
	return 0;
}