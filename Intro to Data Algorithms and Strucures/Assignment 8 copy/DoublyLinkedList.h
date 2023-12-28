#ifndef DOUBLY_H
#define DOUBLY_H

#include "node.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList
{
	DLNode<T>* head;
	DLNode<T>* tail;

public:
	DoublyLinkedList<T>() { head = tail = nullptr; }

	//Insert the item to the end of the linked list
	void insert(T item)
	{
		DLNode<T>* newNode = new DLNode<T>(item);

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			return;
		}

		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	//Same as singly linked version, no difference
	bool lookup(T item)
	{
		DLNode<T>* current = head; //Start at head
		while (current != nullptr) //While not at the end
		{
			if (current->data == item) //If we found the item, return true
				return true;
			current = current->next; //Go to next node
		}

		return false; //If we got to the end without finding the item, it's not there
	}

	void deleteFrom(T item)
	{
		if (head->data == item)
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			return;
		}

		if (tail->data == item)
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
			return;
		}

		DLNode<T>* current = head; //Start at head
		while (current != nullptr) //While not at the end
		{
			if (current->data == item) //If we found the item, remove it
			{
				//if(current->prev != nullptr && current != nullptr) //Safety check if you feel like it
				current->prev->next = current->next; //Make the node before point to the node after
				current->next->prev = current->prev; //Make the node after point to the node before
				delete current;
				return;
			}
			current = current->next; //Go to next node
		}
	}
};

#endif