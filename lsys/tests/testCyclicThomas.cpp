#include <iomanip>
#include <iostream>
#include <calgo/lsys/cyclicThomas.hpp>

bool comp(
	const std::vector<double>& a, 
	const std::vector<double>& b, 
	double delta = 0.01) {
	if (a.size() != b.size())
		return false;

	for (auto ait = a.begin(), bit = b.begin(); ait != a.end(); ait++, bit++)
		if (std::abs(*ait - *bit) > delta)
			return false;

	return true;
}

int main() {
	double cn = 5, a1 = cn;

	std::vector<double>
	a = {a1, 4, 5, 6, 9},
	b = {6, 8, 5, 3, 11},
	c = {9, 7, 3, 1, cn},
	d = {7, 3, 9, 4, 5};

	std::vector<double> 
	sol = ca::lsys::CyclicThomas::solve(a, b, c, d),
	expect = {-3.664, 1.677, -0.606, -0.895, 2.779};

	std::cout << "expected: ";
	for (auto const& x : expect) {
		std::cout << std::setw(6) << std::setprecision(3) << x << " ";
	}
	std::cout << "\nres:      ";
	for (auto const& x : sol) {
		std::cout << std::setw(6) << std::setprecision(3) << x << " ";
	}

	return !comp(sol, expect);
}
