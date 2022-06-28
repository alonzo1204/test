#pragma once
#include "Tangible.h"
#include <vector>

class Material : public Tangible
{
private:
	int ancho;
	int alto;
public:
	Material(int x, int y, Bitmap^ img) {
		this->x = x;
		this->y = y;
		ancho = 30;
		alto = 30;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}

	Rectangle Hitbox() {
		return Rectangle(x, y, ancho, alto);
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {

		g->DrawImage(img, Rectangle(x, y, ancho, alto));
		//g->DrawRectangle(Pens::Black, Area());
		//g->DrawRectangle(Pens::Blue, Hitbox());

	}

};

class Papeles {

private:
	vector<Material*> papeles;

public:
	Papeles(Bitmap^ imgPapel) {
		papeles.push_back(new Material(27, 27, imgPapel));
		papeles.push_back(new Material(253, 27, imgPapel));
		papeles.push_back(new Material(483, 27, imgPapel));

		papeles.push_back(new Material(70, 135, imgPapel));
		papeles.push_back(new Material(290, 160, imgPapel));
		papeles.push_back(new Material(460, 120, imgPapel));

		papeles.push_back(new Material(150, 300, imgPapel));
		papeles.push_back(new Material(420, 300, imgPapel));

		papeles.push_back(new Material(50, 465, imgPapel));
		papeles.push_back(new Material(400, 465, imgPapel));

		papeles.push_back(new Material(60, 500, imgPapel));
		papeles.push_back(new Material(285, 470, imgPapel));

		papeles.push_back(new Material(60, 565, imgPapel));
		papeles.push_back(new Material(253, 565, imgPapel));
		papeles.push_back(new Material(483, 565, imgPapel));
	}
	~Papeles() {}

	bool Colision(Rectangle obj) {
		for each (Material * M in papeles) {
			if (M->Hitbox().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mostrar(Graphics^ g, Bitmap^ imgPapel) {
		for each (Material * M in papeles) {
			M->Mostrar(g, imgPapel);
		}
	}

	void Eliminar(Rectangle obj) {
		for (int i = 0; i < papeles.size(); i++) {
			if (papeles[i]->Hitbox().IntersectsWith(obj)) {
				papeles.erase(papeles.begin() + i);
			}
		}
	}

};

class Vidrios {

private:
	vector<Material*> vidrios;

public:
	Vidrios(Bitmap^ imgVidrio) {
		
		vidrios.push_back(new Material(108, 27, imgVidrio));
		vidrios.push_back(new Material(216, 27, imgVidrio));
		vidrios.push_back(new Material(432, 27, imgVidrio));

		vidrios.push_back(new Material(159, 125, imgVidrio));
		vidrios.push_back(new Material(420, 125, imgVidrio));

		vidrios.push_back(new Material(225, 205, imgVidrio));
		vidrios.push_back(new Material(460, 205, imgVidrio));

		vidrios.push_back(new Material(330, 300, imgVidrio));

		vidrios.push_back(new Material(120, 400, imgVidrio));
		vidrios.push_back(new Material(432, 400, imgVidrio));

		vidrios.push_back(new Material(190, 470, imgVidrio));
		vidrios.push_back(new Material(460, 470, imgVidrio));

		vidrios.push_back(new Material(108, 565, imgVidrio));
		vidrios.push_back(new Material(190, 565, imgVidrio));
		vidrios.push_back(new Material(380, 565, imgVidrio));
	}
	~Vidrios() {}

	bool Colision(Rectangle obj) {
		for each (Material * M in vidrios) {
			if (M->Hitbox().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mostrar(Graphics^ g, Bitmap^ imgVidrio) {
		for each (Material * M in vidrios) {
			M->Mostrar(g, imgVidrio);
		}
	}

	void Eliminar(Rectangle obj) {
		for (int i = 0; i < vidrios.size(); i++) {
			if (vidrios[i]->Hitbox().IntersectsWith(obj)) {
				vidrios.erase(vidrios.begin() + i);
			}
		}
	}

};

class Plasticos {

private:
	vector<Material*> plasticos;

public:
	Plasticos(Bitmap^ imgPlastico) {
		plasticos.push_back(new Material(170, 27, imgPlastico));
		plasticos.push_back(new Material(350, 27, imgPlastico));
		plasticos.push_back(new Material(550, 27, imgPlastico));

		plasticos.push_back(new Material(200, 125, imgPlastico));
		plasticos.push_back(new Material(500, 125, imgPlastico));

		plasticos.push_back(new Material(150, 205, imgPlastico));
		plasticos.push_back(new Material(370, 205, imgPlastico));

		plasticos.push_back(new Material(250, 300, imgPlastico));
	
		plasticos.push_back(new Material(200, 400, imgPlastico));
		plasticos.push_back(new Material(388, 400, imgPlastico));

		plasticos.push_back(new Material(100, 470, imgPlastico));
		plasticos.push_back(new Material(530, 470, imgPlastico));

		plasticos.push_back(new Material(30, 565, imgPlastico));
		plasticos.push_back(new Material(300, 565, imgPlastico));
		plasticos.push_back(new Material(450, 565, imgPlastico));
	}
	~Plasticos() {}

	bool Colision(Rectangle obj) {
		for each (Material * M in plasticos) {
			if (M->Hitbox().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mostrar(Graphics^ g, Bitmap^ imgPlastico) {
		for each (Material * M in plasticos) {
			M->Mostrar(g, imgPlastico);
		}
	}

	void Eliminar(Rectangle obj) {
		for (int i = 0; i < plasticos.size(); i++) {
			if (plasticos[i]->Hitbox().IntersectsWith(obj)) {
				plasticos.erase(plasticos.begin() + i);
			}
		}
	}

};