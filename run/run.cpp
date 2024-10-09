#include "run.hpp"
#include <vector>

namespace nm::lsys {

std::vector<double>
Run::solve(std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> l) {
	int n = b.size();

	std::vector<double> k(n+1);
	k[0] = 0;

	for (int i = 0; i < n-1; i++) {
		k[i+1] = (c[i])/(b[i]-a[i]*k[i]);
	}

	std::vector<double> u(n+1);
	u[0] = 0;

	for (int i = 0; i < n; i++) {
		u[i+1] = (a[i]*u[i]-l[i])/(-b[i]-a[i]*k[i]);
	}

	std::vector<double> result(n+1);
	result[n] = 0;

	for (int i = n-1; i >= 0; i--) {
		result[i] = k[i+1]*result[i+1]+u[i+1];
	}

	result.pop_back();

	return result;
}

}
