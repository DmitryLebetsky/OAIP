#include <iostream>;
#include <cmath>;
using namespace std;

int f(int n, int r, int k) {
	cout << endl << "f()";
	if (n == 0 && r == 0) {
		return 1;
	}
	else if (n > 0 && (r >= 0) && (r < (n*(k - 1) + 1))) {
		int result = 0;
		for (int i = 0; i <= k - 1; i++)
		{
			result = result + f(n - 1, r - i, k);
		}
		return result;
	}
	else {
		return 0;
	}
}


int main() {
	int x = 0, k, n, t, m;

	cout << "Enter k > 0:" << endl;
	if (!(cin >> k) || cin.get() != '\n' || k <= 0) {
		cout << "Incorrect input. Try again";
		return 0;
	}

	cout << "Enter n > 0:" << endl;
	if (!(cin >> n) || cin.get() != '\n' || n <= 0) {
		cout << "Incorrect input. Try again";
		return 0;
	}

	cout << "Enter 0 < t < 10:" << endl;
	if (!(cin >> t) || cin.get() != '\n' || t <= 0 || t >= 10) {
		cout << "Incorrect input. Try again";
		return 0;
	}

	for (int i = 0; i <= n*(k-1); i++)
	{
		x = x + f(n, i, k);
	}

	m = pow(10, t);
	x = x % m;
	cout << "x = " << x;
	return 0;
}