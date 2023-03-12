#include "Heroes/LethalHero.h"
#include <ctime>
#include <cstdlib>
LethalHero::LethalHero()
{
	name = "";
	force = 0;
	vitality = 0;
}
const void LethalHero::OnEnter()
{
	currentAttack = 0;
	pos = 0;
	hasLost = false;
	std::srand(std::time(nullptr));
	const int randomSpeed = std::rand() % 21 + 80;
	speed = randomSpeed;
}
//const void LethalHero::Update()
//{
//
//}
//const void LethalHero::OnExit()
//{
//
//}
void LethalHero::Attack( Character* other)
{
	other->GetDamage(force);
	switch (currentAttack)
	{
	case1:
	{
		std::srand(std::time(nullptr));
		const int nextDamage = 10+std::rand() % 6;
		other->GetDamage(nextDamage);
	}
		break;
	case 2:
	{
		std::srand(std::time(nullptr));
		const int nextDamage = 5+std::rand() % 6;
		other->GetDamage(nextDamage);
	}
		break;

	default:
		break;
	}
}
void LethalHero::OnWin()
{
	currentAttack = 0;
}