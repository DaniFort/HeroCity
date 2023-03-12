#pragma once
#include "Character.h"
#include "State.h"

class SuperHero :public Character
{
public:
	//constructors
	//SuperHero(const std::string _name, int _vitality, int _force);
	//getters
	int* GetFinalPos() { return &finalPos;}
	bool& HasLost() { return hasLost; }
	//functions
	const virtual void  Update() override;
	const virtual void OnEnter() override;
	const virtual void OnExit() override;
	//para habilidades
	virtual void OnWin(){}

	virtual void Attack(Character* other) = 0;
	void SetStats(const int _maxVitality, const int _force, const int _regeneration);
protected:
	int speed{ 5 } ;
	int regenerationCapacity{0};
	int finalPos{0 };
	bool hasLost{ false };
	const int homePos{ 0 };
private:
};