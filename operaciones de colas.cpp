/*
Perez Moreno Sergio Gabriel
Estructuras Computacionales
Operaciones de colas con listas enlazadas
Abril del 2022
*/
#include <iostream>
#include <conio.h>
#include <clocale>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipos de funciones
void insertar(Nodo *&, Nodo *&, int);
void mostrar(Nodo *, Nodo *);
void eliminar(Nodo *&, Nodo *&, int);

Nodo *frente = NULL;
Nodo *final = NULL;

int main()
{
	setlocale(LC_ALL, "spanish");
	int op, dato;
	do
	{
		cout<<"---MENÚ---"<<endl;
		cout<<"1. Insertar. "<<endl;
		cout<<"2. Eliminar. "<<endl;
		cout<<"3. Mostrar. "<<endl;
		cout<<"4. Salir. "<<endl;
		cout<<"¿Qué desea hacer? ";
		cin>>op;
		switch(op)
		{
			//case 1 para insertar elementos a la cola
			case 1:
				cout<<"Elemento a insertar: ";
				cin>>dato;
				insertar(frente, final, dato);
				cout<<"Elemento insertado correctamente. "<<endl;
				cout<<"\n";
				break;
			//case 2 para eliminar un elemento de la lista
			case 2:
				if(frente != NULL)
				{
					eliminar(frente, final, dato);
					cout<<"Elemento eliminado. "<<endl;
				}
				else
				{
					cout<<"No hay elementos que eliminar. "<<endl;
				}
				cout<<"\n";
				break;
			//case 3 para mostrar los elementos de la cola
			case 3:
				mostrar(frente, final);
				cout<<"\n";
				break;
				
			case 4:
				cout<<"Saliendo del programa... "<<endl;
				break;
				
			default:
				cout<<"Opción inválida. "<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(op != 4);
}

//Funcion para insertar elementos a la cola
void insertar(Nodo *&frente, Nodo *&final, int n)
{
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->siguiente = NULL;
	
	if(final == NULL)
	{
		frente = nuevo;
	}
	else
	{
		final->siguiente = nuevo;
	}
	final = nuevo;

}

//Funcion para eliminar los elementos de la cola
void eliminar(Nodo *&frente, Nodo *&final, int n)
{
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == final)
	{
		frente = NULL;
		final = NULL;
	}
	else
	{
		frente = frente->siguiente;
	}
	delete aux;
}

//Funcion para mostrar los elementos de la cola
void mostrar(Nodo *frente, Nodo *final)
{
	Nodo *nuevo = new Nodo();
	nuevo = frente;
	
	if(frente != NULL)
	{
		while(nuevo !=NULL)
		{
			cout<<nuevo->dato<<" - ";
			nuevo = nuevo->siguiente;
		}
	}
	else
	{
		cout<<"La cola está vacia. "<<endl;
	}
}
