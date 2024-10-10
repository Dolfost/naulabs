#ifndef _INTERPOL_HPP_
#define _INTERPOL_HPP_

#include <vector>

namespace nm {

class Interpolation {
public:
	using ListT = std::vector<double>;
	Interpolation(ListT x = {}, ListT y = {}) {
		setX(x), setY(y);
	}

	virtual double interpolate(double) = 0;

	virtual void setX(ListT x) { i_x = x; i_n = i_x.size(); };
	virtual void setY(ListT y) { i_y = y; };
	ListT x() { return i_x; };
	ListT y() { return i_y; };

	double operator()(double x) { return interpolate(x); };

	virtual ~Interpolation() {};
public:
	enum class Node {
		Uniform,
		Chebyshev,
	};

	double h(std::size_t i) {
		return i_x[i] - i_x[i-1];
	}

	static ListT uniformNodes(double, double, std::size_t);
	static ListT chebyshevNodes(double, double, std::size_t);
protected:
	ListT i_x, i_y;
	std::size_t i_n;
};

}

#endif // !_INTERPOL_HPP_
