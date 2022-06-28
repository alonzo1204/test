#pragma once
#include <vector>
#include "Tangible.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Wall : public Tangible
{

public:
	Wall(int x, int y, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		dx = dy = 0;
	}
	~Wall() {}

	void Mostrar(Graphics^ g)
	{
		g->DrawRectangle(Pens::LightGray, Area());

	}

};

class Walls {

private:
	vector<Wall*>walls;

public:
	Walls() {

		walls.push_back(new Wall(10, 10, 10, 590));
		walls.push_back(new Wall(600, 10, 10, 590));
		walls.push_back(new Wall(10, 10, 590, 10));
		walls.push_back(new Wall(10, 600, 600, 10));

		walls.push_back(new Wall(20, 175, 100, 250));
		walls.push_back(new Wall(500, 175, 100, 250));

		walls.push_back(new Wall(60, 70, 85, 40));
		walls.push_back(new Wall(195, 70, 85, 40));
		walls.push_back(new Wall(240, 70, 40, 120));
		walls.push_back(new Wall(330, 70, 40, 120));
		walls.push_back(new Wall(330, 70, 85, 40));
		walls.push_back(new Wall(465, 70, 85, 40));

		walls.push_back(new Wall(170, 240, 110, 40));
		walls.push_back(new Wall(330, 240, 110, 40));
		walls.push_back(new Wall(170, 335, 110, 40));
		walls.push_back(new Wall(330, 335, 110, 40));

		walls.push_back(new Wall(240, 430, 40, 120));
		walls.push_back(new Wall(330, 430, 40, 120));
		walls.push_back(new Wall(120, 510, 120, 40));
		walls.push_back(new Wall(370, 510, 120, 40));
	}
	~Walls() {}

	void Mostrar(Graphics^ g) {

		for (int i = 0; i < walls.size(); i++) {
			walls[i]->Mostrar(g);
		}
	}

	bool Colision(Rectangle obj)
	{
		for each (Wall * wall in walls)
		{
			if (wall->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}

};