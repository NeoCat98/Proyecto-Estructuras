#pragma once

const int maxColumns = 50;
class Mouse {
public:
	Mouse();
	void FindMouse(char mazeArray[][maxColumns], int, int);
	void DuplicandoMaze(char[][maxColumns], int, int);
private:
	int fila;
	int columna;
	int Direccion;
	char VerificarMaze[maxColumns][maxColumns];
	void BuscandoSalida(char [][maxColumns],int,int);
	void Move(char [][maxColumns],int, int);
	void Regresar(char [][maxColumns],int, int);
	void Llego(char [][maxColumns],int, int);
	void PrintMatrix(char[][maxColumns], int, int);
};
