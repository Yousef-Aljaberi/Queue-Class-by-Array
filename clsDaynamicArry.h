#pragma once
#include<iostream>

using namespace std;

template <class T>

class clsDaynamicArry
{
private:

	int _Size = 0;

protected:

	T* _TempArray;

public:
	T* OriginalArry;

	clsDaynamicArry(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArry = new T[_Size];
		
	}

	~clsDaynamicArry()
	{
		delete[]  OriginalArry;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size &&  _Size != 0)
		{
			return false;
		}

		OriginalArry[Index] = Value;
		return true;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	int Size()
	{
		return _Size;
	}


	void PrintList()
	{
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArry[i] << " ";
		}
		cout << "\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;
		
		//limit the original size to the new size if it is less
		if (NewSize < _Size)
			_Size = NewSize;

		_TempArray =new T[NewSize];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArry[i];
		}

		_Size = NewSize;

		delete[]  OriginalArry;

		OriginalArry = _TempArray;
	}

	T GetItem(int Index)
	{
		if (!(Index < 0 || Index>_Size))
		{
			return OriginalArry[Index];
		}

	}

	void Reverse()
	{
		T Temp;

		int midSize = _Size / 2;

		for (int i = 0; i <midSize ; i++)
		{
			
			swap(OriginalArry[i], OriginalArry[_Size - 1 - i]);
			
		}
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArry;

		OriginalArry = _TempArray;
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArry[i] == Value)
				return i;
		}

		return -1;
	}

	//---------------------------------

	bool DeleteItemAt(int Index)
	{
		if (Index < 0 || Index >= _Size)
			return false;

		_Size--;

		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArry[i];
		}
		
		for (int i = Index+1; i <_Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArry[i];
		}

		delete[] OriginalArry;
		OriginalArry = _TempArray;

		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);

	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);	
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);

		if (Index != -1)
		{
			DeleteItemAt(Index);
			return true;
		}
		return false;
	}

	//-----------------------------------
	bool InsertAt(int Index, T Value)
	{
		if (Index < 0 || Index > _Size)
			return false;

		_TempArray = new T[_Size + 1];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArry[i];
		}

		_TempArray[Index] = Value;

		for (int i = Index; i < _Size; i++)
		{
			_TempArray[i + 1] = OriginalArry[i];
		}

		delete[] OriginalArry;
		OriginalArry = _TempArray;

		_Size++;

		return true;
	}

	bool InsertAtBeginning(T Value)
	{
		return InsertAt(0, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size, Value);
		
		else
			return InsertAt(Index + 1, Value);
	}

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
			return InsertAt(0, _Size);

		else
			return InsertAt(Index - 1, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}
};

