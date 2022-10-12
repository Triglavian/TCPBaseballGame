#pragma once
#include <array>
#include <ctime>

class NumberGenerator
{
public:
	NumberGenerator();
	~NumberGenerator();
	void GenerateNumbers(const int& leftIndex);	//generate random seperate 3 numbers
	std::array<int, 3> GetNumbers();
private:
	int GetRandNum(const int& max, const int& min = 0);	//generate random number from min to max, min default is 0
	std::array<int, 3> nums;
};

