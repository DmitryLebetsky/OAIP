#include <iostream>;
#include <cmath>;
using namespace std;

extern "C" __declspec(dllexport) int count(double arr[], int startIndex, int endIndex, int result) {
	if (startIndex < endIndex) {
		result = result + (int)(sin(arr[startIndex] / 2.0) < 0);
		return count(arr, startIndex + 1, endIndex, result);
	}
	else {
		return result;
	}
}