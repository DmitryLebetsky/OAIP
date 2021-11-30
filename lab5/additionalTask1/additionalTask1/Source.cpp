#include <iostream>;
using namespace std;

int F(int n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return F(n / 10);
	}
}

int main() {
	int p, q, S = 0;
	cout << "Enter p >= 0:" << endl;
	if (!(cin >> p) || cin.get() != '\n' || p < 0) {
		cout << "Incorrect input. Try again.";
		return 0;
	}
	cout << "Enter q >= p:" << endl;
	if (!(cin >> q) || cin.get() != '\n' || q < p) {
		cout << "Incorrect input. Try again.";
		return 0;
	}

	for (int i = p; i <= q; i++)
	{
		S = S + F(i);
	}
	cout << "S = " << S;
	return 0;
}