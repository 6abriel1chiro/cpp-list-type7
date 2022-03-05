#pragma once
#include "node.h"
#include "emptyListException.h"
template<class T>
class List7
{
public:
	List7();
	~List7();


	void insertFront(T* elem);
	//void insertFront2(T elem);
	void insertBack(T* elem);
	void mostrar(void (*mostrarT)(T*));
	void deleteFront();
	void deleteBack();
	T* findNotRec(T* elem);
	T* findRec(T* elem);
	T* recorridoRec(T* elem, node<T>* aux);
	T* findMinor(bool(*funcComp)(T*, T*));
	T* findMajor(bool(*funcComp)(T*, T*));

	T* findInPos(int pos);

	void deleteByElement(T* dato);


	bool deleteElem(T* dato);
	bool deleteElem2(T* dato);

	void deleteElem3(T* dato);



private:

	node<T>* first;
	node<T>* last;
	int index;


};
template<class T>
List7<T>::List7()
{
	 index = 0;
	first = NULL;
	last = NULL;
}
template<class T>
List7<T>::~List7()
{

	node<T>* aux;
	while (first != NULL)
	{
		if (first == last)
		{
			delete first;
			last = NULL;
			first = NULL;
		}
		else
		{
			aux = first->getNext();
			delete first;
			first = aux;
		}
	}
}

template<class T>
inline void List7<T>::insertFront(T* elem)
{
	if (first == NULL)
	{
		first = new node<T>(elem);
		last = first;
		index++;
	}
	else
	{
		node<T>* aux = first;
		first = new node<T>(elem);
		first->createNext(aux);
		index++;

	}

}



template<class T>
inline void List7<T>::insertBack(T* elem)
{
	if (first == NULL and last==NULL )
	{
		first = new node<T>(elem);
		last = first;
		index++;

	}
	else
	{
		node<T>* aux = last;
		last = new node<T>(elem);
		aux->createNext(last);
		index++;

	}


}

template<class T>
inline void List7<T>::mostrar(void(*mostrarT)(T*))
{
	if (first == NULL && last == NULL)
	{
		throw emptyListException ();
	}
	else
	{
		node<T>* aux = first;
		while (aux != NULL)
		{
			(*mostrarT)(aux->getElement());
			aux = aux->getNext();
		}
	}
}

template<class T>
inline void List7<T>::deleteFront()
{

	if (first == NULL )
	{
		throw emptyListException();
	}
	if (first == last)
	{
		delete first;
		last = NULL;
		first = NULL;
		index = 0;
	}
	else
	{
		node<T>* aux = first->getNext();
		delete first;
		first = aux;
		index--;

		//first->createNext(NULL);
	}
}

template<class T>
inline void List7<T>::deleteBack()
{

	if (first == NULL)
	{
		throw emptyListException();
	}
	if (first == last)
	{
		delete first;
		last = NULL;
		first = NULL;
		index = 0;

	}
	else
	{
		node<T>* aux = first;
		while (aux->getNext()->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		delete last;
		last = aux;
		last->createNext(NULL);

	}
}

template<class T>
inline T* List7<T>::findNotRec(T* elem)
{
	node<T>* aux = first;
	T* datoEncontrado = NULL;
	while (aux != NULL)
	{
		if (*aux->getElement() == elem)
		{
			datoEncontrado = aux->getElement();
		}
		aux = aux->getNext();
	}
	return datoEncontrado;
}

template<class T>
inline T* List7<T>::findRec(T* elem)
{
	node<T>* aux = first;
	return recorridoRec(elem, aux);
}

template<class T>
inline T* List7<T>::recorridoRec(T* elem, node<T>* aux)
{
	if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		if (*aux->getElement() == elem)
		{
			return aux->getElement();
		}
		else
		{
			return recorridoRec(elem,	aux->getNext());
		}
	}
}

template<class T>
inline T* List7<T>::findMinor(bool(*funcComp)(T*, T*))
{
	if (first == NULL && last == NULL)
	{
		throw emptyListException();
	}
	T* menor = first->getElement();
	node<T>* aux = first->getNext();

	while (aux == NULL)
	{
		if ((*funcComp)(aux->getElement(), menor))
		{
			menor = aux->getElement();
		}
		aux = aux->getNext();
	}
	return menor;
}


