#pragma once
#include "Heroes/SuperHero.h"

class LethalHero :public SuperHero
{
public:
	LethalHero();
	//const void  Update() override;
	const void OnEnter() override;
	//const void OnExit() override;
	void Attack( Character* other) override;
	void OnWin()override;
private:
	int currentAttack{ 0 };
};