#include "VentanaFinal.h"
#include "Maze.h"

VentanaFinal::VentanaFinal() {
	SDL_Window *window = NULL;
	SDL_Surface *windowSurface = NULL; //Siempre igualar a NULL
	SDL_Surface *image1 = NULL;
	SDL_Surface *image2 = NULL;
	SDL_Surface *image3 = NULL;
	SDL_Surface *currentImage = NULL;
	isRunning = true;
}

void VentanaFinal::init() {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Salida", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	windowSurface = SDL_GetWindowSurface(window);
	image3 = SDL_LoadBMP("menufinal.bmp");
}

void VentanaFinal::close() {
	SDL_FreeSurface(image3);
	image3 = NULL;
	window = NULL;
	SDL_QUIT;
}
void VentanaFinal::CorrerVentanaFinal(char Usuario, string Laberinto) {
	init();
	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				isRunning = false;
			}
			else if (ev.type == SDL_MOUSEBUTTONDOWN) {
				if (ev.button.button == SDL_BUTTON_LEFT) {
					if ((ev.button.x <= 647 && ev.button.x >= 162) && (ev.button.y <= 306 && ev.button.y >= 205)) {
						Maze Lab;
						close();
						Lab.FillMaze(Laberinto);
						isRunning = false;
					}
					else if ((ev.button.x <= 530 && ev.button.x >= 281) && (ev.button.y <= 516 && ev.button.y >= 419)) {
						close();
					}
				}
			}
			currentImage = image3;
		}
		SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}
}