#include "GameReport.h"

GameReport::GameReport()
{
	gameCount = tryCount = minTryCount = maxTryCount = 0;
}

GameReport::~GameReport()
{

}

void GameReport::Clear()
{
	gameCount = tryCount = minTryCount = maxTryCount = 0;
}

void GameReport::ResetTryCount()
{
	tryCount = 0;
}

void GameReport::UpdateReport()
{
	gameCount++;
	if (minTryCount == 0 || minTryCount > tryCount)
	{
		minTryCount = tryCount;
		return;
	}
	if (maxTryCount == 0 || maxTryCount < tryCount) 
	{
		maxTryCount = tryCount;
		return;
	}
}
