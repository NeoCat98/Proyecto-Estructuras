#include "Maze.h"
#include "Mouse.h"
#include <fstream> 
#include <string>
#include <cstdlib>
#include <iostream>
#include "MazeSDL.h"

using namespace std;


Maze::Maze(){
}

void Maze::FillMaze(string Laberinto) {
	Mouse Raton;
	MazeSDL sdl;
	int numRows = CountRows(Laberinto);
	int numColumns = CountColumns(Laberinto);
	ifstream file;
	file.open(Laberinto);
	string line;
	for (int i = 0; i < numRows; i++) {
		getline(file, line);
		for (int j = 0; j < numColumns; j++) {
			mazeArray[i][j] = line[j];
		}
	}
	file.close();
	sdl.correr(mazeArray, numRows, numColumns);
};

int Maze::CountRows(string Laberinto) {
	ifstream file;
	file.open( Laberinto);
	int count = 0;
	string line;

	while (getline(file, line)) {
		count++;
	}
	file.close();
	return count;
}

int Maze::CountColumns(string Laberinto) 
{
	string line;
	int count = 0;
	int x;
	ifstream file;
	file.open(Laberinto);
	getline(file, line);
	x = line.size();
	for (int i = 0; i < x; i++) {
		count++;
	}
	file.close();
	return count;
}


