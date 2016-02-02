/*
 * SingleLinkedList.h
 *
 *  Created on: Feb 1, 2016
 *      Author: carolsusieo
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_


template <class Item>
class LinkList {
	private:
	    template <typename Items>
        struct Node
        {
            Items item;
            Node * nextLink;
        };

        Node<Item>* first;


		//LinkList constructor
	public:
		LinkList();
		~LinkList();

		bool isEmpty()    { return first == (Node<Item>*)0; }

		void insertFirst(Item item);
		Item getFirstItem();
		Item getItem(int i);
		void printList();

		Node<Item>* deleteFirst()
			{
					Node<Item>* temp = first;
					first = temp->nextLink;
					return temp;
			}


};

class SingleLinkedList {
private:
	int lsize;
	LinkList<int>* list;

public:
	SingleLinkedList(int num);
	virtual ~SingleLinkedList();

	void main(char** args);

	void show();

	int size() { return lsize;}
	int get(int i) { return list->getItem(i); }

};


#endif /* SINGLELINKEDLIST_H_ */
