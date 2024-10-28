#include "calgo/numeric/simpson.hpp"

namespace ca::numeric {

double Simpson::integrate() {
	std::size_t N = s_x.size() - 1;

	double result = 0.0;
	for (std::size_t i = 1; i < N; i += 2) {
		double h0 = h(i-1), h1 = h(i);
		double hph = h1 + h0, hdh = h1/h0, hmh = h1*h0;
		result += (hph/6)*((2 - hdh)*s_y[i-1] + 
			(std::pow(hph, 2)/hmh)*s_y[i] + (2 - 1/hdh)*s_y[i+1]
		);
	}

	if (N % 2 == 1) {
		double h0 = h(N-2), h1 = h(N-1);
		result += s_y[N]*(2*std::pow(h1, 2) + 3*h0*h1)/(6*(h0 + h1));
		result += s_y[N-1]*(std::pow(h1, 2) + 3*h1*h0)/(6*h0);
		result -= s_y[N-2]*std::pow(h1, 3)/(6*h0*(h0 + h1));
	}

	return result;
}

}

