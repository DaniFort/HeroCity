cmake_minimum_required(VERSION 3.15)

project(
Hero_City
VERSION 0.0.1
LANGUAGES CXX)

set(PROJECT_HEADERS 

	include/Character.h
	include/Game.h
	include/State.h
	include/StateMachine.h
	include/TimeManager.h
	include/World.h
	include/EnemySpawnManager.h
	include/Heroes/HealthyHero.h
	include/Heroes/LastHitHero.h
	include/Heroes/LethalHero.h
	include/Heroes/SuperHero.h
	include/Villains/Villain.h
	include/Villains/HealthyVillain.h
	include/Villains/IncrementalForceVillain.h
	include/Villains/MultiAttackVillain.h

)

set(PROJECT_SOURCES 
    main.cpp
    source/Character.cpp
	source/Game.cpp
	source/StateMachine.cpp
	source/TimeManager.cpp
	source/World.cpp
	source/EnemySpawnManager.cpp
	source/Heroes/HealthyHero.cpp
	source/Heroes/LastHitHero.cpp
	source/Heroes/LethalHero.cpp
	source/Heroes/SuperHero.cpp
	source/Villains/HealthyVillain.cpp
	source/Villains/IncrementalForceVillain.cpp
	source/Villains/MultiAttackVillain.cpp
	source/Villains/Villain.cpp
)

set(PROJECT_FILES 
  ${PROJECT_HEADERS} 
  ${PROJECT_SOURCES}
)

include_directories(${PROJECT_NAME} PRIVATE include)

add_executable(${PROJECT_NAME} ${PROJECT_FILES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

