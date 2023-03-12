#include "Villains/MultiAttackVillain.h"
#include <ctime>
#include <cstdlib>
void MultiAttackVillain::Attack(Character* other)
{
	other->GetDamage(force);
	if (currentAttack >= 2)
	{
		other->GetDamage(force);
		currentAttack = -1;
	}
	currentAttack++;
}
const void MultiAttackVillain::Update()
{

}
const void MultiAttackVillain::OnExit()
{
}
const void MultiAttackVillain::OnEnter()
{
	currentAttack = 0;
	std::srand(std::time(nullptr));
	const int randomPos = 100 + std::rand() % 1401;
	pos = randomPos;
	vitality = maxVitality;
	name = "Villano multiataque";
}