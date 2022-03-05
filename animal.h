#pragma once
#include <iostream>
using namespace std;
class Animal
{


private:
	string nombre;
	int numero;


public:
	Animal();
	Animal(string nombre);
	Animal(string nombre, int numero);
	
	~Animal();
	void mostrar();
	static void mostrarT(Animal* p);
	bool operator==(Animal* Animal);
	string getNombre();
	int getNum();

	void setPeso(int num);
	void setNombre(string name);


	static bool compNumAsc(Animal* p1, Animal* p2);
	static bool compNumDesc(Animal* p1, Animal* p2);


	bool operator>(Animal* animal);
	bool operator<(Animal* animal);













};

