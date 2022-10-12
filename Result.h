#pragma once
class Result
{
public:
	Result(const int& strikes = 0, const int& balls = 0);
	~Result();
	void Clear();
	int strikes;
	int balls;
private:
};

