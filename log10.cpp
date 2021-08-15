// Art of Computer Programming Vol. I, 1.2.2

#include <cassert>
#include <iostream>

constexpr int ITERATIONS { 30 };

double log10(double x) {
	assert(x > 0.0);
	
	int shifts { 0 };
	while (x < 1) { --shifts; x *= 10.0; }
	while (x >= 10) { ++shifts; x *= 0.1; }
	double result = shifts;

	double mult { 0.5 };
	for (int i { ITERATIONS }; i; --i, mult *= 0.5) {
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
