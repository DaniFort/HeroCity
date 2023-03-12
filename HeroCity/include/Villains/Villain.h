#pragma once
#include "Character.h"

class Villain :public Character
{
public:
	Villain();

	virtual void Attack( Character* other)override;
	void SetStats(const int _maxVitality, const int _force);

	const virtual void  Update() override;
	const virtual void OnEnter() override;
	const virtual void OnExit() override;
protected:

private:
};