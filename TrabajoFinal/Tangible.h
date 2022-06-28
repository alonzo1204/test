#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Tangible
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
public:
	Tangible()
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}

	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void SetX(int value) {
		x = value;
	}
	void SetY(int value) {
		y = value;
	}
	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Black, Area());
	}
};