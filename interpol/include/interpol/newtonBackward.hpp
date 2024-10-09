#include <interpol/interpol.hpp>

namespace nm {

class NewtonBackward: public Interpolation {
public:
	using Interpolation::Interpolation;

	virtual void setX(ListT x) override;

	virtual double interpolate(double x) override;
	const ListT& dividedDifference = n_dif;
protected:
	ListT n_dif;
	void calculateDiff();
};

}
