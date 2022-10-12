#pragma once
#include <array>
#include "Result.h"

class NumberComparer
{	
public:
	NumberComparer();
	~NumberComparer();
	void SetGeneratedNumbers(const std::array<int, 3>& nums);	//
	bool CompareNumbers(std::array<int, 3> clientNums);	//return true if all numbers are matched
	int GetStrikes();
	int GetBalls();
	Result GetResult();
private:
	Result result;
	std::array<int, 3> nums;
};

