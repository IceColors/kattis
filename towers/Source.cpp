#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

pair<double, double> normalize(double x, double n) {
	if (x >= 1) return normalize(log(x), n + 1);
	else if (x < 0)	return normalize(exp(x), n - 1);
	else return (pair<double, double>(x, n));
}

pair<double, double> apow(double a, pair<double, double> p) {
	if (a == 1) return pair<double, double>(1, 0));
	if (a < 1) return (rpow(x, n)*log(a), 1);
	if (p.second == 0) return (x*log(a), 1);
	if (p.second >= 1) pair<double, double> y = cpow(log(log(a)), x, n - 1);
	return (y.first, y.second + 2);
}

pair<double, double> cpow(double c, double x, double n) {
	if (c == 0) return pair<double, double>(x, n);
	if (n == 0) return pair<double, double>(x + c, 0);
	double z = rpow(x, n - 1);
	if (z <= log(abs(c))) return pair<double, double>(exp(z) + c, 0);
	if (c < 0) pair<double, double> y = cpow(log(1 - exp(log(-c) - z)), x, n - 1);
	if (c > 0) {
		pair<double, double> y = cpow(log(1 + exp(log(c) - z)), x, n - 1)
			return (y, k + 1)
	}
}

double rpow(double x, double n) {
	try {
		for (double i = 1; i <= n; i++) x = exp(x);
	}
	catch (overflow_error& e) {
		return float('inf');
	}

	return (x);
}

pair<double, double> powtow(int bs[], int len, int pos) {
	if (len == pos) return pair<double, double>(1, 0);
	pos++;
	return apow(bs[0], powtow(bs[1:]))
}