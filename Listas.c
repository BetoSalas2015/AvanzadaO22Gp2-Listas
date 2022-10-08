//   Sesión 18 - 26/09/2022
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

void insert( char dato )
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
}

void insertn( char dato, int n )
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
}

void insert1( char dato )
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
}

char remueve()
{
	char dato;
	nodo *recorre = raiz;
	if( raiz == NULL)
	{
		printf("La lista esta vacía: no hay nada que remover\n");
		pausa;
		return '\0';
	}
	if( recorre->sig == NULL)		//  LA listaligada es de un solo nodo?
	{
		dato = raiz->info;			//  Preservo el dato a borrar
		raiz = NULL;				//  Vaciamos la lista
		free(recorre);				//  Liberamos memoria reservada por malloc()
		return dato;				//  Reresamos el dato sacado de la lista.
	}
	else
	{
		nodo *ultimo = recorre->sig;
		while( ultimo->sig != NULL )
		{
			recorre = recorre->sig;	//  alternatrivo: recorre = ultimo
			ultimo = ultimo->sig;	//  alternativo: ultimo = recorre->sig
		}
		dato = ultimo->info;
		recorre->sig = NULL;		// Se vuelve el último nodo de la lista 
		free(ultimo);
		return dato;
	}
}


void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre != NULL)		//  Estoy posicionado en el ultimo nodo
	{
		printf("%c, ", recorre->info);
		recorre = recorre ->sig;
	}
	putchar('\n');
}

int main()
{
	system("color 1E");
	
	imprimeLista();
	
	insert1('R');
	insert1('o');
	insert1('b');
	insert1('e');
	insert1('r');
	insert1('t');
	insert1('o');
	insertn('x', 3);

	imprimeLista();

	printf("El dato quie sale es: %c\n", remueve() );

	imprimeLista();

	pausa;
	
	return 0;
}