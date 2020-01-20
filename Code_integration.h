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

template<class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual T& GetTop()const = 0;
	virtual void clear() = 0;
	virtual void pop() = 0;
	virtual void push(const T& newelement) = 0;
};

template<class T>
class arrayStack :public Stack<T>
{
public:
	arrayStack(int Capacity = 0)
	{
		maxSize = Capacity;
		top = -1;
		st = new T[maxSize];
	}
	~arrayStack() { delete[]st; }
	bool empty()const { return top == -1; }
	int size()const { return top + 1; }
	T& GetTop()const;
	void clear();
	void pop();
	void push(const T& newelement);
private:
	int maxSize;
	T* st;
	int top;
};

template<class T>
T& arrayStack<T>::GetTop()const
{
	if (top == -1) throw - 1;
	else return st[top];
}

template<class T>
void arrayStack<T>::clear()
{
	while (top != -1) this->pop();
}

template<class T>
void arrayStack<T>::pop()
{
	if (top == -1) throw - 1;
	st[top--].~T();
}

template<class T>
void arrayStack<T>::push(const T& newelement)
{
	if (top == maxSize - 1) throw - 1;
	else st[++top] = newelement;
}



template<class T>
class linkedStack :public Stack<T>
{
public:
	linkedStack()
	{
		top = NULL;
		linked_size = 0;
	}
	~linkedStack();
	bool empty()const;
	int size()const;
	T& GetTop()const;
	void clear();
	void pop();
	void push(const T& newelement);
private:
	Link<T>* top;
	int linked_size;
};

template<class T>
linkedStack<T>::~linkedStack()
{

	while (top != NULL)
	{
		Link<T>* nextNode = top->next;
		top->element.~T();
		delete top;
		top = nextNode;
	}
}

template<class T>
bool linkedStack<T>::empty()const
{
	return top == NULL;
}

template<class T>
int linkedStack<T>::size()const
{
	int i = 0;
	Link<T>* p = top;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

template<class T>
T& linkedStack<T>::GetTop()const
{
	if (top == NULL) throw - 1;
	else return top->element;
}

template<class T>
void linkedStack<T>::clear()
{
	while (top != NULL) this->clear();
}

template<class T>
void linkedStack<T>::pop()
{
	if (top == NULL) throw - 1;
	else
	{
		Link<T>* p = top;
		top->element.~T();
		top = top->next;
		delete p;
		this->linked_size--;
	}
}

template<class T>
void linkedStack<T>::push(const T& newelement)
{
	Link<T>* newtop=new Link<T>(newelement, top);
	top = newtop;
	this->linked_size++;
}
