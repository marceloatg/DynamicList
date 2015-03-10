#pragma once
#include <iostream>

///  This class stores the node information and a pointer to the next
/// element in the list.
template <class Element>
class DynamicListNode
{
public:
	/// Class constructor.
	DynamicListNode();

	/// Class destructor.
	~DynamicListNode();

	/// Element to be stored.
	Element data;

	/// Pointer to next element.
	DynamicListNode* link;
};

#pragma region "DynamicListNode implementation"
template <class Element>
DynamicListNode<Element>::DynamicListNode()
{
	link = NULL;
}

template <class Element>
DynamicListNode<Element>::~DynamicListNode()
{
}

#pragma endregion

///  This class manages the DynamicListNode objects in order to create a dynamic 
/// list, with add, get and remove operations concerning to the nodes.
template <class Element>
class DynamicList
{
public:
	/// Class constructor.
	DynamicList();

	/// Class destructor.
	~DynamicList();

	/// Add an element to the end of the list.
	///
	/// <param element> The Element to be added.
	void add(Element element);

	/// Remove an element from the beginning of the list.
	void remove(void);

	/// Get an element from the beginning of the list.
	///
	/// <returns> Returns DynamicListNode<Element> *head.
	Element get(void);

	/// Get the size of the list (aka quantity of nodes).
	///
	/// <returns> Returns int size.
	inline int getSize(void);

	/// Prints all elements of the stack in order using cout. 
	void print(void);

private:
	/// Head node pointer.
	DynamicListNode<Element> *head;

	/// Tail node pointer.
	DynamicListNode<Element> *tail;

	/// Size of the stack.
	int size;
};

#pragma region "Dynamic list implementation"

template <class Element>
DynamicList<Element>::DynamicList()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

template <class Element>
DynamicList<Element>::~DynamicList()
{
	if (head) delete head;
	if (tail) delete tail;
}

template <class Element>
void DynamicList<Element>::add(Element element)
{
	// Creating auxiliar DynamicListNode.
	DynamicListNode<Element>* aux = new DynamicListNode<Element>();

	// aux receives the element data and becames the head of the stack.
	aux->data = element;
	
	if (size == 0) { this->head = aux; }
	else { this->tail->link = aux; }
	this->tail = aux;

	// Increment stack size and return.
	this->size++;
	return;
}

template <class Element>
void DynamicList<Element>::remove(void)
{
	// If the list is empty, return.
	if (this->size == 0)
	{
		return;
	}

	// Creating auxiliar DynamicListNode.
	DynamicListNode<Element>* aux = this->head->link;

	// Delete head node.
	delete (this->head);
	this->head = aux;

	// Decrement stack size and return.
	this->size--;
	return;
}

template <class Element>
Element DynamicList<Element>::get(void)
{
	return this->head->data;
}

template <class Element>
inline int DynamicList<Element>::getSize(void)
{
	return this->size;
}

template <class Element>
void DynamicList<Element>::print(void)
{
	if (size == 0)
	{
		cout << "List is empty." << endl;
	}
	else
	{
		int counter = 0;
		DynamicListNode<Element>* aux = this->head;
		while (true)
		{
			cout << "Element " << counter++ << " : " << aux->data << endl;
			if ((aux = aux->link) == NULL) break;
		}
	}

	return;
}

#pragma endregion