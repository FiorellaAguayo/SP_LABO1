#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "inputs.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout, NULL);

	char seguir = 's';
	int flag = 0;

	LinkedList *listaJugadores = ll_newLinkedList();

	do
	{
		switch (menu())
		{
			case 1: //CARGA DE ARCHIVOS
				if (controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores) != 0)
				{
					printf("Ha ocurrido un error al cargar el archivo\n");
				}
				else
				{
					printf("Archivo cargado correctamente\n");
					flag = 1;
				}
				break;

			case 2: //ALTA DE JUGADOR
				if(flag)
				{
					if (controller_agregarJugador(listaJugadores) != 0)
					{
						printf("\nHubo un problema en el alta.\n");
					}
				}
				else
				{
					printf("\nPrimero debes cargar el archivo!!\n");
				}
				break;

			case 3: //BAJA DE JUGADOR
				if(flag)
				{
					if (controller_removerJugador(listaJugadores) != 0)
					{
						printf("\nHubo un problema en la baja.\n");
					}
				}
				else
				{
					printf("\nPrimero debes cargar el archivo!!\n");
				}
				break;

			case 4: //MODIFICACION DE JUGADOR
				if(flag)
				{
					if (controller_editarJugador(listaJugadores) != 0)
					{
						printf("\nHubo un problema en la modificacion.\n");
					}
				}
				else
				{
					printf("\nPrimero debes cargar el archivo!!\n");
				}
				break;

			case 5: //GENERAR INFORME DE JUGADORES
				if(flag)
				{
					if (controller_GenerarInforme(listaJugadores) != 0)
					{
						printf("\nHubo un problema al generar informe.\n");
					}
				}
				else
				{
					printf("\nPrimero debes cargar el archivo!!\n");
				}
				break;

			case 6: //GUARDAR EN MODO TEXTO
				if(flag)
				{
					if (controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) != 0)
					{
						printf("\nHubo un problema al guardar archivo.csv en modo texto.\n");
					}
				}
				else
				{
					printf("\nPrimero debes cargar el archivo!!\n");
				}
				break;
			case 7: //GUARDAR EN MODO BINARIO
				if(flag)
				{
					if (controller_guardarJugadorModoBinario("jugadores.bin", listaJugadores) != 0)
					{
						printf("\nHubo un problema al guardar archivo.bin en modo binario.\n");
					}
					else
					{
						printf("\nJugadores.bin (modo binario) guardado exitosamente.\n");
					}
				}
				else
				{
					printf("\nPrimero debes cargar el archivo!!\n");
				}
				break;

			case 8: //LISTAR JUGADORES
				if(flag)
				{
					//controller_sortEmployee(listaJugadores);
					controller_ordenarJugadores(listaJugadores);
				}
				else
				{
					printf("\nPrimero debes cargar el archivo!!\n");
				}
				break;

			case 9: //SALIR
				if(flag)
				{
					switch(menuSalida())
					{
						case 1:
							ll_clear(listaJugadores);
							break;

						case 2:
							ll_deleteLinkedList(listaJugadores);
							break;

						case 3:
							break;
					}
				}
				seguir = 'n';
				printf("\nGracias por utilizar este programa, adios!\n");
				break;
			}
	} while (seguir == 's');

	return 0;
}

