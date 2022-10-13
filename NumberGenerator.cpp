#include "NumberGenerator.h"

NumberGenerator::NumberGenerator()
{
	nums.fill(-1);
	srand(time(NULL));
}

NumberGenerator::~NumberGenerator()
{

}

void NumberGenerator::GenerateNumbers(const int& leftIndex)	//generate random seperate 3 numbers
{
	if (leftIndex < 1) return;
	int tempNum = GetRandNum(9);
	for (int i = 0; i < 3 - leftIndex; i++) 
	{
		if (tempNum == nums[i]) //exception : same number exist
		{
			GenerateNumbers(leftIndex);	//generate new number at current index
			return;
		}
	}
	if (leftIndex > 3 || leftIndex < 1) return;	//overflow guard
	nums[3 - leftIndex] = tempNum;
	GenerateNumbers(leftIndex - 1);	//generate new number at next index
}

std::array<int, 3> NumberGenerator::GetNumbers()	//get numbers array
{
	return nums;
}

int NumberGenerator::GetRandNum(const int& max, const int& min)	//generate random number from min to max, min default is 0
{
	return rand() % (max + 1) + min;
}
