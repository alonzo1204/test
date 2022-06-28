#pragma once
#include <iostream>
#include "Tangible.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
enum SpriteAliado
{
	aCaminarAbajo,
	aCaminarArriba,
	aCaminarDerecha,
	aCaminarIzquierda,
};

class Aliado : public Tangible
{
private:
	SpriteAliado accion;
	int limHD, limHI, limVAr, limVAb;
	bool visible;
	int powerX, powerY;
public:
	Aliado(int x, int y, int dx, int dy, Bitmap^ img, int limHD, int limHI, int limVAb, int limVAr, Bitmap^ imgPowerup)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;

		this->limHD = limHD;
		this->limHI = limHI;
		this->limVAr = limVAr;
		this->limVAb = limVAb;

		ancho = img->Width / 4;
		alto = img->Height / 4;

		accion = aCaminarDerecha;
		visible = true;
		powerX = -35;
		powerY = -45;
	}

	void SetAccion(SpriteAliado value)
	{
		accion = value;
	}
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	void Mover(Graphics^ g)
	{
		if (!(x + dx >= limHI && (x + ancho + dx) * 0.15 < limHD))
			dx *= -1;

		if (!(y + dy >= limVAr && (y + alto + dy) * 0.15 < limVAb))
			dy *= -1;

		if (dx < 0)
			accion = aCaminarIzquierda;
		else if (dx > 0)
			accion = aCaminarDerecha;
		else if (dy < 0)
			accion = aCaminarArriba;
		else if (dy > 0)
			accion = aCaminarAbajo;


		x += dx;
		y += dy;
	}
	Rectangle Area()
	{
		return Rectangle(x, y, ancho * 0.15, alto * 0.15);
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho * 0.15, alto * 0.15);
	}
	Rectangle Hitbox() {
		return Rectangle(x + 7, y + 7, (ancho / 2 * 0.15) + 7, (alto / 2 * 0.15) + 12);
	}
	Rectangle NextHitbox() {
		return Rectangle(x + 7 + dx, y + 7 + dy, (ancho / 2 * 0.15) + 7, (alto / 2 * 0.15) + 12);
	}

	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.15, alto * 0.15);
		g->DrawImage(img, zoom, corte, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());
		//g->DrawRectangle(Pens::Blue, Hitbox());

		if (dx != 0 || dy != 0)
		{
			IDx = (IDx + 1) % 4;
		}
	}

	void MostrarPowerup1(Graphics^ g, Bitmap^ imgPowerup) 
	{
		g->DrawImage(imgPowerup, Rectangle(powerX, 560, 30, 30));
	}
	Rectangle HitBoxPowerup1()
	{
		return Rectangle(powerX, 560, 30, 30);
	}
	void MostrarPowerup2(Graphics^ g, Bitmap^ imgPowerup)
	{
		g->DrawImage(imgPowerup, Rectangle(555, powerY, 30, 30));
	}
	Rectangle HitBoxPowerup2()
	{
		return Rectangle(555, powerY, 30, 30);
	}

	bool ColisionPower1(Rectangle obj) {
		if (HitBoxPowerup1().IntersectsWith(obj)) {
			return true;
		}

		return false;
	}

	bool ColisionPower2(Rectangle obj) {
		if (HitBoxPowerup2().IntersectsWith(obj)) {
			return true;
		}

		return false;
	}
	void SetpowerX(int value)
	{
		powerX = value;
	}
	void SetpowerY(int value)
	{
		powerY = value;
	}
};