#pragma once
 

#include <iostream>
using namespace std;

template <class T>
	class node
	{

	private:
		node* next;
		T* element;


	public:
		node();
		node(T* element);
		~node();

	
		T* getElement();
		void setElement(T* dato);
		node<T>* getNext();
		void createNext(node<T>* dato);
		//bool operator==(node* t);



	};
	template<class T>
	inline node<T>::node()
	{
		element = NULL;
		next = NULL;
	}
	template<class T>
	inline node<T>::node(T* element)
	{
		this->element = element;
		next = NULL;
	}

	template<class T>
	node<T>::~node()
	{
	}

	template<class T>
	inline T* node<T>::getElement()
	{
		return element;
	}

	template<class T>
	inline void node<T>::setElement(T* dato)
	{
		element = dato;
	}

	template<class T>
	inline node<T>* node<T>::getNext()
	{
		return next;
	}

	template<class T>
	inline void node<T>::createNext(node<T>* dato)
	{
		next = dato;

	}

	//template<class T>
	//inline bool node<T>::operator==(node* t)
	//{
	//	return element == t->getElement();
	//}

	