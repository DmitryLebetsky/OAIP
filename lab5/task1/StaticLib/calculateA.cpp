#include <cmath>;

double calculateA(int i) {
	if (i > 17) {
		return sin(i + 1);
	}
	else {
		return 1.0 / tan(pow(i + 1, 2));
	}
}