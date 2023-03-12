#pragma once
#include <chrono>
#include <iostream>
class TimeManager 
{
public:
	TimeManager(int _FPS, int _totaldays) :FPS(_FPS), totalDays(_totaldays) {}
	float* GetFPS() { return &FPS; }
	bool NextHour() { currentHour++; return CheckHour(); }
	bool CheckHour();
	int* GetTotalDay() { return &totalDays; }
	int& GetHour() { return currentHour; }
	int& GetDay() { return currentDay; }
	int& GetWeekDay() { return weekDay; }
protected:
private:
	int currentHour{ 0 };
	int currentDay{ 0 };
	int weekDay{ 1 };
	float FPS{ 1 };
	int totalDays{ 0 };
};