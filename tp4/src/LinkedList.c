#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if (this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node *node;
	int i;
	int length = ll_len(this);
	node = NULL;
	if (this != NULL && nodeIndex < length && nodeIndex >= 0)
	{
		node = this->pFirstNode;
		for (i = 0; i < nodeIndex; i++)
		{
			node = node->pNextNode;
		}
	}

    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *prevNode;
	int returnAux = -1;
	int length = ll_len(this);

	if (this != NULL && nodeIndex <= length && nodeIndex >= 0 && newNode != NULL)
	{
		newNode->pElement = pElement; // se guarda el elemento en el nodo

		if (nodeIndex == 0) // si esta al principio
		{
			newNode->pNextNode = this->pFirstNode;
			this->pFirstNode = newNode;
		}
		else
		{
			if (length == nodeIndex)
			{
				prevNode = getNode(this, nodeIndex - 1);
				newNode->pNextNode = NULL;
				prevNode->pNextNode = newNode;
			}
			else
			{
				prevNode = getNode(this, nodeIndex - 1);
				newNode->pNextNode = prevNode->pNextNode;
				prevNode->pNextNode = newNode;
			}
		}

		this->size += 1;
		returnAux = 0;
	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int length = ll_len(this);
    int returnAux = -1;

    if (this != NULL)
    {
    	addNode(this, length, pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	Node *node;
	int length = ll_len(this);
    void* returnAux = NULL;
    // si la LinkedList no es nula, el index es menor al tamaño maximo de la lista y el index es mayor a 0
    if (this != NULL && index < length && index >= 0)
    {
    	node = getNode(this, index); // obtengo el nodo buscando por el index
    	returnAux = node->pElement; // devuelvo el elemento buscado
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	Node *node;
    int returnAux = -1;
    int length = ll_len(this);

    if (this != NULL && index < length && index >= 0)
    {
    	node = getNode(this, index);
    	node->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	Node *node;
	Node *prevNode;
    int returnAux = -1;
	int length = ll_len(this);

	if (this != NULL && index < length && index >= 0)
	{
		node = getNode(this, index);
		prevNode = getNode(this, index - 1);
		if (node != NULL)
		{
			if (index == 0) // si es la primera posicion
			{
				// el head pasa a ser el nodo siguiente al nodo que se elimina
				this->pFirstNode = node->pNextNode;
			}
			else
			{
				if (index == length)
				{
					// el nodo queda en null
					node = NULL;
				}
				else
				{
					// el siguiente nodo del prevNode pasa a ser el siguiente del nodo borrado
					prevNode->pNextNode = node->pNextNode;
				}
			}
		}
		// desasigna el bloque de memoria ocupado por el nodo
		free(node);
		this->size -= 1;
		returnAux = 0;
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if (this != NULL)
    {
		int length = ll_len(this);
    	for (i = 0; i < length; i++)
    	{
    		//recorro toda la lista y elmino siempre la primera posicion
    		returnAux = ll_remove(this, 0);
    	}

    	/*for (i = length - 1; i >= 0; i--)
    	{
    		// elimino los elementos de la lista de forma inversa
    		returnAux = ll_remove(this, i);
    	}*/
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	returnAux = ll_clear(this);
    	free(this);
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int length;
    void *element;

    if (this != NULL)
    {
		 length = ll_len(this);
		 for (i = 0; i < length; i ++)
		 {
			 element = ll_get(this, i);
			 if (element == pElement)
			 {
				 returnAux = i;
				 break;
			 }
		 }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
		returnAux = 1; // si esta vacia
    	if (ll_len(this) > 0) // si es mayor a 0
    	{
    		returnAux = 0; // no esta vacia
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int length = ll_len(this);
    if (this != NULL && index <= length && index >= 0)
    {
		addNode(this, index, pElement);
		returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int length = ll_len(this);
    void *pElement;

    if (this != NULL && index < length && index >= 0)
    {
    	pElement = ll_get(this, index);
    	if (pElement != NULL)
    	{
    		if (ll_remove(this, index) == 0)
    		{
    			returnAux = pElement;
    		}
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this != NULL)
    {
    	returnAux = 0;
    	if (ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int length;
    int i;
    if (this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	length = ll_len(this2);
    	for (i = 0; i < length; i++)
    	{
    		//Si el elemento en la lista no existe...
    		if(ll_contains(this, ll_get(this2, i)) == 0)
    		{
    			returnAux = 0;
    			//termina la iteracion
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int length = ll_len(this);
    void *pElement;
    if (this != NULL && from >= 0 && from < length && to > from && to <= length)
    {
    	cloneArray = ll_newLinkedList(); // crea una nueva linkedList
    	if (cloneArray != NULL)
    	{
			for (i = from; i < to; i++)
			{
				pElement = ll_get(this, i);
				// añado el los elementos especificados a la nueva lista
				ll_add(cloneArray, pElement);
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int length = ll_len(this);

    if (this != NULL)
    {
    	cloneArray = ll_subList(this, 0, length);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int length = ll_len(this);
    void *elementI;
    void *elementJ;
    void *auxElement;
    int i;
    int j;

    if (this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	for (i = 0; i < length-1; i++)
    	{
    		for (j = i+1; j < length; j++)
    		{
    			elementI = ll_get(this, i);
    			elementJ = ll_get(this, j);

    			// order = 1; !order = 0;
    			if ((pFunc(elementI, elementJ) == 1 && order) || (pFunc(elementI, elementJ) == -1 && !order))
    			{
    				auxElement = elementI; // guarda el elemento en i
    				ll_set(this, i, elementJ); // el elemento en i es igual al elemento en j
    				ll_set(this, j, auxElement); // el elemento en j es igual al elemento guardado en el auxiliar
    			}
    		}
    	}
    	returnAux = 0;
    }

    return returnAux;

}

