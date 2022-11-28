#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"
#include "LinkedList.h"

int controller_cargarJugadoresDesdeTexto(char *path, LinkedList *pArrayListJugador)
{
	int todoOk = -1;
	FILE *f;

	if (path != NULL && pArrayListJugador != NULL)
	{
		f = fopen(path, "r");

		if (f == NULL)
		{
			return todoOk;
		}
		else
		{
			parser_JugadoresDesdeTexto(f, pArrayListJugador);
			todoOk = 0;
		}
		fclose(f);
	}
	return todoOk;
}

int controller_listarJugadores(LinkedList *pArrayListJugador)
{
	int todoOk = -1, lenLista;
	Jugador *auxJugador = NULL;

	if (pArrayListJugador != NULL)
	{
		lenLista = ll_len(pArrayListJugador);
		if (lenLista > 0)
		{
			todoOk = 0;

			printf("\n-------------------------------------------------------------------------------------------\n");
			printf("| ID    |FECHA         | NOMBRE          | APELLIDO        | CIUDAD                  | EDAD |\n");
			printf("---------------------------------------------------------------------------------------------\n");

			for (int i = 0; i < lenLista; i++)
			{
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jugador_MostrarUnJugador(auxJugador);
			}
		}
	}
	else
	{
		jugador_delete(auxJugador);
	}
	return todoOk;
}

int controller_agregarJugador(LinkedList *pArrayListJugador)
{
	int todoOk = -1;
	int id;
	int dia;
	int mes;
	int anio;
	int edad;

	char nombreJugador[30];
	char apellidoJugador[30];
	char ciudadNacimiento[30];
	Jugador *unJugador;

	if (pArrayListJugador != NULL)
	{
		printf("\n>>>>>>>>>> ALTA JUGADOR");
		unJugador = jugador_new();
		if (unJugador != NULL)
		{
			id = controller_siguienteId();
			jugador_setId(unJugador, id);

			pedirCadena(nombreJugador, "\nIngrese nombre del jugador: ", "\nError. El nombre ingresado no es valido: ", 30);
			jugador_setNombreJugador(unJugador, nombreJugador);

			pedirCadena(apellidoJugador, "\nIngrese apellido del jugador: ", "\nError. El apellido ingresado no es valido: ", 30);
			jugador_setApellidoJugador(unJugador, apellidoJugador);

			pedirCadena(ciudadNacimiento, "\nIngrese ciudad del jugador: ", "\nError. La ciudad ingresada no es valida: ", 30);
			jugador_setCiudadNacimiento(unJugador, ciudadNacimiento);

			pedirEntero(&dia, "\nIngrese el dia de nacimiento (1-31): ", "\nError. El dia ingresado no es valido: ", 1, 31);
			jugador_setDia(unJugador, dia);

			pedirEntero(&mes, "\nIngrese el mes de nacimiento (1-12): ", "\nError. El mes ingresado no es valido: ", 1, 12);
			jugador_setMes(unJugador, mes);

			pedirEntero(&anio, "\nIngrese el anio de nacimiento (1980-2005): ", "\nError. El anio ingresado no es valido: ", 1980, 2005);
			jugador_setAnio(unJugador, anio);

			pedirEntero(&edad, "\nIngrese edad del jugador: ", "\nError. La edad ingresada no es valida: ", 1, 50);
			jugador_setEdad(unJugador, edad);

			printf("\n---------------------------------------------------------------------------------------------\n");
			printf("| ID    |FECHA         | NOMBRE          | APELLIDO        | CIUDAD                  | EDAD |\n");
			printf("---------------------------------------------------------------------------------------------\n");
			jugador_MostrarUnJugador(unJugador);

			ll_add(pArrayListJugador, unJugador);
			controller_guardarIdSiguiente(id);

			printf("\nAlta exitosa.\n");

			todoOk = 0;
		}
	}
	return todoOk;
}

int controller_removerJugador(LinkedList *pArrayListJugador)
{
	int todoOk = 0;
	int id;
	int indiceJugador;
	char respuesta;
	Jugador *unJugador;

	if (pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		do
		{
			pedirEntero(&id, "\nIngrese ID del jugador a dar de baja: ", "Error, Reingrese ID del jugador a dar de baja: ", 1, 1000);
		} while (controller_validarId(pArrayListJugador, id) != 0);

		indiceJugador = controller_buscarJugadorPorId(pArrayListJugador, id);

		if (indiceJugador == -1)
		{
			printf("El id ingresado no existe\n");
		}
		else
		{
			unJugador = ll_get(pArrayListJugador, indiceJugador);

			printf("\n---------------------------------------------------------------------------------------------\n");
			printf("| ID    |FECHA         | NOMBRE          | APELLIDO        | CIUDAD                  | EDAD |\n");
			printf("---------------------------------------------------------------------------------------------\n");
			jugador_MostrarUnJugador(unJugador);

			pedirCaracter(&respuesta, "\nSeguro que desea remover este jugador? (s: SI y n: NO): ",
					"\nError. Seguro que desea remover este jugador? (s: SI y n: NO): ", 's', 'n');

			if (respuesta == 's')
			{
				ll_remove(pArrayListJugador, indiceJugador);
				jugador_delete(unJugador);
				printf("\nBaja exitosa.\n");
				todoOk = 0;
			}
			else
			{
				printf("\nSe ha cancelado la baja.\n");
			}
		}
	}
	return todoOk;
}

