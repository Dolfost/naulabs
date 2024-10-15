#ifndef _CALGO_CUBIC_PARAMETRIC_INTERPOL_HPP_
#define _CALGO_CUBIC_PARAMETRIC_INTERPOL_HPP_

#include <calgo/interpol/interpol.hpp>

namespace ca::interpol {

class CubicParametric: public ParametricInterpolation {
public:
	using ParametricInterpolation::ParametricInterpolation;

	virtual void setX(ListT x) override;

	virtual std::pair<double, double> interpolate(double t) override;

	const ListT& mx = n_Mx;
	const ListT& my = n_My;
protected:
	ListT n_Mx, n_My;
	void calculateMs();
};

}

#endif // !_CALGO_CUBIC_PARAMETRIC_INTERPOL_HPP_
