#include "Animal.h"

Animal::Animal()
{
	numero = NULL;
	
}

Animal::Animal(string nombre)
{
	this->nombre = nombre;
	numero = NULL;

}

Animal::Animal(string nombre, int numero)
{
	this->nombre = nombre;
	this->numero = numero;

}



Animal::~Animal()
{


}

void Animal::mostrar()
{
	cout << "animal : " <<nombre << endl;
	cout << "numero : " <<numero << endl;

}

void Animal::mostrarT(Animal* p)
{
	if (p != NULL)
	{
		p->mostrar();
	}
	else { cout << " vacio " << endl; }

}



bool Animal::operator==(Animal* Animal)
{
	return nombre == Animal->nombre;
}

string Animal::getNombre()
{
	return nombre;
}

int Animal::getNum()
{
	return numero;
}

void Animal::setPeso(int num)
{
	numero = num;
}

void Animal::setNombre(string name)
{
	nombre = name;
}

bool Animal::compNumAsc(Animal* p1, Animal* p2)
{
	return p1->getNum() > p2->getNum();
}

bool Animal::compNumDesc(Animal* p1, Animal* p2)
{
	return p1->getNum() < p2->getNum();
}

bool Animal::operator>(Animal* animal)
{
	return numero > animal->numero;
}

bool Animal::operator<(Animal* animal)
{
	return numero < animal->numero;
}


