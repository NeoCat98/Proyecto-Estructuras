#include "MazeSDL.h"
#include <iostream>
#include "Maze.h"

MazeSDL::MazeSDL() {
	VentanaPrincipal = NULL;
	quit = false;
	time = 0.0;
}

void  MazeSDL::init(int numRows, int numColumns) {
	SDL_Init(SDL_INIT_VIDEO);
	VentanaPrincipal = SDL_CreateWindow("Laberinto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (numColumns * 25) + 150, (numRows * 25), SDL_WINDOW_SHOWN);
	pantalla = SDL_GetWindowSurface(VentanaPrincipal);
	imagen1 = SDL_LoadBMP("pared.bmp");
	imagen2 = SDL_LoadBMP("raton.bmp");
	imagen3 = SDL_LoadBMP("camino.bmp");
	imagen4 = SDL_LoadBMP("Queso.bmp");
	imagen5 = SDL_LoadBMP("Lana.bmp");
	imagen6 = SDL_LoadBMP("comenzar.bmp");
}


void MazeSDL::close() {
	//Desasignar superficie
	SDL_FreeSurface(imagen1);
	SDL_FreeSurface(imagen2);
	SDL_FreeSurface(imagen3);
	SDL_FreeSurface(imagen4);
	SDL_FreeSurface(imagen5);
	SDL_FreeSurface(imagen6);
	imagen1 = imagen2 = imagen3 = imagen5= imagen4 = imagen6= NULL;
	//destruyendo ventana
	SDL_DestroyWindow(VentanaPrincipal);
	VentanaPrincipal = NULL;
	//Quit SDL
	SDL_Quit();
}

void MazeSDL::PressXToClose() {
	while (!quit) {
		//establecemos un evento
		while (SDL_PollEvent(&e) != 0) {
			//El usuario se quiere salir
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
}

void MazeSDL::correr(char mazeArray[][maxColumns],int numRows, int numColumns) {
	init(numRows,numColumns);
	LoadMaze(mazeArray,numRows,numColumns);
	SDL_UpdateWindowSurface(VentanaPrincipal);
	LoadOtherImage(numRows, numColumns);
	SDL_UpdateWindowSurface(VentanaPrincipal);
	//mientras la aplicacion este corriendo
	WhereIsTheMouse(mazeArray,numRows,numColumns);
	PressXToClose();
	close();
}

void MazeSDL::LoadMaze(char mazeArray[][maxColumns],int numRows,int numColumns) {
	for (int i = 0; i< numRows; i++)
	{
		for (int j = 0; j< numColumns; j++)
		{
			if (mazeArray[i][j] == 'P'){
				ColocarImagen(i * 25, j * 25, imagen1);
			}
			else if (mazeArray[i][j] == 'C')
			{
				ColocarImagen(i * 25, j * 25, imagen3);
			}
			else if(mazeArray[i][j] == 'Q')
			{
				ColocarImagen(i * 25, j * 25, imagen4);
			}
		}
	}
	LoadOtherImage(numRows, numColumns);
}
void MazeSDL::LoadOtherImage(int numRows,int numColumns) {
	for (int i = 0; i< numRows; i++)
	{
		for (int j = numColumns; j< numColumns + 6; j++)
		{
				ColocarImagen(i * 25, j * 25, imagen1);
		}
	}
	SDL_Rect destino;
	destino.x = numColumns*25;
	destino.y = 0;
	SDL_BlitSurface(imagen6, NULL, pantalla, &destino);
	SDL_UpdateWindowSurface(VentanaPrincipal);
	}


void MazeSDL::ColocarImagen(int x, int y, SDL_Surface *image){
	SDL_Rect destination;
	destination.x = y;
	destination.y = x;
	SDL_BlitSurface(image, NULL,pantalla, &destination);
	SDL_UpdateWindowSurface(VentanaPrincipal);
}

void MazeSDL::WhereIsTheMouse(char mazeArray[][maxColumns], int numRows, int numColumns) {
	bool quit = false;
	bool boton = false;
	while (!quit) {
		//establecemos un evento
		while (SDL_PollEvent(&e) != 0) {
			//El usuario se quiere salir
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (e.button.button == SDL_BUTTON_LEFT) {
					cout << numRows * 25 << endl;
					cout << e.button.x << " " << e.button.y << endl;
					if ((e.button.x >= numColumns * 25 && e.button.x <= ((numColumns + 6) * 25)) && (e.button.y >= 0 && e.button.y <= 28)) {
						boton = true;
					}
					if (boton == true){
						if ((e.button.x >= 0 && e.button.x <= (numRows * 25)) || (e.button.y >= 0 && e.button.y <= (numColumns * 25))) {
							if ((e.button.x >= 0 && e.button.x <= (numRows * 25)) || (e.button.y >= 0 && e.button.y <= (numColumns * 25))) {
								if (mazeArray[e.button.y / 25][e.button.x / 25] == 'C') {
									PosMouseBMP(mazeArray, e.button.y, e.button.x, numRows, numColumns);
									std::cout << "x: " << PosMouseX << std::endl;
									std::cout << "y: " << PosMouseY << std::endl;
									ColocarImagen((e.button.y / 25) * 25, (e.button.x / 25) * 25, imagen2);
									SDL_Delay(500);
									//quit = true;
									DecidirDireccion(mazeArray);
									std::cout << Direccion << std::endl;
									Timer(mazeArray);
								}
							}
						}
					}
				}
			}
		}
	}
	close();
}

void MazeSDL::DecidirDireccion(char mazeArray[][maxColumns]) {
	if (mazeArray[PosMouseX][PosMouseY + 1] == 'X' && mazeArray[PosMouseX][PosMouseY + 2] == 'X' && mazeArray[PosMouseX][PosMouseY + 3] == 'X' && mazeArray[PosMouseX][PosMouseY + 4] == 'X') {
		Direccion = 0;
	}
	else if (mazeArray[PosMouseX][PosMouseY - 1] == 'X' && mazeArray[PosMouseX][PosMouseY - 2] == 'X' && mazeArray[PosMouseX][PosMouseY - 3] == 'X' && mazeArray[PosMouseX][PosMouseY - 4] == 'X') {
		Direccion = 1;
	}
	else if (mazeArray[PosMouseX - 1][PosMouseY] == 'X' && mazeArray[PosMouseX - 2][PosMouseY] == 'X' && mazeArray[PosMouseX - 3][PosMouseY] == 'X' && mazeArray[PosMouseX - 4][PosMouseY] == 'X') {
		Direccion = 3;
	}
	else if (mazeArray[PosMouseX + 1][PosMouseY] == 'X' && mazeArray[PosMouseX + 2][PosMouseY] == 'X' && mazeArray[PosMouseX + 3][PosMouseY] == 'X' && mazeArray[PosMouseX + 4][PosMouseY] == 'X') {
		Direccion = 2;
	}
	else {
		if (mazeArray[PosMouseX][PosMouseY + 1] == 'X' && mazeArray[PosMouseX][PosMouseY + 2] == 'X' && mazeArray[PosMouseX][PosMouseY + 3] == 'X')  {
			Direccion = 0;
		}
		else if (mazeArray[PosMouseX][PosMouseY - 1] == 'X' && mazeArray[PosMouseX][PosMouseY - 2] == 'X' && mazeArray[PosMouseX][PosMouseY - 3] == 'X') {
			Direccion = 1;
		}
		else if (mazeArray[PosMouseX - 1][PosMouseY] == 'X' && mazeArray[PosMouseX - 2][PosMouseY] == 'X' && mazeArray[PosMouseX - 3][PosMouseY] == 'X') {
			Direccion = 3;
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'X' && mazeArray[PosMouseX + 2][PosMouseY] == 'X' && mazeArray[PosMouseX + 3][PosMouseY] == 'X') {
			Direccion = 2;
		}
		else {
			if (mazeArray[PosMouseX][PosMouseY + 1] == 'X' && mazeArray[PosMouseX][PosMouseY + 2] == 'X') {
				Direccion = 0;
			}
			else if (mazeArray[PosMouseX][PosMouseY - 1] == 'X' && mazeArray[PosMouseX][PosMouseY - 2] == 'X') {
				Direccion = 1;
			}
			else if (mazeArray[PosMouseX - 1][PosMouseY] == 'X' && mazeArray[PosMouseX - 2][PosMouseY] == 'X') {
				Direccion = 3;
			}
			else if (mazeArray[PosMouseX + 1][PosMouseY] == 'X' && mazeArray[PosMouseX + 2][PosMouseY] == 'X') {
				Direccion = 2;
			}
			else {
				if (mazeArray[PosMouseX][PosMouseY + 1] == 'X') {
					Direccion = 0;
				}
				else if (mazeArray[PosMouseX][PosMouseY - 1] == 'X') {
					Direccion = 1;
				}
				else if (mazeArray[PosMouseX - 1][PosMouseY] == 'X') {
					Direccion = 3;
				}
				else if (mazeArray[PosMouseX + 1][PosMouseY] == 'X') {
					Direccion = 2;
				}
			}
		}
	}
}

void MazeSDL::PosMouseBMP(char mazeArray[][maxColumns], int y, int x,int numRows, int numColumns) {
	Mouse Raton;
	PosMouseX = (y / 25);
	PosMouseY = (x / 25);
	mazeArray[PosMouseX][PosMouseY] = 'R';
	OldPosX = PosMouseX;
	OldPosY = PosMouseY;
	Raton.DuplicandoMaze(mazeArray, numRows, numColumns);
	Raton.FindMouse(mazeArray, numRows, numColumns);
}

void MazeSDL::SolvedMaze(char mazeArray[][maxColumns]) {
	switch(Direccion){
	case 0:
		if (mazeArray[PosMouseX][PosMouseY + 1] == 'X') { //DERECHA
			ColocarImagen(PosMouseX * 25, (PosMouseY + 1) * 25, imagen2);//poner raton en la siguiente posicion
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5); // poner un camino en la posicion en la que estaba
			mazeArray[PosMouseX][PosMouseY] = 'P';
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseY = PosMouseY + 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		else {
			DecidirDireccion(mazeArray);
		}
		break;
	case 1:
		if (mazeArray[PosMouseX][PosMouseY - 1] == 'X') { //IZUIERDA
			ColocarImagen(PosMouseX * 25, (PosMouseY - 1) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			mazeArray[PosMouseX][PosMouseY] = 'P';
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseY = PosMouseY - 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		else {
			DecidirDireccion(mazeArray);
		}
		break;
	case 2:
		if (mazeArray[PosMouseX + 1][PosMouseY] == 'X') { //ABAJO
			ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			mazeArray[PosMouseX][PosMouseY] = 'P';
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseX = PosMouseX + 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		else {
			DecidirDireccion(mazeArray);
		}
		break;
	case 3:
		if (mazeArray[PosMouseX - 1][PosMouseY] == 'X') { //ARRIBA
			ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			mazeArray[PosMouseX][PosMouseY] = 'P';
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseX = PosMouseX - 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		else {
			DecidirDireccion(mazeArray);
		}
		break ;
	}
}

void MazeSDL::Timer(char mazeArray[][maxColumns]) {
	bool bandera = false;
	Mouse Raton;
	while (!bandera) {
		if (mazeArray[PosMouseX][PosMouseY-1] == 'R') {
			ColocarImagen(PosMouseX * 25, (PosMouseY - 1) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			time = time + 0.5;
			SDL_Delay(500);
			bandera = true;
		}
		else if (mazeArray[PosMouseX][PosMouseY+1] == 'R') {
			ColocarImagen(PosMouseX * 25, (PosMouseY + 1) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			time = time + 0.5;
			SDL_Delay(500);
			bandera = true;
		}
		else if (mazeArray[PosMouseX - 1][PosMouseY] == 'R') {
			ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25,  imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			time = time + 0.5;
			SDL_Delay(500);
			bandera = true;
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'R') {
			ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			time = time + 0.5;
			SDL_Delay(500);
			bandera = true;
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			if ((mazeArray[OldPosX][OldPosY] != mazeArray[PosMouseX + 1][PosMouseY])) {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
			}
			if ((mazeArray[OldPosX][OldPosY] != mazeArray[PosMouseX - 1][PosMouseY])) {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX - 1;
			}
			if ((mazeArray[OldPosX][OldPosY] != mazeArray[PosMouseX][PosMouseY + 1])) {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY + 1;
			}
			if ((mazeArray[OldPosX][OldPosY] != mazeArray[PosMouseX][PosMouseY - 1])) {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY - 1;
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			mazeArray[PosMouseX][PosMouseY] = 'P';
			ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseY = PosMouseY - 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			mazeArray[PosMouseX][PosMouseY] = 'P';
			ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseY = PosMouseY + 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			mazeArray[PosMouseX][PosMouseY] = 'P';
			ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseX = PosMouseX - 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			mazeArray[PosMouseX][PosMouseY] = 'P';
			ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
			ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
			OldPosX = PosMouseX;
			OldPosY = PosMouseY;
			PosMouseX = PosMouseX + 1;
			time = time + 0.5;
			SDL_Delay(500);
		}
		//Validar para dos muros
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			if (mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			if (mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			if (mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			if (mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			if (mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			if (mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M') {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else {
				mazeArray[PosMouseX][PosMouseY] = 'P';
				ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'P') {
			
			if ((mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') && (mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX + 3][PosMouseY] == 'X' || mazeArray[PosMouseX + 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY + 3] == 'X' || mazeArray[PosMouseX][PosMouseY + 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			} //
			else if ((mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') && (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX][PosMouseY + 3] == 'X' || mazeArray[PosMouseX][PosMouseY + 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 3][PosMouseY] == 'X' || mazeArray[PosMouseX - 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else if ((mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M') && (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX + 3][PosMouseY] == 'X' || mazeArray[PosMouseX + 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 3][PosMouseY] == 'X' || mazeArray[PosMouseX - 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else {
				if (mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'P' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			
			if ((mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M') && (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX + 3][PosMouseY] == 'X' || mazeArray[PosMouseX + 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 3][PosMouseY] == 'X' || mazeArray[PosMouseX - 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else if ((mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M') && (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX][PosMouseY - 3] == 'X' || mazeArray[PosMouseX][PosMouseY - 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 3][PosMouseY] == 'X' || mazeArray[PosMouseX - 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else if ((mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M') && (mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M')) {// YA
				if (mazeArray[PosMouseX + 3][PosMouseY] == 'X' || mazeArray[PosMouseX + 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY - 3] == 'X' || mazeArray[PosMouseX][PosMouseY - 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else {
				if ((mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M')) {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					SDL_Delay(500);
				}
				else if ((mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M')) {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'P' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			
			if ((mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') && (mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX + 3][PosMouseY] == 'X' || mazeArray[PosMouseX + 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY + 3] == 'X' || mazeArray[PosMouseX][PosMouseY + 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else{
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else if ((mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') && (mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M')) {
				if (mazeArray[PosMouseX][PosMouseY + 3] == 'X' || mazeArray[PosMouseX][PosMouseY + 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY - 3] == 'X' || mazeArray[PosMouseX][PosMouseY - 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else if ((mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2 ][PosMouseY] == 'M') && (mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M')) {
				if (mazeArray[PosMouseX + 3][PosMouseY] == 'X' || mazeArray[PosMouseX + 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY - 3] == 'X' || mazeArray[PosMouseX][PosMouseY - 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else {
				if ((mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M')) {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if ((mazeArray[PosMouseX + 2][PosMouseY] == 'X' || mazeArray[PosMouseX + 2][PosMouseY] == 'M')) {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
		}
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'P' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			
			if ((mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') && (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX][PosMouseY + 3] == 'X' || mazeArray[PosMouseX][PosMouseY + 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 3][PosMouseY] == 'X' || mazeArray[PosMouseX - 3][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else if ((mazeArray[PosMouseX][PosMouseY + 2] == 'X' || mazeArray[PosMouseX][PosMouseY + 2] == 'M') && (mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M')) {
				if (mazeArray[PosMouseX][PosMouseY + 3] == 'X' || mazeArray[PosMouseX][PosMouseY + 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY - 3] == 'X' || mazeArray[PosMouseX][PosMouseY - 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else if ((mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M') && (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M')) {
				if (mazeArray[PosMouseX][PosMouseY - 3] == 'X' || mazeArray[PosMouseX][PosMouseY - 3] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M') {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
			else {
				if ((mazeArray[PosMouseX][PosMouseY - 2] == 'X' || mazeArray[PosMouseX][PosMouseY - 2] == 'M')) {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if ((mazeArray[PosMouseX - 2][PosMouseY] == 'X' || mazeArray[PosMouseX - 2][PosMouseY] == 'M')) {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else {
					mazeArray[PosMouseX][PosMouseY] = 'P';
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
		}
		//Termino
		else if (mazeArray[PosMouseX + 1][PosMouseY] == 'M' && mazeArray[PosMouseX - 1][PosMouseY] == 'M' && mazeArray[PosMouseX][PosMouseY + 1] == 'M' && mazeArray[PosMouseX][PosMouseY - 1] == 'M') {
			if (mazeArray[PosMouseX + 2][PosMouseY] == 'X') {
				ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				mazeArray[PosMouseX][PosMouseY] = 'P';
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX - 2][PosMouseY] == 'X') {
				ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				mazeArray[PosMouseX][PosMouseY] = 'P';
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseX = PosMouseX - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX][PosMouseY + 2] == 'X') {
				ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				mazeArray[PosMouseX][PosMouseY] = 'P';
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY + 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else if (mazeArray[PosMouseX][PosMouseY - 2] == 'X') {
				ColocarImagen((PosMouseX) * 25, (PosMouseY - 2) * 25, imagen2);
				ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
				mazeArray[PosMouseX][PosMouseY] = 'P';
				OldPosX = PosMouseX;
				OldPosY = PosMouseY;
				PosMouseY = PosMouseY - 1;
				time = time + 0.5;
				SDL_Delay(500);
			}
			else {
				if (mazeArray[PosMouseX + 2][PosMouseY] == 'M') {
					ColocarImagen((PosMouseX + 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					mazeArray[PosMouseX][PosMouseY] = 'P';
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX - 2][PosMouseY] == 'M') {
					ColocarImagen((PosMouseX - 1) * 25, (PosMouseY) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					mazeArray[PosMouseX][PosMouseY] = 'P';
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseX = PosMouseX - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY + 2] == 'M') {
					ColocarImagen((PosMouseX) * 25, (PosMouseY + 1) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					mazeArray[PosMouseX][PosMouseY] = 'P';
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY + 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
				else if (mazeArray[PosMouseX][PosMouseY - 2] == 'M') {
					ColocarImagen((PosMouseX) * 25, (PosMouseY - 2) * 25, imagen2);
					ColocarImagen(PosMouseX * 25, PosMouseY * 25, imagen5);
					mazeArray[PosMouseX][PosMouseY] = 'P';
					OldPosX = PosMouseX;
					OldPosY = PosMouseY;
					PosMouseY = PosMouseY - 1;
					time = time + 0.5;
					SDL_Delay(500);
				}
			}
		}
		else {
			SolvedMaze(mazeArray);
		}
	}
}