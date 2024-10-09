#include <iostream>
#include <thomas.hpp>

int main() {

	std::vector<double>
	a = {4, 5, 6, 9},
	b = {6, 8, 5, 3, 11},
	c = {9, 7, 3, 1},
	l = {7, 3, 9, 4, 5};

	std::vector<double> sol = nm::lsys::Thomas::solve(a, b, c, l);

	for (auto const& x : sol) {
		std::cout << x << " ";
	}

	return sol != std::vector<double>{635/1992.0, 563/996.0, -199/498.0, 2713/996.0, -589/332.0};
}
