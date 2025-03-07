#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include "title.h"
#include "starting.h"
#include "game.h"
#include "gameOver.h"
#include "gamePaused.h"

#define SM_TITLE_STATE 0
#define SM_STARTING_STATE 1
#define SM_GAME_STATE 2
#define SM_PAUSE_STATE 3
#define SM_OVER_STATE 4

#define SM_TPS 60

typedef unsigned char State;

static unsigned char SM_STATE = SM_TITLE_STATE;

void sm_init();

void sm_update(float deltaTime);

void sm_fixedUpdate(float deltaTime);

void sm_render();

void sm_changeState(State newState);

#endif