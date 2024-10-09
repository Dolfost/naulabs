#ifndef _THOMAS_HPP_
#define _THOMAS_HPP_

#include <vector>

namespace nm::lsys {

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

#endif // !_THOMAS_HPP_
