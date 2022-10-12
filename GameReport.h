#pragma once
class GameReport
{
public:
	GameReport();
	~GameReport();
	int gameCount;
	int tryCount;
	int minTryCount;
	int maxTryCount;
	void Clear();
	void ResetTryCount();
	void UpdateReport();
private:
};

