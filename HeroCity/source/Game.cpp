#include "Game.h"
#include "StateMachine.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
bool BeWeekEnd(int& _weekDay)
{
	return _weekDay % 6 == 0 || _weekDay % 7 == 0 ? true : false;
}
Game::Game() :thisWorld(), time(1, 0)
{
	OnEnter();
}

const void Game::OnEnter()
{
	//difficulty level
	do {
		std::cout << "Inserte nivel de dificultad del 1 al 3: ";
		std::cin >> difficultyLevel;
	} while (difficultyLevel <= 0 || difficultyLevel > 3);
	//hero things
	SelectHero();
	std::cout << "Inserte nombre heroe: ";
	std::cin >> *thisHero->GetName();
	//time to play
	std::cout << "Cuantos dias quieres jugar? ";
	std::cin >> *time.GetTotalDay();
	RunGame();
}
const void Game::RunGame()
{
	auto startTime = std::chrono::high_resolution_clock::now();
	while (runningGame)
	{
		auto endTime = std::chrono::high_resolution_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() >= (1 / *time.GetFPS()) * 1000)
		{
			PrintClock();
			Update();
			if (!time.NextHour())
				runningGame = false;
			startTime = endTime;

		}
	}
}
const void Game::Update()
{
	switch (thisHero->GetGameState())
	{
		case GameState::Relaxing:
			if (!BeWeekEnd(time.GetWeekDay()) && !thisHero->HasLost() && thisWorld.GetExistVillain())
			{
				thisHero->SetCurrentState(GameState::GoingBattle);
				std::cout << "se ha acabado el fin de semana y toca ir a pelear.\n";
			}
			thisHero->Update();
			if (!TryToSpawnEnemy()&&!thisHero->HasLost())
				std::cout <<*thisHero->GetName() <<" esta relajado en casa.\n";
			break;

		case GameState::GoingBattle:
			thisHero->Update();
			if (thisHero->GetGameState() == GameState::Fighting)
			{
				std::cout << *thisHero->GetName() << " ha llegado y empezara la pelea con " << *thisVillain->GetName()<<".\n";
			}
			else
			{
				std::cout << *thisHero->GetName() << " esta yendo donde se encuentra " << *thisVillain->GetName() <<
					" y le faltan " << abs(*thisHero->GetFinalPos() - *thisHero->GetPos()) << " km para llegar" << ".\n";
			}
			break;

		case GameState::Fighting:
			{
				std::srand(std::time(nullptr));
				const int whoAttack = std::rand() % 5 + 1;
				if (whoAttack <= 3)
				{
					thisHero->Attack(thisVillain);
					if (thisVillain->GetVitality() <= 0)
					{
						thisHero->SetCurrentState(GameState::GoingHome);
						std::cout << *thisHero->GetName() << " ha derrotado a " << *thisVillain->GetName() << " y vuelve a casa a relajarse.\n";
						thisHero->OnWin();
						thisWorld.ResetVillain();
					}
					else
						std::cout << *thisHero->GetName() << " ha atacado y ha dejado a " << *thisVillain->GetName() << " a " << thisVillain->GetVitality() << " puntos de vida.\n";
				}
				else
				{
					thisVillain->Attack(thisHero);
					if (thisHero->GetVitality() <= 0)
					{
						thisHero->HasLost() = true;
						thisHero->SetCurrentState(GameState::GoingHome);
						std::cout << *thisVillain->GetName() << " ha derrotado a " << *thisHero->GetName() << ", ahora " << *thisHero->GetName() << " debe volver a casa a recuperarse de sus heridas.\n";
					}
					else
						std::cout << *thisVillain->GetName() << " ha atacado y ha dejado a " << *thisHero->GetName() << " a " << thisHero->GetVitality() << " puntos de vida.\n";
				}

			}
			break;

		case GameState::GoingHome:
			thisHero->Update();
			if (!TryToSpawnEnemy())
				std::cout << *thisHero->GetName() << " esta volviendo a casa y le quedan " << abs(0 - *thisHero->GetPos()) << " km.\n";
			break;
	}
}