int controller_editarJugador(LinkedList *pArrayListJugador)
{
	int todoOk = -1;
	int id;
	int dia;
	int mes;
	int anio;
	int indiceJugador;
	int edad;

	char nombreJugador[30];
	char apellidoJugador[30];
	char ciudadNacimiento[30];

	Jugador *unJugador;

	if (pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

		do
		{
			pedirEntero(&id, "\nIngrese ID del jugador a modificar: ", "Error, Reingrese ID del jugador a modificar: ", 1, 1000);
		} while (controller_validarId(pArrayListJugador, id) != 0);

		indiceJugador = controller_buscarJugadorPorId(pArrayListJugador, id);

		unJugador = ll_get(pArrayListJugador, indiceJugador);

		if (indiceJugador == -1)
		{
			printf("El id ingresado no existe\n");
		}
		else
		{
			printf("\n---------------------------------------------------------------------------------------------\n");
			printf("| ID    |FECHA         | NOMBRE          | APELLIDO        | CIUDAD                  | EDAD |\n");
			printf("---------------------------------------------------------------------------------------------\n");
			jugador_MostrarUnJugador(unJugador);

			switch (menuModificacion())
			{
			case 1:
				pedirCadena(nombreJugador, "\nIngrese nuevo nombre del jugador: ", "\nError. El nombre ingresado no es valido: ", 30);
				jugador_setNombreJugador(unJugador, nombreJugador);
				break;

			case 2:
				pedirCadena(apellidoJugador, "\nIngrese nuevo apellido del jugador: ", "\nError. El apellido ingresado no es valido: ", 30);
				jugador_setApellidoJugador(unJugador, apellidoJugador);
				break;

			case 3:
				pedirCadena(ciudadNacimiento, "\nIngrese nueva ciudad del jugador: ", "\nError. La ciudad ingresada no es valida: ", 30);
				jugador_setCiudadNacimiento(unJugador, ciudadNacimiento);
				break;

			case 4:
				pedirEntero(&dia, "\nIngrese el nuevo dia de nacimiento (1-31): ", "\nError. El dia ingresado no es valido: ", 1, 31);
				jugador_setDia(unJugador, dia);
				break;

			case 5:
				pedirEntero(&mes, "\nIngrese el nuevo mes de nacimiento (1-12): ", "\nError. El mes ingresado no es valido: ", 1, 12);
				jugador_setMes(unJugador, mes);
				break;

			case 6:
				pedirEntero(&anio, "\nIngrese el nuevo anio de nacimiento (1980-2005): ", "\nError. El anio ingresado no es valido: ", 1980, 2005);
				jugador_setAnio(unJugador, anio);
				break;

			case 7:
				pedirEntero(&edad, "\nIngrese nueva edad del jugador: ", "\nError. La edad ingresada no es valida: ", 1, 50);
				jugador_setEdad(unJugador, edad);
				break;
			}
			printf("\nModificacion exitosa\n");
			todoOk = 0;
		}
	}

	return todoOk;
}


int controller_siguienteId()
{
	FILE *f = fopen("ultimoId.txt", "r");
	int *idActual = (int*) malloc(sizeof(int));
	int siguienteId;

	if (f == NULL)
	{
		siguienteId = 101;
	}
	else
	{
		fscanf(f, "%d", idActual);
		siguienteId = *idActual + 1;
	}
	fclose(f);

	return siguienteId;
}

void controller_guardarIdSiguiente(int idActual)
{
	FILE *f = fopen("ultimoID.txt", "r+");

	if (f == NULL)
	{
		f = fopen("ultimoID.txt", "w");
	}

	fprintf(f, "%d", idActual);
	fclose(f);
}


int controller_validarId(LinkedList *pArrayListJugador, int id)
{
	int todoOk = -1, idEncontrado, lenLista;

	Jugador *unJugador;

	if (pArrayListJugador != NULL && id >= 0)
	{
		lenLista = ll_len(pArrayListJugador);

		for (int i = 0; i < lenLista; ++i)
		{
			unJugador = ll_get(pArrayListJugador, i);

			if (unJugador != NULL)
			{
				jugador_getId(unJugador, &idEncontrado);

				if (id == idEncontrado)
				{
					todoOk = 0;
					break;
				}
			}
		}
	}
	return todoOk;
}

int controller_buscarJugadorPorId(LinkedList *this, int id)
{
	int todoOk = -1, idComparar;
	Jugador *unJugador;

	if (this != NULL && id > 0)
	{
		for (int i = 0; i < ll_len(this); i++)
		{
			unJugador = ll_get(this, i);

			if (unJugador != NULL)
			{
				jugador_getId(unJugador, &idComparar);
				if (idComparar == id)
				{
					todoOk = i;
					break;
				}
			}
		}
	}
	return todoOk;
}


