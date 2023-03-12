#include "Heroes/SuperHero.h"
#include <math.h>
void SuperHero::SetStats(const int _maxVitality, const int _force, const int _regeneration)
{
	maxVitality = vitality = _maxVitality;

	force = _force;
	regenerationCapacity = _regeneration;
}
const void SuperHero::Update()
{
	switch (state.currentState)
	{
	case GameState::Relaxing:
		vitality += regenerationCapacity;
		if (vitality >= maxVitality)
		{
			vitality = maxVitality;
			if (hasLost)
			{
				std::cout << name << " ya se ha recuperado y vuelve a le pelea\n";
				SetCurrentState(GameState::GoingBattle);
				break;
			}
		}
		break;
	case GameState::GoingBattle:
		if (abs(finalPos - pos) < speed)
		{
			SetCurrentState(GameState::Fighting);
			pos = finalPos;
			hasLost = false;
		}
		else if (pos < finalPos)
			pos += speed;
		else 
			pos -= speed;
		break;
	case GameState::Fighting:

		break;
	case GameState::GoingHome:
		vitality += regenerationCapacity;
		if (vitality >= maxVitality)
			vitality = maxVitality;
		pos -= speed;
		if (pos <= homePos)
			SetCurrentState(GameState::Relaxing);

		break;

	default:
		break;
	}
}
const void SuperHero::OnExit()
{
	std::cout << "playerupdate";
}
const void SuperHero::OnEnter()
{
	std::cout << "playerupdate";
}

