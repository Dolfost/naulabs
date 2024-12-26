#include <calgo/interpol/cubic.hpp>
#include <calgo/lsys/thomas.hpp>

#include <algorithm>
#include <cmath>

namespace ca::interpol {

void Cubic::setX(ListT x) {
	ExplicitInterpolation::setX(x);
	calculateM();
}

void Cubic::calculateM() {
	ListT a(i_n - 3), b(i_n - 2), l(i_n - 2); // c = a
	for (std::size_t i = 0; i < i_n - 3; i++)
		a[i] = hx(i+2)/6;

	for (std::size_t i = 0; i < i_n - 2; i++) {
		b[i] = (hx(i+1) + hx(i+2))/3;
		l[i] = (i_y[i+2] - i_y[i+1])/hx(i+1) - (i_y[i+1] - i_y[i])/hx(i+1);
	}

	ListT sol = ca::lsys::Thomas::solve(a, b, a, l); // c = a

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
	double hi = hx(i);

	return n_M[i-1]*std::pow(i_x[i] - x, 3)/(6*hi) +
		n_M[i]*std::pow(x - i_x[i-1], 3)/(6*hi) + 
		(i_y[i-1] - n_M[i-1]*std::pow(hi, 2)/6)*(i_x[i] - x)/hi +
		(i_y[i] - n_M[i]*std::pow(hi, 2)/6)*(x - i_x[i-1])/hi;
}
	
}
