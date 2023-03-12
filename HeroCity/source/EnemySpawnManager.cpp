#pragma once
#include "EnemySpawnManager.h"
Villain& EnemySpawnManager::SpawnNewEnemy(const int& _value)
{
	switch (_value)
	{
	case 0:
		return healthyVillain;
		break;
	case 1:
		return incrementalVillain;
		break;
	case2:
		return multiAttackVillain;
		break;
	}
}
Villain& EnemySpawnManager::SpawnNewEnemy()
{
	*basicVillain.GetName() = "Villano normal";
	return basicVillain;
}