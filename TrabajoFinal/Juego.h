#pragma once
#include "Wall.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Aliado.h"
#include "Material.h"
#include <time.h>
ref class Juego {

private:
	Walls* walls;
	Jugador* jugador;
	Enemigos* enemigos;
	Aliado* aliado1;
	Aliado* aliado2;
	Papeles* papeles;
	Vidrios* vidrios;
	Plasticos* plasticos;

	Bitmap^ imgJugador;
	Bitmap^ imgEnemigo;
	Bitmap^ imgAliado;
	Bitmap^ imgPowerup;
	Bitmap^ imgVidas;
	Bitmap^ imgPapel;
	Bitmap^ imgVidrio;
	Bitmap^ imgPlastico;
	Bitmap^ imgbarraPlastico;
	Bitmap^ imgbarraVidrio;
	Bitmap^ imgbarraPapel;

	int spawnAliado;
	int cd_AtaqueEnemigo;
	bool ActivePowerUp;
	int cd_ActivePowerUp;
	int tiempo;
	bool powerup1;
	bool powerup2;
	int parpadeo;
	int contador_papel;
	int contador_vidrio;
	int contador_plastico;
	int velocidad_jugador;
public:
	Juego(int vidas, int velocidad_jugador) {
		
		imgJugador = gcnew Bitmap("Images/jugador.png");
		imgEnemigo = gcnew Bitmap("Images/enemigo3.png");
		imgJugador->MakeTransparent(imgJugador->GetPixel(0, 0));
		imgAliado = gcnew Bitmap("Images/aliado.png");
		imgPowerup = gcnew Bitmap("Images/power.png");
		imgVidas = gcnew Bitmap("Images/6.png");
		imgPapel = gcnew Bitmap("Images/papel.png");
		imgVidrio = gcnew Bitmap("Images/vidrio.png");
		imgPlastico = gcnew Bitmap("Images/plastico.png");
		imgbarraPlastico = gcnew Bitmap("Images/p0.png");
		imgbarraVidrio = gcnew Bitmap("Images/v0.png");
		imgbarraPapel = gcnew Bitmap("Images/l0.png");;

		papeles = new Papeles(imgPapel);
		vidrios = new Vidrios(imgVidrio);
		plasticos = new Plasticos(imgPlastico);
		jugador = new Jugador(imgJugador, vidas);
		walls = new Walls();
		enemigos = new Enemigos(imgEnemigo);
		aliado1 = new Aliado(-35, 545, 0, 0, imgAliado, 120, 3, 1, 1, nullptr);
		aliado2 = new Aliado(550, -45, 0, 0, imgAliado, 1, 1, 69, 1,nullptr);
		spawnAliado = 0;
		cd_AtaqueEnemigo = 0;
		ActivePowerUp = false;
		cd_ActivePowerUp = 0;
		tiempo = 300 * 1000;  
		powerup1 = false;
		powerup2 = false;
		parpadeo = 1;
		contador_papel = 0;
		contador_vidrio = 0;
		contador_plastico = 0;
		this->velocidad_jugador = velocidad_jugador;
	}
	~Juego() {
		delete  imgJugador;
		delete jugador, walls;
	}

	void AccionJugador(bool accion, Keys tecla)
	{

		if (accion == true)
		{
			if (tecla == Keys::Up)
			{
				jugador->SetDY(-velocidad_jugador);
				jugador->SetAccion(CaminarArriba);
			}
			else if (tecla == Keys::Down)
			{
				jugador->SetDY(velocidad_jugador);
				jugador->SetAccion(CaminarAbajo);
			}
			else if (tecla == Keys::Left)
			{
				jugador->SetDX(-velocidad_jugador);
				jugador->SetAccion(CaminarIzquierda);
			}
			else if (tecla == Keys::Right)
			{
				jugador->SetDX(velocidad_jugador);
				jugador->SetAccion(CaminarDerecha);
			}
			else if (tecla == Keys::F1) {
				spawnAliado++;
				if (spawnAliado == 1) {
					aliado1 = new Aliado(10, 545, 3, 0, imgAliado, 119, 3, 1, 1, imgPowerup);
				}
				else if (spawnAliado == 2) {
					aliado2 = new Aliado(550, 1, 0, 3, imgAliado, 1, 1, 65, 1,imgPowerup);
				}
			}
		}
		else
		{
			if (tecla == Keys::Up)
				jugador->SetDY(0);
			else if (tecla == Keys::Down)
				jugador->SetDY(0);
			else if (tecla == Keys::Left)
				jugador->SetDX(0);
			else if (tecla == Keys::Right)
				jugador->SetDX(0);
		}
	}

	void DrawEverything(Graphics^ g) {

		g->DrawString("Tiempo: " + (((tiempo - clock())/1000)), gcnew Font("MV boli", 16), Brushes::Black, 30, 610);


		if (jugador->GetVidas() == 5) {
			imgVidas = gcnew Bitmap("Images/5.png");
		}
		else if (jugador->GetVidas() == 4) {
			imgVidas = gcnew Bitmap("Images/4.png");
		}
		else if (jugador->GetVidas() == 3) {
			imgVidas = gcnew Bitmap("Images/3.png");
		}
		else if (jugador->GetVidas() == 2) {
			imgVidas = gcnew Bitmap("Images/2.png");
		}
		else if (jugador->GetVidas() == 1) {
			imgVidas = gcnew Bitmap("Images/1.png");
		}
		else if (jugador->GetVidas() == 0) {
			imgVidas = gcnew Bitmap("Images/0.png");
		}
		g->DrawImage(imgbarraPlastico, Rectangle(607, 9, 50, 180));
		g->DrawImage(imgbarraPapel, Rectangle(607, 209, 50, 180));
		g->DrawImage(imgbarraVidrio, Rectangle(607, 409, 50, 180));
		if (contador_plastico == 15) {
			imgbarraPlastico = gcnew Bitmap("Images/p15.png");
		}
		else if (contador_plastico == 14) {
			imgbarraPlastico = gcnew Bitmap("Images/p14.png");
		}
		else if (contador_plastico == 13) {
			imgbarraPlastico = gcnew Bitmap("Images/p13.png");
		}
		else if (contador_plastico == 12) {
			imgbarraPlastico = gcnew Bitmap("Images/p12.png");
		}
		else if (contador_plastico == 11) {
			imgbarraPlastico = gcnew Bitmap("Images/p11.png");
		}
		else if (contador_plastico == 10) {
			imgbarraPlastico = gcnew Bitmap("Images/p10.png");
		}
		else if (contador_plastico == 9) {
			imgbarraPlastico = gcnew Bitmap("Images/p9.png");
		}
		else if (contador_plastico == 8) {
			imgbarraPlastico = gcnew Bitmap("Images/p8.png");
		}
		else if (contador_plastico == 7) {
			imgbarraPlastico = gcnew Bitmap("Images/p7.png");
		}
		else if (contador_plastico == 6) {
			imgbarraPlastico = gcnew Bitmap("Images/p6.png");
		}
		else if (contador_plastico == 5) {
			imgbarraPlastico = gcnew Bitmap("Images/p5.png");
		}
		else if (contador_plastico == 4) {
			imgbarraPlastico = gcnew Bitmap("Images/p4.png");
		}
		else if (contador_plastico == 3) {
			imgbarraPlastico = gcnew Bitmap("Images/p3.png");
		}
		else if (contador_plastico == 2) {
			imgbarraPlastico = gcnew Bitmap("Images/p2.png");
		}
		else if (contador_plastico == 1) {
			imgbarraPlastico = gcnew Bitmap("Images/p1.png");
		}

		if (contador_vidrio == 15) {
			imgbarraVidrio = gcnew Bitmap("Images/v15.png");
		}
		else if (contador_vidrio == 14) {
			imgbarraVidrio = gcnew Bitmap("Images/v14.png");
		}
		else if (contador_vidrio == 13) {
			imgbarraVidrio = gcnew Bitmap("Images/v13.png");
		}
		else if (contador_vidrio == 12) {
			imgbarraVidrio = gcnew Bitmap("Images/v12.png");
		}
		else if (contador_vidrio == 11) {
			imgbarraVidrio = gcnew Bitmap("Images/v11.png");
		}
		else if (contador_vidrio == 10) {
			imgbarraVidrio = gcnew Bitmap("Images/v10.png");
		}
		else if (contador_vidrio == 9) {
			imgbarraVidrio = gcnew Bitmap("Images/v9.png");
		}
		else if (contador_vidrio == 8) {
			imgbarraVidrio = gcnew Bitmap("Images/v8.png");
		}
		else if (contador_vidrio == 7) {
			imgbarraVidrio = gcnew Bitmap("Images/v7.png");
		}
		else if (contador_vidrio == 6) {
			imgbarraVidrio = gcnew Bitmap("Images/v6.png");
		}
		else if (contador_vidrio == 5) {
			imgbarraVidrio = gcnew Bitmap("Images/v5.png");
		}
		else if (contador_vidrio == 4) {
			imgbarraVidrio = gcnew Bitmap("Images/v4.png");
		}
		else if (contador_vidrio == 3) {
			imgbarraVidrio = gcnew Bitmap("Images/v3.png");
		}
		else if (contador_vidrio == 2) {
			imgbarraVidrio = gcnew Bitmap("Images/v2.png");
		}
		else if (contador_vidrio == 1) {
			imgbarraVidrio = gcnew Bitmap("Images/v1.png");
		}

		if (contador_papel == 15) {
			imgbarraPapel = gcnew Bitmap("Images/l15.png");
		}
		else if (contador_papel == 14) {
			imgbarraPapel = gcnew Bitmap("Images/l14.png");
		}
		else if (contador_papel == 13) {
			imgbarraPapel = gcnew Bitmap("Images/l13.png");
		}
		else if (contador_papel == 12) {
			imgbarraPapel = gcnew Bitmap("Images/l12.png");
		}
		else if (contador_papel == 11) {
			imgbarraPapel = gcnew Bitmap("Images/l11.png");
		}
		else if (contador_papel == 10) {
			imgbarraPapel = gcnew Bitmap("Images/l10.png");
		}
		else if (contador_papel == 9) {
			imgbarraPapel = gcnew Bitmap("Images/l9.png");
		}
		else if (contador_papel == 8) {
			imgbarraPapel = gcnew Bitmap("Images/l8.png");
		}
		else if (contador_papel == 7) {
			imgbarraPapel = gcnew Bitmap("Images/l7.png");
		}
		else if (contador_papel == 6) {
			imgbarraPapel = gcnew Bitmap("Images/l6.png");
		}
		else if (contador_papel == 5) {
			imgbarraPapel = gcnew Bitmap("Images/l5.png");
		}
		else if (contador_papel == 4) {
			imgbarraPapel = gcnew Bitmap("Images/l4.png");
		}
		else if (contador_papel == 3) {
			imgbarraPapel = gcnew Bitmap("Images/l3.png");
		}
		else if (contador_papel == 2) {
			imgbarraPapel = gcnew Bitmap("Images/l2.png");
		}
		else if (contador_papel == 1) {
			imgbarraPapel = gcnew Bitmap("Images/l1.png");
		}


		jugador->Mostrar(g, imgJugador, imgVidas);
		walls->Mostrar(g);
		enemigos->Mostrar(g, imgEnemigo);
		papeles->Mostrar(g, imgPapel);
		vidrios->Mostrar(g, imgVidrio);
		plasticos->Mostrar(g, imgPlastico);

		if (aliado1->getVisible() == true) {
			aliado1->Mostrar(g, imgAliado);
		}
		if (aliado2->getVisible() == true) {
			aliado2->Mostrar(g, imgAliado);
		}

		if (aliado1->getX() > 520|| powerup1 == true) {
			powerup1 = true;
			aliado1->SetpowerX(540);
			aliado1->MostrarPowerup1(g, imgPowerup);
			aliado1->setVisible(false);
			aliado1->SetX(-35);
		}
		if (aliado2->getY() > 105 || powerup2 == true) {
			powerup2 = true;
			aliado2->SetpowerY(140);
			aliado2->MostrarPowerup2(g, imgPowerup);
			aliado2->setVisible(false);
			aliado2->SetY(-45);
		}


	}

	bool MoveEverything(Graphics^ g) {

		if (clock() >= tiempo) {
			return false;
		}
		
		if (papeles->Colision(jugador->NextHitbox()) == true) {
			papeles->Eliminar(jugador->NextHitbox());
			contador_papel++;
		}
		if (vidrios->Colision(jugador->NextHitbox()) == true) {
			vidrios->Eliminar(jugador->NextHitbox());
			contador_vidrio++;
		}
		if (plasticos->Colision(jugador->NextHitbox()) == true) {
			plasticos->Eliminar(jugador->NextHitbox());
			contador_plastico++;
		}

		if (contador_papel == 15 && contador_plastico == 15 && contador_vidrio == 15) {
			return false;
		}

		if (aliado1->ColisionPower1(jugador->Hitbox())) {
			powerup1 = false;
			ActivePowerUp = true;
			aliado1->SetpowerY(-35);
		}
		
		if (aliado2->ColisionPower2(jugador->Hitbox())) {
			powerup2 = false;
			ActivePowerUp = true;
			aliado2->SetpowerX(-35);
		}

		if (ActivePowerUp == true) {
			if (parpadeo == 1) {
				imgJugador = gcnew Bitmap("Images/activepower1.png");
				parpadeo++;
			}
			else if (parpadeo == 2) {
				imgJugador = gcnew Bitmap("Images/activepower2.png");
				parpadeo--;

			}
			if (enemigos->Colision(jugador->Hitbox())) {
				enemigos->Eliminar(jugador->NextHitbox());
			}

			if (clock() - cd_ActivePowerUp >= 10000) {
				imgJugador = gcnew Bitmap("Images/jugador.png");
				cd_ActivePowerUp = clock();
				ActivePowerUp = false;
			}
		}
		
		
		if(enemigos->Colision(jugador->Hitbox()) && clock() - cd_AtaqueEnemigo >= 2000 && ActivePowerUp == false) {
			jugador->SetVidas(-1);
			cd_AtaqueEnemigo = clock();

			if (jugador->GetVidas() == 0)
				return false;
		}

		if(walls->Colision(jugador->NextHitbox()) == false)
		jugador->Mover(g);

		enemigos->Mover(g);

		if (aliado1->getVisible() == true) {
			aliado1->Mover(g);
		}
		if (aliado2->getVisible() == true) {
			aliado2->Mover(g);
		}

		return true;
	}

	int getVidas(){
		return jugador->GetVidas();
	}

	int getVidrio() {
		return contador_vidrio;
	}

	int getPapel() {
		return contador_papel;
	}
	
	int getPlastico() {
		return contador_plastico;
	}

};
