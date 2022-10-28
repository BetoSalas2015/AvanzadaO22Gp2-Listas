//   Sesión 25 - 12/10/2022
#include "Listas.h"

int main()
{
	nodo *nombre = NULL;
	nodo *apellido = NULL;
	char letra;
	system("color 1E");
	
	imprimeLista(nombre);
	imprimeLista(apellido);
	
	nombre = insert(nombre, 'R');
	nombre = insert(nombre, 'o');
	nombre = insert(nombre, 'b');
	nombre = insert(nombre, 'e');
	nombre = insert(nombre, 'r');
	nombre = insert(nombre, 't');
	nombre = insert(nombre, 'o');

	apellido = insert1(apellido, 'S');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'l');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'z');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'r');
	
	apellido = insertn(apellido, 'x', 3);

	imprimeLista(nombre);
	imprimeLista(apellido);

	apellido = remueve(apellido, &letra);
	printf("El dato quie sale es: %c\n",  letra);

	imprimeLista(apellido);

	pausa;
	
	return 0;
}