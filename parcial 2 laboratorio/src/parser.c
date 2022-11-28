#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Jugador.h"
#include "LinkedList.h"

int parser_JugadoresDesdeTexto(FILE *pFile, LinkedList *pArrayListJugadores)
{

	int todoOk = -1;
	char id[30];
	char nombreJugador[30];
	char apellidoJugador[30];
	char ciudadNacimiento[30];
	char edad[30];
	char dia[30];
	char mes[30];
	char anio[30];
	char header[256];
	Jugador *unJugador;

	fscanf(pFile, "%[^\n]\n", header);

	while (!feof(pFile))
	{
		fscanf(pFile, "%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, dia, mes, anio, nombreJugador, apellidoJugador, ciudadNacimiento, edad);

		unJugador = jugador_newParametros(id, nombreJugador, apellidoJugador, ciudadNacimiento, edad, dia, mes, anio);

		ll_add(pArrayListJugadores, unJugador);

		todoOk = 0;
	}

	return todoOk;
}
