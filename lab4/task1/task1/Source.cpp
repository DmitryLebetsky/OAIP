#include <iostream>;
using namespace std;

int main() {
	const int arrSize = 7;
	int arr[arrSize];
	for (int i = 0; i < arrSize; i++) {
		cout << "enter " << i << " element" << endl;
		cin >> arr[i];
	}
	// INPUT DATA
	cout << "Input data: " << endl;
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	for (int i = 1; i < arrSize; i++)
	{
		if (arr[i] > arr[i-1]) {
			cout << endl << "Array is unordered";
			return 0;
		}
	}
	cout << endl << "Array is ordered";
	return 0;
}