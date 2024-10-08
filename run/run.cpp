#include "run.hpp"
#include <vector>

std::pair<std::vector<double>, std::vector<double>> 
Run::solve(std::vector<std::vector<double>> mtrx) {
	int n = mtrx.size();

	std::vector<double> nums;
	for (auto const& x : mtrx) {
		nums.push_back(x[n]);
	}
	std::vector<std::vector<double>> numsM = mtrx;

	std::vector<double> a(n);
	std::vector<double> b(n);
	std::vector<double> c(n);

	a[0] = 0;
	c[n] = 0;
	
	for (int i = 1; i < n; i++) {
		a[i] = mtrx[i][i-1];
		c[i-1] = mtrx[i-1][i];
	}

	for (int i = 0; i < n; i++) {
		b[i] = -mtrx[i][i];
	}

	std::vector<double> k(n+1);
	k[0] = 0;

	for (int i = 0; i < n-1; i++) {
		k[i+1] = (c[i])/(b[i]-a[i]*k[i]);
	}

	std::vector<double> u(n+1);
	u[0] = 0;

	for (int i = 0; i < n; i++) {
		u[i+1] = (a[i]*u[i]-mtrx[i][n])/(b[i]-a[i]*k[i]);
	}

	std::vector<double> result(n+1);
	result[n] = 0;

	for (int i = n-1; i >= 0; i--) {
		result[i] = k[i+1]*result[i+1]+u[i+1];
	}

	result.pop_back();

	// Невʼязки
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			nums[row] -= numsM[row][col]*result[col];
		}
	}

	return {result, nums};
}
