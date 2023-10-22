//============================================================================
// Name        : E4isaacmd.cpp
// Author      : Isaac Moreno Duaso
// Version     :
// Copyright   :
// Description : Practica 4. Juego de la oca, se añaden tiradas alternas entre jugadores. Llega a 63 y gana.
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio2.h>
#include <windows.h>

using namespace std;

#define EDADMINIMA 8
#define EDADMAXIMA 99
#define MAX_CAR 10
#define PUNTOSGANAR 63
#define delay 1000
typedef char cadena[MAX_CAR + 1];

int main()
{
	srand(time(0));
	int vecesJugadas;
	int edadJugador1, edadJugador2;
	int tiradaJugador1, tiradaJugador2, tiradaJugador;
	char jugar;
	cadena nombreJugador1;
	cadena nombreJugador2;
	int puntosJugador1, puntosJugador2, numTiradas;
	textcolor(15);
	cout << "Quieres jugar? (s/n): ";
	cin >> jugar;
	jugar = tolower(jugar);

	while (jugar != 's' && jugar != 'n')
	{
		cout << "La respuesta no es valida. Solo se puede aceptar s y n.";
		cout << "Por favor introduce una respuesta en formato s/n" << endl;
		cin >> jugar;
		jugar = tolower(jugar);
	}
	vecesJugadas = 0;
	if (jugar == 's')
	{
		cout
			<< "*************************************************************\nREGLAS DEL JUEGO DE LA OCA\nCada jugador lanzara un dado por turnos,\ncomenzara a jugar el que obtenga la puntuacion mas alta\n*************************************************************"
			<< endl;
		PlaySound(TEXT("sound/startmusic.wav"), NULL, SND_FILENAME);
		cout << "Ingresa la edad del Jugador 1: ";
		cin >> edadJugador1;
		cout << "Ingresa la edad del Jugador 2: ";
		cin >> edadJugador2;
		if (edadJugador1 > EDADMINIMA && edadJugador1 < EDADMAXIMA && edadJugador2 > EDADMINIMA && edadJugador2 < EDADMAXIMA)
		{
			cout << "Ingresa el nombre del Jugador 1: ";
			cin >> nombreJugador1;
			cout << "Ingresa el nombre del Jugador 2: ";
			cin >> nombreJugador2;

			do
			{
				do
				{ // se elige quien empieza la partida
					tiradaJugador1 = 1 + rand() % 6;
					PlaySound(TEXT("sound/sonidodado.wav"), NULL, SND_FILENAME);
					cout << "   Tirada de " << nombreJugador1 << ": "
						 << tiradaJugador1 << endl;
					Sleep(1000);

					tiradaJugador2 = rand() % 6 + 1;
					PlaySound(TEXT("sound/sonidodado.wav"), NULL, SND_FILENAME);
					cout << "   Tirada de " << nombreJugador2 << ": "
						 << tiradaJugador2 << endl;
					Sleep(1000);
					if (tiradaJugador1 > tiradaJugador2)
					{
						cout << "Comienza la partida: " << nombreJugador1
							 << endl;
						numTiradas = 1; // Asi empieza el jugador1
					}
					else if (tiradaJugador1 < tiradaJugador2)
					{
						cout << "Comienza la partida: " << nombreJugador2
							 << endl;
						numTiradas = 0; // Asi empieza el jugador2
					}
					else
					{
						cout << "Empate! Tenemos que repetir las tiradas!"
							 << endl;
					}
				} while (tiradaJugador1 == tiradaJugador2);
				PlaySound(TEXT("sound/wintoss.wav"), NULL, SND_FILENAME);
				puntosJugador1 = 0;
				puntosJugador2 = 0;
				do
				{
					tiradaJugador = 1 + rand() % 6;
					numTiradas++;
					Sleep(delay); // delay para experiencia de juego
					if (numTiradas % 2 == 0)
					{ // si las tiradas son pares pertenecen al jugador 1
						cout << "Tira " << nombreJugador1 << endl;
						PlaySound(TEXT("sound/sonidodado.wav"), NULL,
								  SND_FILENAME);
						Sleep(delay);
						if (puntosJugador1 + tiradaJugador <= PUNTOSGANAR)
						{
							puntosJugador1 += tiradaJugador;
							cout << "\t" << nombreJugador1 << " ha sacado un "
								 << tiradaJugador << " Total: "
								 << puntosJugador1 << " puntos" << endl;
						}
						else
						{
							cout << "\t" << nombreJugador1 << " no puede mover "
								 << tiradaJugador << ", se ha pasado";
							tiradaJugador = -1;
						}
					}
					else
					{ // si las tiradas son impares pertenecen al jugador 2
						cout << "Tira " << nombreJugador2 << endl;
						PlaySound(TEXT("sound/sonidodado.wav"), NULL, SND_FILENAME);
						Sleep(delay);
						if (puntosJugador2 + tiradaJugador <= PUNTOSGANAR)
						{									 // elige si puede avanzar o no
							puntosJugador2 += tiradaJugador; // avanza
							cout << "\t" << nombreJugador2 << " ha sacado un "
								 << tiradaJugador << " Total: "
								 << puntosJugador2 << " puntos" << endl;
						}
						else
						{
							cout << "\t" << nombreJugador2 << " no puede mover " // no avanza
								 << tiradaJugador << ", se ha pasado";
							tiradaJugador = -1;
						}
					}
					if (tiradaJugador != -1)
					{
						tiradaJugador = rand() % 8; // aleatorio entre 1 y 8
					}
					switch (tiradaJugador)
					{
					case 0:
						textcolor(15);
						cout << "\t"
							 << "Esta casilla no es especial";
						break;
					case 1:
						textcolor(1);
						cout << "\t"
							 << "Has caido en una Oca";
						PlaySound(TEXT("sound/cuaqcuaq.wav"), NULL, SND_FILENAME);
						break;
					case 2:
						textcolor(2);
						cout << "\t"
							 << "Has caido en un Puente";
						break;
					case 3:
						textcolor(3);
						cout << "\t"
							 << "Has caido en la poSada";
						break;
					case 4:
						textcolor(4);
						cout << "\t"
							 << "Has caido en Dados";
						break;
					case 5:
						textcolor(5);
						cout << "\t"
							 << "Has caido en calaVera";
						break;
					case 6:
						textcolor(6);
						cout << "\t"
							 << "Has caido en la Carcel";
						break;
					case 7:
						textcolor(7);
						cout << "\t"
							 << "Has caido en el poZo";
						break;
					case 8:
						textcolor(8);
						cout << "\t"
							 << "Has caido en Laberinto";
						break;
					}
					cout << endl;
					cout << endl;
					textcolor(15);
				} while (puntosJugador1 != PUNTOSGANAR && puntosJugador2 != PUNTOSGANAR);

				textcolor(1);
				cout << "Felicidades has ganado ";
				if (puntosJugador1 > puntosJugador2)
				{
					cout << nombreJugador1 << endl;
				}
				else
				{
					cout << nombreJugador2 << endl;
				}
				PlaySound(TEXT("sound/winningsound.wav"), NULL, SND_FILENAME);
				Sleep(delay);
				textcolor(15);
				cout << "Quieres volver a jugar? (s/n): ";
				cin >> jugar;
				jugar = tolower(jugar);
				while (jugar != 's' && jugar != 'n')
				{
					cout << "\t"
						 << "La respuesta no es valida. Solo se puede aceptar s y n.";
					cout << "\t"
						 << "Por favor introduce una respuesta en formato s/n"
						 << endl;
					cin >> jugar;
					jugar = tolower(jugar);
				}
				vecesJugadas++;
			} while (jugar == 's');
		}
		else
		{
			textcolor(4);
			cout
				<< "Las edades de los jugadores no son validas. El juego ha terminado."
				<< endl;
			PlaySound(TEXT("sound/errorsound.wav"), NULL, SND_FILENAME);
		}
	}
	if (vecesJugadas == 1)
	{
		cout << "Gracias por jugar esta partida. ";
	}
	if (vecesJugadas > 1)
	{
		cout << "Gracias por jugar. "
			 << "Has jugado un total de "
			 << vecesJugadas << " partidas. ";
	}
	cout << "Hasta luego!" << endl;
	textcolor(15);
	system("PAUSE");
	return 0;
}
