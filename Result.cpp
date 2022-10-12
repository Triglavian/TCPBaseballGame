#include "Result.h"

Result::Result(const int& strikes, const int& balls)
{
	this->strikes = strikes;
	this->balls = balls;
}

Result::~Result()
{

}

void Result::Clear()
{
	strikes = balls = 0;
}
