#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "node.h"
#include <iostream>

using namespace std;

//Linked List with recursive implementations of operations
template <class T>
class RecursiveLinkedList {
	Node<T>* head;
public:
	//Wrapper function for first recursive call to insert an item
	void insert(T item)
	{
		//If list is empty, set head
		if (head == nullptr)
		{
			head = new Node<T>(item);
			return;
		}

		//Otherwise, try to insert recursively starting at the head
		insertRecursive(item, head);
	}

	//Recursively inserts the item into the linked list with the given head
	void insertRecursive(const T item, Node<T>* head)
	{
		//Base case, if list contains 1 thing, just tack the new Node to the end
		if (head->next == nullptr)
		{
			head->next = new Node<T>(item);
			return;
		}

		//Try to insert the item to the linked list that starts with the node to the right of the current head
		insertRecursive(item, head->next);
		//NOTE: Going to the next node is a reduction operation, it doesn't always have to be strictly mathematical
	}

	//Wrapper function for first recursive call to delete an item
	void deletion(T item)
	{
		//If the head needs deleted
		if (head->data == item)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		//Try to delete, starting the search from the head
		deletionRecursive(item, head, nullptr);
	}

	//Recursively deletes an item from the linked list starting at the current Node
	void deletionRecursive(T item, Node<T>* current, Node<T>* previous)
	{
		//If list is empty (Didn't find item), nothing to delete
		if (current == nullptr)
			return;

		//If the current node is the one to delete, delete it after updating pointers
		if (current->data == item)
		{
			previous->next = current->next;
			delete current;
			return;
		}

		//Otherwise, try to delete the item from the list to the right
		deletionRecursive(item, current->next, current);
	}
};

#endif
