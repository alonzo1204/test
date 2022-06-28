#pragma once
#include <iostream>
#include "Tangible.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
enum SpriteJugador
{
	CaminarAbajo,
	CaminarArriba,
	CaminarDerecha,
	CaminarIzquierda,
};

class Jugador : public Tangible
{
private:
	SpriteJugador accion;
	int vidas;
public:
	Jugador(Bitmap^ img, int vidas)
	{
		x = 286; y = 380;
		dx = dy = 0;

		ancho = img->Width / 4;
		alto = img->Height / 4;

		accion = CaminarAbajo;

		this->vidas = vidas;
	}

	void SetVidas(int value) {
		vidas += value;
	}
	int GetVidas() {
		return vidas;
	}

	void SetAccion(SpriteJugador value)
	{
		accion = value;
	}


	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && (x + ancho + dx) * 0.15 < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && (y + alto + dy) * 0.15 < g->VisibleClipBounds.Height)
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

	void Mostrar(Graphics^ g, Bitmap^ img, Bitmap^ imgVidas)
	{
		//g->DrawString("Vidas: " + vidas, gcnew Font("Arial", 12), Brushes::Black, 280,620);
		g->DrawImage(imgVidas, Rectangle(400, 615, 100, 20));
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


};