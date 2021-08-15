// Art of Computer Programming Vol. I, 1.2.1

#include <cassert>
#include <iostream>

int gcd(int m, int n, int &a, int &b) {
	assert(m > 0 && n > 0);
	int a2 = b = 1;
	int b2 = a = 0;
	int c = m, d = n;
	for (;;) {
		int q = c / d, r = c - d * q;
		if (r == 0) { return d; }
		c = d; d = r;
		int t = a2; a2 = a; a = t - q * a;
		t = b2; b2 = b; b = t - q * b;
	}
}

void run(int m, int n) {
	int a, b;
	int d = gcd(m, n, a ,b);
	std::cout << "gcd(" << m << ", " << n << ") = " << a << " * " << m <<
		" + " << b << " * " << n << " = " << d << "\n";
	assert(a * m + b * n == d);
}

int main() {
	run(1709, 551);
}
