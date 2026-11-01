#pragma once
#include"clsDaynamicArry.h"

template<class T>

class clsMyQueueArr
{
protected:
	clsDaynamicArry <T> _MyList;

public:

	void push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void pop()
	{
		_MyList.DeleteFirstItem();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	void Print()
	{
		_MyList.PrintList();
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T Value)
	{
		_MyList.SetItem(Index, Value);
	}

	void InsertAfter(int Index, T Value)
	{
		_MyList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}


	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};

