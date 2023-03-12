#pragma once
#include "Villains/Villain.h"

class HealthyVillain :public Villain
{
public:
	HealthyVillain();
	void Attack(Character* other)override;
	const void  Update() override;
	const void OnEnter() override;
	const void OnExit() override;

protected:

private:
};