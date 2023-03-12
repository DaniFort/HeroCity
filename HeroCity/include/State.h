#pragma once
class State 
{
public:
	const virtual void OnEnter() = 0;
	const virtual void Update()  = 0;
	const virtual void OnExit()  = 0;
};