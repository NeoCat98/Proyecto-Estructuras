#pragma once
#include <SDL\include\SDL.h>
#include <string>
using namespace std;
class VentanaFinal
{
public:
	VentanaFinal();
	void CorrerVentanaFinal(char, string);
private:
	SDL_Window *window = NULL;
	SDL_Surface *windowSurface = NULL; //Siempre igualar a NULL
	SDL_Surface *image3 = NULL;
	SDL_Surface *currentImage = NULL;
	SDL_Event ev;
	bool isRunning;
	void init();
	bool LoadMedia();
	void close();
};
