#ifndef _CALGO_LSYS_THOMAS_HPP_
#define _CALGO_LSYS_THOMAS_HPP_

#include <vector>

namespace ca::lsys {

class Thomas {
public:
	static std::vector<double> solve(
		const std::vector<double>&, 
		const std::vector<double>&, 
		const std::vector<double>&, 
		const std::vector<double>&
	);
};

}

#endif // !_CALGO_LSYS_THOMAS_HPP_
