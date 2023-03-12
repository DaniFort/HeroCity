#pragma once
#include "Villains/Villain.h"

class IncrementalForceVillain :public Villain 
{
public:
	IncrementalForceVillain();
	void GetDamage(const int damage)override;
	const void  Update() override;
	const void OnEnter() override;
	const void OnExit() override;

protected:

private:
};