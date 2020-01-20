#pragma once
#include<iostream>
#include"chain.h"
using namespace std;
template<class T>
class Stack
{
public:
	virtual ~Stack(){}
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
	if(top==-1) throw -1;
	st[top--].~T();
}

template<class T>
void arrayStack<T>::push(const T& newelement)
{
	if (top == maxSize - 1) throw -1;
	else st[++top] = newelement;
}


template<class T>
class linkedStack :public Stack<T>
{
public:
	linkedStack(T data, Link<T>* nextValue = NULL)
	{
		this->top->element = data;
		this->top->next = nextValue;
		this->linked_size++;
	}
	~linkedStack();
	bool empty()const;
	int size()const;
	T& GetTop()const;
	void clear();
	void pop();
	void push(const T& newelement);
private:
	Link<T>* top=NULL;
	int linked_size=0;
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
	while (top != NULL)
	{
		i++;
		top = top->next;
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
	linkedStack* newtop = linkedStack(newelement, top);
	top = newtop;
}