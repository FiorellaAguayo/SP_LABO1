#include "LinkedList.h"
#ifndef jugador_H_
#define jugador_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
} eFecha;

//id,nombreJugador,apellidoJugador,ciudadNacimiento,altura,peso,fechaNacimiento
typedef struct
{
	int id;
	char nombreJugador[30];
	char apellidoJugador[30];
	char ciudadNacimiento[30];
	int edad;
	eFecha fechaNacimiento;
} Jugador;

#endif /* jugador_H_ */

/**
 * @fn Jugador* jugador_new()
 * @brief Funcion constructora para crear un nuevo jugador.
 *
 * @return Retorna el jugador creado si tuvo exito.
 */
Jugador* jugador_new();

/**
 * @fn Jugador* jugador_newParametros(char*, char*, char*, char*, char*, char*, char*, char*)
 * @brief Funcion constructora para crear un nuevo jugador a partir de parametros establecidos.
 *
 * @param idStr ID a cargar en el usuario pasado como cadena de caracteres.
 * @param nombreStr Nombre a cargar en el usuario pasado como cadena de caracteres.
 * @param apellidoStr Apellido a cargar en el usuario pasado como cadena de caracteres.
 * @param ciudadNacimientoStr ciudad a cargar en el usuario pasado como cadena de caracteres.
 * @param edadStr edad a cargar en el usuario pasado como cadena de caracteres.
 * @param diaStr dia a cargar en el usuario pasado como cadena de caracteres.
 * @param mesStr mes a cargar en el usuario pasado como cadena de caracteres.
 * @param anioStr anio a cargar en el usuario pasado como cadena de caracteres.
 * @return Retorna el jugador creado si tuvo exito.
 */
Jugador* jugador_newParametros(char *idStr, char *nombreJugadorStr, char *apellidoJugadorStr, char *ciudadNacimientoStr, char *edadStr, char *diaStr,
		char *mesStr, char *anioStr);

/**
 * @fn void jugador_delete()
 * @brief Libera la memoria ocupada por un jugador.
 *
 */
void jugador_delete(Jugador *this);

/**
 * @fn int jugador_setEdad(Jugador*, int)
 * @brief Carga el id del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param id id a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setId(Jugador *this, int id);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca el id del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param id id a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getId(Jugador *this, int *id);

/**
 * @fn int jugador_setNombreJugador(Jugador*, char*)
 * @brief Carga el nombre del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param nombreJugador nombre a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setNombreJugador(Jugador *this, char *nombreJugador);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca el nombre del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param nombre nombre a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getNombreJugador(Jugador *this, char *nombreJugador);

/**
 * @fn int jugador_setApellidoJugador(Jugador*, char*)
 * @brief Carga el apellido del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param apellidoJugador apellido a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setApellidoJugador(Jugador *this, char *apellidoJugador);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca el apellido del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param apellido apellido a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getApellidoJugador(Jugador *this, char *apellidoJugador);

/**
 * @fn int jugador_setCiudadNacimiento(Jugador*, char*)
 * @brief Carga la ciudad del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param ciudadNacimiento ciudad a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setCiudadNacimiento(Jugador *this, char *ciudadNacimiento);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca la ciudad de nacimiento del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param ciudad ciudad a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getCiudadNacimiento(Jugador *this, char *ciudadNacimiento);

/**
 * @fn int jugador_setEdad(Jugador*, int)
 * @brief Carga la edad del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param edad edad a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setEdad(Jugador *this, int edad);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca la edad del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param edad edad a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getEdad(Jugador *this, int *edad);

/**
 * @fn int jugador_setEdad(Jugador*, int)
 * @brief Carga el dia de nacimiento del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param dia dia a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setDia(Jugador *this, int dia);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca el dia de nacimiento del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param dia dia a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getDia(Jugador *this, int *dia);

/**
 * @fn int jugador_setMes(Jugador*, int)
 * @brief Carga el  mes de nacimiento del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param mes mes a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setMes(Jugador *this, int mes);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca el mes de nacimiento del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param mes mes a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getMes(Jugador *this, int *mes);

/**
 * @fn int jugador_setAnio(Jugador*, int)
 * @brief Carga el anio de nacimiento del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param anio anio a cargar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_setAnio(Jugador *this, int anio);

/**
 * @fn int jugador_getEdad(Jugador*, int*)
 * @brief Busca el anio de nacimiento del jugador.
 *
 * @param this Puntero a la lista de jugadores.
 * @param anio anio a buscar en el jugador.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int jugador_getAnio(Jugador *this, int *anio);

/**
 * @fn int jugador_MostrarUnJugador(Jugador*)
 * @brief Funcion que sirve para mostrar un solo jugador.
 *
 * @param unJugador puntero a la lista de jugadores.
 */
int jugador_MostrarUnJugador(Jugador *this);

int jugador_OrdenamientoNombre(void *unJugador, void *otroJugador);

int jugador_OrdenamientoApellido(void *unJugador, void *otroJugador);
