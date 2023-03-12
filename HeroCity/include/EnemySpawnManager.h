#pragma once
#include "Character.h"
#include "Villains/Villain.h"
#include "Villains/HealthyVillain.h"
#include "Villains/IncrementalForceVillain.h"
#include "Villains/MultiAttackVillain.h"
class EnemySpawnManager
{
public:
	Villain& SpawnNewEnemy(const int& _value);
	Villain& SpawnNewEnemy();
	const float& GetPercent() { return spawnPercent; }
	const float& GetNormalPercent() { return basicVillainTypePercent; }
protected:
private:
	float spawnPercent{20};
	float basicVillainTypePercent{20};
	float superVillainTyPercent{ 33.33f };
	Villain basicVillain;
	HealthyVillain healthyVillain;
	IncrementalForceVillain incrementalVillain;
	MultiAttackVillain multiAttackVillain;
};