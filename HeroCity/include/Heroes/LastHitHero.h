#pragma once
#include "Heroes/SuperHero.h"

class LastHitHero :public SuperHero
{
public:
	LastHitHero();
	//const void  Update() override;
	const void OnEnter() override;
	//const void OnExit() override;
	void Attack( Character* other) override;
	void GetDamage(int _amount)override;
private:
	bool lastHitDone{ false };
};