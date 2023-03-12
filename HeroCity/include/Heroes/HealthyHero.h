#pragma once
#include "Heroes/SuperHero.h"
class HealthyHero :public SuperHero
{
public:
	HealthyHero();
	//const void  Update() override;
	const void OnEnter() override;
	//const void OnExit() override;
	void OnWin()override;
	void Attack(Character* other) override;
	void GetDamage(const int _damage)override;
private:
	int shield{0};
};