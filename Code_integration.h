#pragma once
#include<iostream>
using namespace std;
/*This file is an integration of all the uploaded codes. 
If you want to view a certain part of the code, please 
check the corresponding branch. Thanks for your support.*/
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
	Chain() {}
	Chain(Link<T>* p);
	Chain(const Chain<T>&);
	~Chain();
	Chain* GetHead() { return head; }
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
class DoublyLink
{
public:
	T element;
	DoublyLink* left;
	DoublyLink* right;
	DoublyLink(T data, DoublyLink* leftValue = NULL, DoublyLink* rightValue = NULL)
	{
		element = data;
		left = leftValue;
		right = rightValue;
	}
	DoublyLink(DoublyLink* leftValue = NULL, DoublyLink* rightValue = NULL)
	{
		left = leftValue;
		right = rightValue;
	}
};

template<class T>
class DoublyLinkedList :public DoublyLink<T>
{
public:
	DoublyLinkedList() {}
	DoublyLinkedList(DoublyLink<T>* p);
	DoublyLinkedList(const DoublyLinkedList<T>&);
	~DoublyLinkedList();
	DoublyLinkedList* GetHead() { return head; }
	void Getsize() { cout << Listsize << endl; }
	void empty() const { return Listsize == 0; }
	void Insert(int p, T newelement);
	void Delete(int p);
	void Append(T newelement);
	void Traverse();
	DoublyLinkedList* CircularDoublyLinkedList();
private:
	DoublyLink<T>* head;
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
	for (int i = 1; i < p - 1; i++)
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

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLink<T>* p)
{
	head = p;
	Listsize = 0;
	while (p != NULL)
	{
		p = p->right;
		Listsize++;
	}
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& theList)
{
	Listsize = theList.Listsize;
	head = theList.head;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Listsize = 0;
	while (head != NULL)
	{
		DoublyLinkedList<T>* nextNode = head->right;
		delete head;
		head = nextNode;
	}
}

template<class T>
void DoublyLinkedList<T>::Insert(int p, T newelement)//The first cell of the list is position one
{
	if (p > Listsize)
	{
		throw"Input position error";
		return;
	}
	DoublyLink<T>* position = head;
	DoublyLink<T>* newpositon = new DoublyLink<T>(newelement);
	for (int i = 1; i < p - 1; i++)
	{
		position = position->right;
	}
	newpositon->right = position->right;
	position->right = newpositon;
	Listsize++;
}

template<class T>
void DoublyLinkedList<T>::Delete(int p)//The first cell of the list is position one
{
	if (p > Listsize)
	{
		throw"Input position error";
		return;
	}
	DoublyLink<T>* preposition = head;
	DoublyLink<T>* position;
	for (int i = 1; i < p - 1; i++)
	{
		preposition = preposition->right;
	}
	position = preposition->right;
	preposition->right = position->right;
	position->right = NULL;
	delete position;
	Listsize--;
}

template<class T>
void DoublyLinkedList<T>::Append(T newelement)
{
	DoublyLink<T>* position = head;
	DoublyLink<T>* newLink = new DoublyLink<T>(newelement);
	while (position->right != NULL)
	{
		position = position->right;
	}
	position->right = newLink;
	Listsize++;
}

template<class T>
void DoublyLinkedList<T>::Traverse()
{
	while (head != NULL)
	{
		cout << head->element << " ";
		head = head->right;
	}
	cout << "\n";
}

template<class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::CircularDoublyLinkedList()
{
	DoublyLinkedList* p = head;
	while (p != NULL)
	{
		p = p->right;
	}
	head->left = p;
	p->right = head;
	return p;
}