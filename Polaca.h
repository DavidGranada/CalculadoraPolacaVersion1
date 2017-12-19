#pragma once
#include"Operaciones.h"
class Polaca
{
public:
	bool isSigF(float a);
	char sig(float a);
	bool isNumbF(float a);
	void nte( Lista<float> *, Lista<float>*);
	void evaluar(Lista<float> * );
	bool isNumb(char a);
	bool isSig(char a);
	Lista<float> *obExpression(string);
	Polaca();
	~Polaca();

	Lista<float> *getExpression() { return this->expression; };
	void setExpresion(Lista<float> * l) { this->expression = l; };

private:
	Lista<float> *expression = NULL;
	Lista<float> *pila = NULL;

};

Polaca::Polaca()
{
}

Polaca::~Polaca()
{
}

bool Polaca::isSigF(float a)
{
	return (a == 42 * 100000000000 || a == 43 * 100000000000 || a == 45 * 100000000000 || a == 47 * 100000000000);
}
char Polaca::sig(float a)
{
	return (a == 42 * 100000000000) ? '*' : a == 43 * 100000000000 ? '+' : a == 45 * 100000000000 ? '-' : a == 47 * 100000000000 ? '/' : '0';
}
bool Polaca::isNumbF(float a)
{
	//stoi(a, nullptr, 0);
	return a < 42 * 100000000000 && a>-100000000000;

}
bool Polaca::isSig(char a)
{
	return (a == 42 || a == 43 || a == 45 || a == 47);
}
bool Polaca::isNumb(char a)
{
	return (a >= 48 && a <= 57);
}


Lista<float>* Polaca::obExpression(string in)
{
	bool flag;

	char *acum = new char[9];
	int num;
	for (int i = 0, k = 0, pos = 0; i < in[i] != '\0'; i++, k = 0)
	{
		acum = new char[9];
		if (in[i] == '(')
			for (int j = i + 1;; j++)
			{
				if (j == in.length())
				{
					cout << "Error de sintaxis" << endl;
					i = j;
					return NULL;
				}
				else if (isNumb(in[j]))
				{
					*(acum + k) = in[j];
					k++;
					i++;
				}
				else if (in[j] == ')')
				{

					break;
				}
			}
		else if (in[i] == ')')continue;
		else if (isSig(in[i]))
		{
			expression = expression->Insertar(expression, in[i] * 100000000000);
			continue;

		}
		else if (isNumb(in[i]))
		{
			*(acum + k) = in[i];
		}
		expression = expression->Insertar(expression, atof(acum));
	}
	return this->expression;
}



void Polaca::evaluar(Lista<float> * asd)
{

	Lista<float> *aux;
	Lista<float> *temp;
	Lista<float>*cabeza=NULL;
	aux = asd;
	if (asd == NULL)
		cout << "\n\tExpression Vacia" << endl;
	else {
		do 
		{
			//------------------------------------------------------
			if (isNumbF(aux->getDato()))
			{

				pila = pila->Insertar(pila, aux->getDato());
				pila = pila->getAtras();
				if (pila->nElementos(pila) == 1)
					cabeza = pila;
				;
			}	
			else
			{
				if (isSigF(aux->getDato())/* && aux->getAtras()->getAtras() != asd && aux->getAtras() != asd*/)
				{
					//cout << "Evaluando Operacion: " << sig(aux->getDato())<<endl;
					pila = pila->getAdelante();
					if (pila->getAdelante() != cabeza)
						pila = cabeza->getAtras();//controla q estemos al ultimo
					pila->Mostrar(pila->getAdelante());

					if (pila->nElementos(pila) > 2)
					{		
						operation *op = (new operation('+', sig(aux->getDato()), pila->getDato(), pila->getAtras()->getDato()));
						op->print();
						temp = pila->getAtras();//temporal para reemplazar los valores
						temp->setAdelante(cabeza);//
						temp->setAtras(pila->getAtras()->getAtras());
						temp->setDato(op->valor());
						pila = temp->getAtras();
						

					}
					else if ((pila->nElementos(pila) == 2))
					{
						operation *op = (new operation('+', sig(aux->getDato()), pila->getAtras()->getDato(), pila->getDato() ));
						op->print();
						pila = NULL;
						pila->Borrar(pila);
						pila=pila->Insertar(pila, op->valor());
						cabeza = pila;
						pila = pila->getAdelante();
						
					}
					else
					{
						cout << "Error de sintaxis" << endl;
						return;

					}
					
				}
			}
			aux = aux->getAdelante();
		} while (aux != asd);		
		cout << endl;
	}

	if (pila->nElementos(pila) == 1)
		cout << "Resultado: " << pila->getDato() << endl;
	else
	{
		cout << "Expresion Ingresada cuestionable" << endl;
	}
	//expression->Borrar(expression);
}

