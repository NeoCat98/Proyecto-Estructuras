#include "Ranking.h"
#include <fstream>


using namespace std;

Ranking::Ranking() {
	PInicio = nullptr;
}

void Ranking::LeerIncertar() {
	string linea;
	string nombre, User;
	int saltando=0;
	ifstream archivo("TopTen.txt");
	while (getline(archivo, linea)) {
		if (saltando == 1) {
			nombre = linea;
			saltando = 2;
		}
		else if (saltando == 2) {
			//aux = atof(linea.c_str);
			//egundos = aux;
			//Incertar(segundos, nombre, User);
			saltando = 0;
		}
		else {
			User = linea;
			saltando = 1;
		}
	}
	archivo.close();
}

void Ranking::Incertar(int dato,string User,string nombre) {
	nodo* nuevo = new nodo;
	nuevo->Laberinto = nombre;
	nuevo->tiempo = dato;
	nuevo->Usuario = User;
	if (!PInicio) {
		PInicio = nuevo;
		nuevo->sig = nullptr;
	}
	else {
		nodo *aux = PInicio;
		while (aux->sig) {
			aux = aux->sig;
			aux->sig = nuevo;
			nuevo->sig = NULL;
		}
	}
}

void Ranking::NuevoValor(int dato, string User, string nombre) {
	bool run = true;
	Incertar(dato, User, nombre);
	while (Mover() != 0) {}
	NewPos();
}

int Ranking::Mover() {
	int cont = 0;
	nodo *nuevo = PInicio;
	nodo *aux = new nodo;
	int cont;
	while (nuevo) {
		if (nuevo->tiempo > nuevo->sig->tiempo) {
			aux = nuevo->sig;
			nuevo->sig = aux->sig;
			aux->sig = nuevo;
			cont++;
		}
	}
	return cont;
}

void Ranking::NewPos() {
	fstream archivo;
}