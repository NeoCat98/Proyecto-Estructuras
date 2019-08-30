#include "Mouse.h"
#pragma once
#include <SDL\include\SDL.h>
#include <string>

using namespace std;

class MazeSDL{
private:
	//Estableciendo el tiempo para el ranking
	int time;
	//Creando Ventana
	SDL_Window* VentanaPrincipal = NULL;
	//Bandera principal
	bool quit;
	//Evento
	SDL_Event e;
	//Contenido de la Ventana
	SDL_Surface *pantalla;
	//Imagenes
	SDL_Surface* imagen1;
	SDL_Surface* imagen2;
	SDL_Surface* imagen3;
	SDL_Surface* imagen4;
	SDL_Surface* imagen5;
	SDL_Surface* imagen6;
	//Posicion del Raton
	int PosMouseX, PosMouseY;
	int OldPosX, OldPosY; 
	int PosInicialX, PosInicialY;
	void close();
	void PressXToClose();
	void init(int,int);
	bool loadMedia();
	void LoadMaze(char [][maxColumns],int,int);
	void WhereIsTheMouse(char[][maxColumns],int,int);
	void CargandoLaberinto(char [][maxColumns], int ,int );
	void ColocarImagen(int, int, SDL_Surface*);
	void PosMouseBMP(char[][maxColumns],int, int,int,int);
	void SolvedMaze(char[][maxColumns]);
	void Timer(char[][maxColumns]);
	int Direccion;
	void LoadOtherImage(int,int);
	void DecidirDireccion(char [][maxColumns]);
	void InsertaImagenes(int,int);
public:
	MazeSDL();
	void correr(char [][maxColumns],int,int);
};