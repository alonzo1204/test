#pragma once
#include "Tangible.h"
#include <vector>
enum SpriteEnemigo {
	eCaminarAbajo,
	eCaminarArriba,
	eCaminarIzquierda,
	eCaminarDerecha,
};

class Enemigo : public Tangible 
{
private:
	SpriteEnemigo accion;
	int limHD, limHI, limVAr, limVAb;
public:
	Enemigo(int x,int y,int dx, int dy, Bitmap^ img, int limHD,int limHI, int limVAb, int limVAr) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;

		this->limHD = limHD;
		this->limHI = limHI;
		this->limVAr = limVAr;
		this->limVAb = limVAb;
		ancho = img->Width / 2;
		alto = img->Height / 4;

		accion = eCaminarAbajo;
	}

	void Mover(Graphics^ g) {
		if (!(x + dx >= limHI && (x + ancho + dx) * 0.70 < limHD))
			dx *= -1;
		
		if (!(y + dy >= limVAr && (y + alto + dy) * 0.70 < limVAb))
			dy *= -1;

		if (dx < 0)
			accion = eCaminarIzquierda; 
		else if (dx > 0)
			accion = eCaminarDerecha;
		else if (dy < 0)
			accion = eCaminarArriba;
		else if (dy > 0)
			accion = eCaminarAbajo;


		x += dx;
		y += dy;
	}
	Rectangle Area()
	{
		return Rectangle(x, y, ancho * 0.70, alto * 0.70);
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho * 0.70, alto * 0.70);
	}
	Rectangle Hitbox() {
		if (dx != 0) {
			return Rectangle(x + 14, y + 29, (ancho / 2 * 0.70) + 5, (alto / 2 * 0.70));
		}
		else if (dx == 0) {
			return Rectangle(x + 14, y + 20, (ancho / 2 * 0.70) + 1, (alto / 2 * 0.70)+9);
		}
	}
	Rectangle NextHitbox() {
		if (dx != 0) {
			return Rectangle(x + 14 + dx, y + 29 + dy, (ancho / 2 * 0.70) + 5, (alto / 2 * 0.70));
		}
		else if (dx == 0) {
			return Rectangle(x + 14 + dx, y + 20 + dy, (ancho / 2 * 0.70) + 1, (alto / 2 * 0.70) + 9);
		}
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.70, alto * 0.70);
		g->DrawImage(img, zoom, corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());
		//g->DrawRectangle(Pens::Blue, Hitbox());
		IDx = (IDx + 1) % 2;
	}

};


class Enemigos {
	vector<Enemigo*> enemigos;

public:
	Enemigos(Bitmap^ img) {
		//VERTICAL
		enemigos.push_back(new Enemigo(142, 1, 0, 2, img, 1, 1, 190, 0));
		enemigos.push_back(new Enemigo(280, 1, 0, 3, img, 1, 1, 440, 0));
		enemigos.push_back(new Enemigo(418, 1, 0, 1, img, 1, 1, 190, 0));

		enemigos.push_back(new Enemigo(105, 200, 0, 3, img, 1, 1, 380, 70));
		enemigos.push_back(new Enemigo(435, 200, 0, 2, img, 1, 1, 380, 70));

		//HORIZONTAL
		enemigos.push_back(new Enemigo(1, 1, 2, 0, img, 445, 3, 1, 1));
		//
		enemigos.push_back(new Enemigo(1, 100, 2, 0, img, 195, 3, 1, 1));
		enemigos.push_back(new Enemigo(355, 100, 3, 0, img, 445, 355, 1, 1));
		//
		enemigos.push_back(new Enemigo(230, 180, 3, 0, img, 380, 100, 1, 1));
		enemigos.push_back(new Enemigo(100, 270, 2, 0, img, 380, 100, 1, 1));
		enemigos.push_back(new Enemigo(320, 360, 2, 0, img, 380, 100, 1, 1));
		//
		enemigos.push_back(new Enemigo(1, 450, 3, 0, img, 195, 3, 1, 1));
		enemigos.push_back(new Enemigo(355, 450, 2, 0, img, 445, 355, 1, 1));
		//
		//enemigos.push_back(new Enemigo(1, 535, 3, 0, img, 445, 3, 1, 1));
		//
		
	}

	~Enemigos() {}

	bool Colision(Rectangle obj) {
		for each (Enemigo * E in enemigos) {
			if (E->Hitbox().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g) {
		for each (Enemigo * E in enemigos) {
			E->Mover(g);
		}
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		for each (Enemigo * E in enemigos) {
			E->Mostrar(g,img);
		}
	}

	void Eliminar(Rectangle obj) {
		for (int i = 0; i < enemigos.size(); i++) {
			if (enemigos[i]->Hitbox().IntersectsWith(obj)) {
				enemigos.erase(enemigos.begin() + i);
			}
		}
	}

};