#include "Mouse.h"
#include "MazeSDL.h"
#include "Maze.h"
#include <iostream>


Mouse::Mouse(){
	fila = 0;
	columna = 0;
}

void Mouse::FindMouse(char mazeArray[][maxColumns], int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (mazeArray[i][j] == 'R') {
				fila = i;
				columna = j;
			}
		}
	}
	BuscandoSalida(mazeArray, rows, columns);
}

void Mouse::BuscandoSalida(char mazeArray[][maxColumns],int rows, int columns) {
	PrintMatrix(mazeArray, rows, columns);
	std::cout << fila << " " << columna << std::endl;
	if ((mazeArray[fila][columna + 1] == 'Q') || (mazeArray[fila][columna - 1] == 'Q') || (mazeArray[fila + 1][columna] == 'Q') || (mazeArray[fila - 1][columna] == 'Q')) { 
		Llego(mazeArray, rows, columns);  //LLAMA A ESTE SI SOLO ESTA A UNO DE DISTANCIA
	}
	if (columna != 0 && fila != 0 && columna != columns && fila != rows) {
		Move(mazeArray,rows, columns);
	}
}
 
void Mouse::DuplicandoMaze(char mazeArray[][maxColumns], int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			VerificarMaze[i][j] = mazeArray[i][j];
		}
	}
}

