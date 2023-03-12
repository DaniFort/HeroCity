#include "Villains/Villain.h"
#include <ctime>
#include <cstdlib>
Villain::Villain()
{
	name = "";
	force = 0;
}
void Villain::SetStats(const int _maxVitality, const int _force)
{
	maxVitality = vitality = _maxVitality;

	force = _force;
}
void Villain::Attack( Character* other)
{
	other->GetDamage(force);
}

const void Villain::OnExit()
{

}
const void Villain::Update()
{

}
const void Villain::OnEnter()
{
	std::srand(std::time(nullptr));
	const int randomPos = 100 + std::rand() % 1401;
	pos = randomPos;
	vitality = maxVitality;
	name = "Villano basico";
}