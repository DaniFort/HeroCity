#include "Villains/HealthyVillain.h"
#include <ctime>
#include <cstdlib>
HealthyVillain::HealthyVillain()
{
	name = "";
	force = 0;
}
void HealthyVillain::Attack(Character* other)
{
	other->GetDamage(force);
	std::srand(std::time(nullptr));
	const int liveToGet = std::rand() % 5 + 1;
	vitality += liveToGet;
	if (vitality > maxVitality)
		vitality = maxVitality;
}

const void HealthyVillain::Update()
{

}
const void HealthyVillain::OnExit()
{
}
const void HealthyVillain::OnEnter()
{
	std::srand(std::time(nullptr));
	const int randomPos = 100 + std::rand() % 1401;
	pos = randomPos;
	vitality = maxVitality;
	name = "Villano sano";
}