//============================================================================
// Name        : E3isaacmd.cpp
// Author      : Isaac Moreno Duaso
// Version     :
// Copyright   :
// Description : Practica 3. Implementación de correcciones junto con la prácitca 3. Bucles.
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
typedef char cadena[MAX_CAR + 1];

int main()
{
	int vecesJugadas;
	int edadJugador1, edadJugador2;
	int tiradaJugador1, tiradaJugador2;
	char jugar;
	bool puedeJugar;
	cadena nombreJugador1;
	cadena nombreJugador2;
	srand(time(0));

	cout << "Quieres jugar? (s/n): ";
	cin >> jugar;
	jugar = tolower(jugar);

	//bucle de validacion de entrada
	while (jugar != 's' && jugar != 'n')
	{
		cout << "La respuesta no es valida. Solo se puede aceptar s y n.";
		cout << "Por favor introduce una respuesta en formato s/n" << endl;
		cin >> jugar;
		jugar = tolower(jugar);
	}

	puedeJugar = true;
	vecesJugadas = 0;
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
		//Solo repetimos las tiradas, los jugadores y las edades serán las mismas al repetir
		do
		{


			do
			{
				tiradaJugador1 = rand() % 6 + 1;
				PlaySound(TEXT("sonidodado.wav"), NULL, SND_FILENAME);
				cout << "   Tirada de " << nombreJugador1 << ": "
						<< tiradaJugador1 << endl;
				Sleep(1000);

				tiradaJugador2 = rand() % 6 + 1;
				PlaySound(TEXT("sonidodado.wav"), NULL, SND_FILENAME);
				cout << "   Tirada de " << nombreJugador2 << ": "
						<< tiradaJugador2 << endl;
				Sleep(1000);
				if (tiradaJugador1 > tiradaJugador2)
				{
					cout << "Comienza la partida: " << nombreJugador1
							<< endl;
				}
				else if (tiradaJugador1 < tiradaJugador2)
				{
					cout << "Comienza la partida: " << nombreJugador2
							<< endl;
				}
				else
				{
					cout << "Empate! Tenemos que repetir las tiradas!"
											<< endl;
				}
			} while (tiradaJugador1 == tiradaJugador2);

			for (int i = 0; i < 5; i++)
			{
				tiradaJugador1 = rand() % 9;
				switch (tiradaJugador1)
				{
				case 0:
					textcolor(15);
					cout << "Esta casilla no es especial";
					break;
				case 1:
					textcolor(1);
					cout << "Has caido en una Oca";
					break;
				case 2:
					textcolor(2);
					cout << "Has caido en un Puente";
					break;
				case 3:
					textcolor(3);
					cout << "Has caido en la poSada";
					break;
				case 4:
					textcolor(4);
					cout << "Has caido en Dados";
					break;
				case 5:
					textcolor(5);
					cout << "Has caido en calaVera";
					break;
				case 6:
					textcolor(6);
					cout << "Has caido en la Carcel";
					break;
				case 7:
					textcolor(7);
					cout << "Has caido en el poZo";
					break;
				case 8:
					textcolor(8);
					cout << "Has caido en Laberinto";
					break;
				}
				cout << endl;
				textcolor(15);
			}
			textcolor(1);
			cout << "Felicidades has ganado!! " << endl;

			textcolor(15);
			cout << "Quieres volver a jugar? (s/n): ";
			cin >> jugar;
			jugar = tolower(jugar);
			while (jugar != 's' && jugar != 'n')
			{
				cout << "La respuesta no es valida. Solo se puede aceptar s y n.";
				cout << "Por favor introduce una respuesta en formato s/n" << endl;
				cin >> jugar;
				jugar = tolower(jugar);
			}
			vecesJugadas++;
		} while (jugar == 's' && puedeJugar);
	}
	else
	{
		textcolor(4);
		cout << "Las edades de los jugadores no son validas. El juego ha terminado." << endl;
		puedeJugar = false;
	}

	if (vecesJugadas == 0)
	{
		cout << "Esta bien. Hasta luego!" << endl;
	}
	else
	{
		if (vecesJugadas == 1)
		{
			cout << "Gracias por jugar esta partida. Hasta luego!"
					<< endl;
		}
		else
		{
			cout << "Gracias por jugar. "
					<< "Has jugado un total de " << vecesJugadas
					<< " partidas. Hasta luego!" << endl;
		}
	}

	textcolor(15);
	system("PAUSE");
	return 0;
}
