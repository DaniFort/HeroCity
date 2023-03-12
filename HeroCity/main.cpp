#include <iostream>
#include <TimeManager.h>
#include "Heroes/SuperHero.h"
#include "Heroes/HealthyHero.h"
#include "Villains/Villain.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>

int main()
{
	//prueba flujo tiempo
	//int totaldays{ 0 };
	//std::cout << "Durante cuantos dias quieres jugar?";
	//std::cin >> totaldays;
	//TimeManager a(1,totaldays);

	//prueba setRival
	//SuperHero alberto( "alberto", 2, 3);
	//SuperVillain juan("Juan", 10, 3);
	//Villain pepe("pepe", 10, 3);
	//alberto.SetRival(juan);
	//std::cout <<alberto.GetRival()->GetVitality() <<std::endl;
	//alberto.Attack();
	//std::cout << alberto.GetRival()->GetVitality() << std::endl;
	
	//prueba constructor Game
	Game newGame;
	//Villain jose;
	//newGame.GetWorld()->GetHero()->SetRival(jose);
	//newGame.Update();
	//bool runningTime = true;
	//bool* run = &runningTime;
	//std::cout << *run;
	//*run = false;
	//std::cout << *run;

	//int random{ 0 };
	//std::uniform_int<>random(1, 100);
	//std::cout << random;

	return 0;
}
