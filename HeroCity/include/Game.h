#pragma once
#include "TimeManager.h"
#include "EnemySpawnManager.h"
#include "Heroes/HealthyHero.h"
#include "Heroes/LastHitHero.h"
#include "Heroes/LethalHero.h"
#include "Villains/Villain.h"
#include "Villains/HealthyVillain.h"
#define thisHero thisWorld.GetHero()
#define thisVillain thisWorld.GetCurrentVillain()
class Game:public State
{
public:
	Game();
	//getters
	bool* GetRunningGame() { return &runningGame; }

	class World {
	public:
		//constructor
		World(){}

		//getters
		SuperHero* GetHero() { return hero; }
		Villain* GetCurrentVillain() { return currentVillain; }
		bool& GetExistVillain() { return existVillain; }

		//setters
		void SetHero(SuperHero& _newHero) { hero = &_newHero; }
		void SetVillain( Villain& _newVillain) { currentVillain = &_newVillain; }

		//functions
		void ResetVillain() { currentVillain->OnExit(); currentVillain = nullptr;existVillain=false; }

	private:
		SuperHero* hero{nullptr};
		Villain* currentVillain{nullptr};	
		bool existVillain{ false };
	};

	const void RunGame();
	const void OnEnter()override;
	const void Update()override;
	const void OnExit()override;
	//World* GetWorld() {return &thisWorld;}

	//Functions
	void SelectHero();
	bool TryToSpawnEnemy();
	void PrintClock();
private:
	World thisWorld;
	TimeManager time;
	EnemySpawnManager spawnManager;
	bool runningGame{true};
	int difficultyLevel{0};
	//posibles superheroes
	HealthyHero healthyHero;
	LethalHero lethalHero;
	LastHitHero lastHitHero;
};