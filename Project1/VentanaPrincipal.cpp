#include "VentanaPrincipal.h"
#include <iostream>
#include "Maze.h"
#include <string>
#include "Instrucciones.h"

using namespace std;
VentanaPrincipal::VentanaPrincipal() {
	SDL_Window *window = NULL;
	SDL_Surface *windowSurface = NULL; //Siempre igualar a NULL
	SDL_Surface *image1 = NULL;
	SDL_Surface *image2 = NULL;
	SDL_Surface *image3 = NULL;
	SDL_Surface *currentImage = NULL;
	isRunning = true;
}

void VentanaPrincipal::init() {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Main Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	windowSurface = SDL_GetWindowSurface(window);
	image1 = SDL_LoadBMP("raton.bmp");
	image2 = SDL_LoadBMP("queso.bmp");
	image3 = SDL_LoadBMP("menu.bmp");
	currentImage = image1;
}

void VentanaPrincipal::close() {
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(image3);
	currentImage = image1 = image2 = image3 = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}
void VentanaPrincipal::CorrerVentana(char Usuario,string Laberinto) {
	int Evento = 0;
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
				std::cout<< ev.button.x  <<" "<< ev.button.y <<std::endl;
				if (ev.button.button == SDL_BUTTON_LEFT) {
					if ((ev.button.x <= 600 && ev.button.x >= 200) && (ev.button.y <= 500 && ev.button.y >= 380)) {
						Evento = 1;
						ev.type = NULL;
						//close();
						isRunning = false;
					}
					else if ((ev.button.x <= 678 && ev.button.x >= 140 )&& (ev.button.y <= 600 && ev.button.y >= 500)) {
						cout << "evento 2" << endl;
						Evento = 2;
						ev.type = NULL;
						isRunning = false;
						//close();
					}
					else if ((ev.button.x <= 607 && ev.button.x >=202) && (ev.button.y <= 720 && ev.button.y >= 615)) { 
						//cout << "evento 3" << endl;
						isRunning = false;
						ev.type = NULL;
						Evento = 3;
					}
					else if ((ev.button.x <= 798 && ev.button.x >= 737) && (ev.button.y <= 50 && ev.button.y >= 5)) {
						//cout << "evento 3" << endl;
						isRunning = false;
						ev.type = NULL;
						Evento = 4;
					}
				}
			}
			currentImage = image3;
		}
		SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}


	if (Evento == 1) {
		close();
		ComenzarLaberinto(Laberinto);
		
	}
	else if (Evento == 2) {
		close();
		Instrucciones Inst;
		Inst.CorrerInstrucciones(Usuario, Laberinto);
		
	}
	else if(Evento == 3){
		cout << "Rankings" << endl;
	}
	else if (Evento == 4) {
		cout << "Musica" << endl;
	}
}

void VentanaPrincipal::ComenzarLaberinto(string Laberinto) {
	Maze Lab;
	Lab.FillMaze(Laberinto);
}