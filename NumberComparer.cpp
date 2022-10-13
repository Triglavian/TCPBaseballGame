#include "NumberComparer.h"

NumberComparer::NumberComparer()
{
	nums.fill(0);
	result.Clear();
}

NumberComparer::~NumberComparer()
{
	
}

void NumberComparer::SetGeneratedNumbers(const std::array<int, 3>& nums)	//set generated numbers 
{
	for (int i = 0; i < 3; i++)
	{
		this->nums[i] = nums[i];
	}
}

bool NumberComparer::CompareNumbers(std::array<int, 3> clientNums)	//return true if all numbers are matched
{
	result.Clear();
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (nums[i] == clientNums[i]) //strike case : same number at same index
			{
				result.strikes++;
				break;
			}
			if (nums[i] == clientNums[j]) //ball case : same number at another index
			{
				result.balls++;
				break;
			}
		}
	}
	return result.strikes > 2 ? true : false;
}

int NumberComparer::GetStrikes()
{
	return result.strikes;
}

int NumberComparer::GetBalls()
{
	return result.balls;
}

Result NumberComparer::GetResult()
{
	return result;
}
