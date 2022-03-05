
#include "list7.h"
#include "animal.h"
#include <fstream>




void testReadFromFile()
{


	Animal animal("Animal", 1);

	string filename("10000_Numero.txt");
	int number;
	List7<Animal> animales;
	ifstream file;
	file.open(filename);
	while (!file.eof())
	{
		file >> number;
		animales.insertFront(new Animal ("animal", number));

	}

	animales.mostrar(Animal::mostrarT);
	cout << "mayor" << endl;
	animales.findMinor(Animal::compNumAsc)->mostrar();

	cout << "menor" << endl;
	animales.findMinor(Animal::compNumDesc)->mostrar();



}




void test2() {
	List7<Animal> animales;

	animales.insertFront(new Animal("perro", 1));
	animales.insertFront(new Animal("gato", 2));
	animales.insertFront(new Animal("loro", 3));
	animales.mostrar(Animal::mostrarT);


	animales.deleteFront();
	cout << "after deleting" << endl;
	animales.mostrar(Animal::mostrarT);






}
void test3()
{
	List7<Animal> animales;

	animales.insertFront(new Animal("perro", 1));
	animales.insertFront(new Animal("gato", 2));
	animales.insertFront(new Animal("loro", 3));
	//animales.mostrar(Animal::mostrarT);


	//animales.findInPos(1)->mostrar();
	//animales.findRec(new Animal("loro", 3))->mostrar();
	animales.findNotRec(new Animal("loro", 3))->mostrar();


}
void test4()
{
	List7<Animal> animales;

	animales.insertBack(new Animal("perro", 1));
	animales.insertBack(new Animal("gato", 2)); // working
	animales.insertBack(new Animal("loro", 3));
	animales.mostrar(Animal::mostrarT);

	//animales.deleteFront();
	animales.deleteBack();
	cout << "after deleting" << endl;
	animales.mostrar(Animal::mostrarT);



}
void testDefensa()
{
	List7<Animal> animales;

	Animal animalBuscado("loro", 3);

	animales.insertFront(new Animal("perro", 1));
	animales.insertFront(new Animal("gato", 2));
	animales.insertFront(new Animal("loro", 3));
	animales.insertFront(new Animal("mono", 4));
	animales.insertFront(new Animal("pez", 5));

	animales.mostrar(Animal::mostrarT);

	animales.deleteElem3(&animalBuscado);

	cout << "after deleting" << endl;

	animales.mostrar(Animal::mostrarT);
}


int main()
{
	//test2();

	//test4();
	//test3();
	
	//testReadFromFile();
	
	testDefensa();
	return 0;



}

