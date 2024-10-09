#ifndef _RUH_HPP_
#define _RUH_HPP_

#include <vector>

namespace nm::lsys {

class Run {
public:
	static std::vector<double> solve(
		std::vector<double>, 
		std::vector<double>, 
		std::vector<double>, 
		std::vector<double>
	);
};

}

#endif // !_RUH_HPP_
