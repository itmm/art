// Art of Computer Programming Vol. I, 1.2.2

#include <cassert>
#include <iostream>

constexpr int ITERATIONS { 30 };

double log10(double x) {
	assert(x > 0.0);

	double result { 0.0 };
	while (x < 1) { --result; x *= 10.0; }
	while (x >= 10) { ++result; x *= 0.1; }
	constexpr double inv_half { 0.5 };
	double mult { inv_half };
	for (int i { ITERATIONS }; i; --i, mult *= inv_half) {
		x *= x;
		if (x >= 10.0) {
			x *= 0.1;
			result += mult;
		}
	}
	return result;
}

void run(double x) {
	std::cout << "log10(" << x << ") == " << log10(x) << "\n";
}

int main() {
	run(2);
	run(10);
	run(100);
	run(25);
	run(.3);
}
