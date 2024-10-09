#include <interpol/interpol.hpp>

namespace nm {

class Cubic: public Interpolation {
public:
	using Interpolation::Interpolation;

	virtual void setX(ListT x) override;

	virtual double interpolate(double x) override;
	const ListT& dividedDifference = n_M;
protected:
	ListT n_M;
	void calculateM();
};

}
