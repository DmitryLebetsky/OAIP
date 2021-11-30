#include <iostream>;
using namespace std;

int getGOD(int n) { // god - greatest odd divisor = наибольший нечётный делитель
	if (n % 2 == 1) {
		return n;
	}
	else {
		int result = n - 1;
		while (n % result != 0) {
			result = result - 2;
		}
		return result;
	}
}

int main() {
	int n, result = 0;
	cout << "Enter n > 0:" << endl;
	if (!(cin >> n) || cin.get() != '\n' || n <= 0) {
		cout << "Incorrect input. Try again";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		result = result + getGOD(i);
	}
	cout << "Result = " << result;
}