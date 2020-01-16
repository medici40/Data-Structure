#pragma once
#include<iostream>
using namespace std;
template<class T>
class Link
{
public:
	T element;
	Link* next;
	Link(T data, Link* nextValue = NULL)
	{
		element = data;
		next = nextValue;
	}
	Link(Link* nextValue = NULL)
	{
		next = nextValue;
	}
};

template<class T>
class Chain :public Link<T>
{
public:
	Chain() {};
	Chain(Link<T>* p);
	Chain(const Chain<T>&);
	~Chain();
	void Getsize() { cout << Listsize << endl; }
	void empty() const { return Listsize == 0; }
	void Insert(int p, T newelement);
	void Delete(int p);
	void Append(T newelement);
	void Traverse();
private:
	Link<T>* head;
	int Listsize;
};

template<class T>
Chain<T>::Chain(Link<T>* p)
{
	head = p;
	Listsize = 0;
	while (p != NULL)
	{
		p = p->next;
		Listsize++;
	}
}

template<class T>
Chain<T>::Chain(const Chain<T>& theList)
{
	Listsize = theList.Listsize;
	head = theList.head;
}

template<class T>
Chain<T>::~Chain()
{
	Listsize = 0;
	while (head != NULL)
	{
		Chain<T>* nextNode = head->next;
		delete head;
		head = nextNode;
	}
}

template<class T>
void Chain<T>::Insert(int p, T newelement)//The first cell of the list is position one
{
	if (p > Listsize)
	{
		throw"Input position error";
		return;
	}
	Link<T>* position = head;
	Link<T>* newpositon = new Link<T>(newelement);
	for (int i = 1; i < p-1; i++)
	{
		position = position->next;
	}
	newpositon->next = position->next;
	position->next = newpositon;
	Listsize++;
}

template<class T>
void Chain<T>::Delete(int p)//The first cell of the list is position one
{
	if (p > Listsize)
	{
		throw"Input position error";
		return;
	}
	Link<T>* preposition = head;
	Link<T>* position;
	for (int i = 1; i < p - 1; i++)
	{
		preposition = preposition->next;
	}
	position = preposition->next;
	preposition->next = position->next;
	position->next = NULL;
	delete position;
	Listsize--;
}

template<class T>
void Chain<T>::Append(T newelement)
{
	Link<T>* position = head;
	Link<T>* newLink = new Link<T>(newelement);
	while (position->next != NULL)
	{
		position = position->next;
	}
	position->next = newLink;
	Listsize++;
}

template<class T>
void Chain<T>::Traverse()
{
	while (head != NULL)
	{
		cout << head->element << " ";
		head = head->next;
	}
	cout << "\n";
}