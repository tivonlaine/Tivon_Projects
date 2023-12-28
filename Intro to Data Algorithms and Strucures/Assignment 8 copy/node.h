#ifndef NODE_H
#define NODE_H

//Singly linked Node which contains data and a link to the next node after this one
template <class T>
struct Node {
	T data;
	Node<T>* next;

	Node<T>(T data) { this->data = data; next = nullptr; }
	Node<T>() {}
}; 

//Doubly linked node which contains a pointer to the next node and the one before it
template<class T>
struct DLNode : public Node<T>
{
	Node<T>* prev;

	DLNode<T>(T data) : Node<T>(data) { prev = nullptr; }
};

#endif
