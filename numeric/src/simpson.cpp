#include "calgo/numeric/simpson.hpp"

namespace ca::numeric {

double Simpson::integrate() {
	std::size_t n = s_x.size() - 1;

	double step = h(0);

	double sum_odds = 0.0;
	for (int i = 1; i < n; i += 2) {
		sum_odds += s_y[i];
	}
	double sum_evens = 0.0;
	for (int i = 2; i < n; i += 2) {
		sum_evens += s_y[i];
	}

	return (s_y.front() + s_y.back() + 2 * sum_evens + 4 * sum_odds) * step / 3;}
}

