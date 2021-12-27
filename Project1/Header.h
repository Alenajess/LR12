#include <iostream>
#include "AbstractStack.h"
using namespace std;

class NoElementsException :public exception
{
public:
	NoElementsException(const char* msg) :
		exception(msg) {}
};

template <typename T>
struct Node 
{
	T a;
	Node* prev;
	Node* next;
};

template <typename T>
class Stack: AbstractStack<T>
{
public:
	Stack();
	Stack(T);
	Stack<T>& operator=(Stack&&);
	int GetSize() const override;
	void Push(const T) override;
	void Pop(T&) override;
	bool HasElements() const;
	void Peek(T&)override;
private:
	Node<T>* tail;
	Node<T>* next;
	int count;
};