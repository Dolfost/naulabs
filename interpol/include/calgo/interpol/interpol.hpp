#ifndef _CALGO_INTERPOL_HPP_
#define _CALGO_INTERPOL_HPP_

#include <calgo/calgo.hpp>

namespace ca::interpol {

class Interpolation {
public:
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
	double h(std::size_t i) {
		return i_x[i] - i_x[i-1];
	}

protected:
	ListT i_x, i_y;
	std::size_t i_n;
};

class Nodes {
public:
	static ListT uniform(double, double, std::size_t);
	static ListT chebyshev(double, double, std::size_t);
};

}

#endif // !_CALGO_INTERPOL_HPP_
