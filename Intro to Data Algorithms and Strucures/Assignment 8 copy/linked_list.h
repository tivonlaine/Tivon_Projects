#ifndef LL_H
#define LL_H

#include "node.h"
#include <iostream>

using namespace std;

//Singly linked list class with just a head pointer pointing to the first Node
template<class T>
class LinkedList {
	Node<T>* head;

public:
	LinkedList<T>() { head = nullptr; } //Constructor that makes an empty list

	//Inserts an item to the end of the linked list
	void insert(T item)
	{
		Node<T>* newNode = new Node<T>(item); //Create the Node to add to the end
		if (head == nullptr) //If the list is empty, the new Node is the head
		{
			head = newNode;
			return;
		}

		Node<T>* current = head; //Start at the head
		while (current->next != nullptr) //Keep going until we reach the end
			current = current->next; //Go to the next node

		current->next = newNode; //Link the newNode to the end
	}

	//Inserts the item in a sorted order. Assumes the list is already sorted before insert
	void insertSorted(T item)
	{
		Node<T>* newNode = new Node<T>(item); //Create new node to be added
		if (head == nullptr) //If the list is empty, make the new node the head
		{
			head = newNode;
			return;
		}

		//If the item being inserted should come first and be the new head
		if (head->data > item)
		{
			newNode->next = head;
			head = newNode;
			return;
		}

		Node<T>* current = head; //Start at the head
		while (current->next != nullptr) //Keep going until we reach the end
		{
			if (current->next->data > item) //If the next one is bigger than what we are inserting
			{
				newNode->next = current->next;
				current->next = newNode;
				return;			
			}
			current = current->next; //Go to the next node
		}

		current->next = newNode;

	}

	//Tells if the given item is in the LinkedList. Returns true if it is and false if not
	bool lookup(T item)
	{
		Node<T>* current = head; //Start at head
		while (current != nullptr) //While not at the end
		{
			if (current->data == item) //If we found the item, return true
				return true;
			current = current->next; //Go to next node
		}


		return false; //If we got to the end without finding the item, it's not there
	}

	//Deletes the first instance of the item from the LinkedList
	void deleteFrom(T item)
	{
		//If we are deleting the head
		if (head->data == item)
		{
			Node<T>* temp = head; //Keep a temporary pointer to old head
			head = head->next; //Update the head to the next one
			delete temp; //Delete the old head
			return;
		}

		Node<T>* current = head; //Start at head
		Node<T>* before; //Used to point to the node before the current one
		while (current != nullptr) //While not at the end
		{
			if (current->data == item) //If we found the item, return true
			{
				before->next = current->next; //Set the node before the one being deleted to point to the one after it
				delete current; //Delete the node
				return; //We're done, bail
			}
			before = current;
			current = current->next; //Go to next node
		}
	}

	//Prints all elements in the list
	void print()
	{
		Node<T>* current = head; //Start at head
		while (current->next != nullptr) //While not at the end
		{
			cout << current->data << ", ";
			current = current->next;
		}

		cout << current->data << endl;
	}
};

#endif