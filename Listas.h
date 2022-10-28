#include <stdio.h>			//  Para la I/O de programa
#include <stdlib.h>			//  Para las rutinas de utilería
#include <malloc.h>			//  Para la memoria dinámica

#define pausa system("pause")
#define cls	system("cls")

struct Nodo 
{ 
	char info; 
	struct Nodo *sig; 
};

typedef struct Nodo nodo;

nodo *raiz = NULL;				// Creamos la lista vacía o Nula

nodo *insert( nodo *raiz, char dato )
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )					// Ya no hay memoria disponible
	{
		printf("No hay memoria diponible (error 1) ");
		pausa;
		exit(1);				//  Terminamos la ejecucion del programa
	}
	nuevo->info = dato;			//  Preservo la información en la lista ligada
	nuevo->sig = NULL;
	if( raiz == NULL )			//  La lista está vacia?
	{							// Si, está vacía
		raiz = nuevo;			//  Raiz apunta al nodo creado
		// raiz->sig = NULL;	//	El nodo agregado se vuelve el ultimo
	}
	else						// Nom la lista no esta vacía
	{
		nodo *recorre = raiz;
		while( recorre->sig != NULL)		//  Estoy posicionado en el ultimo nodo
		{
			recorre = recorre ->sig;
		}
		recorre->sig = nuevo;		// Inserto el nuevo nodo en la lista
	}
	return raiz;
}

nodo *insertn( nodo *raiz, char dato, int n )
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )					// Ya no hay memoria disponible
	{
		printf("No hay memoria diponible (error 1) ");
		pausa;
		exit(1);		//  Terminamos la ejecucion del programa
	}
	nuevo->info = dato;		//  Preservo la información en la lista ligada
	nuevo->sig = NULL;
	if( raiz == NULL )		//  La lista está vacia?
	{							// Si, está vacía
		raiz = nuevo;			//  Raiz apunta al nodo creado
		// raiz->sig = NULL;	//	El nodo agregado se vuelve el ultimo
		return raiz;
	}
	if( n == 1)
	{
		nuevo->sig = raiz;
		raiz = nuevo;
	}
	else					// Nom la lista no esta vacía
	{
		int cont = 1;
		nodo *recorre = raiz;
		while( recorre->sig != NULL && cont < n - 1)		//  Estoy posicionado en el ultimo nodo
		{
			recorre = recorre ->sig;
			cont++;
		}
		nuevo->sig = recorre->sig;
		recorre->sig = nuevo;		// Inserto el nuevo nodo en la lista
	}
	return raiz;
}

nodo *insert1( nodo *raiz, char dato )
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )					// Ya no hay memoria disponible
	{
		printf("No hay memoria diponible (error 1) ");
		pausa;
		exit(1);		//  Terminamos la ejecucion del programa
	}
	nuevo->info = dato;		//  Preservo la información en la lista ligada
	nuevo->sig = raiz;
	raiz = nuevo;			//  Raiz apunta al nodo creado
	return raiz;
}

nodo *remueve(nodo *raiz,char *dato)
{
	nodo *recorre = raiz;
	if( raiz == NULL)
	{
		printf("La lista esta vacía: no hay nada que remover\n");
		pausa;
		return NULL;
	}
	if( recorre->sig == NULL)		//  LA listaligada es de un solo nodo?
	{
		*dato = raiz->info;			//  Preservo el dato a borrar
		raiz = NULL;				//  Vaciamos la lista
		free(recorre);				//  Liberamos memoria reservada por malloc()
		return raiz;				//  Reresamos el dato sacado de la lista.
	}
	else
	{
		nodo *ultimo = recorre->sig;
		while( ultimo->sig != NULL )
		{
			recorre = recorre->sig;	//  alternatrivo: recorre = ultimo
			ultimo = ultimo->sig;	//  alternativo: ultimo = recorre->sig
		}
		*dato = ultimo->info;
		recorre->sig = NULL;		// Se vuelve el último nodo de la lista 
		free(ultimo);
		return raiz;
	}
}

char remueven(int n)
{
	char dato;
	nodo *recorre = raiz;
	if( raiz == NULL)
	{
		printf("La lista esta vacía: no hay nada que remover\n");
		pausa;
		return '\0';
	}
	if( n == 1)		//  LA lista ligada es de un solo nodo?
	{
		dato = raiz->info;			//  Preservo el dato a borrar
		raiz = recorre->sig;				//  Vaciamos la lista
		free(recorre);				//  Liberamos memoria reservada por malloc()
		return dato;				//  Reresamos el dato sacado de la lista.
	}
	else
	{
		int cont = 1;
		nodo *ultimo = recorre->sig;
		while( ultimo->sig != NULL && cont < n - 1 )
		{
			recorre = recorre->sig;	//  alternatrivo: recorre = ultimo
			ultimo = ultimo->sig;	//  alternativo: ultimo = recorre->sig
			cont++;
		}
		if(cont < n - 1)
		{
			printf("No existe el elemento a remover. \n");
			pausa;
			return '\0';
		}
		dato = ultimo->info;
		recorre->sig = ultimo->sig;		// Se vuelve el último nodo de la lista 
		free(ultimo);
		return dato;
	}
}

char remueve1()
{
	char dato;
	nodo *recorre = raiz;
	if( raiz == NULL)
	{
		printf("La lista esta vacía: no hay nada que remover\n");
		pausa;
		return '\0';
	}
	dato = raiz->info;			//  Preservo el dato a borrar
	raiz = recorre->sig;				//  Vaciamos la lista
	free(recorre);				//  Liberamos memoria reservada por malloc()
	return dato;				//  Reresamos el dato sacado de la lista.
}

void imprimeLista(nodo  *raiz)
{
	nodo *recorre = raiz;
	while( recorre != NULL)		//  Estoy posicionado en el ultimo nodo
	{
		printf("%c, ", recorre->info);
		recorre = recorre ->sig;
	}
	putchar('\n');
}
