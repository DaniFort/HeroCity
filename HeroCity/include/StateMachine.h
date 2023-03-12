#pragma once

enum GameState{Relaxing,GoingBattle, Fighting, GoingHome};

class Statemachine {
public:
	GameState currentState{ GameState::Relaxing };
};