template<class T>
inline T* List7<T>::findMajor(bool(*funcComp)(T*, T*))
{
	if (first == NULL && last == NULL)
	{
		throw emptyListException();
	}
	T* mayor = first->getElement();
	node<T>* aux = first->getNext();

	while (aux == NULL)
	{
		if ((*funcComp)( aux->getElement(),mayor ))
		{
			mayor = aux->getElement();
		}
		aux = aux->getNext();
	}
	return mayor;
}
template<class T>
inline T* List7<T>::findInPos(int pos)
{
	if (first == NULL && last == NULL)
	{
		throw emptyListException();
	}
	node<T>* aux = first;
	T* datoEncontrado = NULL;
	int counter = 0;
	while (aux != NULL)
	{
		if (pos == counter)
		{
			datoEncontrado = aux->getElement();
		}
		counter++;
		aux = aux->getNext();
	}
	return datoEncontrado;
}



template <class T>
void List7<T>::deleteByElement(T* dato)
{

	node<T>* aux =first;				//pointer de recorrido

	if (first == NULL)			//CASE 1; list is empty
		throw emptyListException();
	else
	{							//CASE 2: delete first node 
		
		if (aux->getElement() == dato)
		{
			cout << "si";
		deleteFront();
		}
		if (last->getElement() == dato)
		{
			cout << "si";
			deleteBack();
		}
		else  //buscamos el node con el elemento
		{

			while (aux->getNext()->getElement() !=dato && aux->getNext() != last)
			{
				aux = aux->getNext();
			}
			
				if (aux->getNext() == last && aux->getNext()->getElement()==dato)
				{
					delete aux->getNext();
					last = aux;
					last->createNext(NULL);
					index--;

				}
				else
					if (aux->getNext()->getElement() == dato)
					{
						node<T>* helpAux = aux->getNext()->getNext();

						helpAux = aux->getNext()->getNext();
						delete aux->getNext();
						aux->createNext(helpAux);
					}


			
			// end while
				cout << "El elemento no se encontraba en la lista." << endl;
		}
	}
}

template<class T>
inline bool List7<T>::deleteElem(T* dato)
{
	bool res = true;
	node<T>* aux;
	aux = first;

	if (first == NULL)
	{
		throw emptyListException();
	}
	if (dato == first->getElement() )
	{
		cout << "si";

		deleteFront();
	}
	else if (dato == last->getElement())
	{
		cout << "si";

		deleteBack();
	}
	else
	while (aux->getNext()->getElement() != dato && aux->getNext() != last)
	{
		aux = aux->getNext();
	
	if (aux->getNext()->getElement() == dato)
	{
		node<T>* helpAux = aux->getNext()->getNext();
		delete aux->getNext();
		aux->createNext(helpAux);
	}

	}
	return res;
}



template <class T>
inline bool List7<T>::deleteElem2(T* dato)
{
	bool res = false;
	if (first == NULL)
	{
		res = false;
	}
	else
	{
		if (first->getElement() == dato)
		{
			deleteFront();
			res = true;
			cout << "si";

		}
		else if (last->getElement() == dato)
		{
		 deleteBack();
		 res = true;
		 cout << "si";


		}
		else
		{
			node<T>* aux = first;
			while (aux->getNext()->getElement() != dato && aux->getNext() != last)
			{
				aux = aux->getNext();
				if (aux->getNext() == last && aux->getNext()->getElement() == dato)
				{
					delete aux->getNext();
					last = aux;
					last->createNext(NULL);
					res = true;
				}
				else
				{
					if (aux->getNext()->getElement() == dato)
					{
						node<T>* helpAux = aux->getNext()->getNext();
						delete aux->getNext();
						aux->createNext(helpAux);
						res = true;
					}
				}
			}
		}
	}
	return res;
}

template<class T>
inline void List7<T>::deleteElem3(T* dato)
{

		node<T>* current;				//pointer de recorrido
		node<T>* trailCurrent;			//pointer antes de current
		bool found;

		if (first == NULL)			//CASE 1; vacio
			cout << "vacio." << endl;
		else
		{							//CASE 2: delete first
			if (*(first->getElement()) == dato)
			{
				current = first;
				first = first->getNext();
				if (first == NULL)   //list lista tiene solo 1 nodo
					last = NULL;
				delete current;
			}
			else  // buscamos el nodo por element
			{
				found = false;
				trailCurrent = first;		//set trailCurrent to point first 
											
				current = first->getNext(); //set current to point to    second 
											

				while (current != NULL && !found)
				{
					if (!(*(current->getElement()) == dato))
					{
						trailCurrent = current;
						current = current->getNext();
					}
					else
						found = true;
				} // end while

				if (found) //CASE 3; if found, delete node
				{
					trailCurrent->createNext(current->getNext());

					if (last == current)			//el elemento esta en last 
												
						last = trailCurrent;	//actualizamos el last

					delete current;				
				}
				else
					cout << "el elemento no estaba en la lista." << endl;
			}
		}
	}

