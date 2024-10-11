#include <interpol/interpol.hpp>

namespace nm {

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