int controller_GenerarInforme(LinkedList *pArrayListJugador)
{
	int todoOk = -1;
	int lenLista;
	Jugador *auxJugador;
	int edad;
	char nombre[30];
	char ciudad[30];
	int contadorMayor25 = 0;
	int contadorMenor20 = 0;
	int contadorNombresA = 0;
	int contadorCiudadCordoba = 0;

	FILE *f;

	if (pArrayListJugador != NULL)
	{
		lenLista = ll_len(pArrayListJugador);

		if (lenLista > 0)
		{
			for (int i = 0; i < lenLista; i++)
			{
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jugador_getEdad(auxJugador, &edad);
				jugador_getNombreJugador(auxJugador, nombre);
				jugador_getCiudadNacimiento(auxJugador, ciudad);

				if (edad > 25)
				{
					contadorMayor25++;
				}

				if (edad < 20)
				{
					contadorMenor20++;
				}

				if (nombre[0] == 'A')
				{
					contadorNombresA++;
				}

				if (strcmp(ciudad, "Cordoba") == 0)
				{
					contadorCiudadCordoba++;
				}

			}
		}

		f = fopen("informeJugadores.txt", "w");

		fprintf(f, "********************\n");
		fprintf(f, "Informe de jugadores\n");
		fprintf(f, "********************\n");
		fprintf(f, "- Cantidad de jugadores mayor a 25 anios: %d\n", contadorMayor25);
		fprintf(f, "- Cantidad de jugadores menor a 20 anios: %d\n", contadorMenor20);
		fprintf(f, "- Cantidad de jugadores que empiecen por la letra A: %d\n", contadorNombresA);
		fprintf(f, "- Cantidad de jugadores que nacieron en ciudad de Cordoba: %d\n", contadorCiudadCordoba);

		fclose(f);

		printf("\nArchivo generado exitosamente.\n");

		todoOk = 0;
	}

	return todoOk;
}


int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador)
{
	int todoOk = -1;
	int id;
	int dia;
	int mes;
	int anio;
	int edad;

	char nombreJugador[30];
	char apellidoJugador[30];
	char ciudadNacimiento[30];

	Jugador *unJugador;
	FILE *f;

	if (path != NULL && pArrayListJugador != NULL)
	{
		f = fopen(path, "w");

		unJugador = jugador_new();

		fprintf(f, "id,fechaNacimiento,nombreJugador,apellidoJugador,ciudadNacimiento,edad\n");

		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			unJugador = ll_get(pArrayListJugador, i);
			if (unJugador != NULL)
			{
				jugador_getId(unJugador, &id);
				jugador_getNombreJugador(unJugador, nombreJugador);
				jugador_getApellidoJugador(unJugador, apellidoJugador);
				jugador_getCiudadNacimiento(unJugador, ciudadNacimiento);
				jugador_getDia(unJugador, &dia);
				jugador_getMes(unJugador, &mes);
				jugador_getAnio(unJugador, &anio);
				jugador_getEdad(unJugador, &edad);

				fprintf(f, "%d,%d/%d/%d,%s,%s,%s,%d\n", id, dia, mes, anio, nombreJugador, apellidoJugador, ciudadNacimiento, edad);

				todoOk = 0;
			}
		}

		fclose(f);

		printf("\nJugadores.csv (modo texto) guardado exitosamente.\n");
	}
	return todoOk;
}


int controller_guardarJugadorModoBinario(char *path, LinkedList *pArrayListJugador)
{
	int todoOk = -1;
	FILE *f;
	Jugador *unJugador;

	if (path != NULL && pArrayListJugador != NULL)
	{
		f = fopen(path, "wb");

		unJugador = jugador_new();

		if (unJugador != NULL)
		{
			for (int i = 0; i < ll_len(pArrayListJugador); i++)
			{
				unJugador = ll_get(pArrayListJugador, i);
				fwrite(unJugador, sizeof(Jugador), 1, f);
			}
			todoOk = 0;
		}
		fclose(f);
	}
	return todoOk;
}


int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int todoOk = -1;
	int criterio;

	LinkedList* listaClonada;

	if (pArrayListJugador != NULL)
	{
		listaClonada = ll_clone(pArrayListJugador);
		criterio = menuCriterioOrdenamiento();

		if(ll_isEmpty(listaClonada) == 0 && ll_containsAll(pArrayListJugador, listaClonada) == 1)
		{
			switch (menuOrdenamiento())
			{
				case 1:
					printf("\nantes sort");
					ll_sort(pArrayListJugador, jugador_OrdenamientoNombre, criterio);
					printf("\ndespues sort");
					controller_listarJugadores(listaClonada);
					printf(" \ndespeus listar");
					break;

				case 2:
					ll_sort(pArrayListJugador, jugador_OrdenamientoApellido, criterio);
					controller_listarJugadores(listaClonada);
					break;
			}
			todoOk = 0;
		}
		else
		{
			printf("La lista esta vacia y no se puede ordenar\n");
		}
		ll_deleteLinkedList(listaClonada);
	}
	return todoOk;
}
