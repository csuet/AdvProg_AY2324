// DO NOT CHANGE THIS FILE


#ifndef SDL_UTILS__H
#define SDL_UTILS__H

#include <iostream>

#if defined(_WIN64) || defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif




#include "Game.h"
#include "constants.h"
#include "Gallery.h"

void logSDLError(std::ostream& os, 
                 const std::string &msg, bool fatal = false);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle) ;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

// moved from main.cpp
void renderSplashScreen();
void renderGamePlay(SDL_Renderer*, const Game& game, Gallery* gallery);
void renderGameOver(SDL_Renderer* renderer, const Game& game);
void interpretEvent(SDL_Event e, Game& game);
void updateRankingTable(const Game& game);

#endif
