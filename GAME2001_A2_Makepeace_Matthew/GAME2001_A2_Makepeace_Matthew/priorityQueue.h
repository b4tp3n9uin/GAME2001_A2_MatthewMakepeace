#pragma once
#include "linkedList.h"
#include <cassert>

template <class T, class CMP>
class PriorityQueue
{
public:
	PriorityQueue(int size);
	~PriorityQueue();

	void Pop();
	void Push(T val);

	T& front();
	T& back();

	int GetSize() { return elements.GetSize(); }
	T GetMaxSize() { return size; }
	bool isEmpty();
	void ReSize(int mSize) { assert(mSize); size = mSize; }
private:
	int size;
	LinkedList<T> elements;
};



template<class T, class CMP>
inline PriorityQueue<T, CMP>::PriorityQueue(int size)
{
	assert(size > 0);
	this->size = size;
}

template<class T, class CMP>
inline PriorityQueue<T, CMP>::~PriorityQueue()
{
}

template<class T, class CMP>
inline void PriorityQueue<T, CMP>::Pop()
{
	elements.Pop();
}

template<class T, class CMP>
void PriorityQueue<T, CMP>::Push(T val)
{
	assert(elements.GetSize() < size);
	if (elements.GetSize() == 0)
		elements.Push(val);

	else
	{
		LinkIterator<T> it;
		it = elements.Begin();

		CMP cmp;

		while (it.isValid())
		{
			if (cmp(val, *it))
			{
				break;
			}
			it++;
		}

		if (it.isValid())
			elements.Insert_Before(it, val);

		else
			elements.Push(val);
	}
}

template<class T, class CMP>
inline T& PriorityQueue<T, CMP>::front()
{
	LinkIterator<T> it;
	it = elements.Begin();

	return *it;
}

template<class T, class CMP>
inline T& PriorityQueue<T, CMP>::back()
{
	LinkIterator<T> it;
	it = elements.Last();

	return *it;
}

template<class T, class CMP>
inline bool PriorityQueue<T, CMP>::isEmpty()
{
	return (elements.GetSize() == 0);
}