void Mouse::Move(char mazeArray[][maxColumns],int rows, int columns) {
	if (mazeArray[fila][columna + 1] == 'C' && mazeArray[fila][columna + 2] == 'C' && mazeArray[fila][columna + 3] == 'C' && mazeArray[fila][columna + 4] == 'C') {
		mazeArray[fila][columna + 1] = 'R';
		mazeArray[fila][columna] = 'X';
		FindMouse(mazeArray, rows, columns);
	}
	if (mazeArray[fila][columna - 1] == 'C' && mazeArray[fila][columna - 2] == 'C' && mazeArray[fila][columna - 3] == 'C' && mazeArray[fila][columna - 4] == 'C') {
		mazeArray[fila][columna - 1] = 'R';
		mazeArray[fila][columna] = 'X';
		FindMouse(mazeArray, rows, columns);
	}
	if (mazeArray[fila - 1][columna] == 'C' && mazeArray[fila - 2][columna] == 'C' && mazeArray[fila - 3][columna] == 'C' && mazeArray[fila - 4][columna] == 'C') {
		mazeArray[fila - 1][columna] = 'R';
		mazeArray[fila][columna] = 'X';
		FindMouse(mazeArray, rows, columns);
	}
	if (mazeArray[fila + 1][columna] == 'C' && mazeArray[fila + 2][columna] == 'C' && mazeArray[fila + 3][columna] == 'C' && mazeArray[fila + 4][columna] == 'C') {
		mazeArray[fila + 1][columna] = 'R';
		mazeArray[fila][columna] = 'X';
		FindMouse(mazeArray, rows, columns);
	}
	else {
		if (mazeArray[fila][columna + 1] == 'C' && mazeArray[fila][columna + 2] == 'C' && mazeArray[fila][columna + 3] == 'C') {
			mazeArray[fila][columna + 1] = 'R';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		if (mazeArray[fila][columna - 1] == 'C' && mazeArray[fila][columna - 2] == 'C' && mazeArray[fila][columna - 3] == 'C' ) {
			mazeArray[fila][columna - 1] = 'R';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		if (mazeArray[fila - 1][columna] == 'C' && mazeArray[fila - 2][columna] == 'C' && mazeArray[fila - 3][columna] == 'C' ) {
			mazeArray[fila - 1][columna] = 'R';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		if (mazeArray[fila + 1][columna] == 'C' && mazeArray[fila + 2][columna] == 'C' && mazeArray[fila + 3][columna] == 'C' ) {
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			if (mazeArray[fila][columna + 1] == 'C' && mazeArray[fila][columna + 2] == 'C') {
				mazeArray[fila][columna + 1] = 'R';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
			if (mazeArray[fila][columna - 1] == 'C' && mazeArray[fila][columna - 2] == 'C') {
				mazeArray[fila][columna - 1] = 'R';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
			if (mazeArray[fila - 1][columna] == 'C' && mazeArray[fila - 2][columna] == 'C' ) {
				mazeArray[fila - 1][columna] = 'R';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
			if (mazeArray[fila + 1][columna] == 'C' && mazeArray[fila + 2][columna] == 'C' ) {
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				if (mazeArray[fila][columna + 1] == 'C') {
					mazeArray[fila][columna + 1] = 'R';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
				if (mazeArray[fila][columna - 1] == 'C') {
					mazeArray[fila][columna - 1] = 'R';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
				if (mazeArray[fila - 1][columna] == 'C') {
					mazeArray[fila - 1][columna] = 'R';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
				if (mazeArray[fila + 1][columna] == 'C') {
					mazeArray[fila + 1][columna] = 'R';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
				else {
					Regresar(mazeArray, rows, columns);
				}
			}
		}
	}
}

void Mouse::Regresar(char mazeArray[][maxColumns],int rows, int columns) {
	//Eligir entre dos caminos
	if ((mazeArray[fila][columna + 1] == 'P'|| mazeArray[fila][columna + 1] == 'M') && (mazeArray[fila][columna - 1] == 'P' || mazeArray[fila][columna - 1] == 'M') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'X')) {
		if ((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila + 1][columna + 1]== 'P' || mazeArray[fila + 1][columna + 1] == 'M')) {
			mazeArray[fila + 1][columna] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila + 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'M';
			mazeArray[fila + 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila][columna - 1] == 'M' && mazeArray[fila - 1][columna] == 'M') {
		if (VerificarMaze[fila - 1][columna] == 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if (VerificarMaze[fila][columna - 1] == 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna - 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila + 1][columna] == 'M' && mazeArray[fila][columna - 1] == 'P' && mazeArray[fila - 1][columna] == 'M') {
		if (VerificarMaze[fila - 1][columna] = 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if (VerificarMaze[fila + 1][columna] == 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila + 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if (mazeArray[fila][columna + 1] == 'M' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila][columna - 1] == 'P' && mazeArray[fila - 1][columna] == 'M') {
		if (VerificarMaze[fila][columna + 1] = 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if (VerificarMaze[fila - 1][columna] == 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna - 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila + 1][columna] == 'M' && mazeArray[fila][columna - 1] == 'M' && mazeArray[fila - 1][columna] == 'P') {
		if (VerificarMaze[fila][columna - 1] = 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna - 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if (VerificarMaze[fila + 1][columna] == 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila + 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if (mazeArray[fila][columna + 1] == 'M' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila][columna - 1] == 'M' && mazeArray[fila - 1][columna] == 'P') {
		if (VerificarMaze[fila][columna - 1] = 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna - 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if (VerificarMaze[fila][columna + 1] == 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if (mazeArray[fila][columna + 1] == 'M' && mazeArray[fila + 1][columna] == 'M' && mazeArray[fila][columna - 1] == 'P' && mazeArray[fila - 1][columna] == 'P') {
		if (VerificarMaze[fila][columna + 1] = 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if (VerificarMaze[fila][columna + 1] == 'C') {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'P';
			mazeArray[fila + 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila][columna - 1] == 'P' && mazeArray[fila - 1][columna] == 'P') {
		if (mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'P' && mazeArray[fila][columna - 2] == 'M' && mazeArray[fila - 2][columna] == 'M') {
			if (VerificarMaze[fila - 1][columna] == 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila - 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else if (VerificarMaze[fila][columna - 1] == 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna - 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila - 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'M' && mazeArray[fila][columna - 2] == 'P' && mazeArray[fila - 2][columna] == 'M') {
			if (VerificarMaze[fila - 1][columna] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila - 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else if (VerificarMaze[fila + 1][columna] == 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila - 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'M' && mazeArray[fila + 2][columna] == 'P' && mazeArray[fila][columna - 2] == 'P' && mazeArray[fila - 2][columna] == 'M') {
			if (VerificarMaze[fila][columna + 1] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna + 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else if (VerificarMaze[fila - 1][columna] == 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna - 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila - 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'M' && mazeArray[fila][columna - 2] == 'M' && mazeArray[fila - 2][columna] == 'P') {
			if (VerificarMaze[fila][columna - 2] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna - 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else if (VerificarMaze[fila + 1][columna] == 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna + 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'M' && mazeArray[fila + 2][columna] == 'P' && mazeArray[fila][columna - 2] == 'M' && mazeArray[fila - 2][columna] == 'P') {
			if (VerificarMaze[fila][columna - 1] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna - 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else if (VerificarMaze[fila][columna + 1] == 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna + 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna + 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'M' && mazeArray[fila + 2][columna] == 'M' && mazeArray[fila][columna - 2] == 'P' && mazeArray[fila - 2][columna] == 'M') {
			if (VerificarMaze[fila][columna + 1] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna + 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else if (VerificarMaze[fila][columna + 1] == 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna + 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'P' && mazeArray[fila][columna - 2] == 'P' && mazeArray[fila - 2][columna] == 'M') {
			if (VerificarMaze[fila - 1][columna] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila - 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'P' && mazeArray[fila][columna - 2] == 'M' && mazeArray[fila - 2][columna] == 'P') {
			if (VerificarMaze[fila][columna - 1] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna - 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'M' && mazeArray[fila][columna - 2] == 'P' && mazeArray[fila - 2][columna] == 'P') {
			if (VerificarMaze[fila + 1][columna] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if (mazeArray[fila][columna + 2] == 'M' && mazeArray[fila + 2][columna] == 'P' && mazeArray[fila][columna - 2] == 'P' && mazeArray[fila - 2][columna] == 'P') {
			if (VerificarMaze[fila][columna + 1] = 'C') {
				mazeArray[fila][columna] = 'P';
				mazeArray[fila][columna + 1] = 'R';
				FindMouse(mazeArray, rows, columns);
			}
		}
	}
	if ((mazeArray[fila][columna + 1] == 'P' || mazeArray[fila][columna + 1] == 'M') && mazeArray[fila][columna - 1] == 'X' && (mazeArray[fila + 1][columna] == 'P' || mazeArray[fila + 1][columna] == 'M') && mazeArray[fila - 1][columna] == 'X') {
		if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P'|| mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
			mazeArray[fila][columna - 1] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1]= 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna-1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna - 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	if ((mazeArray[fila][columna + 1] == 'X') && (mazeArray[fila][columna - 1] == 'P' || mazeArray[fila][columna - 1] == 'M') && (mazeArray[fila + 1][columna] == 'P' || mazeArray[fila + 1][columna] == 'M') && (mazeArray[fila - 1][columna] == 'X')) {
		if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1]== 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			mazeArray[fila][columna + 1] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1]== 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'M';
			mazeArray[fila - 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	if ((mazeArray[fila][columna + 1] == 'P' || mazeArray[fila][columna + 1] == 'M') && (mazeArray[fila][columna - 1] == 'X') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'P' || mazeArray[fila - 1][columna] == 'M')) {
		if ((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila + 1][columna + 1]== 'P' || mazeArray[fila + 1][columna + 1] == 'M')) {
			mazeArray[fila + 1][columna] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna - 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila + 1][columna - 1]== 'P' || mazeArray[fila + 1][columna - 1] == 'M')) {
			mazeArray[fila][columna - 1] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila + 1][columna] = 'R'; 
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'M';
			mazeArray[fila + 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	if ((mazeArray[fila][columna + 1] == 'X') && (mazeArray[fila][columna - 1] == 'P' || mazeArray[fila][columna - 1] == 'M') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'P' || mazeArray[fila - 1][columna] == 'M')) {
		if ((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila + 1][columna + 1]== 'P' || mazeArray[fila + 1][columna + 1] == 'M')) {
			mazeArray[fila + 1][columna] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') &&( mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M') && (mazeArray[fila + 1][columna + 1]== 'P' || mazeArray[fila + 1][columna + 1] == 'M')) {
			mazeArray[fila][columna + 1] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila + 1][columna] = 'M';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'M';
			mazeArray[fila + 1][columna] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	if ((mazeArray[fila][columna + 1] == 'X') && (mazeArray[fila][columna - 1] == 'X') && (mazeArray[fila + 1][columna] == 'P' || mazeArray[fila + 1][columna] == 'M') && (mazeArray[fila - 1][columna] == 'P' || mazeArray[fila - 1][columna] == 'M')) {
		if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M') && (mazeArray[fila + 1][columna + 1]== 'P' || mazeArray[fila + 1][columna + 1] == 'M')) {
			mazeArray[fila][columna + 1] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna - 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila + 1][columna - 1]== 'P' || mazeArray[fila + 1][columna - 1] == 'M')) {
			mazeArray[fila][columna - 1] = 'M';
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila][columna] = 'M';
			mazeArray[fila][columna + 1] = 'R';
			FindMouse(mazeArray, rows, columns);
		}
	}
	//ELigir entr 4 caminos
	//Si se queda atrapado en X verifica cual de las X tienen P al lado si es asi no se va ahi y convierte esa X en P 
	if ((mazeArray[fila][columna + 1] == 'X') && (mazeArray[fila][columna - 1] == 'X') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'X')) {
		if (mazeArray[fila][columna - 2] == 'P' && mazeArray[fila][columna + 2] == 'P' && mazeArray[fila - 2][columna] == 'P') {
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna] = 'P';
			FindMouse(mazeArray, rows, columns);
		}
		else if (mazeArray[fila][columna - 2] == 'P' && mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'P') {
			mazeArray[fila - 1][columna] = 'R';
			mazeArray[fila][columna] = 'P';
			FindMouse(mazeArray, rows, columns);
		}
		else if (mazeArray[fila - 2][columna] == 'P' && mazeArray[fila][columna + 2] == 'P' && mazeArray[fila + 2][columna] == 'P') {
			mazeArray[fila][columna - 1] = 'R';
			mazeArray[fila][columna] ='P';
			FindMouse(mazeArray, rows, columns);
		}
		else if (mazeArray[fila][columna - 2] == 'P' && mazeArray[fila - 2][columna] == 'P' && mazeArray[fila + 2][columna] == 'P') {
			mazeArray[fila][columna + 1] = 'R';
			mazeArray[fila][columna] = 'P';
			FindMouse(mazeArray, rows, columns);
		}
		else{
			if ((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M')) {//Ya esta verificado si este esta así
				if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
					if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
						mazeArray[fila][columna + 1] = 'P';
						mazeArray[fila - 1][columna] = 'P';
						mazeArray[fila + 1][columna] = 'P';
						mazeArray[fila][columna - 1] = 'R';
						mazeArray[fila][columna] = 'P';
						std::cout << " Paso pero no " << std::endl;
						FindMouse(mazeArray, rows, columns);
					}
					else if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
						mazeArray[fila][columna + 1] = 'R';
						mazeArray[fila - 1][columna] = 'P';
						mazeArray[fila + 1][columna] = 'P';
						mazeArray[fila][columna - 1] = 'P';
						mazeArray[fila][columna] = 'P';
						FindMouse(mazeArray, rows, columns);
					}
					else {
						mazeArray[fila][columna + 1] = 'X';
						mazeArray[fila - 1][columna] = 'P';
						mazeArray[fila + 1][columna] = 'P';
						mazeArray[fila][columna - 1] = 'R';
						mazeArray[fila][columna] = 'X';
						FindMouse(mazeArray, rows, columns);
					}
				}
				else if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
					if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
						mazeArray[fila - 1][columna] = 'R';
						mazeArray[fila][columna + 1] = 'P';
						mazeArray[fila + 1][columna] = 'P';
						mazeArray[fila][columna - 1] = 'P';
						mazeArray[fila][columna] = 'P';
						FindMouse(mazeArray, rows, columns);
					}
					else {
						mazeArray[fila - 1][columna] = 'R';
						mazeArray[fila][columna + 1] = 'X';
						mazeArray[fila + 1][columna] = 'P';
						mazeArray[fila][columna - 1] = 'P';
						mazeArray[fila][columna] = 'X';
						FindMouse(mazeArray, rows, columns);
					}
				}
				else if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
					mazeArray[fila - 1][columna] = 'R';
					mazeArray[fila][columna + 1] = 'P';
					mazeArray[fila + 1][columna] = 'P';
					mazeArray[fila][columna - 1] = 'X';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
				else {
					mazeArray[fila - 1][columna] = 'R';
					mazeArray[fila][columna + 1] = 'X';
					mazeArray[fila + 1][columna] = 'P';
					mazeArray[fila][columna - 1] = 'X';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
			}
			else if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
				if (((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M'))) {
					if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
						mazeArray[fila - 1][columna] = 'P';
						mazeArray[fila][columna + 1] = 'P';
						mazeArray[fila + 1][columna] = 'R';
						mazeArray[fila][columna - 1] = 'P';
						mazeArray[fila][columna] = 'P';
						FindMouse(mazeArray, rows, columns);
					}
					else {
						mazeArray[fila - 1][columna] = 'X';
						mazeArray[fila][columna + 1] = 'P';
						mazeArray[fila + 1][columna] = 'R';
						mazeArray[fila][columna - 1] = 'P';
						mazeArray[fila][columna] = 'X';
						FindMouse(mazeArray, rows, columns);
					}
				}
				else if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
					mazeArray[fila - 1][columna] = 'P';
					mazeArray[fila][columna + 1] = 'P';
					mazeArray[fila + 1][columna] = 'X';
					mazeArray[fila][columna - 1] = 'R';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
				else {
					mazeArray[fila - 1][columna] = 'X';
					mazeArray[fila][columna + 1] = 'P';
					mazeArray[fila + 1][columna] = 'R';
					mazeArray[fila][columna - 1] = 'X';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
			}
			else if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
				if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
					mazeArray[fila - 1][columna] = 'P';
					mazeArray[fila][columna + 1] = 'P';
					mazeArray[fila + 1][columna] = 'R';
					mazeArray[fila][columna - 1] = 'X';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
				else {
					mazeArray[fila - 1][columna] = 'P';
					mazeArray[fila][columna + 1] = 'X';
					mazeArray[fila + 1][columna] = 'R';
					mazeArray[fila][columna - 1] = 'X';
					mazeArray[fila][columna] = 'X';
					FindMouse(mazeArray, rows, columns);
				}
			}
			else {
				mazeArray[fila - 1][columna] = 'X';
				mazeArray[fila][columna + 1] = 'X';
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna - 1] = 'X';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
	}
	}
	//Elegir entre tres caminos
	if (((mazeArray[fila][columna + 1] == 'X')) && (mazeArray[fila][columna - 1] == 'X') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'P' || mazeArray[fila - 1][columna] == 'M')) {
		if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
			if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') &&( mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
				mazeArray[fila - 1][columna] = 'P';
				mazeArray[fila][columna + 1] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna - 1] = 'P';
				mazeArray[fila][columna] = 'P';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila - 1][columna] = 'P';
				mazeArray[fila][columna + 1] = 'X';
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna - 1] = 'P';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'P';
			mazeArray[fila][columna + 1] = 'P';
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			mazeArray[fila + 1][columna] = 'P';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila - 1][columna] = 'P';
			mazeArray[fila][columna + 1] = 'X';
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if ((mazeArray[fila][columna + 1] == 'X') && (mazeArray[fila][columna - 1] == 'X') && (mazeArray[fila + 1][columna] == 'P' || mazeArray[fila + 1][columna] == 'M') && (mazeArray[fila - 1][columna] == 'X')) {
		if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna  -2] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
			if ((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M')) {
				mazeArray[fila - 1][columna] = 'R';
				mazeArray[fila][columna + 1] = 'P';
				mazeArray[fila + 1][columna] = 'P';
				mazeArray[fila][columna - 1] = 'P';
				mazeArray[fila][columna] = 'P';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila - 1][columna] = 'X';
				mazeArray[fila][columna + 1] = 'P';
				mazeArray[fila + 1][columna] = 'X';
				mazeArray[fila][columna - 1] = 'P';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila -1][columna + 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'R';
			mazeArray[fila][columna + 1] = 'P';
			mazeArray[fila + 1][columna] = 'P';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'P';
			mazeArray[fila][columna + 1] = 'R';
			mazeArray[fila + 1][columna] = 'P';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila - 1][columna] = 'X';
			mazeArray[fila][columna + 1] = 'R';
			mazeArray[fila + 1][columna] = 'P';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
	}
	else if ((mazeArray[fila][columna + 1] == 'X') && (mazeArray[fila][columna - 1] == 'P' || mazeArray[fila][columna - 1] == 'M') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'X')) {
		if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
				mazeArray[fila - 1][columna] = 'P';
				mazeArray[fila][columna + 1] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna - 1] = 'P';
				mazeArray[fila][columna] = 'P';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila - 1][columna] = 'P';
				mazeArray[fila][columna + 1] = 'X';
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna - 1] = 'P';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if ((mazeArray[fila][columna + 2] == 'P' || mazeArray[fila][columna + 2] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'X';
			mazeArray[fila][columna + 1] = 'P';
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna - 1] = 'P';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else if((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M')){
			mazeArray[fila - 1][columna] = 'X';
			mazeArray[fila][columna + 1] = 'R';
			mazeArray[fila + 1][columna] = 'P';
			mazeArray[fila][columna - 1] = 'P';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila - 1][columna] = 'X';
			mazeArray[fila][columna + 1] = 'X';
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna - 1] = 'P';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
	}
	if (((mazeArray[fila][columna + 1] == 'P' || mazeArray[fila][columna + 1] == 'M')) && (mazeArray[fila][columna - 1] == 'X') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'X')) {
		if ((mazeArray[fila - 2][columna] == 'P' || mazeArray[fila - 2][columna] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna + 1] == 'P' || mazeArray[fila - 1][columna + 1] == 'M')) {
			if ((mazeArray[fila][columna - 2] == 'P' || mazeArray[fila][columna - 2] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M') && (mazeArray[fila - 1][columna - 1] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
				mazeArray[fila - 1][columna] = 'P';
				mazeArray[fila][columna + 1] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna - 1] = 'P';
				mazeArray[fila][columna] = 'P';
				FindMouse(mazeArray, rows, columns);
			}
			else {
				mazeArray[fila - 1][columna] = 'P';
				mazeArray[fila][columna + 1] = 'P';
				mazeArray[fila + 1][columna] = 'R';
				mazeArray[fila][columna - 1] = 'X';
				mazeArray[fila][columna] = 'X';
				FindMouse(mazeArray, rows, columns);
			}
		}
		else if ((mazeArray[fila][columna -2 ] == 'P' || mazeArray[fila][columna - 2] == 'M' )&&( mazeArray[fila + 1][columna -1 ] == 'P' || mazeArray[fila + 1][columna - 1] == 'M' )&& (mazeArray[fila - 1][columna - 1 ] == 'P' || mazeArray[fila - 1][columna - 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'X';
			mazeArray[fila][columna + 1] = 'P';
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna - 1] = 'P';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else if ((mazeArray[fila + 2][columna] == 'P' || mazeArray[fila + 2][columna] == 'M') && (mazeArray[fila + 1][columna + 1] == 'P' || mazeArray[fila + 1][columna + 1] == 'M') && (mazeArray[fila + 1][columna - 1] == 'P' || mazeArray[fila + 1][columna - 1] == 'M')) {
			mazeArray[fila - 1][columna] = 'R';
			mazeArray[fila][columna + 1] = 'P';
			mazeArray[fila + 1][columna] = 'P';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
		else {
			mazeArray[fila - 1][columna] = 'X';
			mazeArray[fila][columna + 1] = 'P';
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna - 1] = 'X';
			mazeArray[fila][columna] = 'X';
			FindMouse(mazeArray, rows, columns);
		}
	}
	// Regresar por donde viniste 
	else if ((mazeArray[fila][columna + 1] == 'P' || mazeArray[fila][columna + 1] == 'M') && (mazeArray[fila][columna - 1] == 'P' || mazeArray[fila][columna - 1] == 'M') && (mazeArray[fila + 1][columna] == 'P' || mazeArray[fila+ 1 ][columna] == 'M') &&( mazeArray[fila - 1][columna] == 'X')) {
		mazeArray[fila][columna] = 'P';
		mazeArray[fila - 1][columna] = 'R';
		FindMouse(mazeArray, rows, columns);
	}
	else if ((mazeArray[fila][columna + 1] == 'X') && (mazeArray[fila][columna - 1] == 'P' || mazeArray[fila][columna - 1] == 'M') && (mazeArray[fila + 1][columna] == 'P' || mazeArray[fila + 1][columna] == 'M') && (mazeArray[fila - 1][columna] == 'P' || mazeArray[fila - 1][columna] == 'M')) {
		mazeArray[fila][columna] = 'P';
		mazeArray[fila][columna + 1] = 'R';
		FindMouse(mazeArray, rows, columns);
	}
	else if ((mazeArray[fila][columna + 1] == 'P' || mazeArray[fila][columna + 1] == 'M') && (mazeArray[fila][columna - 1] == 'X') && (mazeArray[fila + 1][columna] == 'P' || mazeArray[fila + 1][columna] == 'M' )&& (mazeArray[fila - 1][columna] == 'P' || mazeArray[fila - 1][columna] == 'M')) {
		mazeArray[fila][columna] = 'P';
		mazeArray[fila][columna - 1] = 'R';
		FindMouse(mazeArray, rows, columns);
	}
	else if ((mazeArray[fila][columna + 1] == 'P' || mazeArray[fila][columna + 1] == 'M') && (mazeArray[fila][columna - 1] == 'P' || mazeArray[fila][columna - 1] == 'M') && (mazeArray[fila + 1][columna] == 'X') && (mazeArray[fila - 1][columna] == 'P' || mazeArray[fila -1][columna] ==  'M')) {
		mazeArray[fila][columna] = 'P';
		mazeArray[fila + 1][columna] = 'R';
		FindMouse(mazeArray, rows, columns);
	}
	else if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila][columna - 1] == 'P' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila - 1][columna] == 'M') {
		mazeArray[fila - 1][columna] = 'R';
		mazeArray[fila][columna] = 'P';
		FindMouse(mazeArray, rows, columns);
	}
	else if (mazeArray[fila][columna + 1] == 'M' && mazeArray[fila][columna - 1] == 'P' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila - 1][columna] == 'P') {
		mazeArray[fila][columna + 1] = 'R';
		mazeArray[fila][columna] = 'P';
		FindMouse(mazeArray, rows, columns);
	}
	else if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila][columna - 1] == 'M' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila - 1][columna] == 'P') {
		mazeArray[fila][columna - 1] = 'R';
		mazeArray[fila][columna] = 'P';
		FindMouse(mazeArray, rows, columns);
	}
	else if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila][columna - 1] == 'P' && mazeArray[fila + 1][columna] == 'M' && mazeArray[fila - 1][columna] == 'P') {
		mazeArray[fila + 1][columna] = 'R';
		mazeArray[fila][columna] = 'P';
		FindMouse(mazeArray, rows, columns);
	}
	else if (mazeArray[fila][columna + 1] == 'P' && mazeArray[fila - 1][columna] == 'P' && mazeArray[fila + 1][columna] == 'P' && mazeArray[fila][columna - 1] == 'P') {
		if (VerificarMaze[fila][columna + 1] == 'C') {
			mazeArray[fila][columna + 1] = 'R';
			mazeArray[fila][columna] = 'M';
		}
		else if (VerificarMaze[fila][columna - 1] == 'C') {
			mazeArray[fila][columna - 1] = 'R';
			mazeArray[fila][columna] = 'M';
		}
		else if (VerificarMaze[fila + 1][columna] == 'C') {
			mazeArray[fila + 1][columna] = 'R';
			mazeArray[fila][columna] = 'M';
		}
		else if (VerificarMaze[fila - 1][columna] == 'C') {
			mazeArray[fila - 1][columna] = 'R';
			mazeArray[fila][columna] = 'M';
		}
	}
} 

void Mouse::Llego(char mazeArray[][maxColumns],int rows, int columns) {
	std::cout << "Llego :) " << std::endl;
	if (mazeArray[fila][columna + 1] == 'Q') {
		mazeArray[fila][columna] = 'X';
		mazeArray[fila][columna + 1] = 'R';
		PrintMatrix(mazeArray, rows, columns);
	}
	if (mazeArray[fila][columna - 1] == 'Q') {
		mazeArray[fila][columna] = 'X';
		mazeArray[fila][columna - 1] = 'R';
		PrintMatrix(mazeArray, rows, columns);
	}
	if (mazeArray[fila - 1][columna] == 'Q') {
		mazeArray[fila][columna] = 'X';
		mazeArray[fila - 1][columna] = 'R';
		PrintMatrix(mazeArray, rows, columns);
	}
	if (mazeArray[fila + 1][columna] == 'Q') {
		mazeArray[fila][columna] = 'X';
		mazeArray[fila + 1][columna] = 'R';
		PrintMatrix(mazeArray, rows, columns);
	}
}

void Mouse::PrintMatrix(char array[][maxColumns], int rows, int columns) {
	std::cout << std::endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<columns; j++) {
			std::cout << array[i][j];
		}
		std::cout << std::endl;
	}
}