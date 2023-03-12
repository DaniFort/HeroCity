#pragma once
#include "Villains/Villain.h"

class MultiAttackVillain :public Villain
{
public:
	void GetDamage() {}
	void Attack(Character* other)override;
	const void  Update() override;
	const void OnEnter() override;
	const void OnExit() override;

protected:

private:
	int currentAttack{ 0 };
};