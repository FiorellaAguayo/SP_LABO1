#include "LinkedList.h"
#ifndef PARSER_H_
#define PARSER_H_

#endif /* PARSER_H_ */

/**
 * @fn int parser_JugadoresDesdeTexto(FILE*, LinkedList*)
 * @brief Parsea los datos de los jugadores desde el archivo data.csv (modo texto).
 *
 * @param pFile Direccion de memoria del archivo.
 * @param pArrayListJugador puntero a la lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int parser_JugadoresDesdeTexto(FILE *pFile, LinkedList *pArrayListJugadores);