const void Game::OnExit()   
{
	
}
void Game::SelectHero()
{
	int type = 0;
	std::cout << "Que Superheroe quiere ser?" << "\n";
	std::cout << "1. Coraza: Despues de cada victoria obtiene entre 15 y 20 puntos de armadura." << "\n";
	std::cout << "2. Ultimas palabras: Antes de morir da un golpe de entre 10 y 20 de fuerza." << "\n";
	std::cout << "3. Inyeccion mortifera: Existe una probabilidad de un 30% de envenenar al enemigocon un ataque." << "\n";
	do{
		std::cin >> type;
	} while (type < 1 && type>3);

	switch(type)
	{
	case 1:
		thisWorld.SetHero(healthyHero);
		break;
	case 2:
		thisWorld.SetHero(lastHitHero);
		break;
	case 3:
		thisWorld.SetHero(lethalHero);
		break;
	}
	//settear player
	thisHero->OnEnter();
	thisHero->SetCurrentState(GameState::Relaxing);
	switch (difficultyLevel)
	{
	case 1:
		thisHero->SetStats(20, 8, 5);
		break;
	case 2:
		thisHero->SetStats(16, 6, 4);
		break;
	case 3:
		thisHero->SetStats(13, 4, 3);
		break;
	default:
		break;
	}

	
}

bool Game::TryToSpawnEnemy()
{
	if (!thisWorld.GetExistVillain() && !thisHero->HasLost())//spawnear villano///TO DO: probar a quitar aqui el segundo bool
	{
		std::srand(std::time(nullptr));
		const int randomNumber = std::rand() % 100 + 1;
		if (randomNumber <= spawnManager.GetPercent())
		{
			std::srand(std::time(nullptr));
			const int randomNumber = std::rand() % 100 + 1;
			if (randomNumber <= spawnManager.GetNormalPercent())
			{
				thisWorld.SetVillain(spawnManager.SpawnNewEnemy());
			}
			else
			{
				std::srand(std::time(nullptr));
				const int randomNumber = std::rand() % 2;
				thisWorld.SetVillain(spawnManager.SpawnNewEnemy(randomNumber));

			}
			//set villain things
			switch (difficultyLevel)
			{
			case 1:
				thisVillain->SetStats(9, 3);
				break;
			case 2:
				thisVillain->SetStats(10, 4);
				break;
			case 3:
				thisVillain->SetStats(13, 5);
				break;
			default:
				break;
			}

			thisVillain->OnEnter();
			//set hero things
			*thisHero->GetFinalPos() = *thisVillain->GetPos();
			thisHero->SetRival(*thisVillain);
			if (!BeWeekEnd(time.GetWeekDay()))
				thisHero->SetCurrentState(GameState::GoingBattle);
			thisWorld.GetExistVillain() = true;
			std::cout << "hay un nuevo villano en la ciudad. \n";
			return true;
		}
		return false;
	}
	return false;
}
void Game::PrintClock()
{
	std::string weekDay = "";
	if (time.GetWeekDay() %7 == 0)
	{
		weekDay = "Domingo";
		std::cout << "\n Son las " << time.GetHour() << ":00 del " << weekDay  << " y ";
		return;
	}
	else if (time.GetWeekDay() % 6 == 0)
	{
		weekDay = "Sabado";
		std::cout << "\n Son las " << time.GetHour() << ":00 del " << weekDay<< " y ";
		return;
	}
	else if (time.GetWeekDay() % 5 == 0)
	{
		weekDay = "Viernes";
		std::cout << "\n Son las " << time.GetHour() << ":00 del " << weekDay << " y ";
		return;

	}
	else if (time.GetWeekDay() % 4 == 0)
	{
		weekDay = "Jueves";
		std::cout << "\n Son las " << time.GetHour() << ":00 del " << weekDay  << " y ";
		return;
	}

	else if (time.GetWeekDay()  % 3 == 0)
	{
		weekDay = "Miercoles";	
		std::cout << "\n Son las " << time.GetHour() << ":00 del " << weekDay << " y ";
		return;
	}
	else if (time.GetWeekDay() % 2 == 0)
	{
		weekDay = "Martes";	
		std::cout << "\n Son las " << time.GetHour() << ":00 del " << weekDay   << " y ";
		return;
	}
	else
	{
		weekDay = "Lunes";
		std::cout << "\n Son las " << time.GetHour() << ":00 del " << weekDay  << " y ";
		return;
	}
}
