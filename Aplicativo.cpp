/*
=======================================================
UNIVERSIDAD DE LAS FUERZAS ARMADAS - "ESPE"
=======================================================
Departamento Ciencias De La Computación
=======================================================
Tema:			PILAS
Carrera:		Ingeniería en Sistemas
Docente:		Ing. Fernando Solis
Integrantes:	Granada David
Conejo Ivan
Francisco Sampedro
=======================================================
Fecha Creación:		18/12/2017
Fecha Modificación:	18/12/2017
=======================================================
Calculadora Polaca CON PILAS
=======================================================
*/
#include"Polaca.h"
int n = 0;
const string space = "                                                       ";
#include"Header.h"
void ReadCin(std::atomic<bool>& run)
{
	std::string buffer;
	std::string cadena;
	char buf;
	Polaca poly = Polaca();
	while (run.load())
	{	
		gotoxy(0, 9);
		cout << "Ingrese una expresion: ";
		buffer = _getch();
		buf = buffer[0];
		gotoxy(n, 10);
		if (poly.isNumb(buf) || poly.isSig(buf) || buf=='(' || buf == ')')
		{
			cadena.insert(cadena.length(), buffer);
			cout << buffer;
			n++;
		}
		else if(buf == 13)
		{
			gotoxy(n, 11);
			poly.obExpression(cadena);
			poly.getExpression()->Mostrar(poly.getExpression());
			poly.evaluar(poly.getExpression());
			_getch();
			system("cls");
			n = 0;
			cadena = "";
			poly = Polaca();
		}
		else if (buf == 112)
			system("help.chm");
		else if (buf == 27)
		{
			gotoxy(n, 11);
			cout << "SALIENDO...";
			run.store(false);
		}
		else if (buf == 8)
		{
			gotoxy(--n, 10);
			puts(" ");
			if (cadena.length() > 0)cadena.erase(cadena.length() - 1);
		}
		
	

	}
}

int main()
{
	//imagen("espe.png");
	std::atomic<bool> run(true);
	std::thread cinThread(ReadCin, std::ref(run));
	system("cls");
	gotoxy(0, 9);
	wcout << "Ingrese una expresion: ";

	while (run.load())
	{
		for (int i = 0; i<70; i++)
		{
			gotoxy(i, 1);
			puts(" UNIVERSIDAD DE LAS FUERZAS ARMADAS - 'ESPE'                                                                ");
			Sleep(50);
		}// main loop2
	}

	run.store(false);
	cinThread.join();

	return 0;
}