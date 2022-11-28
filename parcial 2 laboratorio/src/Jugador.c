#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"

Jugador* jugador_new()
{
	Jugador *unJugador = NULL;

	unJugador = (Jugador*) malloc(sizeof(Jugador));

	if (unJugador != NULL)
	{
		unJugador->id = 0;
		unJugador->edad = 0;
		unJugador->fechaNacimiento.dia = 0;
		unJugador->fechaNacimiento.mes = 0;
		unJugador->fechaNacimiento.anio = 0;
		strcpy(unJugador->nombreJugador, " ");
		strcpy(unJugador->apellidoJugador, " ");
		strcpy(unJugador->ciudadNacimiento, " ");
	}

	return unJugador;
}

Jugador* jugador_newParametros(char *idStr, char *nombreJugadorStr, char *apellidoJugadorStr, char *ciudadNacimientoStr, char *edadStr, char *diaStr,
		char *mesStr, char *anioStr)
{
	Jugador *unJugador = NULL;

	unJugador = jugador_new();

	if (unJugador != NULL)
	{
		if ((jugador_setId(unJugador, atoi(idStr)) || jugador_setNombreJugador(unJugador, nombreJugadorStr)
				|| jugador_setApellidoJugador(unJugador, apellidoJugadorStr) || jugador_setCiudadNacimiento(unJugador, ciudadNacimientoStr)
				|| jugador_setEdad(unJugador, atoi(edadStr)) || jugador_setDia(unJugador, atoi(diaStr)) || jugador_setMes(unJugador, atoi(mesStr))
				|| jugador_setAnio(unJugador, atoi(anioStr))) != 0)
		{
			unJugador = NULL;
			jugador_delete(unJugador);
		}
	}

	return unJugador;
}

void jugador_delete(Jugador *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

int jugador_setId(Jugador *this, int id)
{
	int todoOk = -1;

	if (this != NULL && id >= 0)
	{
		this->id = id;
		todoOk = 0;
	}
	else
	{
		printf("\nID invalido\n");
	}

	return todoOk;
}

int jugador_getId(Jugador *this, int *id)
{
	int todoOk = -1;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 0;
	}

	return todoOk;
}

int jugador_setNombreJugador(Jugador *this, char *nombreJugador)
{
	int todoOk = -1;

	if (this != NULL && nombreJugador != NULL)
	{
		if (strlen(nombreJugador) < 100 && strlen(nombreJugador) > 1)
		{
			strcpy(this->nombreJugador, nombreJugador);
			strlwr(this->nombreJugador);
			this->nombreJugador[0] = toupper(this->nombreJugador[0]);
			todoOk = 0;
		}
	}
	else
	{
		printf("\nNombre Invalido\n");
	}

	return todoOk;
}

int jugador_getNombreJugador(Jugador *this, char *nombreJugador)
{
	int todoOk = -1;

	if (this != NULL && nombreJugador != NULL)
	{
		strcpy(nombreJugador, this->nombreJugador);
		todoOk = 0;
	}

	return todoOk;
}

int jugador_setApellidoJugador(Jugador *this, char *apellidoJugador)
{
	int todoOk = -1;

	if (this != NULL && apellidoJugador != NULL)
	{
		if (strlen(apellidoJugador) < 100 && strlen(apellidoJugador) > 1)
		{
			strcpy(this->apellidoJugador, apellidoJugador);
			strlwr(this->apellidoJugador);
			this->apellidoJugador[0] = toupper(this->apellidoJugador[0]);
			todoOk = 0;
		}
	}
	else
	{
		printf("\nApellido de jugador Invalido\n");
	}
	return todoOk;
}

int jugador_getApellidoJugador(Jugador *this, char *apellidoJugador)
{
	int todoOk = -1;

	if (this != NULL && apellidoJugador != NULL)
	{
		strcpy(apellidoJugador, this->apellidoJugador);
		todoOk = 0;
	}

	return todoOk;
}

int jugador_setCiudadNacimiento(Jugador *this, char *ciudadNacimiento)
{
	int todoOk = -1;

	if (this != NULL && ciudadNacimiento != NULL)
	{
		if (strlen(ciudadNacimiento) < 100 && strlen(ciudadNacimiento) > 1)
		{
			strcpy(this->ciudadNacimiento, ciudadNacimiento);
			strlwr(this->ciudadNacimiento);
			this->ciudadNacimiento[0] = toupper(this->ciudadNacimiento[0]);
			todoOk = 0;
		}
	}
	else
	{
		printf("\nciudadNacimiento Invalida\n");
	}
	return todoOk;
}

int jugador_getCiudadNacimiento(Jugador *this, char *ciudadNacimiento)
{
	int todoOk = -1;

	if (this != NULL && ciudadNacimiento != NULL)
	{
		strcpy(ciudadNacimiento, this->ciudadNacimiento);
		todoOk = 0;
	}

	return todoOk;
}

