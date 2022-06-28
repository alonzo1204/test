#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class Facil {
private:
	ofstream fileWrite; //Write
	ifstream fileRead; //Read
	string text;

	int vidas, velocidad_jugador;

public:
	Facil() {
		readData();
	}
	~Facil() {}

	void readData() {
		fileRead.open("facil.txt", ios::in);

		getline(fileRead, text);
		vidas = stoi(text);
		getline(fileRead, text);
		velocidad_jugador = stoi(text);


		fileRead.close();
	}

	int getVidas() { return vidas; }
	int getVelocidad() { return velocidad_jugador; }

};