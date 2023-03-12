#include "Heroes/HealthyHero.h"
#include <ctime>
#include <cstdlib>
HealthyHero::HealthyHero()
{
	name = "";
	force = 0;
}

const void HealthyHero::OnEnter()
{
	shield = 10;
	hasLost = false;
	std::srand(std::time(nullptr));
	const int randomSpeed = std::rand() % 21 + 80;
	speed = randomSpeed;
}
void HealthyHero::OnWin()
{
	std::srand(std::time(nullptr));
	const int shieldPlus = 10+std::rand() % 30;
	shield += shieldPlus;
}
void HealthyHero::GetDamage(const int _amount)
{
	int amount = _amount;
	if (shield > 0)
	{
		if (amount > shield)
		{
			amount -= shield;
			shield = 0;
		}
		else
		{
			shield -= amount;
			amount = 0;
		}
	}
	vitality -= amount;
}
void HealthyHero::Attack(Character* other)
{
	other->GetDamage(force);
}