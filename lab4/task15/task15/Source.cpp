#include <iostream>;
using namespace std;

int main() {
	int counter = 0, rowsCount = 0, colsCount = 0, currentCol = 0, currentRow = 0, toFind;
	bool isFound = false;
	cout << "Enter number you want to find: " << endl;
	cin >> toFind;
	while (!isFound)
	{
		counter++;
		if (toFind == counter) {
			cout << currentRow << " row" << endl;
			cout << currentCol << " col";
			isFound = true;
		}
		if (currentCol == 0) {
			rowsCount++;
			colsCount++;
			currentRow = 0;
			currentCol = colsCount;
		} else if (currentRow < rowsCount) {
			currentRow++;
		}
		else {
			currentCol--;
		}
	}
	return 0;
}