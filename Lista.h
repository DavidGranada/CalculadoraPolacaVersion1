#pragma once
#include <iostream>       // std::cout
#include "ubica.h"
#include <thread>         // std::thread
#include "string"
#include<string.h>
#include <atomic>
#include<time.h>
using namespace::std;
template<class T>
class Lista
{
private:
	T Dato;
	Lista *adelante;
	Lista *atras;
public:
	Lista();
	Lista(T d);
	~Lista();
	Lista *getAdelante() { return this->adelante; };
	Lista *getAtras() { return this->atras; };
	void setAdelante(Lista *n) { this->adelante = n; };
	void setAtras(Lista *n) { this->atras = n; };
	T getDato() { return this->Dato; };
	void setDato(T a) { this->Dato = a; };

	int nElementos(Lista *);
	Lista * Insertar(Lista * cabeza, T entrada);
	void Mostrar(Lista *cabeza);
	void Borrar(Lista *lista);

};
template<class T>Lista<T>::Lista(T p)
{
	Dato = p;
	atras = adelante = NULL;
}

template<class T>Lista<T>::~Lista()
{
}
template<class T>Lista<T>* Lista<T>::Insertar(Lista * cabeza,T entrada) {
	
	Lista *nuevo, *aux, **cab = &cabeza;
	nuevo = new Lista(entrada);
	aux = (*cab);
	if ((*cab) == NULL){
		*cab = nuevo;
		nuevo->adelante = nuevo;
		nuevo->atras = nuevo;
		cabeza = *cab;
	}
	else{
		while (aux->adelante != (*cab)){	//Recorre hasta que aux->sig == cabeza
			aux = aux->adelante;
		}
		(cabeza)->atras = nuevo;
		aux->adelante = nuevo;		//Enlaza los nodos
		nuevo->atras = aux;
		nuevo->adelante = (cabeza);
		
	}
	return cabeza;
}

template<class T>void Lista<T>::Mostrar(Lista *cabeza)
{
	Lista *aux;
	aux = cabeza;
	if (cabeza == NULL)
		cout << "\n\tLista Vacia" << endl;
	else{
		do{
			cout << aux->Dato << " | " ;
			aux = aux->adelante;
		} while (aux != cabeza);		//Imprime hasta que sea != de cabeza
		cout << endl;
	}
}
template<class T> int Lista<T>::nElementos(Lista *cabeza)
{
	int i = 0;
	Lista *aux;
	aux = cabeza;
	if (cabeza == NULL)
		cout << "\n\tLista Vacia" << endl;
	else {
		do {
			i++;
			//cout << "Elemento " << i <<" : "<<aux->getDato()<< endl;
			aux = aux->adelante;
		} while (aux != cabeza);		//Imprime hasta que sea != de cabeza

	}
	return i;
}
template<class T>void Lista<T>::Borrar(Lista *cabeza)
{
	Lista *aux=cabeza;
	if (cabeza == NULL)
		;
	else 
		do {
			free(aux);
			aux = aux->adelante;
		} while (aux != cabeza);		//Imprime hasta que sea != de cabeza
		free(cabeza);
		cabeza = NULL;
}


