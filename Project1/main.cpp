#include <SDL\include\SDL.h>
#include <iostream>
#include "VentanaPrincipal.h"
#include <string>
using namespace std;

int main(int argc, char* args[]) {
	char Usuario;
	string Laberinto = "laberinto002.txt";
	cout << "Ingrese su nombre de usuario: " << endl;
	cin >> Usuario;
	cin.ignore(256, '\n');
	cout << "Ingrese el nombre del laberinto: " << endl;
	getline(cin, Laberinto);
	Laberinto += ".txt";
	cout << "El laberinto que escribio fue: "<< Laberinto << endl;

	VentanaPrincipal Vent;                   //EMPIEZA EL MAIN MENU
	Vent.CorrerVentana(Usuario, Laberinto);
	return 0;
}