int jugador_setEdad(Jugador *this, int edad)
{
	int todoOk = -1;

	if (this != NULL && edad >= 0)
	{
		this->edad = edad;
		todoOk = 0;
	}
	else
	{
		printf("\nAltura invalida\n");
	}
	return todoOk;
}

int jugador_getEdad(Jugador *this, int *edad)
{
	int todoOk = -1;

	if (this != NULL && edad != NULL)
	{
		*edad = this->edad;
		todoOk = 0;
	}

	return todoOk;
}

int jugador_setDia(Jugador *this, int dia)
{
	int todoOk = -1;

	if (this != NULL && dia > 0 && dia <= 31)
	{
		this->fechaNacimiento.dia = dia;
		todoOk = 0;
	}
	else
	{
		printf("\nDia invalido\n");
	}
	return todoOk;
}

int jugador_getDia(Jugador *this, int *dia)
{
	int todoOk = -1;

	if (this != NULL && dia != NULL)
	{
		*dia = this->fechaNacimiento.dia;
		todoOk = 0;
	}

	return todoOk;
}

int jugador_setMes(Jugador *this, int mes)
{
	int todoOk = -1;

	if (this != NULL && mes > 0 && mes <= 12)
	{
		this->fechaNacimiento.mes = mes;
		todoOk = 0;
	}
	else
	{
		printf("\nMes invalido\n");
	}
	return todoOk;
}

int jugador_getMes(Jugador *this, int *mes)
{
	int todoOk = -1;

	if (this != NULL && mes != NULL)
	{
		*mes = this->fechaNacimiento.mes;
		todoOk = 0;
	}

	return todoOk;
}

int jugador_setAnio(Jugador *this, int anio)
{
	int todoOk = -1;

	if (this != NULL && anio >= 1980 && anio <= 2005)
	{
		this->fechaNacimiento.anio = anio;
		todoOk = 0;
	}
	else
	{
		printf("\nAnio invalido\n");
	}
	return todoOk;
}

int jugador_getAnio(Jugador *this, int *anio)
{
	int todoOk = -1;

	if (this != NULL && anio != NULL)
	{
		*anio = this->fechaNacimiento.anio;
		todoOk = 0;
	}

	return todoOk;
}

int jugador_MostrarUnJugador(Jugador *this)
{
	int todoOk = -1;
	int id;
	char nombreJugador[30];
	char apellidoJugador[30];
	char ciudadNacimiento[30];
	int edad;
	int dia;
	int mes;
	int anio;

	if (this != NULL)
	{
		jugador_getId(this, &id);
		jugador_getNombreJugador(this, nombreJugador);
		jugador_getApellidoJugador(this, apellidoJugador);
		jugador_getCiudadNacimiento(this, ciudadNacimiento);
		jugador_getEdad(this, &edad);
		jugador_getDia(this, &dia);
		jugador_getMes(this, &mes);
		jugador_getAnio(this, &anio);

		printf("| %-5d | %.2d/%.2d/%-6d | %-15s | %-15s | %-23s | %-5d|\n", id, dia, mes, anio, nombreJugador, apellidoJugador, ciudadNacimiento, edad);
		todoOk = 0;
	}
	return todoOk;
}

int jugador_OrdenamientoNombre(void *unJugador, void *otroJugador)
{
	int todoOk = 0;
	Jugador *jugadorUno = NULL;
	Jugador *jugadorDos = NULL;

	char nombreUno[100];
	char nombreDos[100];

	jugadorUno = (Jugador*) unJugador;
	jugadorDos = (Jugador*) otroJugador;

	if (unJugador != NULL && otroJugador != NULL)
	{
		if (jugador_getNombreJugador(jugadorUno, nombreUno) == 0 && jugador_getNombreJugador(jugadorDos, nombreDos) == 0)
		{
			if (strcmp(nombreUno, nombreDos) > 0)
			{
				todoOk = 1;
			}
			else if (strcmp(nombreUno, nombreDos) < 0)
			{
				todoOk = -1;
			}
		}
	}

	return todoOk;
}

int jugador_OrdenamientoApellido(void *unJugador, void *otroJugador)
{
	int todoOk = 0;
	Jugador *jugadorUno = NULL;
	Jugador *jugadorDos = NULL;

	char apellidoUno[100];
	char apellidoDos[100];

	jugadorUno = (Jugador*) unJugador;
	jugadorDos = (Jugador*) otroJugador;

	if (unJugador != NULL && otroJugador != NULL)
	{
		if (jugador_getApellidoJugador(jugadorUno, apellidoUno) == 0 && jugador_getApellidoJugador(jugadorDos, apellidoDos) == 0)
		{
			if (strcmp(apellidoUno, apellidoDos) > 0)
			{
				todoOk = 1;
			}
			else if (strcmp(apellidoUno, apellidoDos) < 0)
			{
				todoOk = -1;
			}
		}
	}

	return todoOk;
}
