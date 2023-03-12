#include "Villains/IncrementalForceVillain.h"
#include <ctime>
#include <cstdlib>
IncrementalForceVillain::IncrementalForceVillain()
{
	force = 0;
	name = "";
}
void IncrementalForceVillain::GetDamage(const int damage)
{
	vitality -= damage;
	std::srand(std::time(nullptr));
	const int forceToIncrement = std::rand() % 5 + 1;
	force += forceToIncrement;
}
const void IncrementalForceVillain::Update()
{
}
const void IncrementalForceVillain::OnExit()
{
}
const void IncrementalForceVillain::OnEnter()
{
	std::srand(std::time(nullptr));
	const int randomPos = 100 + std::rand() % 1401;
	pos = randomPos;
	vitality = maxVitality;
	name = "Villano poderoso";

}