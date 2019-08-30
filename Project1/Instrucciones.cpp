#include "Instrucciones.h"
#include "VentanaPrincipal.h"


Instrucciones::Instrucciones()
{
	SDL_Window *window = NULL;
	SDL_Surface *windowSurface = NULL; //Siempre igualar a NULL
	SDL_Surface *image1 = NULL;
	SDL_Surface *image2 = NULL;
	SDL_Surface *image3 = NULL;
	SDL_Surface *currentImage = NULL;
	isRunning = true;
}

void Instrucciones::init() {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Instrucciones", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	windowSurface = SDL_GetWindowSurface(window);
	image3 = SDL_LoadBMP("Instrucciones.bmp");
	currentImage = image3;
}

void Instrucciones::CorrerInstrucciones(char Usuario,string Laberinto) {
	init();
	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0){
			if (ev.type == SDL_QUIT){
				isRunning = false;
				VentanaPrincipal Vent;
				close();
				Vent.CorrerVentana(Usuario, Laberinto);
			}
			currentImage = image3;
		}
		SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}
	
}

void Instrucciones::close() {
	SDL_FreeSurface(image3);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	image1=image2=image3 = NULL;

	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
	;
}