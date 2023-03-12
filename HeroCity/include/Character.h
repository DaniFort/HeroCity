#pragma once
#include <string>
#include <iostream>
#include "StateMachine.h"
#include "State.h"
#

class Character:public State
{
public:
	//getters
	std::string* GetName() { return &name; }
	Character* GetRival()const { return rival; }
	int GetVitality()const { return vitality; }
	int GetForce()const { return force; }
	const int* GetPos()const { return &pos; }
	//setters
	void SetRival( Character& other) { rival = &other; }
	 void SetPos(const int value) {pos = value ; }
	//functions
	virtual void Attack(Character* other) =0;
	virtual void GetDamage(const int damage);

	const virtual void OnEnter() = 0;
	const virtual void Update() = 0;
	const virtual void OnExit() = 0;
	//state things
	GameState GetGameState() { return state.currentState; }
	void SetCurrentState(const GameState newState) { state.currentState = newState; }

protected:
	std::string name="";
	int maxVitality{ 0 };
	int vitality{ 0 };
	int force{ 0 };
	Character* rival{nullptr};
	Statemachine state;
	int pos{ 0 };
private:
};
