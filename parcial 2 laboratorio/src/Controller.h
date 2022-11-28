
/**
 * @fn int controller_cargarJugadoresDesdeTexto(char*, LinkedList*)
 * @brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * @param path Nombre del archivo a cargar.
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_cargarJugadoresDesdeTexto(char *path, LinkedList *pArrayListJugador);

/**
 * @fn int controller_listarJugadores(LinkedList*)
 * @brief Listar jugadores.
 *
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_listarJugadores(LinkedList *pArrayListJugador);

/**
 * @fn int controller_agregarJugador(LinkedList*)
 * @brief Da de alta un jugador.
 *
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_agregarJugador(LinkedList *pArrayListJugador);

/**
 * @fn int controller_removerJugador(LinkedList*)
 * @brief Da de baja un jugador.
 *
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_removerJugador(LinkedList *pArrayListJugador);

/**
 * @fn int controller_editarJugador(LinkedList*)
 * @brief Modifica datos del jugador.
 *
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_editarJugador(LinkedList *pArrayListJugador);

/**
 * @fn int controller_buscarJugadorId(LinkedList*, int)
 * @brief Busca un jugador mediante su ID.
 *
 * @param this lista de jugadores
 * @param id ID del jugador a buscar
 * @return Retorna -1 si no existe el id y el indice si existe.
 */
int controller_buscarJugadorPorId(LinkedList *this, int id);

/**
 * \fn int controller_GenerarInforme(LinkedList*)
 * \brief Genera un informe con datos a partir de la lista.
 *
 * \param pArrayListJugador Puntero a lista de jugadores.
 * \return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_GenerarInforme(LinkedList *pArrayListJugador);

/**
 * @fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
 * @brief Guarda los datos de los jugadores en el achivo jugadores.csv (modo texto).
 *
 * @param path Nombre de archivo a cargar.
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador);

/**
 * @fn int controller_guardarJugadoresModoBinario(char*, LinkedList*)
 * @brief Guarda los datos de los jugadores en el achivo jugadores.csv (modo binario).
 *
 * @param path Nombre de archivo a cargar.
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_guardarJugadorModoBinario(char *path, LinkedList *pArrayListJugador);

/**
 * @fn int controller_ordenarJugadores(LinkedList*)
 * @brief  Ordena jugadores segun un criterio.
 *
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @return Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/**
 * @fn int controller_validarIdExistente(LinkedList*, int)
 * @brief Verifica si el ID ingresado existe.
 *
 * @param pArrayListJugador Puntero a lista de jugadores.
 * @param id ID ingresado por el usuario.
 * @return todoOk Retorna -1 si esta mal y 0 si esta bien.
 */
int controller_validarId(LinkedList *pArrayListJugador, int id);

/**
 * @fn void controller_guardarIdSiguiente(int)
 * @brief Guarda el ultimo ID utilizado en un archivo.txt
 *
 * @param id variable que guarda el ultimo id.
 */
void controller_guardarIdSiguiente(int idActual);

/**
 * @fn int controller_siguienteId()
 * @brief Calcula el siguiente ID para el siguiente jugador partiendo desde el ultimo.
 *
 * @return siguienteId Retorna el siguiente ID.
 */
int controller_siguienteId();

