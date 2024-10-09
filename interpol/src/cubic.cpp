#include <interpol/cubic.hpp>
#include <thomas.hpp>

#include <algorithm>

namespace nm {

void Cubic::setX(ListT x) {
	Interpolation::setX(x);
	calculateM();
}

void Cubic::calculateM() {
	ListT a(i_n - 3), b(i_n - 2), l(i_n - 2); // c = a
	for (std::size_t i = 0; i < i_n - 3; i++) {
		a[i] = (i_x[i+2] - i_x[i+1])/6;
	}

	for (std::size_t i = 0; i < i_n - 2; i++) {
		b[i] = (i_x[i+1] - i_x[i] + i_x[i+2]-i_x[i+1])/3;
		l[i] = (i_y[i+2] - i_y[i+1])/(i_x[i+1] - i_x[i]) - (i_y[i+1] - i_y[i])/(i_x[i+1] - i_x[i]);
	}

	ListT sol = nm::lsys::Thomas::solve(a, b, a, l);

	n_M.clear();
	n_M.push_back(0);
	n_M.insert(n_M.end(), sol.begin(), sol.end());
	n_M.push_back(0);
}

double Cubic::interpolate(double x) {
	auto it = std::lower_bound(
		i_x.begin(), i_x.end(), x, std::less_equal{}
	);
	std::size_t i = std::distance(i_x.begin(), it);
	double h = *it - *std::prev(it);
	double val = n_M[i-1]*std::pow(i_x[i] - x, 3)/(6*h) +
		n_M[i]*std::pow(x - i_x[i-1], 3)/(6*h) + 
		(i_y[i-1] - n_M[i-1]*std::pow(h, 2)/6)*(i_x[i] - x)/h +
		(i_y[i] - n_M[i]*std::pow(h, 2)/6)*(x - i_x[i-1])/h;
	return val;
}
	
}
