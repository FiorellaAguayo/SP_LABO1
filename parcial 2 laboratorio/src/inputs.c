#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "inputs.h"

static int imprimeMensaje(char mensaje[]);
static int pideDato(char *cadena);
static int soloLetras(char cadena[]);
static int ordenarCadena(char cadena[]);
static int validarEntero(char pEnteroAValidar[]);

static int imprimeMensaje(char mensaje[])
{
	int todoOk = -1;
	if (mensaje != NULL)
	{
		printf(mensaje);
		todoOk = 0;
	}
	return todoOk;
}

static int pideDato(char *cadena)
{
	if (cadena != NULL)
	{

		char buffer[256];
		fflush(stdin);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer) - 1] = '\0';
		strcpy(cadena, buffer);
		return 0;
	}

	return -1;
}

static int validarEntero(char pEnteroAValidar[])
{
	int todoOk = 1;

	if (strlen(pEnteroAValidar) > 0)
	{
		for (int i = 0; i < strlen(pEnteroAValidar); i++)
		{
			if (isdigit(pEnteroAValidar[i]) == 0)
			{
				if (i == 0 && pEnteroAValidar[0] == '-')
				{
					todoOk = 1;

				}
				else
				{
					todoOk = 0;
				}
			}
		}
	}
	else
	{
		todoOk = 0;
	}

	return todoOk;
}

static int soloLetras(char cadena[])
{
	int soloHayLetras = 1;
	int i = 0;

	if (cadena != NULL)
	{
		while (cadena[i] != '\0')
		{
			if (cadena[i] != ' ' && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
			{
				soloHayLetras = 0;
			}
			i++;
		}
	}
	return soloHayLetras;
}

static int ordenarCadena(char cadena[])
{
	int todoOk = -1;

	if (cadena != NULL)
	{
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);

		for (int i = 0; cadena[i] != '\0'; i++)
		{
			if (cadena[i] == ' ')
				cadena[i + 1] = toupper(cadena[i + 1]);
		}
		todoOk = 0;
	}
	return todoOk;
}

int pedirFlotante(float *numFloat, char mensaje[], char mensajeError[], float min, float max)
{
	int todoOk = -1;

	if (numFloat != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		char auxFlotante[150];
		imprimeMensaje(mensaje);
		pideDato(auxFlotante);

		while (validarEntero(auxFlotante) == 0 || atof(auxFlotante) > max || atof(auxFlotante) < min)
		{
			imprimeMensaje(mensaje);
			pideDato(auxFlotante);
		}

		*numFloat = atof(auxFlotante);
		todoOk = 1;
	}
	return todoOk;
}

int pedirEntero(int *enteroValidado, char mensaje[], char mensajeError[], int min, int max)
{
	int todoOk = 0;

	if (enteroValidado != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		char auxEntero[150];
		imprimeMensaje(mensaje);
		pideDato(auxEntero);

		while (validarEntero(auxEntero) == 0 || atoi(auxEntero) > max || atoi(auxEntero) < min)
		{
			imprimeMensaje(mensaje);
			pideDato(auxEntero);
		}

		*enteroValidado = atoi(auxEntero);
		todoOk = 1;
	}
	return todoOk;
}

int pedirShort(short *shortValidado, char mensaje[], char mensajeError[], int min, int max)
{
	int todoOk = 0;

	if (shortValidado != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		char auxEntero[150];
		imprimeMensaje(mensaje);
		fflush(stdin);
		pideDato(auxEntero);

		while (validarEntero(auxEntero) == 0 || atoi(auxEntero) > max || atoi(auxEntero) < min)
		{
			imprimeMensaje(mensaje);
			fflush(stdin);
			pideDato(auxEntero);
		}

		*shortValidado = atoi(auxEntero);
		todoOk = 1;
	}
	return todoOk;
}

int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar)
{
	int todoOk = -1;
	char auxChar;

	if (mensaje != NULL && mensajeError != NULL)
	{
		imprimeMensaje(mensaje);
		fflush(stdin);
		scanf("%c", &auxChar);

		while (auxChar != primerChar && auxChar != segundoChar)
		{
			imprimeMensaje(mensajeError);
			fflush(stdin);
			scanf("%c", &auxChar);
		}

		*charValidado = auxChar;
		todoOk = 1;
	}
	return todoOk;
}

int pedirCadena(char cadena[], char mensaje[], char mensajeError[], int max)
{
	int todoOk = -1;

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		char auxString[256];
		imprimeMensaje(mensaje);
		pideDato(auxString);

		while (strlen(auxString) > max || soloLetras(auxString) == 0 || auxString[0] == 00)
		{
			imprimeMensaje(mensajeError);
			pideDato(auxString);
		}
		strcpy(cadena, auxString);
		ordenarCadena(cadena);

		todoOk = 0;
	}
	return todoOk;
}

int menu()
{
	int opcion;

	printf("\n\n                                         ***  ABM JUGADORES  ***                \n\n\n");
	printf("1) Cargar datos de jugadores desde los archivos.csv.\n");
	printf("2) Alta de jugador.\n");
	printf("3) Baja de jugador.\n");
	printf("4) Modificacion de jugador.\n");
	printf("5) Generar informe jugador.\n");
	printf("6) Guardar los datos del archivo.csv (en modo texto).\n");
	printf("7) Guardar los datos del archivo.bin (en modo binario).\n");
	printf("8) Listar jugadores ordenados\n");
	printf("9) Salir.\n");

	pedirEntero(&opcion, "\nIngrese opcion: ", "\nError, reingrese opcion: ", 1, 9);

	return opcion;
}

int menuModificacion()
{
	int opcion;

	printf("              			***  MENU MODIFICACION JUGADOR  ***                        \n");
	printf("\n");
	printf("1) Modificar nombre.\n");
	printf("2) Modificar apellido.\n");
	printf("3) Modificar ciudad de nacimiento.\n");
	printf("4) Modificar dia nacimiento.\n");
	printf("5) Modificar mes nacimiento.\n");
	printf("6) Modificar anio nacimiento.\n");
	printf("7) Modificar edad.\n");

	pedirEntero(&opcion, "\nIngrese opcion: ", "\nError. El numero ingresado no es valido: ", 1, 7);

	return opcion;
}

int menuSalida()
{
	int opcion;

	printf("Antes de salir desea...");
	printf("1) Limpiar la lista.\n");
	printf("2) Borrar la lista.\n");

	pedirEntero(&opcion, "\nIngrese opcion: ", "\nError. El numero ingresado no es valido: ", 1, 3);

	return opcion;
}

int menuOrdenamiento()
{
	int opcion;

	printf("\n¿Desea ordenar la lista por nombre o apellido?");
	printf("\n1) Nombre.");
	printf("\n2) Apellido.");

	pedirEntero(&opcion, "\nIngrese opcion: ", "\nError. El numero ingresado no es valido: ", 1, 2);

	return opcion;
}

int menuCriterioOrdenamiento()
{
	int opcion;

	printf("\n¿Como desea ordenar la lista?");
	printf("\n0) Descendente (Z-A).");
	printf("\n1) Ascendente (A-Z).");

	pedirEntero(&opcion, "\nIngrese opcion: ", "\nError. El numero ingresado no es valido: ", 0, 1);

	return opcion;
}
