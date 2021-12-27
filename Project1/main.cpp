#include "Header.h"
#include <conio.h>
#include<iostream>


using namespace std;

template <typename T>
Stack<T>::Stack() {}


template <typename T>
Stack<T>::Stack(T a)
{
	tail = new Node<T>;
	tail->prev = tail;
	tail->next = tail;
	tail->a = a;
	count = 0;

}


template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete tail;
	delete next;
	tail = other.tail;
	other.tail = nullptr;
}


template <typename T>
int Stack<T>::GetSize() const
{
	return count;
}


template <typename T>
void Stack<T>::Push(const T a)
{
	Node<T>* newnode = new Node<T>;
	Node<T>* checking = next;
	if (HasElements())
	{
		while (checking->next != tail)
		{
			checking = checking->next;
		}
		checking->next = newnode;
		tail->prev = next;
	}
	else
	{
		tail = newnode;
		next = newnode;
	}
	newnode->a = a;
	newnode->prev = checking;
	newnode->next = tail;
	count = count + 1;
}


template <typename T>
void Stack<T>::Pop(T& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	Node<T>* temp = tail;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	a = temp->a;
	next = temp;
	if (next != tail)
	{
		next->prev->next = tail;
	}
	else
	{
		next = tail = nullptr;
	}
	count = count - 1;
}


template <typename T>
void Stack<T>::Peek(T& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	Node<T>* temp = next;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	a = temp->a;
}


template <typename T>
bool Stack<T>::HasElements() const
{
	if (this->tail != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	Stack<double> a;
	double b;
	bool flag = true;
	while (flag)
	{
		cout << "1. Добавить элемент в стек\n";
		cout << "2. Получить элемент из стека\n";
		cout << "3. Посмотреть элемент из стека\n";
		cout << "4. Длина стека\n";
		cout << "5. Выход\n";
		switch (_getch()) 
		{
			case '1':
				cout << "Добавить элемент: ";
				cin >> b;
				a.Push(b);
				break;
			case '2':
				try
				{
					a.Pop(b);
					cout << "Полученный элемент " << b << endl;

				}
				catch (NoElementsException ex)
				{
					cout << "Cтек пуст\n";
				}
				break;
			case '3':
				try 
				{
					a.Peek(b);
					cout << "Последний элемент " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "Cтек пуст\n";
				}
				break;
			case '4':
				b = a.GetSize();
				cout << "Длина стека: " << b << endl;
				break;
			case '5':
				flag = false;
				break;

		}
	}

}