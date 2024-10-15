#include <calgo/interpol/cubicParametric.hpp>
#include <calgo/lsys/cyclicThomas.hpp>

namespace ca::interpol {

void CubicParametric::setX(ListT x) {
	ParametricInterpolation::setX(x);
	calculateMs();
}

void CubicParametric::calculateMs() {
	ListT a(i_n, 1.0/6.0), b(i_n, 2.0/3.0), fx(i_n), fy(i_n); // c = a
	
	fx[0] = fx[1] - fx[0] - (fx[0] - fx[i_n-1]);
	fy[0] = fy[1] - fy[0] - (fy[0] - fy[i_n-1]);
	fx[i_n-1] = fx[0] - fx[i_n-1] - (fx[i_n-1] - fx[i_n-2]);
	fy[i_n-1] = fy[0] - fy[i_n-1] - (fy[i_n-1] - fy[i_n-2]);
	for (std::size_t i = 1; i < i_n - 1; i++) {
		fx[i] = i_x[i+1] - i_x[i] - (i_x[i] - i_x[i-1]);
		fy[i] = i_y[i+1] - i_y[i] - (i_y[i] - i_y[i-1]);
	}

	n_Mx = ca::lsys::CyclicThomas::solve(a, b, a, fx); // c = a
	n_My = ca::lsys::CyclicThomas::solve(a, b, a, fy); // c = a
}

std::pair<double, double> CubicParametric::interpolate(double t) {
	std::size_t ti = static_cast<std::size_t>(t);
	ti %= i_n;

	return {
		n_Mx[ti-1]*std::pow(ti - t, 3)/6 +
		n_Mx[ti]*std::pow(t - (ti-1), 3)/6 + 
		(i_x[ti-1] - n_Mx[ti-1]/6)*(ti - t) +
		(i_x[ti] - n_Mx[ti]/6)*(t - (ti-1)),
		n_My[ti-1]*std::pow(ti - t, 3)/6 +
		n_My[ti]*std::pow(t - (ti-1), 3)/6 + 
		(i_y[ti-1] - n_My[ti-1]/6)*(ti - t) +
		(i_y[ti] - n_My[ti]/6)*(t - (ti-1)),
	};
}
	
}
