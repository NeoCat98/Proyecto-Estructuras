#include "Mouse.h"
#pragma once
#include <string>
using namespace std;


class Maze{
private:
	char mazeArray[maxColumns][maxColumns];
	int CountRows(string);
	int CountColumns(string);
public:
	Maze();
	void FillMaze(string);
};

