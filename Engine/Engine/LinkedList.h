#pragma once

#include "CommonFunctions.h"

template <typename T>
class LinkedList {
private:

	struct Node
	{
		T data;
		Node *next = nullptr;
		Node *prev = nullptr;
		
		Node(T data)
		{
			this->data = data;
		}

		bool operator==(const T& rhs)
		{
			return data == rhs;
		}
		bool operator!= (const T &rhs) 
		{
			return data != rhs;
		}

	};

	Node *head = nullptr;
	Node *tail = nullptr;

	int size;
public:

	LinkedList()
	{
		size = 0;
	}

	LinkedList(T* data)
	{
		head = new Node(*data);
		tail = head;
		size = 1;
	}

	~LinkedList()
	{
		DeleteAll();
	}
	
	void AddToEnd(T* data)
	{
		if (!head)
		{
			head = new Node(*data);
			tail = head;
			size = 1;
		}
		else
		{
			Node *temp = new Node(*data);
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			size++;
		}
	}

	void AddToFront(T* data)
	{
		if (!head)
		{
			head = new Node(*data);
			tail = head;
			size = 1;
		}
		else
		{
			Node *temp = new Node(*data);
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void PopFront()
	{
		if (!head)
		{
			DisplayErrorBox("No data to delete/pop");
		}
		else
		{
			Node *temp = head;
			if (head->next)
			{
				head = head->next;
				head->prev = nullptr;
			}
			delete temp;
			size--;
		}
	}

	void PopBack()
	{
		if (!tail)
		{
			DisplayErrorBox("No data to delete/pop");
		}
		else
		{
			if (size == 1)
			{
				PopFront();
			}
			else
			{
				Node *temp = tail;
				tail = tail->prev;
				delete temp;
				size--;
			}
			
		}
	}

	void DeleteAll()
	{
		if (size > 0)
		{
			Node *loopThis = tail;
			while (loopThis)
			{
				Node *temp = loopThis;
				loopThis = loopThis->prev;
				delete temp;
				size--;
			}
		}
	}

	void Delete(T* element)
	{
		if (size > 0)
		{
			Node *temp = head;
			if (head->data == *element)
			{
				head = head->next;
				delete temp;
			}
			else if(tail->data == *element)
			{
				temp = tail;
				tail = tail->prev;
				delete temp;
			}
			else
			{
				temp = head->next;
				bool found = false;
				for (int i = 1; i < size; i++)
				{
					if (temp->data == *element)
					{
						temp->prev->next = temp->next;
						delete temp;
						found = true;
						break;
					}
					temp = temp->next;
				}
				if (!found)
				{
					DisplayErrorBox("No data to delete");
				}
			}
			size--;
		}
		else
		{
			DisplayErrorBox("No data to delete");
		}
	}
	
	T* Get(int index)
	{
		if (index < size)
		{
			Node *temp;
			temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			return &temp->data;
		}
		else
		{
			DisplayErrorBox("Index bigger than array");
			return nullptr;
			
		}
	}
};

