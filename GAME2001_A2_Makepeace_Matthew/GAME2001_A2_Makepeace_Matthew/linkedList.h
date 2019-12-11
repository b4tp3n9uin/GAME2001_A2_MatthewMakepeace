#pragma once
#include <cassert>

template<class T> class LinkIterator;
template<class T> class LinkList;

// Describes a single node
template <class T>
class Node
{
	// Giving access to the private member variables
	friend class LinkIterator<T>;
	friend class LinkList<T>;

public:
	int priority;
	T data;
	Node* next;
	Node* prev;
};

template <class T>
class LinkIterator
{
public:
	Node<T>* node;
public:
	LinkIterator();
	~LinkIterator();

	T& operator*();
	void operator++();
	void operator++(int);
	void operator=(Node<T>* node);

	bool isValid()
	{
		return (node != NULL);
	}
};

template <class T>
class LinkedList
{
public:
	int size;
	Node<T>* root;
	Node<T>* lastNode;

public:
	LinkedList();
	~LinkedList();

	Node<T>* Begin();
	Node<T>* End();
	Node<T>* Last();

	void Pop();
	void Push(T newData);
	int GetSize();

	void Insert_Before(LinkIterator<T> &it, T newData);
	void Insert_After(LinkIterator<T>& it, T newData);
};


template<class T>
inline LinkIterator<T>::LinkIterator()
{
	node = NULL;
}

template<class T>
inline LinkIterator<T>::~LinkIterator()
{
}

template<class T>
inline T & LinkIterator<T>::operator*()
{
	assert(node != NULL);
	return node->data;
}

template<class T>
inline void LinkIterator<T>::operator++()
{
	assert(node != NULL);
	node = node->next;
}

template<class T>
inline void LinkIterator<T>::operator++(int)
{
	assert(node != NULL);
	node = node->next;
}

template<class T>
inline void LinkIterator<T>::operator=(Node<T>* Node)
{
	node = Node;
}








template<class T>
inline LinkedList<T>::LinkedList()
{
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	while (root)
	{
		Pop();
	}
}

template<class T>
inline Node<T>* LinkedList<T>::Begin()
{
	assert(root != NULL);
	return root;
}

template<class T>
inline Node<T>* LinkedList<T>::End()
{
	return NULL;
}

template<class T>
inline Node<T>* LinkedList<T>::Last()
{
	return lastNode;
}

template<class T>
inline void LinkedList<T>::Pop()
{

	assert(root != NULL);

	// We are eventually deleting the contents of temp
	Node<T>* temp = root;

	root = root->next;

	if (root != NULL)
	{
		root->prev = NULL;
	}
	else // BOOK ERROR
	{
		lastNode = NULL;
	}

	delete temp;
	temp = NULL;

	size = (size == 0 ? size : size - 1); // Prevent negative numbers
}

template<class T>
inline void LinkedList<T>::Push(T newData)
{
	Node<T>* mNode = new Node<T>;

	assert(mNode != NULL);
	mNode->data = newData;
	mNode->next = NULL;
	mNode->prev = NULL;

	// Add new LinkNode to the existing link list
	if (lastNode != NULL) // Items currently exist in the link list
	{
		lastNode->next = mNode;
		mNode->prev = lastNode; // New node should point to the previous node
	}
	else // An empty link list
	{
		root = mNode;
	}

	lastNode = mNode;

	size++;
}

template<class T>
inline int LinkedList<T>::GetSize()
{
	return size;
}

template<class T>
inline void LinkedList<T>::Insert_Before(LinkIterator<T>& it, T newData)
{
	assert(it.node != NULL);

	Node<T>* nodePTR = new Node<T>;
	assert(nodePTR != NULL);

	nodePTR->data = newData;
	nodePTR->next = it.node;
	nodePTR->prev = it.node->prev;

	if (nodePTR->prev != NULL)
		nodePTR->prev->next = nodePTR;

	it.node->prev = nodePTR;

	if (it.node == root)
		root = nodePTR;

	size++;
}

template<class T>
inline void LinkedList<T>::Insert_After(LinkIterator<T>& it, T newData)
{
	assert(it.node != NULL);

	Node<T>* nodePTR = new Node<T>;
	assert(nodePTR != NULL);

	nodePTR->data = newData;
	nodePTR->next = it.node->next;
	nodePTR->prev = it.node;
	if (nodePTR->next != NULL)
		nodePTR->next->prev = nodePTR;

	it.node->next = nodePTR;

	if (it.node == lastNode)
		lastNode = nodePTR;

	size++;
}
