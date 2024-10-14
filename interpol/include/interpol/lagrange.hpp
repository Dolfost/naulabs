#ifndef _CALGO_INTERPOL_LAGRANGE_
#define _CALGO_INTERPOL_LAGRANGE_

#include <interpol/interpol.hpp>

namespace ca::interpol {

class Lagrange: public Interpolation {
public:
	using Interpolation::Interpolation;

	virtual void setX(ListT x) override;

	virtual double interpolate(double x) override;
protected:
	ListT n_L;
	void calculateL();
};

}

#endif // !_CALGO_INTERPOL_LAGRANGE_
