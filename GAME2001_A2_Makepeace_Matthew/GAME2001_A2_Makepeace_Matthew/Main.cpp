#include <iostream>
#include "priorityQueue.h"
using namespace std;

template<class T>
class lessCMP
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return (lVal < rVal);
	}
};

template<class T>
class lessCMPptr
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return ((*lVal) < (*rVal));
	}
};

template<class T>
class greaterCMP
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !(lVal < rVal);
	}
};

template<class T>
class greaterCMPptr
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !((*lVal) < (*rVal));
	}
};

class NetworkMessage
{
private:
	int priority, ID;
public:
	NetworkMessage() : priority(0), ID(0) {}
	NetworkMessage(int p, int id) : priority(p), ID(id) { }
	~NetworkMessage() { }

	int GetPriority();
	int GetID();

	bool operator<(NetworkMessage& m);
	bool operator>(NetworkMessage& m);
};

int NetworkMessage::GetPriority()
{
	return priority;
}

int NetworkMessage::GetID()
{
	return ID;
}

bool NetworkMessage::operator<(NetworkMessage& m)
{
	if (priority < m.GetPriority())
	{
		return true;
	}
	else if (ID < m.GetID())
	{
		return true;
	}

	return false;
}

bool NetworkMessage::operator>(NetworkMessage& m)
{
	return !(*this < m);
}


int main()
{
	cout << "Priority Queue Data Structures Examples: " << endl << endl;

	const int size = 5;

	PriorityQueue<NetworkMessage, lessCMP<NetworkMessage> > que(size);

	que.Push(NetworkMessage(4, 33));
	que.Push(NetworkMessage(3, 9));
	que.Push(NetworkMessage(2, 23));
	que.Push(NetworkMessage(2, 7));
	que.Push(NetworkMessage(1, 43));


	cout << "Priority Queue-" << endl << endl;

	cout << "Priority Queue contents (Size - "
		<< que.GetSize() << ") ) :" << endl;

	while (que.isEmpty() == false)
	{
		cout << "  Priority: " << que.front().GetPriority();
		cout << "- ID: " << que.front().GetID() << endl;

		que.Pop();
	}

	cout << endl;

	if (que.isEmpty() == true)
		cout << "Container is MT. I mean empty Aha ha ha." << endl << endl;
	else
		cout << "Container is NOT empty." << endl << endl;

	return 1;
}