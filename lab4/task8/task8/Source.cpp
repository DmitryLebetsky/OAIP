#include <iostream>;
#include  <cmath>;
using namespace std;

int main() {
	int arrSize, indexOfBiggest = 0, indexOfSmallest = 0, zerosCount = 0;
	cout << "Enter array size: " << endl;
	cin >> arrSize;
	int* arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		int enteredElement;
		cout << "Enter " << i << " element: ";
		cin >> enteredElement;
		if (!enteredElement) {
			zerosCount++;
		}
		arr[i] = enteredElement;
	}
	// COUT INPUT
	cout << "current array: " << endl;
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
		if (arr[i] > arr[indexOfBiggest]) {
			indexOfBiggest = i;
		}
		if (arr[i] < arr[indexOfSmallest]) {
			indexOfSmallest = i;
		}
	}
	// FILL ARRAY WITH 0 + count them
	cout << endl << "Biggest is: " << arr[indexOfBiggest] << endl;
	cout << "Smalles is: " << arr[indexOfSmallest] << endl;
	if (indexOfSmallest < indexOfBiggest) {
		for (int i = indexOfSmallest + 1; i < indexOfBiggest; i++)
		{
			arr[i] = 0;
		}
	}
	else {
		for (int i = indexOfBiggest + 1; i < indexOfSmallest; i++)
		{
			arr[i] = 0;
		}
	}
	zerosCount = zerosCount + (abs(indexOfBiggest - indexOfSmallest) - 1);
	// COUT ARRAY WITH 0
	cout << "Array with 0 between biggest and smallest: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << "Zeros count: " << zerosCount;
	// Removing 0s if needed
	if (zerosCount > (arrSize / 2)) {
		int noZerosSize = arrSize - zerosCount;
		int* noZerosArr = new int[noZerosSize];
		cout << endl << "Array without zeros: " << endl;
		for (int i = 0, p = 0; i < arrSize; i++)
		{
			if (arr[i] != 0) {
				noZerosArr[p] = arr[i];
				cout << noZerosArr[p] << " ";
				p++;
			}
		}
		delete[] noZerosArr;
	}
	// DELETING
	delete[] arr;
	return 0;
}