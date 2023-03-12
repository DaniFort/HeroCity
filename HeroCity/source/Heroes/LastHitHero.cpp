#include "Heroes/LastHitHero.h"
#include<iostream>
LastHitHero::LastHitHero()
{
	name = "";
	force = 0;
	vitality = 0;
}
void LastHitHero::GetDamage(const int _amount)
{
	vitality -= _amount;
	if (vitality <= 0 && !lastHitDone)
	{
		lastHitDone = true;
		vitality = 1;
		Attack(GetRival());
	}
}
const void LastHitHero::OnEnter()
{
	pos = 0;
	hasLost = false;
	std::srand(std::time(nullptr));
	const int randomSpeed = std::rand() % 21 + 80;
	speed = randomSpeed;	
	lastHitDone = false;
}
//const void LastHitHero::Update()
//{
//}
//const void LastHitHero::OnExit()
//{
//
//}
void LastHitHero::Attack( Character* other)
{
	other->GetDamage(force);
}