#ifndef _RUH_HPP_
#define _RUH_HPP_

#include <vector>

class Run {
public:
    std::pair<std::vector<double>,std::vector<double>> 
			solve(std::vector<std::vector<double>>);
};

#endif // !_RUH_HPP_
